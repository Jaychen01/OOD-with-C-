
#include "commissionemployee.h"

commissionemployee::commissionemployee(const char* f, const char* l, const char* s, const char* w, double p)
	: employee(f, l, s), _w(nullptr), _p(p) {
	_alloAndCopy(_w, w);
	if (show()) {
		cout << "In commissionemployee::commissionemployee constructor " << *this << endl;
	}
}

commissionemployee::~commissionemployee() {
	if (show()) {
		cout << "In commissionemployee::~commissionemployee destructor " << *this << endl;
	}
	_release();
}

commissionemployee::commissionemployee(const commissionemployee& e)
	: employee(e), _w(nullptr), _p(e._p) {
	_alloAndCopy(_w, e._w);
	if (show()) {
		cout << "In commissionemployee copy constructor " << *this << endl;
	}
}

commissionemployee& commissionemployee::operator=(const commissionemployee& e) {
	if (this != &e) {
		employee::operator=(e);
		_release();
		_copy(e);
	}
	if (show()) {
		cout << "In commissionemployee euqal operator " << *this << endl;
	}
	return *this;
}

commissionemployee& commissionemployee::operator=(const employee& e) {
	assert(typeid(e) == typeid(*this));
	const commissionemployee& s = static_cast<const commissionemployee&>(e);
	return (*this = s);
}

void commissionemployee::_print(ostream& o) const {
	employee::_print(o);
	o << _w << " " << _p << " ";
}

ostream& operator<<(ostream& o, const commissionemployee& e) {
	e._print(o);
	return o;
}

void commissionemployee::_copy(const commissionemployee& e) {
	_alloAndCopy(_w, e._w);
	_p = e._p;
}

void commissionemployee::_release() {
	delete[] _w;
}