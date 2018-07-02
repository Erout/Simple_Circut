#ifndef DOORANDNOT_HPP
#define DOORANDNOT_HPP
#include"door.hpp"
class doorAndNot:public door{
public:
	doorAndNot(int id);
	~doorAndNot();
	type getType();
	bool setInput(vector<bool> in);
	bool getOutput();
	void setStatus(bool s);
	int getId();
	string getName();
	door& operator+=(door& d);
	door& operator=(door& d);
};
#endif