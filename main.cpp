#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

#include "Console.h"
#include "Arrival.h"
#include "Restaurant.h"
#include "Master.h"
#include "Studyroom.h"

int reservation() {
	int reservation_1;
	cout << "����� ����:1, �Ĵ� ����:2, ������ �¼� ����:3, ���� �ý��� ����:4 >> ";
	cin >> reservation_1;
	return reservation_1;
}

int main() {
	map<string, int> airplane_login;
	map<string, int> restaurant_login;
	map<string, int> studyroom_login;
	map<int, int> study;

	Console* c = new Console;
	Arrival a;
	Restaurant r;
	Master m;
	Studyroom s;

	int airplane = 0;
	int restaurant = 0;
	int studyroom = 0;
	int w_studyroom = 0;

	int index = 0;
	int number_3 = 0;
	int mileage;
	int number_4 = reservation();
	string airport_lo, airport_lo_1 = "";

	while (number_4 != 4) {
		while (number_4 == 1) {
			string id;
			int password;

			cout << "���̵� (������� �̸��� ����) �Է�>> ";
			cin >> id;
			cout << "��й�ȣ (���� 4�ڸ�) �Է�>> ";
			cin >> password;

			if ((airplane_login.find(id) == airplane_login.end()) && (airplane_login[id] != password)) {
				cout << "ȯ���մϴ�. ���� ��ϵǾ����ϴ�." << endl;
				airplane_login.insert(make_pair(id, password));
			}

			else {
				if (airplane_login.find(id) != airplane_login.end())
					cout << "ȯ���մϴ�." << id << " ȸ����!" << endl;

				else
					cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
			}
			cout << endl;
			if (c->ticket_check())
				cout << endl;
			else {
				number_3 = c->way();
				airport_lo = c->airport(); //�����
				airport_lo_1 = a.airport(); //������
				c->getArrival(airport_lo_1);
				a.getArrival(airport_lo);

				cout << endl;
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "********  " << airport_lo << "�� ���� �� ȯ���մϴ�  ********" << endl;
				cout << endl;
				c->date();
				cout << endl;

				int number = c->menu();
				int number_1;
				int number_2;
				string name_2;


				while (number != 4) {
					if (number == 1) {
						c->mileage += 100;
						if (c->possible_seat(c->budget())) {
							c->possible_seat(c->budget());
						}
						number_1 = c->time();
						number_2 = c->seat_num();
						name_2 = c->name();
						c->save(number_1, number_2, name_2);
						airplane += 1;
					}
					if (number == 2) {
						number_1 = c->time();
						number_2 = c->seat_num();
						name_2 = c->name();
						c->cancel(number_1, number_2, name_2);
						airplane -= 1;
					}
					if (number == 3) {
						c->show();
					}
					cout << "\n" << endl;
					number = c->menu();
				}

				c->info_write();

				if ((number_3 == 2) && (number == 4)) {
					a.mileage += 100;
					cout << "" << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "********  " << airport_lo_1 << "�� ���� �� ȯ���մϴ�  ********" << endl;
					cout << "" << endl;
					a.date();
					number = a.menu();
					while (number != 4) {
						if (number == 1) {
							if (a.possible_seat(a.budget())) {
								a.possible_seat(a.budget());
							}
							number_1 = a.time();
							number_2 = a.seat_num();
							name_2 = a.name();
							a.save(number_1, number_2, name_2);
						}
						if (number == 2) {
							number_1 = a.time();
							number_2 = a.seat_num();
							name_2 = a.name();
							a.cancel(number_1, number_2, name_2);
							airplane -= 1;
						}
						if (number == 3) {
							a.show();
						}
						cout << "\n" << endl;
						number = a.menu();
					}
					if (number == 4) {
						a.info_write();
						a.finish();
						c->seat_reset();
						a.seat_reset();
					}
				}

				else {
					c->finish();
					c->seat_reset();
				}
			}
			number_4 = reservation();
			cout << endl;
		}
		while (number_4 == 2) {
			string id;
			int password;

			int waiting_num = 0;

			cout << "���̵� (������� �̸��� ����) �Է�>> ";
			cin >> id;
			cout << "��й�ȣ (���� 4�ڸ�) �Է�>> ";
			cin >> password;

			if ((restaurant_login.find(id) == restaurant_login.end()) && (restaurant_login[id] != password)) {
				cout << "ȯ���մϴ�. ���� ��ϵǾ����ϴ�." << endl;
				restaurant_login.insert(make_pair(id, password));
			}

			else {
				if (restaurant_login.find(id) != restaurant_login.end())
					cout << "ȯ���մϴ�." << id << " ȸ����!" << endl;

				else
					cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
			}
			cout << endl;
			bool t_f = true;

			int check;
			cout << "���� ����� Ȯ���ص帱��� ? (Ȯ��: 1, Ȯ�� ����: 2) >> ";
			cin >> check;
			if (check == 1) {
				cout << "�Ĵ� ���� Ȯ���� ���͵帮�ڽ��ϴ�." << endl;
				r.check();
			}
			else {
				string Date_1 = r.get();
				cout << endl;
				if (r.date() != Date_1)
					r.de();
				while (t_f) {
					if (r.age()) {
						cout << "7�� ���� ������ �Ƶ��� ������ �� �����ϴ�." << endl;
						cout << endl;
						t_f = r.finish_reserve();
					}
					else {
						int number_5 = r.cus_kind();
						r.table();
						int number_7 = r.cus_num();

						if (r.table_match(number_7)) {
							int number_6 = r.table_show(number_5);

							if (number_6 != 100) {
								r.reserve(number_6);
								cout << "���� �Ϸ�Ǿ����ϴ�." << endl;
								r.info_write(number_6,number_5);
								restaurant += 1;
								cout << endl;
							}

							if (number_6 == 100 && number_5 == 2) {
								waiting_num += 1;
								r.inform(waiting_num);
								m.add(waiting_num);
								cout << endl;
							}
						}

						if (m.finish_eat()) {
							int t_n = m.finish_table_num();
							m.out(t_n);

							if (waiting_num != 0) {
								if (m.cus_num() <= m.getcap(t_n)) {
									cout << m.next() << "�� �մ� ���� ���̺� ���� �����մϴ�." << endl;
									m.popping();
									cout << endl;
								}
								else
									cout << "�˼��մϴ�. ���ݸ� �� ������ּ���. " << endl;
							}
						}
						t_f = r.finish_reserve();
					}
				}
			}
			number_4 = reservation();
			cout << endl;
		}

		while (number_4 == 3) {
			string id;
			int password;

			cout << "���̵� (������� �̸��� ����) �Է�>> ";
			cin >> id;
			cout << "��й�ȣ (���� 4�ڸ�) �Է�>> ";
			cin >> password;

			if ((studyroom_login.find(id) == studyroom_login.end()) && (studyroom_login[id] != password)) {
				cout << "ȯ���մϴ�. ���� ��ϵǾ����ϴ�." << endl;
				studyroom_login.insert(make_pair(id, password));
			}

			else {
				if (studyroom_login.find(id) != studyroom_login.end())
					cout << "ȯ���մϴ�." << id << " ȸ����!" << endl;

				else
					cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
			}
			cout << endl;
			bool t_f = true;
			int check;
			cout << "���� ����� Ȯ���ص帱��� ? (Ȯ��: 1, Ȯ�� ����: 2) >> ";
			cin >> check;
			if (check == 1) {
				cout << "������ ���� Ȯ���� ���͵帮�ڽ��ϴ�." << endl;
				s.checking();
			}
			else {
				string Date_1 = s.get();
				cout << endl;
				if (s.date() != Date_1)
					s.de();
				while (t_f) {
					if (s.menu() == 1) {
						if (s.age() > 13) {
							int I = s.id();

							if (study.find(I) == study.end()) {
								study[I] = 0;
								if (s.start_time(I, 0) == 1) {
									string sex = s.sex();
									w_studyroom += s.get_sex();
									s.table_show(sex);
									int seat_num = s.seat_number();
									s.reserve(sex, seat_num);
									studyroom += 1;
								}
							}
							else {
								if (s.start_time(I, study[I]) == 1) {
									string sex = s.sex();
									w_studyroom += s.get_sex();
									s.table_show(sex);
									int seat_num = s.seat_number();
									s.reserve(sex, seat_num);
									studyroom += 1;
									cout << endl;
								}
							}
						}
						else
							cout << "13�� ���ϴ� ������ �� �����ϴ�." << endl;
					}
					else {
						int I_D = s.id();
						int seat_num_2 = s.seat_number();
						s.finish_time();
						s.cancel(seat_num_2);
						int time = s.add(I_D);
						study[I_D] += time;
						if (study[I_D] > 240) {
							cout << "�ڵ����� �¼��� �����Ǿ����ϴ�." << endl;
							study[I_D] = 240;
						}
						cout << "���ݱ��� �̿����ּż� �����մϴ�." << endl;
						s.info_write(I_D, seat_num_2, study[I_D]);
						cout << endl;
						index += 1;
					}
					t_f = s.finish_study();
				}
			}
			number_4 = reservation();
			cout << endl;
		}
	}
	if (number_4 == 4) {
		cout << "����� ���� : " << airplane << "��" << endl;
		cout << "�Ĵ� ���� : " << restaurant << "��" << endl;
		cout << "������ ���� : " << studyroom << "��" << endl;
		cout << "������ ���� : " << "���� - > " << studyroom - w_studyroom << "��,  ���� - > " << w_studyroom << "��" << endl;
	}
}