#ifndef CONSOLE_H
#define CONSOLE_H

class Console {
public:
	int way_1;
	int pay;
	int menu_1;
	int time_1;
	int seat_num_1;
	int mileage = 0;

	string name_1;
	string airport_lo;
	string airport_lo_1;
	string date_1;
	
	Console();

	friend int reservation();
	int way();
	int budget();
	int menu();
	int time();
	int seat_num();
	int info_write();

	string airport();
	string name();
	string date();
	string getTime(int t);
	
	void save(int t, int s, string n);
	void cancel(int t, int s, string n);
	void show();
	void seat_show(int t, int n = 8);
	void seat_reset();
	void finish();
	void getArrival(string s);

	bool ticket_check();
	bool possible_seat(int p);
};
#endif
