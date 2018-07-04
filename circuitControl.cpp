#include<iostream>
#include"circuitControl.hpp"
circuitControl* circuitControl::instance_ = NULL;
circuitControl::circuitControl(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			adjMatrix[i][j] = 0;
		}
	}
	for(int j = 0; j < size; j++)
		vertex[j] = NULL;
	head_ = NULL;
	tail_ = NULL;
	doorNumber_ = 0;
	time = 0;
}
circuitControl::~circuitControl(){
	clear();
	delete instance_;
	instance_ = NULL;
}
void circuitControl::clearInput(){
	door* temp = head_;
	while(temp != tail_){
		temp->clearInput();
		temp = temp->getNext();
	}
	temp->clearInput();
}
void circuitControl::clear(){
	door* temp = head_;
	while(head_ != tail_){
		head_ = head_->getNext();
		delete temp;
		temp = head_;
	}
	delete head_;
	head_ = NULL;
	tail_ = NULL;
	existlist.clear();
	connectlist.clear();
	topologyOrder.clear();
	for(int i = 0; i < doorNumber_; i++)
		vertex[i] = NULL;
	for(int i = 0; i < doorNumber_; i++){
		for(int j = 0; j < doorNumber_; j++)
			adjMatrix[i][j] = 0;
	}
	doorNumber_ = 0;
	time = 0;
}
circuitControl* circuitControl::getInstance(){
	if(instance_  == NULL){
		instance_ = new circuitControl;
	}
	return instance_;
}
bool circuitControl::create(int T){
	if((T < 0)||(T > 4)){
		cout<<"creation failed. you don't enter a right number"<<endl;
		return false;
	}
	door* temp = head_;
	if(temp == NULL){
		if(T == And){
			head_ = new doorAnd(doorNumber_);
		}
		else if(T == Or){
			head_ = new doorOr(doorNumber_);
		}
		else if(T == Not){
			head_ = new doorNot(doorNumber_);
		}
		else if(T == Andnot){
			head_ = new doorAndNot(doorNumber_);
		}
		else{
			head_ = new doorOrNot(doorNumber_);
		}
		tail_ = head_;
		existlist.push_back(doorNumber_);
		doorNumber_++;
		return true;
	}
	while(temp->getNext() != NULL){
		temp = temp->getNext();
	}
	if(T == And){
		temp->setNext(new doorAnd(doorNumber_));
	}
	else if(T == Or){
		temp->setNext(new doorOr(doorNumber_));
	}
	else if(T == Not){
		temp->setNext(new doorNot(doorNumber_));
	}
	else if(T == Andnot){
		temp->setNext(new doorAndNot(doorNumber_));
	}
	else{
		temp->setNext(new doorOrNot(doorNumber_));
	}
	tail_ = temp->getNext();
	existlist.push_back(doorNumber_);
	doorNumber_++;
	return true;

}
void circuitControl::list(){
	cout<<"The doors you have created:"<<endl;
	door* temp = head_;
	while(temp != tail_){
		if(find(existlist,temp->getId())){
			cout<<"Id: "<<temp->getId()<<"  doorType: "<<temp->getName()<<endl;	
		}
		temp = temp->getNext();
	}
	if(find(existlist,temp->getId()))
		cout<<"Id: "<<temp->getId()<<"  doorType: "<<temp->getName()<<endl;

	cout<<"the door that have input are: "<<endl;
	
	temp = head_;
	while(temp != tail_){
		if(temp->haveInput()){
			cout<<"id: "<<temp->getId()<<"  Input: ";
			temp->printInput();
			cout<<endl;
		}
		temp = temp->getNext();
	}
}
bool circuitControl::connect(int ida, int idb){
	if(!find(existlist,ida)||!find(existlist,idb)){
		//cout<<"invalid id choice! Connection failed"<<endl;
		return false;
	}
	adjMatrix[ida][idb] = 1;
	connectlist.push_back(ida);
	connectlist.push_back(idb);
	return true;
}

