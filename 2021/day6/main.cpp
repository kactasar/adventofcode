#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <array>

#define DAYS_PART_1 80
#define DAYS_PART_2 256

uint64_t count_fish(const std::array<uint64_t, 2>& new_fish, 
					const std::array<uint64_t, 7>& grown_fish){
	uint64_t sum{0};
	std::for_each(grown_fish.begin(), grown_fish.end(), 
		[&sum] (uint64_t amount) { sum += amount; });
	std::for_each(new_fish.begin(), new_fish.end(), 
		[&sum] (uint64_t amount) { sum += amount; });
	return sum;
}

int main(){
	std::fstream input_file("input");
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	std::string input_string_raw;
	getline(input_file, input_string_raw);
	std::replace(input_string_raw.begin(), input_string_raw.end(), ',', ' ');
    std::stringstream input_string(input_string_raw);
	int phase{};
	std::array<uint64_t, 7> grown_fish = {0,0,0,0,0,0,0};
    while (input_string >> phase)
        grown_fish[phase]++;
	
    std::array<uint64_t, 2> new_fish = {0,0};
    uint64_t tmp {0};
    for (int i = 1; i <= DAYS_PART_2; i++){
        // save amount of fish that transition form new to grown 
		tmp = new_fish[0];
        // move new fish to next phase
		std::rotate(new_fish.begin(), new_fish.begin()+1, new_fish.end());
        // create amount of new fish equal to amount of grown fish in phase 0
		new_fish[1] = grown_fish[0];
        // move grown fish to next phase
		std::rotate(grown_fish.begin(), grown_fish.begin()+1, grown_fish.end());
        // add fish transitioning from new to grown
		grown_fish[6] += tmp;
		if (i == DAYS_PART_1)
			std::cout << "Part 1: " << count_fish(new_fish, grown_fish) << std::endl;
    }
    std::cout << "Part 2: " << count_fish(new_fish, grown_fish) << std::endl;
    
    return 0;
}