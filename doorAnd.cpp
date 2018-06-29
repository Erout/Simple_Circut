#include"doorAnd.hpp"
doorAnd::doorAnd(int id,stirng name, type T):door(id,name,T){
	;
}
type doorAnd::getType(){
	return T_;
}
void doorAnd::setInput(vector<bool> in){
	auto it = in.begin();
	while(it != in.end()){
		input_.pushback(*it);
		it++;
	}
}
bool doorAnd::getOutupt(){
	auto it = input_.begin();
	bool total = *it;
	it++;
	while(it != input_.end()){
		total *= *it;
		it++;
	}
}//vector .end() contains element?
door& doorAnd::operator+=(door& d){
	input_.pushback(d.output_);
	return *this;
}
door& doorAnd::operator=(door& d){
	name_ = d.name_;
	T_ = d.T_;
	id_ = d.id_;
	input_.clear();
	auto it = d.input_.begin();
	while(it != d.input_.end()){
		input_.pushback(*it);
		it++;
	}
	output_ = d.output_;
}