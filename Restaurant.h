#ifndef RESTAURANT_H
#define RESTAURANT_H

class Restaurant {
public:
	int age_1;
	int number_1;
	int kind;
	int table_num;
	int waiting_num;

	string Date;

	Restaurant();
	bool age();
	bool finish_reserve();
	void de();

	string date();
	string get();

	int info_write(int n, int k);
	int cus_num();
	int cus_kind();
	int table_show(int k);
	int getcap(int i);
	
	void inform(int i);
	void reserve(int i);
	void out(int i);
	void table();
	void check();

	bool table_match(int i);
};

#endif