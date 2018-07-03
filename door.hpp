#ifndef DOOR_HPP
#define DOOR_HPP
#include<iostream>
#include<vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
class door{
protected:
	string name_;
	int id_;
	vector<int> input_;
	bool output_;
	//bool status_;//connected or not
	door* next;
public:
	door(int id,string name){
		id_ = id;
		name_ = name;
		output_ = false;
	}
	virtual ~door(){};
	//virtual int getType()=0;
	//int getId();
	virtual bool setInput(vector<int> in)=0;//需要按连接顺序运行
	virtual bool getOutput()=0;
	//virtual bool* getInput()=0;
	//virtual void setStatus(bool s);
	bool haveInput();
	void printInput();
	int getId();
	string getName();
	door* getNext();
	bool setNext(door* d);
	door& operator+=(door& d);//增加输入
	door& operator=(door & d);
};
#endif