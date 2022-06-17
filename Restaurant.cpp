#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "Restaurant.h"

vector<int> v(6,0);
vector<int> ve(6, 0);

int* T_1 = new int[2];  // 6�� ���̺� 2��
int* T_2 = new int[2];  // 4�� ���̺� 2��
int* T_3 = new int[2];  // 2�� ���̺� 2��

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
	cout << "[ 6��1��" << ", 6��2��" << ", 6��3��" << ", 6��4��" << ", 6��5��" << ", 6��6��" << ", 6��7�� ]" << endl;
	cout << "������" << " ��¥�� �����ϼ��� >> ";
	cin >> date_1;
	Date = date_1;
	return date_1;
}

bool Restaurant::age() {
	cout << "---------------------------------------------------------------------" << endl;
	cout << "7�� ���� ������ �Ƶ��� ���ԵǾ� �ֳ���? (����: 1, ������: 2) >> ";
	cin >> age_1;
	if (age_1 == 1)
		return true;
	else
		return false;
}

int Restaurant::cus_kind() {
	cout << "���� ������ �������ּ��� (���� ���� : 1, ���� ���� : 2) >> ";
	cin >> kind;
	return kind;
}

void Restaurant::inform(int i) {    // ��� ��ȣ �θ��� �Լ�
	cout << "��� ��ȣ " << i << "������ �ҷ��帮�ڽ��ϴ�." << endl;
}

void Restaurant::de() {
	v.clear();
	ve.clear();
}

int Restaurant::info_write(int n, int k) {
	ofstream fout;
	if (!fout) {
		cout << "Restaurant_reservation_info.txt ������ �� �� �����ϴ�.";
		return 0;
	}
	fout.open("Restaurant_reservation_info.txt", ios::out | ios::app);
	fout << "-------------------------------------------------------------" << endl;
	fout << "��¥ : " << Date << endl;
	fout << "�¼� ��ȣ : " << n << "��" << endl;
	if (k == 1)
		fout << "���� ����" << endl;
	else
		fout << "���� ����" << endl;
	fout << "-------------------------------------------------------------" << endl;
	fout.close();
}

void Restaurant::check() {
	const char* file = "Restaurant_reservation_info.txt";
	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if (!fin) {
		cout << "���� ���� ����";
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

void Restaurant::out(int i) {       //table_num �Ű� ������ ����
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

void Restaurant::reserve(int i) {   // ���� �Լ� (table_num �Ű� ������ ����)
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
	cout << "������ ����� ���� �Է��ϼ��� >> ";
	cin >> number_1;
	return number_1;
}

int Restaurant::table_show(int k) {          // ���� ���� ���̺� ��� 
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
		cout << "������ ������ �� �����ϴ�. " << endl;
		return 100;
	}

	else {
		cout << "���� ������ ���̺� ��ȣ�� �˷��帳�ϴ�." << endl;
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
		cout << "������ ���̺� ��ȣ�� �Է��ϼ��� >> ";
		cin >> table_num;
		return table_num;
	}
}

void Restaurant::table() {
	cout << endl;
	cout << "1�� (6��) \t" << "3�� (4��) \t" << "5�� (2��) \t" << endl;
	cout << "2�� (6��) \t" << "4�� (4��) \t" << "6�� (2��) \t" << endl;
	cout << endl;
}

bool Restaurant::table_match(int i) {    //�ο� ���� ���� ���� ���̺� ���
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
		cout << "�˼��մϴ�. ������ �� �ִ� ���̺��� �����ϴ�." << endl;
		return false;
	}
}

bool Restaurant::finish_reserve() {
	int i;
	cout << "�Ĵ� ������ �����Ͻðڽ��ϱ�? (YES : 1, NO : 2) >> ";
	cin >> i;
	cout << endl;
	if (i == 2)
		return true;

	else {
		return false;
	}
}
