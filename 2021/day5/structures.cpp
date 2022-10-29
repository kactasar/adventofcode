struct Line{
	Point start;
	Point finish;
	bool vertical{false};
	bool horizontal{false};
	bool diagonal_down{false};
	bool diagonal_up{false};
	
	Line(Point& first_point, Point& second_point){
		if (first_point.x == second_point.x){
			if (first_point.y < second_point.y){
				start = first_point;
				finish = second_point;
			} else { 
				start = second_point;
				finish = first_point;
			}
			vertical = true;
		} else {
			if (first_point.x < second_point.x){
				start = first_point;
				finish = second_point;
			} else {
				start = second_point;
				finish = first_point;
			}
			if (start.y < finish.y)
				diagonal_down = true;
			if (start.y > finish.y)
				diagonal_up = true;
			if (start.y == finish.y)
				horizontal = true;
		} 
	}
	
	void draw_line(int arr[1000][1000]){
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
	}
};