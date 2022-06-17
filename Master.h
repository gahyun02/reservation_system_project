#ifndef MASTER_H
#define MASTER_H

#include "Restaurant.h"

class Master : public Restaurant {
public:
	int finish_table_num();
	int next();

	void popping();
	void add(int i);

	bool finish_eat();
};
#endif