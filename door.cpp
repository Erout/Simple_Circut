#include"door.hpp"
bool door::haveinput(){
	if(input_.empty())
		return false;
	return true;
}
void door::printInput(){
	auto iter = input_.begin();
	while(iter != input_.end()){
		cout<<"*iter ";
		iter++;
	}
}
int door::getId(){
	return id_;
}
string door::getName(){
	return name_;
}
door& door::operator+=(door& d){
	input_.pushback(d.output);
	return *this;
}
door& door::operator=(door& d){
	name_ = d.name_;
	id_ = d.id_;
	input_.clear();
	auto it = d.input_.begin();
	while(it != d.input_.end()){
		input_.pushback(*it);
		it++;
	}
	output_ = d.output_;
}