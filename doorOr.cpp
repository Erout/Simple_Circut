#include"doorOr.hpp"
doorOr::doorOr(int id):door(id,"OR"){
	;
}
doorOr::~doorOr(){};
bool doorOr::setInput(vector<bool> in){
	auto it = in,begin();
	while(it != in.end()){
		input_.pushback(*it);
		it++;
	}
	return true;
}
bool doorOr::getOutput(){
	auto it = input_.begin();
	bool total = *it;
	it++;
	while(it != input_.end()){
		total += *it;
		it++;
	}
	output_ = total;
	return output_;
}
/*
door& doorOr::operator+=(door& d){
	input_.pushback(d.output_);
	return *this;
}
door& doorOr::operator=(door& d){
	name_ = d.name_;
	T_ =d.T_;
	id_ = d.id_;
	 input_.clear();
	 auto it = d.input_.begin();
	 while(it != d.input_.end()){
	 	input_.pushback(*it);
	 	it++;
	 }
	 output_ = d.output_;
}
/*void doorOr::setStatus(bool s){
	status_ = s;
}*/
int doorOr::getId(){
	return id_;
}
string doorOr::getName(){
	return name_;
}*/