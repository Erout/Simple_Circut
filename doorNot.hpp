#ifndef DOORNOT_HPP
#define DOORNOT_HPP
#include"door.hpp"
class doorNot:public door{
public:
	doorNot();
	~doorNot();
	int getType();
	void setInput(bool* in);
	bool getOutput();
	bool* getInput();
	door& operator+=(door& d);
	door& operator=(door& d);
};
#endif