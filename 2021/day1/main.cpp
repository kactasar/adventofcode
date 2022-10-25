#include <iostream>
#include <fstream>
#include <vector>

int main(){
	std::fstream input_file("input");
	std::vector<int> input_vector;
	
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	while(!input_file.eof()){
		int tmp;
		input_file >> tmp;
		input_vector.push_back(tmp);
	}
	
	int count1{0};
	for (auto i = input_vector.begin() ; i < input_vector.end()-1 ; i++){
		if (*i < *(i+1))
			count1++;
	}
	
	int count2{0};
	for (auto i = input_vector.begin() ; i < input_vector.end()-4 ; i++){
		if ( (*i + *(i+1) + *(i+2)) < (*(i+1) + *(i+2) + *(i+3)) )
			count2++;
	}
	
	std::cout << "Part 1: " << count1 << std::endl;
	std::cout << "Part 2: " << count2 << std::endl;
	
	return 0;
}
