#include "source.hpp"

int count_overlaps(const int arr[ARRSIZE][ARRSIZE]){
	int ctr{0};
    for (int y = 0; y < ARRSIZE; y++){
		for (int x = 0; x < ARRSIZE; x++){
			if (arr[x][y] > 1)
				ctr++;
		} 
	}
	return ctr;
}

Line::Line(Point& point1, Point& point2){
	if (point1.x == point2.x){
		if (point1.y < point2.y){
			start = point1;
			finish = point2;
		} else { 
			start = point2;
			finish = point1;
		}
		vertical = true;
	} else {
		if (point1.x < point2.x){
			start = point1;
			finish = point2;
		} else {
			start = point2;
			finish = point1;
		}
		if (start.y < finish.y)
			diagonal_down = true;
		if (start.y > finish.y)
			diagonal_up = true;
		if (start.y == finish.y)
			horizontal = true;
	} 
}
	
void Line::draw_line(int arr[ARRSIZE][ARRSIZE]){
	if (horizontal == true){
		while (start.x <= finish.x){
			arr[start.x][start.y]++;
			start.x++;
		}
	}
	if (vertical == true){
		while (start.y <= finish.y){
			arr[start.x][start.y]++;
			start.y++;
		}
	}
	if (diagonal_down == true){
		while (start.x <= finish.x && start.y <= finish.y){
			arr[start.x][start.y]++;
			start.x++;
			start.y++;
		}
	}
	if (diagonal_up == true){
		while (start.x <= finish.x && start.y >= finish.y){
			arr[start.x][start.y]++;
			start.x++;
			start.y--;
		}
	}
};