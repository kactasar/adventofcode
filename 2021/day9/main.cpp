#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "functions.hpp"

int main()
{	
	std::fstream input_file("/home/eryk/prog/2021/day9/input");
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	Point** datapoints;
	datapoints = new Point* [INPUT_SIZE_X];
	for (size_t i = 0 ; i < INPUT_SIZE_X ; i++){
		datapoints[i] = new Point [INPUT_SIZE_Y];
	}
	
	std::string input_string {};
	for (size_t y_cord = 0; y_cord < INPUT_SIZE_Y; y_cord++){
		getline(input_file, input_string);
		for (size_t x_cord = 0; x_cord < INPUT_SIZE_X; x_cord++){
//			(-48): coverting digit character to its value as an integer
			datapoints[x_cord][y_cord].height = input_string[x_cord]-48;
		}
	}
	
	int sum_of_low_points{0};
	for (size_t y_cord = 0; y_cord < INPUT_SIZE_Y; y_cord++){
		for (size_t x_cord = 0; x_cord < INPUT_SIZE_X; x_cord++){
			if (is_lowest_point(datapoints, x_cord, y_cord)){
				sum_of_low_points += datapoints[x_cord][y_cord].height+1;
			}
		}
	}
	std::cout << "Part 1: " << sum_of_low_points << std::endl;
	
	std::vector<int> basins_sizes{};
	bool all_points_asigned_to_basins {false};
	while (all_points_asigned_to_basins == false){
		for (size_t y_cord = 0; y_cord < INPUT_SIZE_Y; y_cord++){
			for (size_t x_cord = 0; x_cord < INPUT_SIZE_X; x_cord++){
				if (datapoints[x_cord][y_cord].height != 9 && 
					datapoints[x_cord][y_cord].is_part_of_basin == false){
						create_new_basin(x_cord, y_cord, datapoints, basins_sizes);
						continue;
				}
			}
		}
		all_points_asigned_to_basins = true;
	}
	std::sort(basins_sizes.begin(), basins_sizes.end());
	std::cout << "Part 2: " << (*basins_sizes.rbegin()) * (*(basins_sizes.rbegin()+1)) * (*(basins_sizes.rbegin()+2)) << std::endl;
	
	for (size_t i = 0 ; i < INPUT_SIZE_X ; i++)
		delete [] datapoints[i];
	delete [] datapoints;
	return 0;
}
