#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <deque>
#include <vector>
#include <algorithm>
#include "functions.hpp"

int main()
{
	std::fstream input_file("input");
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	int syntax_score {0};
	std::vector<unsigned long long> completion_scores {};
	
	calculate_scores(input_file, syntax_score, completion_scores);
	std::cout << "Part 1: " << syntax_score << std::endl;
	
	std::sort(completion_scores.begin(), completion_scores.end());
	std::cout << "Part 2: " << *(completion_scores.begin() + completion_scores.size()/2) << std::endl;
	
	return 0;
}