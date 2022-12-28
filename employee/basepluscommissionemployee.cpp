
#include "basepluscommissionemployee.h"

basepluscommissionemployee::basepluscommissionemployee(const char* f, const char* l, const char* s, const char* b, double p, const char* w, double bs)
	: commissionemployee(f, l, s, b, p), _w(nullptr), _bs(bs) {
	_alloAndCopy(_w, w);
	if (show()) {
		cout << "In basepluscommissionemployee::basepluscommissionemployee constructor " << *this << endl;
	}
}

basepluscommissionemployee::~basepluscommissionemployee() {
	if (show()) {
		cout << "In basepluscommissionemployee::~basepluscommissionemployee destructor " << *this << endl;
	}
	_release();
}

basepluscommissionemployee::basepluscommissionemployee(const basepluscommissionemployee& e)
	: commissionemployee(e), _w(nullptr), _bs(e._bs) {
	_alloAndCopy(_w, e._w);
	if (show()) {
		cout << "In basepluscommissionemployee copy constructor " << *this << endl;
	}
}

basepluscommissionemployee& basepluscommissionemployee::operator=(const basepluscommissionemployee& e) {
	if (this != &e) {
		commissionemployee::operator=(e);
		_release();
		_copy(e);
	}
	if (show()) {
		cout << "In basepluscommissionemployee euqal operator " << *this << endl;
	}
	return *this;
}

basepluscommissionemployee& basepluscommissionemployee::operator=(const employee& e) {
	assert(typeid(e) == typeid(*this));
	const basepluscommissionemployee& s = static_cast<const basepluscommissionemployee&>(e);
	return (*this = s);
}

void basepluscommissionemployee::_print(ostream& o) const {
	commissionemployee::_print(o);
	o << _w << " " << _bs << " ";
}

ostream& operator<<(ostream& o, const basepluscommissionemployee& e) {
	e._print(o);
	return o;
}

void basepluscommissionemployee::_copy(const basepluscommissionemployee& e) {
	_alloAndCopy(_w, e._w);
	_bs = e._bs;
}

void basepluscommissionemployee::_release() {
	delete[] _w;
}