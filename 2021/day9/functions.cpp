#include "functions.hpp"

//	returns true for points that are lower than any of their neighbours
bool is_lowest_point(Point** datapoints, size_t& x_cord, size_t& y_cord){
    if (x_cord > 0){
    if (datapoints[x_cord][y_cord].height >= datapoints[x_cord-1][y_cord].height)
            return false;
    }
    if (x_cord < 99){
        if (datapoints[x_cord][y_cord].height >= datapoints[x_cord+1][y_cord].height)
            return false;        
    }
    if (y_cord > 0){
        if (datapoints[x_cord][y_cord].height >= datapoints[x_cord][y_cord-1].height)
            return false;
    }
    if (y_cord < 99){
        if (datapoints[x_cord][y_cord].height >= datapoints[x_cord][y_cord+1].height)
            return false;        
    }
    return true;
}

void create_new_basin(const size_t& x_cord, const size_t& y_cord, Point** datapoints, std::vector<int>& basins_sizes){
//	Push back new basin size into the vector, initial size is 1 as this is the first point of the new basin.
//	Change first point's bool value to true as it was just assigned to a basin. Create vector of coordinates
//	for points that are also part of this new basin.
	basins_sizes.push_back(1);
    datapoints[x_cord][y_cord].is_part_of_basin = true;
    std::vector<std::pair<int, int>> valid_points{};
//	Populate valid_points vector with coordinates of points adjacent to the first point that meet the criteria.
//	Repeat this for every point in the vector, increasing basin size for each of them, until no new points can 
//	be found and basin is complete.
    check_adjacent_points(x_cord, y_cord, datapoints, valid_points);
    for (size_t i = 0, valid_points_count = valid_points.size() ; i < valid_points_count ; i++){
        if (datapoints[valid_points[i].first][valid_points[i].second].is_part_of_basin == false){
            basins_sizes.back() += 1;
            datapoints[valid_points[i].first][valid_points[i].second].is_part_of_basin = true;
            check_adjacent_points(valid_points[i].first, valid_points[i].second, datapoints, valid_points);
			valid_points_count = valid_points.size();
        }
    }
}

//	Checks points adjacent to passed in point, with regards for array boundaries.
//	Point meets criteria if it's height is lower than 9 (points with height of 9 are not part of any 
//	basin), and if it is not part of any other basin already. Valid points are pushed back into the vector.
void check_adjacent_points(const size_t x_cord, const size_t y_cord, Point** datapoints, std::vector<std::pair<int, int>>& valid_points){
    if (y_cord > 0){
        if (datapoints[x_cord][y_cord-1].height < 9 && datapoints[x_cord][y_cord-1].is_part_of_basin == false)
                valid_points.push_back(std::pair<int, int> (x_cord, y_cord-1));
	}
    if (x_cord < INPUT_SIZE_X - 1){
        if (datapoints[x_cord+1][y_cord].height < 9 && datapoints[x_cord+1][y_cord].is_part_of_basin == false)
                valid_points.push_back(std::pair<int, int> (x_cord+1, y_cord));
    }
    if (y_cord < INPUT_SIZE_Y - 1){
        if (datapoints[x_cord][y_cord+1].height < 9 && datapoints[x_cord][y_cord+1].is_part_of_basin == false)
                valid_points.push_back(std::pair<int, int> (x_cord, y_cord+1));
    }
    if (x_cord > 0){
        if (datapoints[x_cord-1][y_cord].height < 9 && datapoints[x_cord-1][y_cord].is_part_of_basin == false)
                valid_points.push_back(std::pair<int, int> (x_cord-1, y_cord));
    }
}