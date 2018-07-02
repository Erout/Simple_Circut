#ifndef DOOR_HPP
#define DOOR_HPP
#include<iostream>
#include<vector>
using std::string;
using std::cout;
using std::endl;
class door{
protected:
	string name_;
	int id_;
	vector<bool> input_;
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
	virtual int getId()=0;
	virtual bool setInput(vector<bool> in)=0;//需要按连接顺序运行
	virtual bool getOutput()=0;
	//virtual bool* getInput()=0;
	//virtual void setStatus(bool s);
	virtual int getId()=0;
	virtual string getName()=0;
	virtual door& operator+=(door& d)=0;//增加输入
	virtual door& operator=(door & d)=0;
};
#endif