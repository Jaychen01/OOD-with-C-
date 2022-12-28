/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
Filename: slist1.cpp
-----------------------------------------------------------------*/

#include "slist1.h"
//NOTHING CAN BE ADDED HERE

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
slist1::~slist1() {
	_release();
}

void slist1::_release() {
	if (first_) {
		while (first_) {
			node* temp = first_->next_;
			delete first_;
			first_ = temp;
		}
	}
}

void slist1::append(const T& v) {
	node* n = new node(v);
	if (!first_) {
		first_ = n;
	}
	else {
		last_->next_ = n;
	}
	last_ = n;
}

void slist1::prepend(const T& v) {
	node* n = new node(v);
	if (!first_) {
		last_ = n;
	}
	else {
		n->next_ = first_;	
	}
	first_ = n;
}

int slist1::size() const {
	int size = 0;
	node* count = first_;
	while (count) {
		 count = count->next_;
		 size++;
	}
	return size;
}

ostream& operator<<(ostream& o, const slist1& list) {
	node* n = list.first_;
	while (n) {
		o << n->getData();
		o << "->";
		n = n->next();
	}
	o << "NULL";
	return o;
}

slist1::slist1(const slist1& sl) {
	_copy(sl);
}

void slist1::_copy(const slist1& b) {
	first_ = nullptr;
	last_ = nullptr;
	if (this != &b && b.first_) {
		node* n = b.first_;
		while (n) {
			append(n->getData());
			n = n->next_;
		}
	}
}

slist1& slist1::operator=(const slist1& rhs) {
	if (this != &rhs) {
		_release();
		_copy(rhs);
	}
	return *this;
}

bool slist1::operator==(const slist1& rhs) {
	node* pb = rhs.first_;
	node* pa = first_;
	while (pa && pb) {
		if (pa->getData() != pb->getData()) return false;
		pa = pa->next_;
		pb = pb->next_;
	}
	if (!pa && !pb) return true;
	return false;
}

bool slist1::operator!=(slist1& rhs) {
	return !(* this == rhs);
}

bool slist1::find(const T& d) const{
	if (!first_) return false;
	node* n = first_;
	while (n) {
		if (n->getData() == d) return true;
		n = n->next_;
	}
	return false;
}

bool slist1::remove(const T& d) {
	if (find(d)) {
		node* pre = nullptr;
		node* cur = first_;
		while (cur) {
			if (cur->getData() == d) {
				if (last_ == first_) {
					first_ = nullptr;
					last_ = nullptr;
				}
				else if (cur == first_) {
					first_ = cur->next_;
				}
				else if (cur == last_) {
					pre->next_ = nullptr;
					last_ = pre;
				}
				else {
					pre->next_ = cur->next_;
				}
				delete cur;
				return true;
			}
			pre = cur;
			cur = cur->next_;
		}
	}
	return false;
}


const T* slist1::operator[](int i) const {
	if (i < 0) return nullptr;
	int idx = 0;
	node* count = first_;
	while (count) {
		if (idx == i) {
			T ans = count->getData();
			return &ans;
		}
		count = count->next_;
		idx++;
	}
	return nullptr;
}
