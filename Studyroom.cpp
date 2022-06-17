#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <map>
#include <fstream>

using namespace std;

#include "Studyroom.h"

vector <int> start;
vector <int> finish;
vector <vector <string>> v(15, vector<string>(15, "__"));
map <int, int> remember;

int Studyroom::get_sex() {
	if (sex_1 == "W")
		return 1;
	else
		return 0;
}

void Studyroom::de() {
	start.clear();
	finish.clear();
	vector <vector <string>> v(15, vector<string>(15, "__"));
}

int Studyroom::start_time(int ID, int s) {

	if (s >= 240) {
		cout << "죄송합니다. 최대 이용시간은 4시간입니다." << endl;
		return 0;
	}

	string st;
	cout << "시간을 입력하세요 (ex: 17:20) >> ";
	cin >> st;

	istringstream ss(st);
	string buf;
	
	while (getline(ss, buf, ':')) {
		start.push_back(stoi(buf));
	}

	if (start[0] < 9 || start[0] >= 23) {
		cout << "죄송합니다. " << "예약 가능 시간은" << " 오전 9시부터 오후 11시입니다." << endl;
		start.clear();
		return 0;
	}

	else {
		remember[this->ID] = (start[0] - 9) * 60 + start[1];
		start.clear();
		return 1;
	}
}

string Studyroom::get() {
	return date_r;
}

int Studyroom::info_write(int id, int seat_num, int time) {
	ofstream fout;
	if (!fout) {
		cout << "Studyroom_reservation_info.txt 파일을 열 수 없습니다.";
		return 0;
	}
	fout.open("Studyroom_reservation_info.txt", ios::out | ios::app);
	fout << "-------------------------------------------------------------" << endl;
	fout << "세대 ID : " << id << endl;
	fout << "날짜 : " << date_r << endl;
	fout << "좌석 번호 : " << seat_num << endl;
	fout << "총 이용 시간 : " << time / 60 << "시간 " << time % 60 << "분" << endl;
	fout << "-------------------------------------------------------------" << endl;
	fout.close();
}

void Studyroom::checking() {
	const char* file = "Studyroom_reservation_info.txt";
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
	cout << endl;
	fin.close();
}

void Studyroom::finish_time() {
	string st;
	cout << "시간을 입력하세요 (ex: 17:20) >> ";
	cin >> st;

	istringstream ss(st);
	string buf;

	while (getline(ss, buf, ':')) {
		finish.push_back(stoi(buf));
	}

	if (finish[0] >= 23) {
		cout << "이용 시간이 지나 자동으로 예약이 만료되었습니다." << endl;
	}
}
int Studyroom::age() {
	int age_1;
	cout << "나이를 입력하세요. >> ";
	cin >> age_1;
	return age_1;
}

int Studyroom::menu() {
	int i;
	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "예약 시작: 1, 예약 종료: 2 >> ";
	cin >> i;
	return i;
}

int Studyroom::seat_number() {
	int seat_num;
	cout << "좌석 번호를 입력하세요 >> ";
	cin >> seat_num;
	seat_num_1 = seat_num;
	return seat_num;
}

int Studyroom::add(int ID) {
	int study_time = 0;
	study_time += ((finish[0] - 9) * 60 + finish[1] - remember[this->ID]);
	finish.clear();
	remember.erase(ID);
	return study_time;   //study_time 은 분 단위
 }

int Studyroom::id() {
	int id_1;
	cout << "세대 ID를 입력하세요. (1~300) >> ";
	cin >> id_1;
	ID = id_1;
	return id_1;
}

string Studyroom::sex() {
	string sex;
	cout << "성별을 입력하세요. (남자: M, 여자: W) >> ";
	cin >> sex;
	sex_1 = sex;
	return sex_1;
}

void Studyroom::reserve(string c, int seat_num) {
	int row;  // 열
	int column;  // 행
	row = (seat_num - 1) / 15;
	column = seat_num - (15 * row) - 1;
	v[row][column] = c;

	cout << "환영합니다. 예약이 완료되었습니다." << endl;
}

string Studyroom::check(int x, int y, string c) {

	if (x < 0 || y < 0 || x > 14 || y > 14)
		return c;
	else
		return v[x][y];
}

void Studyroom::table_show(string c) {
	int n = 1;
	string d_sex;

	if (c == "W")
		d_sex = "M";
	
	else 
		d_sex = "W";
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == "__") {
				if ((check(i - 1, j, c) != d_sex) && (check(i, j - 1, c) != d_sex) && (check(i, j + 1, c) != d_sex) && (check(i + 1, j, c) != d_sex))
					cout << v[i][j] << " ";
				else
					cout << " X ";
			}
			else
				cout << " X ";
		}
		cout << "( " << n << " ~ " << n + 14 << " )" << endl;
		n += 15;
	}
	
	cout << endl;
}

void Studyroom::cancel(int seat_num) {
	int row; 
	int column;  
	row = (seat_num - 1) / 15;
	column = seat_num - (15 * row) - 1;
	v[row][column] = "__";
}

bool Studyroom::finish_study() {
	int i;
	cout << "독서실 예약을 종료하시겠습니까? (YES : 1, NO : 2) >> ";
	cin >> i;
	if (i == 2)
		return true;

	else {
		return false;
	}
}

string Studyroom::date() {
	string date_1;
	cout << "[ 6월1일" << ", 6월2일" << ", 6월3일" << ", 6월4일" << ", 6월5일" << ", 6월6일" << ", 6월7일 ]" << endl;
	cout << "날짜를 선택하세요 >> ";
	cin >> date_1;
	date_r = date_1;
	return date_1;
}