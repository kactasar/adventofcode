#include "functions.hpp"

inline void open_chunk(std::deque<char>& chunks, const char& syntax_char){
    chunks.push_back(syntax_char);
}

inline void close_last_chunk(std::deque<char>& chunks){
    chunks.pop_back();
}

void calculate_scores(std::fstream& input_file, int& syntax_score, std::vector<unsigned long long>& completion_scores){
	std::string input_string;
    while (getline(input_file, input_string)){
        bool line_corrupted {false};
        std::deque<char> chunks {};
//		Function below reads characters form input line in order. If character opens new chunk ("left" characters)
//		then new chunk in deck is opened, if character is a closing character it is compared to last element in 
//		the deque to check whether clousure is correct. If it is, chunk is closed (removed form deque), otherwise 
//		line is corrupted, score for first part of challenge is updated and new line is passed into the function.
		for (char syntax_char : input_string){
            if (syntax_char == ')' || syntax_char == ']' || syntax_char == '}' || syntax_char == '>'){
                if (!compare_to_last_chunk(chunks, syntax_char)){
                    add_syntax_error_points(syntax_score, syntax_char);
                    line_corrupted = true;
                    break;
                } else{
                    close_last_chunk(chunks);
                }
            } else{
                open_chunk(chunks, syntax_char);
            }
        }
//		If line is not corrupted then score for second part is calculated. For every character left in the deque, score
//		is updated according to rules of the challenge and chunks are closed in reverse order they were created (LIFO).
        if (!line_corrupted){
            completion_scores.push_back(0);
            while(!chunks.empty()){
                switch (chunks.back()){
                    case '(':
                        completion_scores.back() *= 5;
                        completion_scores.back() += 1;
                        close_last_chunk(chunks);
                        continue;
                    case '[':
                        completion_scores.back() *= 5;
                        completion_scores.back() += 2;
                        close_last_chunk(chunks);
                        continue;
                    case '{':
                        completion_scores.back() *= 5;
                        completion_scores.back() += 3;
                        close_last_chunk(chunks);
                        continue;
                    case '<':
                        completion_scores.back() *= 5;
                        completion_scores.back() += 4;
                        close_last_chunk(chunks);
                        continue;
                    default:
                        std::cout << "Error in completion score calculation." << std::endl;
                        break;
                }
            }
        }
    }
}

//	If syntax_char is proper closure for last character in chunks deck, function returns true and false otherwise.
bool compare_to_last_chunk(std::deque<char>& chunks, const char& syntax_char){
    if (chunks.size() == 0)
        return false;
    switch (chunks.back()){
        case '(':
            if (syntax_char == ')')
                return true;
            return false;
        
		case '[':
            if (syntax_char == ']')
                return true;
            return false;
            
        case '{':
            if (syntax_char == '}')
                return true;
            return false;
            
        case '<':
            if (syntax_char == '>')
                return true;
            return false;
            
        default:
            std::cout << "ERROR: unexpected character in deque." << std::endl;
            return false;
    }
}

void add_syntax_error_points(int& syntax_score, const char& syntax_char){
    switch (syntax_char){
        case ')':
            syntax_score += 3;
            break;
        case ']':
            syntax_score += 57;
            break;
        case '}':
            syntax_score += 1197;
            break;
        case '>':
            syntax_score += 25137;
            break;
    }
}