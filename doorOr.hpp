#ifndef DOOROR_HPP
#define DOOROR_HPP
#include"door.hpp"
class doorOr:public door{
public:
	doorOr(int id, string name, type T);
	~doorOr();
	int getType();
	void setInput(bool* in);
	bool getOutput();
	void setStatus(bool s);
	bool* getInput();
	door& operator+=(door& d);
	door& operator=(door& d);
};
#endif