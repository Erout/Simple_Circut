#include"doorAnd.hpp"
doorAnd::doorAnd(int id):door(id,"AND"){
	;
}
type doorAnd::getType(){
	return T_;
}
bool doorAnd::setInput(vector<bool> in){
	auto it = in.begin();
	while(it != in.end()){
		input_.pushback(*it);
		it++;
	}
	return true;
}
bool doorAnd::getOutupt(){
	auto it = input_.begin();
	bool total = *it;
	it++;
	while(it != input_.end()){
		total *= *it;
		it++;
	}
	output_ = total;
	return output_;
}//vector .end() contains element?->no
door& doorAnd::operator+=(door& d){
	input_.pushback(d.output_);
	return *this;
}
//= door and to door and
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
/*void doorAnd::setStatus(bool s){
	status_ = s;
}*/
int doorAnd::getId(){
	return id_;
}
string doorAnd::getName(){
	return name_;
}