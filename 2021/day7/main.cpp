#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

int main()
{
    std::fstream input_file("input");
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	std::string input_string_raw;
	getline(input_file, input_string_raw);
	std::replace(input_string_raw.begin(), input_string_raw.end(), ',', ' ');
	std::stringstream input_string(input_string_raw);
	
	int location {};
	std::vector<int> crab_locations {};
	while (input_string >> location)
		crab_locations.push_back(location);
			
	int min_loc = *std::min_element(crab_locations.begin(), crab_locations.end());
	int max_loc = *std::max_element(crab_locations.begin(), crab_locations.end());
	
	std::vector<int> total_fuel_cost {};
	for (int i = min_loc; i <= max_loc; i++){
		int fuel_needed{0};
		for (int location : crab_locations){
			int distance = std::abs(i-location);
			fuel_needed += distance;
		}
		total_fuel_cost.push_back(fuel_needed);
	}
	std::cout << "Part 1: " << *std::min_element(total_fuel_cost.begin(), total_fuel_cost.end()) << std::endl;
	
	total_fuel_cost.clear();
	for (int i = min_loc; i <= max_loc; i++){
		int fuel_needed{0};
		for (int location : crab_locations){
			int distance = std::abs(i-location);
			fuel_needed += (distance*(distance+1))/2;
		}
		total_fuel_cost.push_back(fuel_needed);
	}    
	std::cout << "Part 2: " << *std::min_element(total_fuel_cost.begin(), total_fuel_cost.end()) << std::endl;
	
	return 0;
}