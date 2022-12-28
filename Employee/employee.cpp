
#include "employee.h"

bool employee::_show = false;

employee::employee(const char* f, const char* l, const char* s) 
	: _f(nullptr), _l(nullptr), _s(nullptr) {
	_alloAndCopy(_f, f);
	_alloAndCopy(_l, l);
	_alloAndCopy(_s, s);
	if (show()) {
		cout << "In employee::employee constructor " << *this << endl;
	}
}

employee::~employee() {
	if (show()) {
		cout << "In employee::~employee destructor " << *this << endl;
	}
	_release();
}

employee::employee(const employee& e) {
	_copy(e);
	if (show()) {
		cout << "In employee copy constructor " << *this << endl;
	}
}

employee& employee::operator=(const employee& e) {
	if (this != &e) {
		_release();
		_copy(e);
	}
	if (show()) {
		cout << "In employee euqal operator " << *this << endl;
	}
	return *this;
}

void employee::_print(ostream& o) const {
	o << _f << " " << _l << " " << _s << " ";
}

ostream& operator<<(ostream& o, const employee& e) {
	e._print(o);
	return o;
}

void employee::_alloAndCopy(char*& to, const char* from) {
	to = new char[strlen(from) + 1];
	strcpy(to, from);
}

void employee::_copy(const employee& e) {
	_alloAndCopy(_f, e._f);
	_alloAndCopy(_l, e._l);
	_alloAndCopy(_s, e._s);
}

void employee::_release() {
	delete[] _f;
	delete[] _l;
	delete[] _s;
}

