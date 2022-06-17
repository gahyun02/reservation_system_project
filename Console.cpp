#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Console.h"

string* Seat_1 = new string[8];
string* Seat_2 = new string[8];
string* Seat_3 = new string[8];


Console::Console() {
	for (int i = 0; i < 8; i++) {
		Seat_1[i] = "___\t";
		Seat_2[i] = "___\t";
		Seat_3[i] = "___\t";
	}	
}

void Console::getArrival(string s) {
	airport_lo_1 = s;
}

int Console::info_write() {
	ofstream fout;
	if (!fout) {
		cout << "Airplane_reservation_info.txt 파일을 열 수 없습니다.";
		return 0;
	}
	fout.open("Airplane_reservation_info.txt", ios::out | ios::app);
	fout << "-------------------------------------------------------------" << endl;
	fout << "출발지 - > 도착지 : " << airport_lo << " - > " << airport_lo_1 << endl;
	fout << "날짜 : " << date_1 << endl;
	fout << "시간 : " << getTime(time_1) << endl;
	fout << "이름 : " << name_1 << endl;
	fout << "좌석 번호 : " << seat_num_1 << endl;
	fout << "-------------------------------------------------------------" << endl;
	fout.close();
}

bool Console::ticket_check() {  // way 정보 매개변수로 받음
	int check;
	cout << "예약 기록을 확인해드릴까요 ? (확인: 1, 확인 안함: 2) >> ";
	cin >> check;
	if (check == 1) {
		const char* file = "Airplane_reservation_info.txt";

		ifstream fin;
		fin.open(file, ios::in | ios::binary);
		if (!fin) {
			cout << "파일 열기 오류";
		}
		int count = 0;
		char s[32];
		cout << endl;
		cout << "티켓 확인을 도와드리겠습니다." << endl;
		while (!fin.eof()) {
			fin.read(s, 32);
			int n = fin.gcount();
			cout.write(s, n);
			count += n;
		}
		fin.close();
		
		return true;
	}
	else 
		return false;
}

string Console::date() {
	cout << "[ 6월1일" << ", 6월2일" << ", 6월3일" << ", 6월4일" << ", 6월5일" << ", 6월6일" << ", 6월7일 ]" << endl;
	cout << "출발할" << " 날짜를 선택하세요 >> ";
	cin >> date_1;
	return date_1;
}

string Console::airport() {
	cout << "[ 인천국제공항" << ", 광주공항" << ", 무안공항" << ", 제주공항" << ", 대구공항 ]" << endl;
	cout << "출발할" << " 공항을 선택하세요 >> ";
	cin >> airport_lo;
	return airport_lo;
}

int Console::way() {
	cout << "편도:1, 왕복:2 >> ";
	cin >> way_1;
	return way_1;
}

int Console::budget() {
	cout << "예산을 입력하세요 >> ";
	cin >> pay;
	cout << endl;
	return pay;
}

int Console::menu() {
	cout << "예약:1, 취소:2, 보기:3, 끝내기:4 >> ";
	cin >> menu_1;
	return menu_1;
}

int Console::time() {
	cout << "07시:1, 12시:2, 17시:3 >> ";
	cin >> time_1;
	return time_1;
}

string Console::getTime(int t) {
	if (t == 1)
		return "07시";
	if (t == 2)
		return "12시";
	else
		return "17시";
}
int Console::seat_num() {
	cout << "좌석 번호 (1~3번은 이코노미석, 4~8번은 비즈니스석) >> ";
	cin >> seat_num_1;
	return seat_num_1;
}

string Console::name() {
	cout << "예약자 이름 입력 >> ";
	cin >> name_1;
	return name_1;
}

void Console::save(int t, int s, string n) {

	if (t == 1) {
		Seat_1[s - 1] = n + "\t";
	}
	if (t == 2) {
		Seat_2[s - 1] = n + "\t";
	}
	if (t == 3) {
		Seat_3[s - 1] = n + "\t";
	}
}

void Console::cancel(int t, int s, string n) {

	if ((t == 1) && (n == Seat_1[s - 1])) {
		Seat_1[s - 1] = "___\t";
	}
	if ((t == 2) && (n == Seat_2[s - 1])) {
		Seat_2[s - 1] = "___\t";
	}
	if ((t == 3) && (n == Seat_3[s - 1])) {
		Seat_3[s - 1] = "___\t";
	}
	else {
		cout << "예약자 이름과 일치하지 않습니다." << endl;
	}

}

void Console::show() {
	cout << "07시:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_1[i];
	}
	cout << endl;
	cout << "12시:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_2[i];
	}
	cout << endl;
	cout << "17시:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_3[i];
	}
	cout << endl;
}

void Console::seat_show(int t, int n) {

	if (t == 1) {
		cout << "07시:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_1[i];
		}
	}
	if (t == 2) {
		cout << "12시:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_2[i];
		}
	}
	if (t == 3) {
		cout << "17시:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_3[i];
		}
	}
	cout << endl;
}

bool Console::possible_seat(int p) {

	if (p >= 80000) {
		cout << "예약 가능한 좌석을 보여드립니다." << endl;
		show();
		cout << endl;
		return false;
	}

	if ((p < 80000) && (p >= 30000)) {
		cout << "예약 가능한 좌석을 보여드립니다." << endl;
		seat_show(1, 3);
		seat_show(2, 3);
		seat_show(3, 3);
		cout << endl;
		return false;
	}
	else
		cout << "예약할 수 있는 좌석이 없습니다." << endl;
		return true;
}

void Console::seat_reset() {
	for (int i = 0; i < 8; i++) {
		Seat_1[i] = "___\t";
		Seat_2[i] = "___\t";
		Seat_3[i] = "___\t";
	}
}

void Console::finish() {
	cout << "비행기 예약을 종료합니다." << endl;
	cout << endl;
}
