#pragma once

#include "../util/util.h"
#include "employee.h"

class commissionemployee : public employee {
public:
	commissionemployee(const char* f, const char* l, const char* s, const char* w, double p);
	virtual ~commissionemployee();
	commissionemployee(const commissionemployee& e);
	commissionemployee& operator=(const commissionemployee& e);
	commissionemployee& operator=(const employee& e);
	friend ostream& operator<<(ostream& o, const commissionemployee& e);

protected:
	virtual void _print(ostream& o) const;

private:
	char* _w;
	double _p;
	void _copy(const commissionemployee& e);
	void _release();
};
