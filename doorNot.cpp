#include "doorNot.hpp"
doorNot::doorNot(int id):door(id,"NOT"){
	;
}
doorNot::~doorNot(){};
bool doorNot::setInput(vector<int> in){
	if(in.size() > 1)
		return false;
	auto it = in.begin();
	input_.push_back(*it);
	return true;
}
bool doorNot::getOutput(){
	if(input_.empty())
		return false;
	auto iter = input_.begin();
	int total = *iter;
	iter++;
	while(iter != input_.end()){
		total += *iter;
		iter++;
	}
	//output_ = !total;
	if(total == 0)
		output_ = true;
	else
		output_ = false;
	return output_;
}