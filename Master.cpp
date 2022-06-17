#include <iostream>
#include <queue>
#include <string>
using namespace std;

#include "Master.h"

queue<int> q;

void Master::add(int i) {
	q.push(i);
}

void Master::popping() {    // table_show(2) 값이 100이 아닐때 대기 번호 앞당겨 부르기 (예약 가능 통보하기)
	q.pop();
}

int Master::finish_table_num() {
	int n;
	cout << "식사가 끝난 테이블 번호를 입력하세요. >> ";
	cin >> n;
	return n;
}

int Master::next() {      
	return q.front();
}

bool Master::finish_eat() {
	int ans;
	cout << "식사가 끝난 테이블이 있나요? (YES : 1, NO : 2) >> ";
	cin >> ans;

	if (ans == 1) 
		return true;
	else 
		return false;
}