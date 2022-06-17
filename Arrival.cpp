#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Arrival.h"

string* Seat_4 = new string[8];
string* Seat_5 = new string[8];
string* Seat_6 = new string[8];

Arrival::Arrival() {
	for (int i = 0; i < 8; i++) {
		Seat_4[i] = "___\t";
		Seat_5[i] = "___\t";
		Seat_6[i] = "___\t";
	}
}

bool Arrival::possible_seat(int p) {

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

void Arrival::getArrival(string s) {
	airport_lo = s;
}

int Arrival::info_write() {
	ofstream fout;
	if (!fout) {
		cout << "Airplane_reservation_info.txt 파일을 열 수 없습니다.";
		return 0;
	}
	fout.open("Airplane_reservation_info.txt", ios::out | ios::app);
	fout << "출발지 - > 도착지 : " << airport_lo_1 << " - > " << airport_lo << endl;
	fout << "날짜 : " << date_1 << endl;
	fout << "시간 : " << getTime(time_1) << endl;
	fout << "이름 : " << name_1 << endl;
	fout << "좌석 번호 : " << seat_num_1 << endl;
	fout << "-------------------------------------------------------------" << endl;
	fout.close();
}

string Arrival::date() {
	cout << "[ 6월1일" << ", 6월2일" << ", 6월3일" << ", 6월4일" << ", 6월5일" << ", 6월6일" << ", 6월7일 ]" << endl;
	cout << "도착할" << " 날짜를 선택하세요 >> ";
	cin >> date_1;
	return date_1;
}
string Arrival::airport() {
	cout << endl;
	cout << "[ 인천국제공항" << ", 광주공항"<< ", 무안공항"<< ", 제주공항"<< ", 대구공항 ]" << endl;
	cout << "도착할" << " 공항을 선택하세요 >> ";
	cin >> airport_lo_1;
	return airport_lo_1;
}

void Arrival::save(int t, int s, string n) {

	if (t == 1) {
		Seat_4[s - 1] = n + "\t";
	}
	if (t == 2) {
		Seat_5[s - 1] = n + "\t";
	}
	if (t == 3) {
		Seat_6[s - 1] = n + "\t";
	}
}

void Arrival::cancel(int t, int s, string n) {

	if ((t == 1) && (n == Seat_4[s - 1])) {
		Seat_4[s - 1] = "___\t";
	}
	if ((t == 2) && (n == Seat_5[s - 1])) {
		Seat_5[s - 1] = "___\t";
	}
	if ((t == 3) && (n == Seat_6[s - 1])) {
		Seat_6[s - 1] = "___\t";
	}
	else {
		cout << "예약자 이름과 일치하지 않습니다." << endl;
	}

}

void Arrival::show() {
	cout << "07시:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_4[i];
	}
	cout << endl;
	cout << "12시:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_5[i];
	}
	cout << endl;
	cout << "17시:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_6[i];
	}
	cout << endl;
}

void Arrival::seat_show(int t, int n) {

	if (t == 1) {
		cout << "07시:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_4[i];
		}
	}
	if (t == 2) {
		cout << "12시:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_5[i];
		}
	}
	if (t == 3) {
		cout << "17시:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_6[i];
		}
	}
	cout << endl;
}

void Arrival::seat_reset() {
	for (int i = 0; i < 8; i++) {
		Seat_4[i] = "___\t";
		Seat_5[i] = "___\t";
		Seat_6[i] = "___\t";
	}
}