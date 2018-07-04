#include"doorAnd.hpp"
doorAnd::doorAnd(int id):door(id,"AND"){
	;
}
doorAnd::~doorAnd(){};
bool doorAnd::setInput(vector<int> in){
	auto it = in.begin();
	while(it != in.end()){
		input_.push_back(*it);
		it++;
	}
	return true;
}
bool doorAnd::getOutput(){
	if(input_.empty())
		return false;
	auto it = input_.begin();
	int total = *it;
	it++;
	while(it != input_.end()){
		total *= *it;
		it++;
	}
	if(total == 0){
		output_ = false;
	}
	else{
		output_ = true;
	}
	return output_;
}