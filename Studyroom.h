#ifndef STUDYROOM_H
#define STUDYROOM_H

class Studyroom {
public:
	string date_r;
	string sex_1;

	int ID;
	int seat_num_1;

	int add(int ID);
	int id();
	int age();
	int menu();
	int seat_number();
	int start_time(int ID, int s);
	int get_sex();
	int info_write(int id, int seat_num, int time);

	string get();
	string sex();
	string date();
	string check(int x, int y, string c);

	void de();
	void finish_time();
	void reserve(string c, int seat_num);
	void table_show(string c);
	void cancel(int seat_num);
	void checking();

	bool finish_study();
};


#endif
