#include "doorAndNot.hpp"
doorAndNot::doorAndNot(int id):door(id,"ANDNOT"){
	;
}
doorAndNot::~doorAndNot(){};
bool doorAndNot::setInput(vector<int> in){
	auto it = in.begin();
	while(it != in.end()){
		input_.push_back(*it);
		it++;
	}
	return true;
}
bool doorAndNot::getOutput(){
	if(input_.empty())
		return false;
	auto iter = input_.begin();
	int total = *iter;
	iter++;
	while(iter != input_.end()){
		total *= *iter;
		iter++;
	}
	//output_ = !total;
	if(total == 0)
		output_ = true;
	else 
		output_ = false;
	return output_;
}