void circuitControl::print(vector<int> doorlist){
	cout<<"The adjMatrix is: "<<endl;
	cout<<"id  ";
	for(int j = 0; j < doorNumber_; j++){
		if(find(existlist,j)){
			cout<<j<<" ";
		}
	}
	cout<<endl;
	for(int i = 0; i < doorNumber_; i++){
		if(find(existlist,i)){
			cout<<i<<" | ";
			for(int j = 0; j < doorNumber_; j++){
				if(find(existlist,j)){
					cout<<adjMatrix[i][j]<<" ";
				}
			}
		}
		cout << endl;
	}
	
	door* temp = head_;
	while(temp != tail_){
		if(find(doorlist,temp->getId())){
			cout<<"The door Id: "<<temp->getId()<<"  The door output: "<<temp->getOutput()<<endl;
		}
		temp = temp->getNext();
	}
	if(find(doorlist,temp->getId())){
			cout<<"The door Id: "<<temp->getId()<<"  The door output: "<<temp->getOutput()<<endl;
		}
}
bool circuitControl::setInput(int id,vector<int> in){
	if(!find(connectlist,id)){
		//cout<<"the door isn't connected, set input failed"<<endl;
		return false;
	}
	door* temp = head_;
	while(temp->getId() != id)
		temp = temp->getNext();
	temp->setInput (in);
	return true;
}
bool circuitControl::execute(){
	if(abnormalCheck() == 0){
		cout<<"Abnormal! Please check your circuit and redo your job."<<endl;
		return false;
	}
	if(inputCheck() == 0){
		cout<<"You haven't set all the input,execution failed."<<endl;
		return false;
	}
	DFS();
	auto iter = topologyOrder.rbegin();
	door* temp = head_;
	door* putto = head_;
	int output = 1;
	for(iter; iter != topologyOrder.rend(); iter++){
		temp = head_;
		while(temp->getId() != *iter){
			temp = temp->getNext();
		}
		temp->getOutput();
		for(int i = 0; i < doorNumber_; i++){
			if(adjMatrix[*iter][i] == 1){
				putto = head_;
				while(putto->getId() != i)
					putto = putto->getNext();
				(*putto) += (*temp);
			}
		}
		output = 1;
		for(int i = 0; i < doorNumber_; i++){
			if(adjMatrix[*iter][i] == 1)
				output = 0;
		}
		if(output == 1){
			cout<<"the output of the door: id: "<<temp->getId()<<" type: "<<temp->getName()<<" is "<<temp->getOutput()<<endl;
		}
	}
	return true;
}
bool circuitControl::abnormalCheck(){
	for(int i = 0; i < doorNumber_; i++){
		for(int j = 0; j < doorNumber_; j++){
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
	for(int i = 0; i < doorNumber_; i++){
		if(find(connectlist,i)){
			vertex[i] = new Node(i);
		}
		else
			vertex[i] = NULL;
	}
	for(int i = 0; i < doorNumber_; i++){
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
	for(int i = 0; i < doorNumber_; i++){
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
	topologyOrder.push_back(n->id);
}

bool circuitControl::inputCheck(){
	int haveinput = 0;
	door* temp = head_;
	auto iter = connectlist.begin();
	for(iter; iter != connectlist.end(); iter++){
		haveinput = 0;
		for(int i = 0; i < doorNumber_; i++){
			if(adjMatrix[i][*iter] == 1){
				haveinput = 1;
				break;
			}
		}
		if(haveinput == 0){
			temp = head_;
			while(temp->getId() != *iter)
				temp = temp->getNext();
			if(temp->haveInput())
				haveinput = 1;			
		}
		if(haveinput == 0){
			return false;
		}
	}
	return true;
}

bool circuitControl::find(vector<int> list, int ele){
	auto iter = list.begin();
	while(iter != list.end()){
		if(*iter == ele)
			return true;
		iter++;
	}
	return false;
}
//for debugging
/*
void circuitControl::getDoorInformation(){
	cout<<"door head add: "<<head_<<"   door tail add: "<<tail_<<endl;
	door* temp = head_;
	while(temp != NULL){
		cout<<"ID: "<<temp->getId()<<" add: "<<temp<<"  nextadd: "<<temp->getNext()<<endl;
		temp = temp->getNext();
	}

}*/