#ifndef DOOR_HPP
#define DOOR_HPP
#include<iostream>
class door{
private:
	string name;
	int type;
	int id;
protected:
	bool* input;
	bool output;
public:
	door();
	virtual ~door();
	virtual int getType()=0;
	virtual void setInput(bool* in)=0;//需要按连接顺序运行
	virtual bool getOutput()=0;
	virtual bool* getInput()=0;
	virtual door& operator+=(door& d)=0;//增加输入
	virtual door& operator=(door & d)=0;
	//virtual door operator+(door& d)=0;//
};
#endif