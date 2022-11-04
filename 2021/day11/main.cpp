#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Octopus.hpp"
#include "functions.hpp"

int main(){	
	std::fstream input_file("/home/eryk/prog/2021/day11/input");
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	Octopus** octopi_array = new Octopus* [X_SIZE];
	for (size_t x = 0 ; x < X_SIZE ; x++){
		octopi_array[x] = new Octopus [Y_SIZE];
	}
	populate_octopi_array(input_file, octopi_array);
	
	std::cout << "Part 1: " << evolve_array_for_n_turns(octopi_array, STEPS) << std::endl;
	std::cout << "Part 2: " << evolve_array_until_in_sync(octopi_array) << std::endl;
	
	for (size_t x = 0 ; x < X_SIZE ; x++){
		delete [] octopi_array[x];
	}
	delete [] octopi_array;
	
	return 0;
}