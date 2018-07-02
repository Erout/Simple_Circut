#ifndef CIRCIUT_HPP
#define CIRCIUT_HPP
#include<iostream>
#include<vector>
#include"door.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
#define size 100
#define infinite 1000000
enum Colour={white,grey,black};
enum Type={and,or,not,andnot,ornot};
typedef struct Node{
	Node* father;
	Colour color;
	int id;
	int discover;
	int finish;
	Node(int identity,Colour c = white, Node* n = NULL, int d = infinite, int f = infinite){
		id = identity;
		color = c;
		father = n;
		discover = d;
		finish = f;
	}						
}Node;
class circuitControl{
private:	
	static circuitControl* instance_;
	bool adjMatrix[size][size]; 
	door* head_;
	door* tail_;
	int doorNumber_;
	//vector<int> removelist;
	vector<int> existlist;
	vector<int> connectlist;
	vector<int> topologyOrder;//要从后往前
	Node* vertex[size];
	int time;
public:
	circuitControl();
	~circuitControl();
	bool create(int type);
	void list();
	bool connect(int ida, int idb);
	//void remove(int id);
	void print();
	bool setInput(vector<bool> in);
	void execute();
	void clear();
	bool abnormalCheck();//有自反的或者对称的存在，则报错
	bool inputCheck();//检查connect list 里面的电路是否有输入
	void DFS();
	void DFSVisit(Node* n);
	circuitControl* getInstance();
}