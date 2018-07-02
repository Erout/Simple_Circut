#ifndef DOORORNOT_HPP
#define DOORORNOT_HPP
#include"door.hpp"
class doorOrNot:public door{
public:
	doorOrNot(int id);
	~doorOrNot();
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