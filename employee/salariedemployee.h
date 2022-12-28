#pragma once

#include "../util/util.h"
#include "employee.h"

class salariedemployee : public employee{
public:
	salariedemployee(const char* f, const char* l, const char* s, const char* w, double p);
	virtual ~salariedemployee();
	salariedemployee(const salariedemployee& e);
	salariedemployee& operator=(const salariedemployee& e);
	salariedemployee& operator=(const employee& e);
	friend ostream& operator<<(ostream& o, const salariedemployee& e);
	
protected:
	virtual void _print(ostream& o) const;

private:
	char* _w;
	double _p;
	void _copy(const salariedemployee& e);
	void _release();
};

