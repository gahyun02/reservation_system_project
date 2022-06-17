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
		cout << "Airplane_reservation_info.txt ������ �� �� �����ϴ�.";
		return 0;
	}
	fout.open("Airplane_reservation_info.txt", ios::out | ios::app);
	fout << "-------------------------------------------------------------" << endl;
	fout << "����� - > ������ : " << airport_lo << " - > " << airport_lo_1 << endl;
	fout << "��¥ : " << date_1 << endl;
	fout << "�ð� : " << getTime(time_1) << endl;
	fout << "�̸� : " << name_1 << endl;
	fout << "�¼� ��ȣ : " << seat_num_1 << endl;
	fout << "-------------------------------------------------------------" << endl;
	fout.close();
}

bool Console::ticket_check() {  // way ���� �Ű������� ����
	int check;
	cout << "���� ����� Ȯ���ص帱��� ? (Ȯ��: 1, Ȯ�� ����: 2) >> ";
	cin >> check;
	if (check == 1) {
		const char* file = "Airplane_reservation_info.txt";

		ifstream fin;
		fin.open(file, ios::in | ios::binary);
		if (!fin) {
			cout << "���� ���� ����";
		}
		int count = 0;
		char s[32];
		cout << endl;
		cout << "Ƽ�� Ȯ���� ���͵帮�ڽ��ϴ�." << endl;
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
	cout << "[ 6��1��" << ", 6��2��" << ", 6��3��" << ", 6��4��" << ", 6��5��" << ", 6��6��" << ", 6��7�� ]" << endl;
	cout << "�����" << " ��¥�� �����ϼ��� >> ";
	cin >> date_1;
	return date_1;
}

string Console::airport() {
	cout << "[ ��õ��������" << ", ���ְ���" << ", ���Ȱ���" << ", ���ְ���" << ", �뱸���� ]" << endl;
	cout << "�����" << " ������ �����ϼ��� >> ";
	cin >> airport_lo;
	return airport_lo;
}

int Console::way() {
	cout << "��:1, �պ�:2 >> ";
	cin >> way_1;
	return way_1;
}

int Console::budget() {
	cout << "������ �Է��ϼ��� >> ";
	cin >> pay;
	cout << endl;
	return pay;
}

int Console::menu() {
	cout << "����:1, ���:2, ����:3, ������:4 >> ";
	cin >> menu_1;
	return menu_1;
}

int Console::time() {
	cout << "07��:1, 12��:2, 17��:3 >> ";
	cin >> time_1;
	return time_1;
}

string Console::getTime(int t) {
	if (t == 1)
		return "07��";
	if (t == 2)
		return "12��";
	else
		return "17��";
}
int Console::seat_num() {
	cout << "�¼� ��ȣ (1~3���� ���ڳ�̼�, 4~8���� ����Ͻ���) >> ";
	cin >> seat_num_1;
	return seat_num_1;
}

string Console::name() {
	cout << "������ �̸� �Է� >> ";
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
		cout << "������ �̸��� ��ġ���� �ʽ��ϴ�." << endl;
	}

}

void Console::show() {
	cout << "07��:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_1[i];
	}
	cout << endl;
	cout << "12��:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_2[i];
	}
	cout << endl;
	cout << "17��:   ";
	for (int i = 0; i < 8; i++) {
		cout << Seat_3[i];
	}
	cout << endl;
}

void Console::seat_show(int t, int n) {

	if (t == 1) {
		cout << "07��:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_1[i];
		}
	}
	if (t == 2) {
		cout << "12��:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_2[i];
		}
	}
	if (t == 3) {
		cout << "17��:   ";
		for (int i = 0; i < n; i++) {
			cout << Seat_3[i];
		}
	}
	cout << endl;
}

bool Console::possible_seat(int p) {

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

void Console::seat_reset() {
	for (int i = 0; i < 8; i++) {
		Seat_1[i] = "___\t";
		Seat_2[i] = "___\t";
		Seat_3[i] = "___\t";
	}
}

void Console::finish() {
	cout << "����� ������ �����մϴ�." << endl;
	cout << endl;
}
