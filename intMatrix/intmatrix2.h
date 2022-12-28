#pragma once

#include "../util/util.h"

class intmatrix2
{
public:
	intmatrix2(int r = 0, int c = 0, int v = 0);
	intmatrix2(const char* s);
	~intmatrix2();
	intmatrix2(const intmatrix2& b);
	intmatrix2& operator=(const intmatrix2& rhs);
	void print() const;
	bool isEmpty() const { return !(m_); }
	bool isEqual(const intmatrix2& b) const;
	intmatrix2 add(const intmatrix2& b) const;
	intmatrix2 mult(const intmatrix2& b) const;
    friend ostream& operator<<(ostream& o, const intmatrix2& a);
	static void makeShowOn();
	static bool shown;
private:
	int r_;
	int c_;
	int** m_;
	void _release();
	void _copy(const intmatrix2& from);
};