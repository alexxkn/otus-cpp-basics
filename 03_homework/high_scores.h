#pragma once
#include <string>

int save_score(std::string username, int score, std::string filename="high_scores.txt");
int read_score(std::string filename="high_scores.txt");
