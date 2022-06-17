#ifndef ARRIVAL_H
#define ARRIVAL_H

#include "Console.h"

class Arrival : public Console {
public:
	string airport_lo;
	string aiport_lo_1;
	string date_1;

	Arrival();
	string airport();
	string date();

	void save(int t, int s, string n);
	void cancel(int t, int s, string n);
	void show();
	void seat_show(int t , int n = 8);
	void seat_reset();
	void getArrival(string s);

	bool possible_seat(int p);

	int info_write();
};


#endif
