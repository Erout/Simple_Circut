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
	auto iter = input_.begin();
	bool total = *iter;
	iter++;
	while(iter != input_.end()){
		total *= *iter;
		iter++;
	}
	output_ = !total;
	return output_;
}
/*void doorAndNot::setStatus(bool s){
	status_ = s;
}*//*
door& doorAndNot::operator+=(door& d){
	input_.pushback(d.output);
	return *this;
}
door& doorAndNot::operator=(door& d){
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
int doorAndNot::doorAndNot::getId(){
	return id_;
}
string doorAndNot::getName(){
	return name_;
}*/