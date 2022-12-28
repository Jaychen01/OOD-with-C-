
#include "dealornodeal.h"

bool dealornodeal::_interactive = true;
static const int MILL = 1000000;
static const int boxes[] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000,50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000 };

dealornodeal::dealornodeal() : _start(1), _end(_num_of_suitcase()), _suitcase(nullptr), _suitcase_selected(0) {
	_suitcase = new int[_end];
	_fill_initial_money();
	_game();
}

dealornodeal::~dealornodeal() {
	delete[] _suitcase;
}

int dealornodeal::_num_of_suitcase() {
	return 26;
}

void dealornodeal::_fill_initial_money() {
	for (int i = _start; i <= _end; ++i) {
		_suitcase[i-1] = boxes[i-1];
	}
	_shuffle();
}

void dealornodeal::_shuffle() {
	int index = 0; 
	for (int i = _end - 1; i >= 0; --i) {
		index = rand() % _end;
		int temp = _suitcase[i];
		_suitcase[i] = _suitcase[index];
		_suitcase[index] = temp;
	}
}

void dealornodeal::_game() {
	_available_suitcase();
	_select_suitcase(_end);
	_play();
}

void dealornodeal::_play() {
	int round_num = 1;
	int select_num = 6;
	int closed_case = _end - 1;
	while (closed_case > 0) {
		cout << "----------ROUND NUMBER " << round_num << "----------" << endl;
		cout << "*** Select " << select_num << " suitcases now ***" << endl;
		int count = select_num;
		while (count > 0) {
			_available_suitcase();
			_select_suitcase(closed_case);
			closed_case--;
			count--;
		}
		if (select_num > 1) select_num--;
		if (closed_case > 0) {
			_cal_banker_offer();
			char c = _dealornot();
			if (c == 'd') {
				cout << "Congratulations!" << endl;
				break;
			}
		}
		round_num++;
	}
	cout << "Your suicase has: " << _suitcase_selected-1 << " dollars" << endl;
}

char dealornodeal::_dealornot() {
	cout << "Deal[d] or NoDeal[n]: ";
	if (_interactive) {
		char c = read_a_character();
		if (c == 'd' || c == 'n') return c;
		else return _dealornot();
	}
	else {
		cout << endl;
		return 'n';
	}
}

void dealornodeal::_cal_banker_offer() {
	cout << "Money left are: ";
	int offer = 0;
	int cnt = 0;
	for (int j = _start; j <= _end; ++j) {
		for (int i = _start; i <= _end; ++i) {
			if (_suitcase[i - 1] == boxes[j-1]) {
				cout << _suitcase[i - 1] << ",";
				offer += _suitcase[i - 1];
				cnt++;
			}
		}
	}
	cout << endl;
	cout << "Banker offer: " << offer/cnt << endl;
}

void dealornodeal::_available_suitcase() {
	cout << "Select ONE suitcase from ";
	for (int i = _start; i <= _end; ++i) {
		if (_suitcase[i - 1] > -1)
			cout << i << ",";
	}
	cout << endl;
}

void dealornodeal::_select_suitcase(int& a) {
	cout << "Select ONE suitcase from above ";
	int num = 0;
	if (_interactive) {
		num = read_an_integer();
	}
	else {
		int idx = rand() % a + 1;
		for (int i = _start; i <= _end; ++i) {
			if (_suitcase[i - 1] > -1) {
				if (--idx == 0) num = i;
			}
		}
		cout << endl;
	}
	
	if (num >= _start && num <= _end && _suitcase[num-1] > -1) {
		if (_suitcase_selected == 0) {
			_suitcase_selected = _suitcase[num - 1] + 1;
			cout << "Your suitcase is: " << num << endl;
		}
		else {
			cout << "Your selected suitcase " << num << " which has " << _suitcase[num - 1] << " dollars" << endl;
		}
		_suitcase[num - 1] = -1;
	}
	else {
		_select_suitcase(a);
	}
}

int dealornodeal::read_an_integer() {
	const int MAX = 1024;
	char buffer[1000];
	cin.getline(buffer, MAX);
	int i = 0;
	int num = 0;
	while (char c = buffer[i++]) {
		if (c >= '0' && c <= '9') {
			num = num * 10 + (c - '0');
		}
		else {
			return 0;
		}
	}
	return num;
}

char dealornodeal::read_a_character() {
	const int MAX = 1024;
	char buffer[1000];
	cin.getline(buffer, MAX);
	int i = 0;
	char ch = '0';
	while (char c = buffer[i++]) {
		if (ch != '0') {
			return '0';
		}
		else if (c >= 'a' && c <= 'z') {
			ch = c;
		}
	}
	return ch;
}

void dealornodeal::get_interactive_or_computer() {
	cout << "Interactive[i] or Computer[c]: ";
	char c = read_a_character();
	if (c == 'c') {
		_interactive = false;
	}
	else if (c == 'i') {
		_interactive = true;
	}
	else {
		get_interactive_or_computer();
	}
}

void dealornodeal::play_a_game() {
	dealornodeal d;
}

void dealornodeal::play_until_millionare() {
	int times = 0;
	int bonus = -1;
	_interactive = false;
	while (bonus != MILL) {
		times++;
		dealornodeal d;
		bonus = d._suitcase_selected - 1;
	}
	cout << "A millionare after " << times << " iteration" << endl;
}

void dealornodeal::play_until_bankrupt() {
	int times = 0;
	int bonus = -1;
	_interactive = false;
	while (bonus != 0) {
		times++;
		dealornodeal d;
		bonus = d._suitcase_selected - 1;
	}
	cout << "A bankrupt after " << times << " iteration" << endl;
}

int main() {
	dealornodeal::get_interactive_or_computer();
	dealornodeal::play_a_game();
	dealornodeal::play_until_millionare();
	dealornodeal::play_until_bankrupt();
	return 0;
}