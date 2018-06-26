#ifndef CIRCIUT_HPP
#define CIRCIUT_HPP
#include<iostream>
#include"door.hpp"
#define size 100
typedef struct Node{
	door* D;
	Node* next;
}
class circuitControl{
private:
	circuitControl* instance;
	bool matrix[size][size];
	Node* head;
	Node* tail;
	int doorNumber;
public:
	void create(int type);
	void list();
	void connect();
	void print();
	void setInput();
	void execute();
}