
#include "intmatrix2.h"

bool intmatrix2::shown = false;
void intmatrix2::makeShowOn() {
	shown = true;
}

intmatrix2::intmatrix2(int r, int c, int v)
	: m_(nullptr), r_(r), c_(c) {
	if (shown) {
		cout << "In constructor ";
		cout << "r = " << r_ << " c = " << c_ << " v = " << v << endl;
	}
	if (r_ && c_) {
		m_ = new int* [r_];
		for (int i = 0; i < r_; ++i) {
			m_[i] = new int[c_];
		}
		for (int i = 0; i < r_; ++i) {
			for (int j = 0; j < c_; ++j) {
				m_[i][j] = v;
			}
		}
	}
}

intmatrix2::intmatrix2(const char* s) 
	: m_(nullptr), r_(0), c_(0) {
	if (shown) {
		cout << "In constructor " << "s = " << s << endl;
	}
	int row = 0;
	int col = 0;
	int k = 0;
	bool isvalid = true;
	int temp[1000]{ 0 };
	int idx = 0;
	int j = 0;
	char ch = '0';
	do {
		ch = *(s++);
		if (ch == ' ') {
			if (!j) continue;
			idx++;
			j = 0;
			k++;
		}
		else if (ch == '|' || ch == '\0') {
			++row;
			if (j) {
				idx++;
				j = 0;
				k++;
			}
			if (col == 0) {
				col = k;
			}
			if (k == 0 || k != col) {
				isvalid = false;
				break;
			}
			k = 0;
		}
		else if (ch >= '0' && ch <= '9') {
			temp[idx] = temp[idx] * 10 + (ch - '0');
			j++;
		}
		else {
			isvalid = false;
			break;
		}
	} while (ch != '\0');

	if (isvalid && row && col) {
		r_ = row;
		c_ = col;
		m_ = new int* [r_];
		for (int i = 0; i < r_; ++i) {
			m_[i] = new int[c_];
		}
		idx = 0;
		for (int i = 0; i < r_; ++i) {
			for (int j = 0; j < c_; ++j) {
				m_[i][j] = temp[idx++];
			}
		}
	}
}

intmatrix2::intmatrix2(const intmatrix2& b) {
	if (shown) {
		cout << "In copy constructor" << endl;
	}
	_copy(b);
	if (shown) {
		cout << (*this) << endl;
	}
}

void intmatrix2::_copy(const intmatrix2& b) {
	r_ = b.r_;
	c_ = b.c_;
	if (r_ && c_) {
		m_ = new int* [r_];
		for (int i = 0; i < r_; ++i) {
			m_[i] = new int[c_];
		}
		for (int i = 0; i < r_; ++i) {
			for (int j = 0; j < c_; ++j) {
				m_[i][j] = b.m_[i][j];
			}
		}
	}
}

intmatrix2:: ~intmatrix2() {
	if (shown) {
		cout << "In Destructor" << endl;
		cout << (*this) << endl;
	}
	_release();
}

void intmatrix2::_release() {
	if (!isEmpty()) {
		for (int i = 0; i < r_; ++i) {
			delete[] m_[i];
		}
		delete m_;
	}
}

bool intmatrix2::isEqual(const intmatrix2& b) const {
	if (r_ != b.r_ || c_ != b.c_) return false;
	for (int i = 0; i < r_; ++i) {
		for (int j = 0; j < c_; ++j) {
			if (m_[i][j] != b.m_[i][j])
				return false;
		}
	}
	return true;
}

intmatrix2& intmatrix2::operator=(const intmatrix2& rhs) {
	if (shown) {
		cout << "In equal operator rhs" << endl;
	}
	if (this != &rhs) {
		_release();
		_copy(rhs);
	}
	if (shown) {
		cout << (*this) << endl;
	}
	return *this;
}

void intmatrix2::print() const {
	const intmatrix2& a = *this;
	if (!a.isEmpty()) {
		for (int i = 0; i < a.r_; ++i) {
			for (int j = 0; j < a.c_; ++j) {
				cout << a.m_[i][j] << " ";
			}
			cout << endl;
		}
	}
}

ostream& operator<<(ostream& o, const intmatrix2& b) {
	if (intmatrix2::shown) {
		if (b.isEmpty()) {
			cout << "         Empty Matrix        " << endl;
		}
		else {
			b.print();
		}
	}
	return o;
}

intmatrix2 intmatrix2::add(const intmatrix2& b) const {
	if (r_ == b.r_ && c_ == b.c_) {
		intmatrix2 sum(r_, c_);
		for (int i = 0; i < r_; ++i) {
			for (int j = 0; j < c_; ++j) {
				sum.m_[i][j] = m_[i][j] + b.m_[i][j];
			}
		}
		return sum;
	}
	intmatrix2 sum;
	return sum;
}

intmatrix2 intmatrix2::mult(const intmatrix2& b) const {
	const intmatrix2& a = *this;
	if (!a.isEmpty() && !b.isEmpty()) {
		if (r_ == 1 && c_ == 1) {
			//intmatrix2 prod(b.r_, b.c_);
			for (int i = 0; i < b.r_; ++i) {
				for (int j = 0; j < b.c_; ++j) {
					b.m_[i][j] *= a.m_[0][0];
				}
			}
			return b;
		}
		else if (b.r_ == 1 && b.c_ == 1) {
			//intmatrix2 prod(r_, c_);
			for (int i = 0; i < r_; ++i) {
				for (int j = 0; j < c_; ++j) {
					a.m_[i][j] *= b.m_[0][0];
				}
			}
			return a;
		}
		else if (c_ == b.r_) {
			intmatrix2 prod(r_, b.c_);
			for (int i = 0; i < r_; ++i) {
				for (int j = 0; j < b.c_; ++j) {
					for (int k = 0; k < c_; ++k) {
						prod.m_[i][j] += (a.m_[i][k] * b.m_[k][j]);
					}
				}
			}
			return prod;
		}
	} 
	intmatrix2 prod;
	return prod;
}
