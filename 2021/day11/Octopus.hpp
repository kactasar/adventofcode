#pragma once

class Octopus {
private:
	bool flashed = false;
	int power_level {0};
	int pos_x {};
	int pos_y {};
public:
	void increase_power_level();
	void reset_power_level_if_flashed();
	int return_power_level();
	void set_initial_conditions(int initial_power, int initial_x, int initial_y);
	bool try_to_flash(Octopus** octopi_array);
	Octopus() = default;
	~Octopus() = default;
};