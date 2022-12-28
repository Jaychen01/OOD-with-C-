/*----------------------------------------------------------------
Copyright (c) 2021 Author: Jagadeesh Vasudevamurthy
file: snakeandadder.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has snakeandadder class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once

#include "util.h" //0 grade will be given if you call any other library

/*----------------------------------------------------------------
Declaration of result class
result of 1 game
NOTHING CAN BE CHANGED HERE
-----------------------------------------------------------------*/
struct result {
		int game_number = 0;
		vector<int> dice_thrown ;
		int num_ladder_got = 0;
		int num_snake_got = 0;
		int num_never_moved = 0;
		string ans;
};


/*----------------------------------------------------------------
Declaration of snakeandadder1 class
-----------------------------------------------------------------*/
class snakeandadder1 {
		//WRITE CODE
public:
	snakeandadder1(const int N, const vector<int>& l, const vector<int>& s, const int NR, vector<result>& data);
	~snakeandadder1() {};
	void play(vector<result>& data);

private:
	Random _r;
	int _nr;
	int _n;
	vector<int> _l;
	vector<int> _s;
	int _mindicethrown;
	int _maxdicethrown;
	int _maxladdergot;
	int _maxsnakegot;
	int _maxnomove;
	bool _check(const int& a,const int& b) const;
	void _updatedata(vector<result>& data, const result& s);
};



