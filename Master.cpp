#include <iostream>
#include <queue>
#include <string>
using namespace std;

#include "Master.h"

queue<int> q;

void Master::add(int i) {
	q.push(i);
}

void Master::popping() {    // table_show(2) ���� 100�� �ƴҶ� ��� ��ȣ �մ�� �θ��� (���� ���� �뺸�ϱ�)
	q.pop();
}

int Master::finish_table_num() {
	int n;
	cout << "�Ļ簡 ���� ���̺� ��ȣ�� �Է��ϼ���. >> ";
	cin >> n;
	return n;
}

int Master::next() {      
	return q.front();
}

bool Master::finish_eat() {
	int ans;
	cout << "�Ļ簡 ���� ���̺��� �ֳ���? (YES : 1, NO : 2) >> ";
	cin >> ans;

	if (ans == 1) 
		return true;
	else 
		return false;
}