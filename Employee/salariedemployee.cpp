
#include "salariedemployee.h"

salariedemployee::salariedemployee(const char* f, const char* l, const char* s, const char* w, double p) 
	: employee(f, l, s), _w(nullptr), _p(p) {
	_alloAndCopy(_w, w);
	if (show()) {
		cout << "In salariedemployee::salariedemployee constructor " << *this << endl;
	}
}

salariedemployee::~salariedemployee() {
	if (show()) {
		cout << "In salariedemployee::~salariedemployee destructor " << *this << endl;
	}
	_release();
}

salariedemployee::salariedemployee(const salariedemployee& e) 
	: employee(e), _w(nullptr), _p(e._p) {
	_alloAndCopy(_w, e._w);
	if (show()) {
		cout << "In salariedemployee copy constructor " << *this << endl;
	}
}

salariedemployee& salariedemployee::operator=(const salariedemployee& e) {
	if (this != &e) {
		employee::operator=(e);
		_release();
		_copy(e);
	}
	if (show()) {
		cout << "In salariedemployee euqal operator " << *this << endl;
	}
	return *this;
}

salariedemployee& salariedemployee::operator=(const employee& e) {
	assert(typeid(e) == typeid(*this));
	const salariedemployee& s = static_cast<const salariedemployee&>(e);
	return (*this = s);
}

void salariedemployee::_print(ostream& o) const {
	employee::_print(o);
	o << _w << " " << _p << " ";
}

ostream& operator<<(ostream& o, const salariedemployee& e) {
	e._print(o);
	return o;
}

void salariedemployee::_copy(const salariedemployee& e) {
	_alloAndCopy(_w, e._w);
	_p = e._p;
}

void salariedemployee::_release() {
	delete[] _w;
}
