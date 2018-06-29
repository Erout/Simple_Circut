#ifndef DOORNOT_HPP
#define DOORNOT_HPP
#include"door.hpp"
class doorNot:public door{
public:
	doorNot(int id, string name, type T);
	~doorNot();
	type getType();
	void setInput(bool* in);
	bool getOutput();
	bool* getInput();
	void setStatus(bool s);
	door& operator+=(door& d);
	door& operator=(door& d);
};
#endif