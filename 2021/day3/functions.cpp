#include "functions.hpp"

size_t count_ones_at_pos_i_in_vec(const size_t& i, const std::vector<std::string>& vec){
	size_t count{0};
	for (std::string line : vec){
		if (line[i] == '1')
			count += 1;
	}
	return count;
}

int binary_str_to_int(const std::string& str){
	int value{0};
	for (size_t i = 0 ; i < str.size() ; i++){
		if (str[i] == '1')
			value += pow(2, str.size()-1 - i);
	}
	return value;
}

std::string find_string_by_bit_criteria (std::vector<std::string> vec, char preferred_char){
	for(size_t i = 0 ; i < vec.front().size() ; i++){
		if (vec.size() == 1)
			break;
		double ones_at_i = count_ones_at_pos_i_in_vec(i, vec);
		auto it = vec.begin();
		if (ones_at_i < (double)vec.size()/2){
			while(it != vec.end()){
				if ((*it)[i] == preferred_char)
					vec.erase(it);
				else
					it++;
			}
		} else {
			while(it != vec.end()){
				if ((*it)[i] != preferred_char)
					vec.erase(it);
				else
					it++;
			}
		}
	}
	return vec.front();
}