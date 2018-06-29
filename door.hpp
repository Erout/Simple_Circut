#ifndef DOOR_HPP
#define DOOR_HPP
#include<iostream>
#include<vector>
enum type={and,or,not};//right?
class door{
protected:
	string name_;
	type T_;
	int id_;
	vector<bool> input_;
	//bool* input_;
	bool output_;
	bool status_;//connected or not
public:
	door(int id,string name,type T){
		id_ = id;
		name_ = name;
		T_ = T;
		output_ = false;
		status_ = false;
	}
	virtual ~door(){};
	virtual int getType()=0;
	virtual void setInput(bool* in)=0;//需要按连接顺序运行
	virtual bool getOutput()=0;
	virtual bool* getInput()=0;
	virtual void setStatus(bool s);
	virtual door& operator+=(door& d)=0;//增加输入
	virtual door& operator=(door & d)=0;
};
#endif