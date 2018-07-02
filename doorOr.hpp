#ifndef DOOROR_HPP
#define DOOROR_HPP
#include"door.hpp"
class doorOr:public door{
public:
	doorOr(int id);
	~doorOr();
	int getType();
	bool setInput(vector<bool> in);
	bool getOutput();
	void setStatus(bool s);
	int getId();
	string getName();
	door& operator+=(door& d);
	door& operator=(door& d);
};
#endif