#include "doorNot.hpp"
doorNot::doorNot(int id,string name,type T):door(id,name,T){
	;
}
doorNot::~doorNot(){};
type doorNot::getType(){
	return T_;
}