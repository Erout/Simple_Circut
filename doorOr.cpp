#include"doorOr.hpp"
doorOr::doorOr(int id):door(id,"OR"){
	;
}
doorOr::~doorOr(){};
bool doorOr::setInput(vector<int> in){
	auto it = in.begin();
	while(it != in.end()){
		input_.push_back(*it);
		it++;
	}
	return true;
}
bool doorOr::getOutput(){
	if(input_.empty())
		return false;
	auto it = input_.begin();
	int total = *it;
	it++;
	while(it != input_.end()){
		total += *it;
		it++;
	}
	if(total == 0)
		output_ = false;
	else
		output_ = true;
	return output_;
}