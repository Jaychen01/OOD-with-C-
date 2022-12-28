/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
Filename: slist1.h
-----------------------------------------------------------------*/
#pragma once

#include "../util/util.h" //NOTHING CAN BE ADDED
#define T int //Must use T. if we want  change to double : #define T double

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
class node;
class slist1;

/*----------------------------------------------------------------
class Node
-----------------------------------------------------------------*/
class node {
public:
		//Write all public functions below
		friend class slist1;//key
		node(const T& data) : data_(data), next_(nullptr) {}
		~node() {}
		node* next() const{ return next_; }
		const T& getData() const { return data_; }
		//no one can copy node or equal node;
		node(const node& x) = delete;
		node& operator=(const node& x) = delete;
private:
		T  data_;
		node* next_;
		//YOU CANNOT ADD ANY DATA MEMBERS
		//You can have any number of private functions here
};

/*----------------------------------------------------------------
class slist
-----------------------------------------------------------------*/
class slist1 {
public:
		//Write all public functions below
	slist1() : first_(nullptr), last_(nullptr) {}
	~slist1();
	slist1(const slist1& sl);
	slist1& operator=(const slist1& rhs);
	
	void append(const T& d);
	void prepend(const T& d);
	int size() const;
	bool find(const T& d) const;
	bool remove(const T& d);
	friend ostream& operator<<(ostream& o, const slist1& rhs);
	const T* operator[](int i) const;
	bool operator==(const slist1& rhs);
	bool operator!=(slist1& rhs);
	operator bool() const { return first_; }
private:
		node* first_;
		node* last_;
		void _release();
		void _copy(const slist1& from);
};


