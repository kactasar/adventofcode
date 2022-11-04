#include "Octopus.hpp"
#include "functions.hpp"

void Octopus::increase_power_level(){
	power_level++;
}
	
void Octopus::reset_power_level_if_flashed(){
	if (flashed == true){
		power_level = 0;
		flashed = false;
	}
}

int Octopus::return_power_level(){
	return power_level;
}

void Octopus::set_initial_conditions(int initial_power, int initial_x, int initial_y){
	power_level = initial_power;
	pos_x = initial_x;
	pos_y = initial_y;
}

//	If this octopus has sufficien power level and it hasn't flashed in this turn yet, this function changes 
//	it's bool value 'flashed' from false to true and raises power of all neighbours by 1. Function returns 
//	true if flash happened and false if it didn't.
bool Octopus::try_to_flash(Octopus** octopi_array){
	if (power_level > 9 && flashed == false){
		flashed = true;
		// Increase neighbours' power level by one with regards for array boundaries.
		if (pos_y > 0){
			octopi_array[pos_x][pos_y-1].increase_power_level();
		}
		if (pos_y > 0 && pos_x < X_SIZE-1){
			octopi_array[pos_x+1][pos_y-1].increase_power_level();
		}
		if (pos_x < X_SIZE-1){
			octopi_array[pos_x+1][pos_y].increase_power_level();
		}
		if (pos_x < X_SIZE-1 && pos_y < Y_SIZE-1){
			octopi_array[pos_x+1][pos_y+1].increase_power_level();
		}
		if (pos_y < Y_SIZE-1){
			octopi_array[pos_x][pos_y+1].increase_power_level();
		}
		if (pos_x > 0 && pos_y < Y_SIZE-1){
			octopi_array[pos_x-1][pos_y+1].increase_power_level();
		}
		if (pos_x > 0){
			octopi_array[pos_x-1][pos_y].increase_power_level();
		}
		if (pos_x > 0 && pos_y > 0){
			octopi_array[pos_x-1][pos_y-1].increase_power_level();
		}
		return true;
	} else {
		return false;
	}
}