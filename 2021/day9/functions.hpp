#include <stdlib.h>
#include <vector>

#define INPUT_SIZE_X 100
#define INPUT_SIZE_Y 100

struct Point{
    int height;
    bool is_part_of_basin {false};
};

bool is_lowest_point(Point** datapoints, size_t& x_cord, size_t& y_cord);
void create_new_basin(const size_t& x_cord, const size_t& y_cord, Point** datapoints, std::vector<int>& basins_sizes);
void check_adjacent_points(const size_t x_cord, const size_t y_cord, Point** datapoints, std::vector<std::pair<int, int>>& valid_points);