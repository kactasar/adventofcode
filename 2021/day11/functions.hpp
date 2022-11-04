#include <fstream>
#include "Octopus.hpp"

#pragma once

//	Dimensions for an array
#define X_SIZE 10
#define Y_SIZE 10
//	Steps in first part of the challenge.
#define STEPS 100

void populate_octopi_array(std::fstream& input_file, Octopus** octopi_array);
void first_step(Octopus** octopi_array);
void second_step(Octopus** octopi_array);
void second_step(Octopus** octopi_array, int& total_flashes);
void third_step(Octopus** octopi_array);
int evolve_array_for_n_turns(Octopus** octopi_array, const int& n);
int evolve_array_until_in_sync(Octopus** octopi_array);
