#include<iostream>
#include"circuitControl.hpp"
void initialize();
void instruction();
int main(){
	initialize();
	circuitControl* circuit = circuitControl::getInstance();
	int act;
	int doortype;
	int first,second;
	int inputdoor,element;
	int outputdoor;
	bool execution = 1;
	vector<int> sequence;
	vector<int> seeDoorOutput;
	instruction();
	cin >> act;
	while(act != 9){
		//instruction();
		//cin>> act;
		switch(act){
			case 1:
			if(!execution){
				cout<<"you cannot create doors now"<<endl;
				break;
			}
			cout<<"please enter the door type you want to create:"<<endl;
			cout<<"0:and  1:or  2:not  3:andnot  4:ornot"<<endl;
			cin>>doortype;
			circuit->create(doortype);
			cout<<"Create door sucessfully!"<<endl;
			break;
			case 2:
			if(!execution){
				cout<<"you cannot connect the doors now"<<endl;
				break;
			}
			cout<<"please enter two ids of door(the first will be connected to the second" <<endl;
			cin>>first>>second;
			if(circuit->connect(first,second))
				cout<<"connection finish"<<endl;
			else
				cout<<"invalid id choice! Connection failed"<<endl;
			break;
			case 3:
			circuit->list();
			break;
			case 4:
			if(!execution){
				cout<<"you cannot set input now"<<endl;
				break;
			}
			cout<<"please enter id of door you want to set input"<<endl;
			cin>>inputdoor;
			cout<<"please enter the sequence of input (0 1 sequence,if you enter a number that is not 0 1, that means you finish setting input"<<endl;
			cin>>element;
			while((element==0)||(element==1)){
				sequence.push_back(element);
				cin>>element;
			}
			if(circuit->setInput(inputdoor,sequence)){
				cout<<"setinput seccesfully"<<endl;
			}
			else
				cout<<"the door isn't connected, set input failed"<<endl;
			break;
			case 5:
			/*if(execution){
				cout<<"Please execute the circuit first"<<endl;
				break;
			}*/
			cout<<"please enter the sequence of doors if you want to see its output, enter -1 to end.(The input of the doors which doesn't exist will be ignored automatically"<<endl;
			cin>>outputdoor;
			while(outputdoor != -1){
				seeDoorOutput.push_back(outputdoor);
				cin>>outputdoor;
			}
			circuit->print(seeDoorOutput);
			break;
			case 6:
			if(circuit->execute() == 1)
				execution =0;
			cout<<"execution finish"<<endl;
			break;
			case 7:
			circuit->clearInput();
			cout<<"Input have been cleared" <<endl;
			case 8:
			circuit->clearInput();
			circuit->clear();
			execution = 1;
			cout<<"Clear finish" <<endl;
			break;

		} 
		cout<<"Please enter action"<<endl;
		cin >> act;
		//for debugging
		//circuit->getDoorInformation();
	}
	cout<<"Thank you for using it, goodbye!"<<endl;
}

void instruction(){
	cout<<"**********************************************************************************************"<<endl;
	cout<<"Please enter the corresponding number to take actions:"<<endl;
	cout<<"1: create a new door"<<endl;
	cout<<"2: connect two doors"<<endl; 
	cout<<"3: list the doors you have created"<<endl;
	cout<<"4: set door input"<<endl;
	cout<<"5: print the circuit(by the form of adjacent matrix)"<<endl;
	cout<<"6: execute "<<endl;
	cout<<"7: clear the input of all the doors(the doors and their connection does not change)"<<endl;
	cout<<"8: clear the circuit and restart your job"<<endl;
	cout<<"9: exit"<<endl;
	cout<<"**********************************************************************************************"<<endl;

}
void initialize(){
	cout<<"**********************************************************************************************"<<endl;
	cout<<"Welcome!"<<endl;
	cout<<"Here are some things that you should notice when use this program"<<endl;
	cout<<"once you have execute the circuit, you can't create or connect the doors anymore"<<endl;
	cout<<"when you set door input, you need to point out the door id"<<endl;
	cout<<"you should execute the circuit before you operate on print"<<endl;
	cout<<"you should point out the id of door if you want its output when print"<<endl;
	cout<<"Once your circuit connection goes wrong, you need to redo it."<<endl;
	cout<<"**********************************************************************************************"<<endl;
}