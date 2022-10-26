#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "Bingo_Board.hpp"

int main()
{
	std::fstream input_file("input");
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	// Load sequence of numbers for bingo from file into list
	int tmp;
	std::list<int> bingo_sequence;
	while (input_file >> tmp){
		bingo_sequence.push_back(tmp);
		if (input_file.peek() == ',')
			input_file.ignore(1);
		else 
			break;
	}
	
	// Load boards' layouts from file into vector
	std::vector<Bingo_Board> boards;
	while (true){
		Bingo_Board tmp_board;
		for (int y = 0 ; y < BOARDSIZE ; y++){
			for (int x = 0 ; x < BOARDSIZE ; x++){
				input_file >> tmp_board.contents[x][y]; 
			}
		}
		if (input_file.eof()) // Stops loading after reaching EOF
			break;
		boards.push_back(tmp_board);
	}
	
	// Function below calculates score only for the first valid solution 
	// and for the last board that is solved, removing from the vector
	// any other board that is solved in between
	bool first_solution_found = false;
	while (!bingo_sequence.empty() && !boards.empty()){
		auto board = boards.begin();
		while (board != boards.end()){
			board -> mark_number_if_present_on_board(bingo_sequence.front());
			if (board -> check_if_any_line_is_marked()){
				if (first_solution_found == false){ 
					std::cout << "Part 1: " << board -> calculate_score(bingo_sequence.front()) << std::endl;
					first_solution_found =true;
				}
				if (boards.size() == 1){
					std::cout << "Part 2: " << board -> calculate_score(bingo_sequence.front()) << std::endl;
				}
				boards.erase(board);
			} else
				board++;
		}
		bingo_sequence.pop_front();
	}
	
	return 0;
}
