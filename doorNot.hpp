#ifndef DOORNOT_HPP
#define DOORNOT_HPP
#include"door.hpp"
class doorNot:public door{
public:
	doorNot(int id);
	~doorNot();
	//type getType();
	bool setInput(vector<bool> in);
	bool getOutput();
	/*void setStatus(bool s);
	int getId();
	string getName();
	door& operator+=(door& d);
	door& operator=(door& d);*/
};
#endif