#include "Bingo_Board.hpp"
	
void Bingo_Board::mark_number_if_present_on_board(const int& called_number){
	for (int y = 0 ; y < BOARDSIZE ; y++){
		for (int x = 0 ; x < BOARDSIZE ; x++){
			if (contents[x][y] == called_number){
				contents[x][y] = -1;
				horizontal_lines[y] += 1;
				vertical_lines[x] += 1;
			}
		}
	}
}
	
bool Bingo_Board::check_if_any_line_is_marked(){
	for (int i = 0 ; i < BOARDSIZE ; i++){
		if (horizontal_lines[i] == 5)
			return true;
		if (vertical_lines[i] == 5)
			return true;
	}
	return false;
}
	
int Bingo_Board::calculate_score(const int& called_number){
	int sum{0};
	for (int y = 0 ; y < BOARDSIZE ; y++){
		for (int x = 0 ; x < BOARDSIZE ; x++){
			if (contents[x][y] != -1)
				sum += contents[x][y];
		}
	}
	return sum * called_number;
}