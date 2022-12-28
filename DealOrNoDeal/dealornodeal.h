#pragma once

#include "../util/util.h"
class dealornodeal {
public:
	dealornodeal();
	~dealornodeal();
	static bool _interactive;
	static int read_an_integer();
	static char read_a_character();
	static void get_interactive_or_computer();
	static void play_a_game();
	static void play_until_millionare();
	static void play_until_bankrupt();
	
private:	
	int _start;
	int _end;
	int _suitcase_selected;
	int* _suitcase;
	int _num_of_suitcase();
	void _fill_initial_money();
	void _play();
	void _game();
	void _shuffle();
	void _available_suitcase();
	void _select_suitcase(int& a);
	void _cal_banker_offer();
	char _dealornot();
};
