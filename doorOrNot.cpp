#include "doorOrNot.hpp"
doorOrNot::doorOrNot(int id):door(id,"ORNOT"){
	;
}
doorOrNot::~doorOrNot(){};
bool doorOrNot::setInput(vector<int> in){
	auto it = in.begin();
	while(it != in.end()){
		input_.push_back(*it);
		it++;
	}
	return true;
}
bool doorOrNot::getOutput(){
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
		 output_ =false;
	return output_;
}
/*void doorOrNot::setStatus(bool s){
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
int doorOrNot::getId(){
	return id_;
}
string doorOrNot::getName(){
	return name_;
}*/