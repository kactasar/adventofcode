#pragma once
#define ARRSIZE 1000

int count_overlaps(const int arr[ARRSIZE][ARRSIZE]);

struct Point{
	int x;
	int y;
	Point(int& x_input, int& y_input): x{x_input}, y{y_input} {};
	Point() = default;
};

struct Line{
	Point start;
	Point finish;
	bool vertical{false};
	bool horizontal{false};
	bool diagonal_down{false};
	bool diagonal_up{false};
	
	Line(Point& first_point, Point& second_point);
	void draw_line(int arr[ARRSIZE][ARRSIZE]);
};