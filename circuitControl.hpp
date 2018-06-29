#ifndef CIRCIUT_HPP
#define CIRCIUT_HPP
#include<iostream>
//#include<vector>
#include"door.hpp"
using std::cout;
using std::cin;
using std::vector;
#define size 100
typedef struct Node{
	door* D;
	Node* next;
}
class circuitControl{
private:
	circuitControl* instance_;
	bool adjMatrix[size][size];
	Node* head_;
	Node* tail_;
	int doorNumber_;//record the number of doors that have been created
	//vector<int> exist_;//record the id of doors that still exist
	//vecotr<int> removed_;//record the id of doors that have been removed
public:
	void create(int type);
	void list();
	void connect();
	//void remove(int id);
	void print();
	void setInput();
	void execute();
}