#pragma once

#include "../util/util.h"
#include "employee.h"
#include "commissionemployee.h"

class basepluscommissionemployee : public commissionemployee {
public:
	basepluscommissionemployee(const char* f, const char* l, const char* s, const char* b, double p, const char* w, double bs);
	virtual ~basepluscommissionemployee();
	basepluscommissionemployee(const basepluscommissionemployee& e);
	basepluscommissionemployee& operator=(const basepluscommissionemployee& e);
	basepluscommissionemployee& operator=(const employee& e);
	friend ostream& operator<<(ostream& o, const basepluscommissionemployee& e);

protected:
	virtual void _print(ostream& o) const;

private:
	char* _w;
	double _bs;
	void _copy(const basepluscommissionemployee& e);
	void _release();
};