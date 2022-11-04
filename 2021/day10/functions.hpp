#include <deque>
#include <vector>
#include <fstream>
#include <iostream>

#pragma once

void open_chunk(std::deque<char>& chunks, const char& syntax_char);
void close_last_chunk(std::deque<char>& chunks);
void calculate_scores(std::fstream& input_file, int& syntax_score, std::vector<unsigned long long>& completion_scores);
bool compare_to_last_chunk(std::deque<char>& chunks, const char& syntax_char);
void add_syntax_error_points(int& syntax_score, const char& syntax_char);






