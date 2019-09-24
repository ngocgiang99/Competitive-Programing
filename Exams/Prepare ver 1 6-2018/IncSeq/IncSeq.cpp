#include <iostream>
#define maxn 1000002
using namespace std;
struct Node{
	int x;
	Node* next;
};

int N, a[maxn], trace[maxn], Q[maxn], counter;
Node* stacks[maxn];

void read(){
	cin>> N;
	for (int i=0; i<N; i++){
		cin>> a[i];
	}
	for (int i=0; i<=N; i++)
		stacks[i] = NULL;
}

void push(int x, Node*& head){
	Node* node = new Node();
	node->next = head;
	node->x = x;
	head = node;
}

int pop(Node*& head){
	Node* node = head;
	int x = node->x;
	head = head->next;
	delete node;
	return x;
}

int findPos(int x){
	int cd = 1, ct = counter, i, remember = 0;
	while(cd <= ct){
		i = (cd + ct) / 2;
		if (x < a[Q[i]]){
			cd = i + 1;
			remember = i;
		} else {
			ct = i - 1;
		}
	}
	return remember;
}


void process(){
	Q[0] = -1;
	counter = 0;
	for (int i=N-1; i>=0; i--){
		int d = findPos(a[i]);
		if (d >= counter){
			counter++;
		} 
		Q[d + 1] = i;
		push(i, stacks[d + 1]);
	}
}


int findAns(){
	int i = counter, c = 0, im = -1, xm = -2000000002, re;
	while (i > 0){
		int re = 0;
		int xmax = -2000000001;
		while (stacks[i] != NULL){
			int id = pop(stacks[i]);
			if (id > im && a[id] > xmax && a[id] > xm){
				xmax = a[id];
				re = id;
			}
		}
		Q[c++] = xmax;
		xm = xmax;
		im = re;
		i--;
	}
}

void print(){
	cout<<counter<<endl;
	for (int i=0; i<counter; i++)
		cout<<Q[i]<<endl;
}

int main(){
	read();
	//cout<<"pause"<<endl;
	process();
	//cout<<"pause"<<endl;
	findAns();
	//cout<<"pause"<<endl;
	print();
	//cout<<"pause"<<endl;
	return 0;
}
