#pragma once

#include "../util/util.h"

class employee {
public:
	employee(const char* f, const char* l, const char* s);
	virtual ~employee();
	employee(const employee& e);
	virtual employee& operator=(const employee& e);
	friend ostream& operator<<(ostream& o, const employee& e);

	static bool _show;
	static void setShow(bool x) { _show = x; }
	static bool show() { return _show; }

protected:
	void _alloAndCopy(char*& to, const char* from);
	virtual void _print(ostream& o) const;

private:
	char* _f;
	char* _l;
	char* _s;
	void _copy(const employee& e);
	void _release();
};

