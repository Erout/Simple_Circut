#include<iostream>
#include"circuitControl.hpp"
#include"door.hpp"
#include"doorAnd.hpp"
#include"doorOr.hpp"
#include"doorNot.hpp"
#include"doorAndNot.hpp"
#include"doorOrNot.hpp"
circuitControl* circuitControl::instance_ = NULL;
circuitControl::circuitControl(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			adjMatrix[i][j] = 0;
		}
	}
	for(int j = 0; j < size; j++)
		vertex[j] = NULL;
	head = NULL;
	tail = NULL;
	doorNum = 0;
	time = 0;
}
circuitControl::~circuitControl(){
	clear();
}
void circuitControl::clear(){
		door* temp = head;
	while(head != tail){
		head = head->next;
		delete temp;
		temp = head;
	}
	delete head;
	head = NULL;
	tail = NULL;
	delete instance_;
	instance_ = NULL;
	removelist.clear();
	existlist.clear();
	connectlist.clear();
	topologyOrder.clear();
	for(int i = 0; i < doorNum; i++)
		vertex[i] = NULL;
	for(int i = 0; i < doorNum; i++){
		for(int j = 0; j < doorNum; j++)
			adjMatrix[i][j] = 0;
	}
	doorNum = 0;
	time = 0;
}
circuitControl::getInstance(){
	if(instance_  == NULL){
		instance_ = new circuitControl;
	}
	return instance_;
}
bool circuitControl::create(type T){
	door* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	if(T == and){
		temp->next = new doorAnd(doorNum);
	}
	else if(T == or){
		temp->next = new doorOr(doorNum);
	}
	else if(T == not){
		temp->next = new doorNot(doorNum);
	}
	else if(T == andnot){
		temp->next = new doorAndNot(doorNum);
	}
	else{
		temp->next = new doorOrNot(doorNum);
	}
	existlist.push_back(doorNum);
	doorNum++;

}
void circuitControl::list(){
	cout<<"The doors you have created:"<<endl;
	door* temp = head;
	while(temp != tail){
		if(existlist.find(temp->getId())){
			cout<<"Id: "<<temp->getId()<<"doorType: "<<temp->getName()<<"door status(connected ot not): "<<temp->getstatus()<<endl;	
		}
		temp = temp->next;
	}
	if(existlist.find(temp->getId()))
		cout<<"Id: "<<temp->getId()<<"doorType: "<<temp->getName()<<"door status(connected ot not): "<<temp->getstatus()<<endl;
}
bool circuitControl::connect(int ida, int idb){
	if((!existlist.find(ida))||(!existlist.find(idb)))
		return false;
	adjMatrix[ida][idb] = 1;
	connectlist.pushback(ida);
	connectlist.pushback(idb);
	return true;
}
bool circuitControl::remove(int id){
	if(!existlist.find(id))
		return false;
	removelist.push_back(id);
	existlist.erase(id);
	connectlist.erase (id);
	return true;
}
void circuitControl::print(){
	cout<<"The adjMatrix is: "<<endl;
	cout<<"id: ";
	for(int j = 0; j < doorNum; j++){
		if(!removelist.find(j)){
			cout<<j<<" ";
		}
	}
	cout<<endl;
	for(int i = 0; i < doorNum; i++){
		if(!removelist.find(i)){
			cout<<i<<" | "
			for(int j = 0; j < doorNum; j++){
				if(!removelist.find(j)){
					cout<<adjMatrix[i][j];
				}
			}
		}
	}
}
bool circuitControl::setInput(int id,vector<bool> in){
	if(!connectlist.find(id))
		return false;
	door* temp = head;
	while(temp->getId() != id)
		temp = temp->next;
	temp.setInput (in);
	return true;
}
void circuitControl::execute(){
	if(abnormalCheck == 0){
		cout<<"Abnormal! Please restart."<<endl;
		return;
	}
	DFS();
	auto iter = topologyOrder.rbegin()
	//检查是否有输入？
	door* temp = head;
	door* putto = head;
	int output = 1;
	for(iter; iter != topologyOrder.rend(); iter++){
		temp = head;
		while(temp->getId() != *iter){
			temp = temp->next;
		}
		for(int i = 0; i < doorNum; i++){
			if(adjMatrix[*iter][i] == 1){
				putto = head;
				while(putto->getId() != i)
					putto = putto->next;
				(*putto) += (*temp);
			}
		}
		temp->getOutput();
		output = 1;
		for(int i = 0; i < doorNum; i++){
			if(adjMatrix[*iter][i] == 1)
				output = 0;
		}
		if(output == 1){
			cout<<"the output of the door: id: "<<temp->getId()<<" type: "<<temp->getName()<<" is "<<temp->getOutput()<<endl;
		}
	}
	
}
bool circuitControl::abnormalCheck(){
	for(int i = 0; i < doorNum; i++){
		for(int j = 0; j < doorNum; j++){
			if(i == j){
				if(adjMatrix[i][j] == 1)
					return false;
			}
			if((adjMatrix[i][j] == 1)&&(adjMatrix[j][i] == 1))
				return false;
		}
	}
	return true;
}
void circuitControl::DFS(){
	time = 0;
	for(int i = 0; i < doorNum; i++){
		if(connectlist.find(i)){
			vertex[i] = new Node(i);
		}
		else
			vertex[i] = NULL;
	}
	for(int i = 0; i < doorNum; i++){
		if(vertex[i] != NULL){
			if(vertex[i]->color == white){
				DFSVisit(vertex[i]);
			}
		}
	}
}
void circuitControl::DFSVisit(Node* n){
	time++;
	n->discover = time;
	n->color = grey;
	for(int i = 0; i < doorNum; i++){
		if((adjMatrix[n->id][i] == 1)&&(vertex[i] != NULL)){
			if(vertex[i]->color == white){
				vertex[i]->father = n;
				DFSVisit(vertex[i]);
			}
		}
	}
	n->color = black;
	time++;
	n->finish = time;
	topologyOrder.pushback(n->id);
}