#include "functions.hpp"

void populate_octopi_array(std::fstream& input_file, Octopus** octopi_array){
	std::string line{};
	int y{0};
	while (getline(input_file, line)){
		for (int x = 0 ; x < X_SIZE ; x++){
//			'line[x]-48' converts digit character to integer value it represents. 
			octopi_array[x][y].set_initial_conditions(line[x]-48, x, y);
		}
		y++;
	}
}

int evolve_array_for_n_turns(Octopus** octopi_array, const int& n){
	int total_flashes{0};
	for (int turn = 0 ; turn < n ; turn++){
		first_step(octopi_array);
		second_step(octopi_array, total_flashes);
		third_step(octopi_array);
	}
	return total_flashes;
}

int evolve_array_until_in_sync(Octopus** octopi_array){
	int n_turn{STEPS};
	not_in_sync:
		n_turn++;
		first_step(octopi_array);
		second_step(octopi_array);
		third_step(octopi_array);
		for(int y = 0 ; y < Y_SIZE ; y++){
			for(int x = 0 ; x < X_SIZE ; x++){
				if (octopi_array[x][y].return_power_level() != 0)
					goto not_in_sync;
			}
		}
	return n_turn;
}

//	Raise power level of every octopus in the array.
void first_step(Octopus** octopi_array){
	for(int y = 0 ; y < Y_SIZE ; y++){
		for(int x = 0 ; x < X_SIZE ; x++){
			octopi_array[x][y].increase_power_level();
		}
	}
}

//	This step is repeated every time at least one flash happened as flash changes power level of other
//	octopi potentially triggering another flash. Function is overloaded to provide total_flashes count
//	for part 1 of the challenge.
void second_step(Octopus** octopi_array){
	bool still_flashing;
	do {
		still_flashing = false;
		for(int y = 0 ; y < Y_SIZE ; y++){
			for(int x = 0 ; x < X_SIZE ; x++){
				if (octopi_array[x][y].try_to_flash(octopi_array))
					still_flashing = true;
			}
		}	
	} while (still_flashing == true);
}

void second_step(Octopus** octopi_array, int& total_flashes){
	bool still_flashing {false};
	do {
		still_flashing = false;
		for(int y = 0 ; y < Y_SIZE ; y++){
			for(int x = 0 ; x < X_SIZE ; x++){
				if (octopi_array[x][y].try_to_flash(octopi_array)){
					total_flashes++;
					still_flashing = true;
				}
			}
		}	
	} while (still_flashing == true);
}

//	Reset power level to 0 for every octopus that has flashed.
void third_step(Octopus** octopi_array){
	for(int y = 0 ; y < Y_SIZE ; y++){
		for(int x = 0 ; x < X_SIZE ; x++){
			octopi_array[x][y].reset_power_level_if_flashed();
		}
	}
}
