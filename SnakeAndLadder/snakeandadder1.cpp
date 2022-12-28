/*----------------------------------------------------------------
Copyright (c) 2021 Author: Jagadeesh Vasudevamurthy
file: snakeandadder1.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has snakeandadder1 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "snakeandadder1.h" //0 grade will be given if you call any other library


//EOF
snakeandadder1::snakeandadder1(const int N, const vector<int>& l, const vector<int>& s, const int NR, vector<result>& data) 
	: _n(N), _nr(NR), _mindicethrown(INT_MAX), _maxdicethrown(INT_MIN), _maxladdergot(-1), _maxsnakegot(-1), _maxnomove(-1) {
	_l = l;
	_s = s;
	play(data);
}

void snakeandadder1::play(vector<result>& data) {
	for (int j = 0; j < _nr; ++j) {
		result s;
		s.game_number = j + 1;
		int position = 1;
		s.ans.append(to_string(position));
		while (position != _n) {
			s.ans.append("->");
			int dice = (_r.get_random_number(1, 6));
			s.dice_thrown.push_back(dice);
			// arrive destination
			if (position + dice == _n) {
				position += dice;
				s.ans.append(to_string(position));
			}
			// need more step
			else if (position + dice < _n) {
				position += dice;
				//check ladder
				bool foundladder = false;
				for (int i = 0; i < _l.size()-1; i += 2) {
					if (_l[i] > _l[i + 1]) {
						int temp = _l[i + 1];
						_l[i + 1] = _l[i];
						_l[i] = temp;
					}
					foundladder = _check(position, _l[i]);
					if (foundladder) {
						s.num_ladder_got++;
						s.ans.append("(").append(to_string(position)).append(")");
						position = _l[i + 1];
						s.ans.append(to_string(position));
						break;
					}
				}
				if (foundladder) continue;
				//check snake
				bool foundsnake = false;
				for (int k = 0; k < _s.size() - 1; k += 2) {
					if (_s[k] < _s[k + 1]) {
						int temp = _s[k + 1];
						_s[k + 1] = _s[k];
						_s[k] = temp;
					}
					foundsnake = _check(position, _s[k]);
					if (foundsnake) {
						s.num_snake_got++;
						s.ans.append("(").append(to_string(position)).append(")");
						position = _s[k + 1];
						s.ans.append(to_string(position));
						break;
					}
				}
				if (foundsnake) continue;
				//no ladder, no snake
				s.ans.append(to_string(position));
			}
			//never moved
			else {
				s.num_never_moved++;
				s.ans.append("(").append(to_string(dice)).append(")");
				s.ans.append(to_string(position));
			}
		}
		_updatedata(data, s);
	}
}

bool snakeandadder1::_check(const int& a, const int& b) const {
	return a == b;
}

void snakeandadder1::_updatedata(vector<result>& data, const result& s) {
	const int num_dice = static_cast<int>(s.dice_thrown.size());
	if (num_dice < _mindicethrown) {
		_mindicethrown = num_dice;
		data.at(0) = s;
	}
	if (num_dice > _maxdicethrown) {
		_maxdicethrown = num_dice;
		data.at(1) = s;
	}
	if (s.num_ladder_got > _maxladdergot) {
		_maxladdergot = s.num_ladder_got;
		data.at(2) = s;
	}
	if (s.num_snake_got > _maxsnakegot) {
		_maxsnakegot = s.num_snake_got;
		data.at(3) = s;
	}
	if (s.num_never_moved > _maxnomove) {
		_maxnomove = s.num_never_moved;
		data.at(4) = s;
	}
}
