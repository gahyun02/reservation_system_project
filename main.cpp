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
	cout << "비행기 예약:1, 식당 예약:2, 독서실 좌석 예약:3, 예약 시스템 종료:4 >> ";
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

			cout << "아이디 (사용자의 이름과 동일) 입력>> ";
			cin >> id;
			cout << "비밀번호 (숫자 4자리) 입력>> ";
			cin >> password;

			if ((airplane_login.find(id) == airplane_login.end()) && (airplane_login[id] != password)) {
				cout << "환영합니다. 새로 등록되었습니다." << endl;
				airplane_login.insert(make_pair(id, password));
			}

			else {
				if (airplane_login.find(id) != airplane_login.end())
					cout << "환영합니다." << id << " 회원님!" << endl;

				else
					cout << "비밀번호가 일치하지 않습니다." << endl;
			}
			cout << endl;
			if (c->ticket_check())
				cout << endl;
			else {
				number_3 = c->way();
				airport_lo = c->airport(); //출발지
				airport_lo_1 = a.airport(); //도착지
				c->getArrival(airport_lo_1);
				a.getArrival(airport_lo);

				cout << endl;
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "********  " << airport_lo << "에 오신 걸 환영합니다  ********" << endl;
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
					cout << "********  " << airport_lo_1 << "에 오신 걸 환영합니다  ********" << endl;
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

			cout << "아이디 (사용자의 이름과 동일) 입력>> ";
			cin >> id;
			cout << "비밀번호 (숫자 4자리) 입력>> ";
			cin >> password;

			if ((restaurant_login.find(id) == restaurant_login.end()) && (restaurant_login[id] != password)) {
				cout << "환영합니다. 새로 등록되었습니다." << endl;
				restaurant_login.insert(make_pair(id, password));
			}

			else {
				if (restaurant_login.find(id) != restaurant_login.end())
					cout << "환영합니다." << id << " 회원님!" << endl;

				else
					cout << "비밀번호가 일치하지 않습니다." << endl;
			}
			cout << endl;
			bool t_f = true;

			int check;
			cout << "예약 기록을 확인해드릴까요 ? (확인: 1, 확인 안함: 2) >> ";
			cin >> check;
			if (check == 1) {
				cout << "식당 예약 확인을 도와드리겠습니다." << endl;
				r.check();
			}
			else {
				string Date_1 = r.get();
				cout << endl;
				if (r.date() != Date_1)
					r.de();
				while (t_f) {
					if (r.age()) {
						cout << "7세 이하 미취학 아동은 예약할 수 없습니다." << endl;
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
								cout << "예약 완료되었습니다." << endl;
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
									cout << m.next() << "번 손님 현재 테이블 예약 가능합니다." << endl;
									m.popping();
									cout << endl;
								}
								else
									cout << "죄송합니다. 조금만 더 대기해주세요. " << endl;
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

			cout << "아이디 (사용자의 이름과 동일) 입력>> ";
			cin >> id;
			cout << "비밀번호 (숫자 4자리) 입력>> ";
			cin >> password;

			if ((studyroom_login.find(id) == studyroom_login.end()) && (studyroom_login[id] != password)) {
				cout << "환영합니다. 새로 등록되었습니다." << endl;
				studyroom_login.insert(make_pair(id, password));
			}

			else {
				if (studyroom_login.find(id) != studyroom_login.end())
					cout << "환영합니다." << id << " 회원님!" << endl;

				else
					cout << "비밀번호가 일치하지 않습니다." << endl;
			}
			cout << endl;
			bool t_f = true;
			int check;
			cout << "예약 기록을 확인해드릴까요 ? (확인: 1, 확인 안함: 2) >> ";
			cin >> check;
			if (check == 1) {
				cout << "독서실 예약 확인을 도와드리겠습니다." << endl;
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
							cout << "13세 이하는 예약할 수 없습니다." << endl;
					}
					else {
						int I_D = s.id();
						int seat_num_2 = s.seat_number();
						s.finish_time();
						s.cancel(seat_num_2);
						int time = s.add(I_D);
						study[I_D] += time;
						if (study[I_D] > 240) {
							cout << "자동으로 좌석이 해지되었습니다." << endl;
							study[I_D] = 240;
						}
						cout << "지금까지 이용해주셔서 감사합니다." << endl;
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
		cout << "비행기 예약 : " << airplane << "번" << endl;
		cout << "식당 예약 : " << restaurant << "번" << endl;
		cout << "독서실 예약 : " << studyroom << "번" << endl;
		cout << "독서실 예약 : " << "남자 - > " << studyroom - w_studyroom << "번,  여자 - > " << w_studyroom << "번" << endl;
	}
}