#ifndef DOOROR_HPP
#define DOOROR_HPP
#include"door.hpp"
class doorOr:public door{
public:
	doorOr();
	~doorOr();
	int getType();
	void setInput(bool* in);
	bool getOutput();
	bool* getInput();
	door& operator+=(door& d);
	door& operator=(door& d);
};
#endif