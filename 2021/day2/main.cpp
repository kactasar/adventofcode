#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::fstream input_file("input");
	
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	int xpart1{0}, ypart1{0};
	int xpart2{0}, ypart2{0}, aim{0};
	
	std::string command;
	int value;
	while (input_file >> command){
		input_file >> value;
		if (command == "forward"){
			//Part 1 calculations:
			xpart1 += value;
			//Part 2 calculations:
			xpart2 += value;
			ypart2 += aim*value;
			continue;
		}
		if (command == "down"){
			//Part 1 calculations:
			ypart1 += value;
			//Part 2 calculations:
			aim += value;
			continue;
		}
		if (command == "up"){
			//Part 1 calculations:
			ypart1 -= value;
			//Part 2 calculations:
			aim -= value;
			continue;
		}
		std::cout << "Error: unknown command: " << command << std::endl;
		return 1;
	}
	
	std::cout << "Part 1: " << xpart1*ypart1 << std::endl;
	std::cout << "Part 2: " << xpart2*ypart2 << std::endl;
	
	return 0;
}
