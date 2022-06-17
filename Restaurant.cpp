#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "Restaurant.h"

vector<int> v(6,0);
vector<int> ve(6, 0);

int* T_1 = new int[2];  // 6인 테이블 2개
int* T_2 = new int[2];  // 4인 테이블 2개
int* T_3 = new int[2];  // 2인 테이블 2개

Restaurant::Restaurant() {
	for (int i = 0; i < 2; i++) {
		T_1[i] = 6;
		T_2[i] = 4;
		T_3[i] = 2;
	}
	v.clear();
	ve.clear();
}

string Restaurant::date() {
	string date_1;
	cout << "[ 6월1일" << ", 6월2일" << ", 6월3일" << ", 6월4일" << ", 6월5일" << ", 6월6일" << ", 6월7일 ]" << endl;
	cout << "예약할" << " 날짜를 선택하세요 >> ";
	cin >> date_1;
	Date = date_1;
	return date_1;
}

bool Restaurant::age() {
	cout << "---------------------------------------------------------------------" << endl;
	cout << "7세 이하 미취학 아동이 포함되어 있나요? (포함: 1, 미포함: 2) >> ";
	cin >> age_1;
	if (age_1 == 1)
		return true;
	else
		return false;
}

int Restaurant::cus_kind() {
	cout << "예약 종류를 선택해주세요 (사전 예약 : 1, 당일 예약 : 2) >> ";
	cin >> kind;
	return kind;
}

void Restaurant::inform(int i) {    // 대기 번호 부르는 함수
	cout << "대기 번호 " << i << "번으로 불러드리겠습니다." << endl;
}

void Restaurant::de() {
	v.clear();
	ve.clear();
}

int Restaurant::info_write(int n, int k) {
	ofstream fout;
	if (!fout) {
		cout << "Restaurant_reservation_info.txt 파일을 열 수 없습니다.";
		return 0;
	}
	fout.open("Restaurant_reservation_info.txt", ios::out | ios::app);
	fout << "-------------------------------------------------------------" << endl;
	fout << "날짜 : " << Date << endl;
	fout << "좌석 번호 : " << n << "번" << endl;
	if (k == 1)
		fout << "사전 예약" << endl;
	else
		fout << "당일 예약" << endl;
	fout << "-------------------------------------------------------------" << endl;
	fout.close();
}

void Restaurant::check() {
	const char* file = "Restaurant_reservation_info.txt";
	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if (!fin) {
		cout << "파일 열기 오류";
	}
	int count = 0;
	char s[32];
	cout << endl;
	while (!fin.eof()) {
		fin.read(s, 32);
		int n = fin.gcount();
		cout.write(s, n);
		count += n;
	}
	fin.close();
}

string Restaurant::get() {
	return Date;
}

void Restaurant::out(int i) {       //table_num 매개 변수로 받음
	vector<int>::iterator it;
	it = v.begin();
	int n = *it;

	for (int j = 0; j < v.size(); j++) {
		if (n == i) {
			it = v.erase(it);
			break;
		}
		it++;
	}
	
}

void Restaurant::reserve(int i) {   // 예약 함수 (table_num 매개 변수로 받음)
	v.push_back(i);
}

int Restaurant::getcap(int i) {
	if ((i == 1) || (i == 2))
		return 6;
	if ((i == 3) || (i == 4))
		return 4;
	if ((i == 5) || (i == 6))
		return 2;
}

int Restaurant::cus_num() {
	cout << "예약할 사람의 수를 입력하세요 >> ";
	cin >> number_1;
	return number_1;
}

int Restaurant::table_show(int k) {          // 예약 가능 테이블 출력 
	vector <vector <string>> show(2, vector<string>(3, " "));

	int w = 0;
	for (int i : ve) {
		for (int j : v) {
			if (i == j) {
				ve[w] = 0;
			}	
		}
		w += 1;
	}

	bool n = true;
	for (int i : ve) {
		if (i != 0) {
			n = false;
			break;
		}
	}

	if (n) {
		cout << "지금은 예약할 수 없습니다. " << endl;
		return 100;
	}

	else {
		cout << "예약 가능한 테이블 번호를 알려드립니다." << endl;
		cout << endl;
		for (int i : ve) {
			if (i != 0) {
				if (i % 2 == 0) {
					show[1][i / 2 - 1] = to_string(i);
				}
				else {
					show[0][(i - 1) / 2] = to_string(i);
				}
			}
		}

		for (int i = 0; i < show.size(); i++) {
			for (int j = 0; j < show[i].size(); j++)
				cout << "  " << show[i][j] << "  |";
			cout << endl;
			cout << " -----------------" << endl;
		}

		show[0].assign(3, " ");
		show[1].assign(3, " ");

		cout << endl;
		cout << "예약할 테이블 번호를 입력하세요 >> ";
		cin >> table_num;
		return table_num;
	}
}

void Restaurant::table() {
	cout << endl;
	cout << "1번 (6인) \t" << "3번 (4인) \t" << "5번 (2인) \t" << endl;
	cout << "2번 (6인) \t" << "4번 (4인) \t" << "6번 (2인) \t" << endl;
	cout << endl;
}

bool Restaurant::table_match(int i) {    //인원 수에 따른 가능 테이블 출력
	int j = 1;
	ve.clear();
	if ((i <= 6) && (i > 4)) {
		ve.push_back(j);
		ve.push_back(j + 1);
		return true;
	}
	if ((i <= 4) && (i > 2)) {
		for (int i = 0; i < 2; i++) {
			ve.push_back(j);
			ve.push_back(j + 2);
			j++;
		}
		return true;
	}
	if ((i <= 2) && (i > 0)) {
		for (int i = 0; i < 2; i++) {
			ve.push_back(j);
			ve.push_back(j + 2);
			ve.push_back(j + 4);
			j++;
		}
		return true;
	}
	if (i > 6 || i <= 0) {
		cout << "죄송합니다. 수용할 수 있는 테이블이 없습니다." << endl;
		return false;
	}
}

bool Restaurant::finish_reserve() {
	int i;
	cout << "식당 예약을 종료하시겠습니까? (YES : 1, NO : 2) >> ";
	cin >> i;
	cout << endl;
	if (i == 2)
		return true;

	else {
		return false;
	}
}
