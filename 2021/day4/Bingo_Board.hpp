#pragma once

#define BOARDSIZE 5

struct Bingo_Board{
	int contents[BOARDSIZE][BOARDSIZE] = {0};
	int horizontal_lines[BOARDSIZE] = {0};
	int vertical_lines[BOARDSIZE] = {0};
	
	void mark_number_if_present_on_board(const int& called_number);
	bool check_if_any_line_is_marked();
	int calculate_score(const int& called_number);
};