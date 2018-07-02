#include<iostream>
#include"circuitControl.hpp"
void initialize();
void instruction();
int main(){
	initialize();
	circuitControl* circuit = circuitControl::getInstance();
	int act;
	while(1){
		instruction();
		cin>> act;
		switch(act){
			case 1:
			break;
		} 
	}
}
void initialize(){
	cout<<"**********************************************************************************************"<<endl;
	cout<<"Welcome!"<<endl;
	cout<<"Here are some things that you should notice when use this program"<<endl;
	cout<<"once you have execute the circuit, you can't create, remove or connect the doors anymore"<<endl;
	cout<<"you should point out the id of door if you want its output"<<endl;
	cout<<"be careful when you connect the circuit. You can not disconnect two connected doors."
	cout<<"Once your circuit goes wrong, you need to redo it."<<endl;
	cout<<"**********************************************************************************************"<<endl;
}
void instruction(){
	cout<<"**********************************************************************************************"<<endl;
	cout<<"Please enter the corresponding number to take actions:"<<endl;
	cout<<"1: create a new door"<<endl;
	cout<<"2: remove a door"<<endl;
	cout<<"3: connect two doors"<<endl; 
	cout<<"4: set door input"<<endl;
	cout<<"5: list the doors you have created"<<endl;
	cout<<"6: print the circuit(by the form of adjacent matrix"<<endl;
	cout<<"7: execute "<<endl;
	cout<<"8: clear and redo"<<endl;
	cout<<"**********************************************************************************************"<<endl;

}