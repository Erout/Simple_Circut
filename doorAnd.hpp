#ifndef DOORAND_HPP
#define DOORAND_HPP
#include"door.hpp"
class doorAnd:public door{
public:
	doorAnd(int id, string name, type T);
	~doorAnd(){};
	int getType();
	void setInput(vector<bool> in);
	bool getOutput();
	//bool* getInput();
	door& operator+=(door& d);
	door& operator=(door& d);
};
#endif