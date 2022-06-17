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
		cout << "���� ������ �¼��� �����帳�ϴ�." << endl;
		show();
		cout << endl;
		return false;
	}

	if ((p < 80000) && (p >= 30000)) {
		cout << "���� ������ �¼��� �����帳�ϴ�." << endl;
		seat_show(1, 3);
		seat_show(2, 3);
		seat_show(3, 3);
		cout << endl;
		return false;
	}
	else
		cout << "������ �� �ִ� �¼��� �����ϴ�." << endl;
	return true;
}

void Arrival::getArrival(string s) {
	airport_lo = s;
}

int Arrival::info_write() {
	ofstream fout;
	if (!fout) {
		cout << "Airplane_reservation_info.txt ������ �� �� �����ϴ�.";
		return 0;
	}
	fout.open("Airplane_reservation_info.txt", ios::out | ios::app);
	fout << "����� - > ������ : " << airport_lo_1 << " - > " << airport_lo << endl;
	fout << "��¥ : " << date_1 << endl;
	fout << "�ð� : " << getTime(time_1) << endl;
	fout << "�̸� : " << name_1 << endl;
	fout << "�¼� ��ȣ : " << seat_num_1 << endl;
	fout << "-------------------------------------------------------------" << endl;
	fout.close();
}

string Arrival::date() {
	cout << "[ 6��1��" << ", 6��2��" << ", 6��3��" << ", 6��4��" << ", 6��5��" << ", 6��6��" << ", 6��7�� ]" << endl;
	cout << "������" << " ��¥�� �����ϼ��� >> ";
	cin >> date_1;
	return date_1;
}
string Arrival::airport() {
	cout << endl;
	cout << "[ ��õ��������" << ", ���ְ���"<< ", ���Ȱ���"<< ", ���ְ���"<< ", �뱸���� ]" << endl;
	cout << "������" << " ������ �����ϼ��� >> ";
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
		cout << "������ �̸��� ��ġ���� �ʽ��ϴ�." << endl;
	}

}

void Arrival::show() {
	cout << "07��:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_4[i];
	}
	cout << endl;
	cout << "12��:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_5[i];
	}
	cout << endl;
	cout << "17��:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_6[i];
	}
	cout << endl;
}

void Arrival::seat_show(int t, int n) {

	if (t == 1) {
		cout << "07��:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_4[i];
		}
	}
	if (t == 2) {
		cout << "12��:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_5[i];
		}
	}
	if (t == 3) {
		cout << "17��:   ";
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