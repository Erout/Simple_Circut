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
	auto iter = input_.begin();
	bool total = *iter;
	iter++;
	while(iter != input_.end()){
		total += *iter;
		iter++;
	}
	output_ = !total;
	return output_;
}
/*void doorNot::setStatus(bool s){
	status_ = s;
}*//*
door& operator+=(door& d){
	input_.pushback(d.output);
	return *this;
}
door& operator=(door& d){
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
int doorNot::getId(){
	return id_;
}
string doorNot::getName(){
	return name_;
}*/