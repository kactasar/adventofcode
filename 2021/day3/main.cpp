#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"

int main(){
	std::fstream input_file("input");
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	std::vector<std::string> input_vector;
	std::string tmp;
	while (input_file >> tmp)
		input_vector.push_back(tmp);
	
	std::string gamma_binary{};
	std::string epsilon_binary{};
	for (size_t i = 0 ; i < input_vector.front().size() ; i++){
		size_t count = count_ones_at_pos_i_in_vec(i, input_vector);
		if (count > input_vector.size()/2){
			gamma_binary.push_back('1');
			epsilon_binary.push_back('0');
		}
		else {
			gamma_binary.push_back('0');
			epsilon_binary.push_back('1');
		}
	}
	std::cout << "Part 1: " << binary_str_to_int(gamma_binary) * binary_str_to_int(epsilon_binary) << std::endl;

	std::string oxygen_rate_str = find_string_by_bit_criteria(input_vector, '1');
	std::string co2_rate_str = find_string_by_bit_criteria(input_vector, '0');
	std::cout << "Part 2: " << binary_str_to_int(oxygen_rate_str) * binary_str_to_int(co2_rate_str) << std::endl;
	
	return 0;
}
