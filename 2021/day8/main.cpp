#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <array>
#include <map>

int main()
{
//	This is how digits are represented on seven-segment display:
//	
//	 ###    ```    ###    ###    ```    ###    ###    ###    ###    ###
//	#   #  `   #  `   #  `   #  #   #  #   `  #   `  `   #  #   #  #   #
//	#   #  `   #  `   #  `   #  #   #  #   `  #   `  `   #  #   #  #   #
//	 ```    ```    ###    ###    ###    ###    ###    ```    ###    ### 
//	#   #  `   #  #   `  `   #  `   #  `   #  #   #  `   #  #   #  `   #
//	#   #  `   #  #   `  `   #  `   #  `   #  #   #  `   #  #   #  `   #
//	 ###    ```    ###    ###    ```    ###    ###    ```    ###    ### 
//	
//	Representation below is created by counting how many times each 
//	individual segment occurs across all ten of them:
//	
//	 888
//	6   8
//	6   8
//	 777 
//	4   9
//	4   9
//	 777
//	
//	Each digit has different sum of it's segments frequency:
//	0 -> 42, 1 -> 17, 2 -> 34 and so on (stored in digit_by_segment_freq_sum). 
//	Reading the first part of line entry, that consists of all ten digits (unique_signal_patterns), 
//	is used to recreate this representation (segment_count). 
//  With this data the second part (four_digit_output_value) can be translated to digits it represents.
//	
	std::map<int, int> digit_by_segment_freq_sum{
		{42, 0},
		{17, 1},
		{34, 2},
		{39, 3},
		{30, 4},
		{37, 5},
		{41, 6},
		{25, 7},
		{49, 8},
		{45, 9},
	};
	
	std::fstream input_file("input");
	if(!input_file){
		std::cout << "Error: input file not found.\n";
		return 1;
	}
	
	int easy_digits_count{0};
	int output_value_sum{0};
	std::string input_string_raw {};
	while (getline(input_file, input_string_raw)){
		std::replace(input_string_raw.begin(), input_string_raw.end(), '|', ' ');
		std::stringstream input_string(input_string_raw);
		std::array<std::string, 10> unique_signal_patterns;
		for (int i = 0; i < 10; i++)
			input_string >> unique_signal_patterns[i];
		
		std::map<char, int> segment_count{{'a', 0},{'b', 0},{'c', 0},{'d', 0},{'e', 0},{'f', 0},{'g', 0}};
		for (std::string& digit : unique_signal_patterns){
			for (char& segment : digit)
				segment_count[segment]++;
		}
		
		std::array<std::string,4> four_digit_output_value;
		for (int i = 0; i < 4 ; i++)
			input_string >> four_digit_output_value[i];
		
//		Part 1 of challange:
		for (std::string& digit : four_digit_output_value){
			if (digit.size() == 2 || digit.size() == 3 || digit.size() == 4 || digit.size() == 7)
				easy_digits_count++;
		}
//		Back to part 2.
		
		int digit_0_segment_sum{0};
		for (char& segment : four_digit_output_value[0])
			digit_0_segment_sum += segment_count[segment];
		
		int digit_1_segment_sum{0};
		for (char& segment : four_digit_output_value[1])
			digit_1_segment_sum += segment_count[segment];
		
		int digit_2_segment_sum{0};
		for (char& segment : four_digit_output_value[2])
			digit_2_segment_sum += segment_count[segment];
		
		int digit_3_segment_sum{0};
		for (char& segment : four_digit_output_value[3])
			digit_3_segment_sum += segment_count[segment];
		
		output_value_sum += digit_by_segment_freq_sum[digit_0_segment_sum] * 1000 + 
							digit_by_segment_freq_sum[digit_1_segment_sum] * 100 + 
							digit_by_segment_freq_sum[digit_2_segment_sum] * 10 + 
							digit_by_segment_freq_sum[digit_3_segment_sum];
	}
	
	std::cout << "Part 1: " << easy_digits_count << std::endl;
	std::cout << "Part 2: " << output_value_sum << std::endl;
	
    return 0;
}