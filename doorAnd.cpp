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
	auto it = input_.begin();
	bool total = *it;
	it++;
	while(it != input_.end()){
		total *= *it;
		it++;
	}
	output_ = total;
	return output_;
}