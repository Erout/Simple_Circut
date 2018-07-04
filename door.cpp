#include"door.hpp"
void door::printInput(){
	auto iter = input_.begin();
	while(iter != input_.end()){
		cout<<*iter;
		iter++;
	}
}
int door::getId(){
	return id_;
}
string door::getName(){
	return name_;
}
door* door::getNext(){
	return next;
}
bool door::setNext(door* d){
	next = d;
	return true;
}
door& door::operator+=(door& d){
	input_.push_back(d.output_);
	return *this;
}
door& door::operator=(door& d){
	name_ = d.name_;
	id_ = d.id_;
	input_.clear();
	auto it = d.input_.begin();
	while(it != d.input_.end()){
		input_.push_back(*it);
		it++;
	}
	output_ = d.output_;
	return *this;
}
bool door::haveInput(){
	if(input_.empty())
		return false;
	return true;
}
void door::clearInput(){
	input_.clear();
}