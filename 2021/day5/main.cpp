#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "source.hpp"

int main()
{
    std::fstream input_file("input");
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
    
    int arr[ARRSIZE][ARRSIZE]{0};
	std::vector<Line> diagonal_points;
	std::string line_raw_input{};
	while (getline(input_file, line_raw_input)){
// 		next two lines are removing unwanted characters 
//		from every line of input before processing.
		std::replace(line_raw_input.begin(), line_raw_input.end(), ',', ' ');
        std::erase_if(line_raw_input, [](char c){return c == '-' || c == '>';});
//    --------------------------------------------------------------------------------------
//	  | erase_if requires C++20, for earlier versions 'erase-remove idiom' should be used. |
//    --------------------------------------------------------------------------------------
//		line.erase(
//			std::remove_if(line.begin(), line.end(), 
//				[](char c){return c == '-' || c == '>';}), 
//		line.end());
		std::stringstream line_input(line_raw_input);
		std::pair<int, int> coords;
		line_input >> coords.first >> coords.second;
		Point point_1(coords.first, coords.second);
        line_input >> coords.first >> coords.second;
		Point point_2(coords.first, coords.second);
		Line current_line(point_1, point_2);
//		if-else statement below is used to save diagonal lines for later
//		and separate results for part 1 and part 2. running draw_line on
//		all lines now would give result for part 2 only. 
		if (current_line.diagonal_up == true || current_line.diagonal_down == true)
			diagonal_points.push_back(current_line);
		else
			current_line.draw_line(arr);
	}
	std::cout << "Part 1: " << count_overlaps(arr) << std::endl;
	
	for (Line& diagonal : diagonal_points)
		diagonal.draw_line(arr);
    std::cout << "Part 2: " << count_overlaps(arr) << std::endl;
	
    return 0;
}