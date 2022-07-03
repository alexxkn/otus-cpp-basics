#include "high_scores.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>

int save_score(std::string username, int score, std::string filename) {

	bool new_record = true;
	std::fstream record_file;

	record_file.open(filename, std::ios::app);
	if (!record_file.is_open()) {
		std::cout << "Failed to open file: " << filename << "!" << std::endl;
		return 1;
	}
  	record_file.close();

  	record_file.open(filename, std::ios::in);
	std::vector<std::string> data;
	std::string str;
	while(getline(record_file, str)) {
		std::size_t found = str.find(username);
		if (found!=std::string::npos) {
			int sc = std::stoi(str.substr (username.length() + 1));
			std::cout << sc <<std::endl;
			if (score < sc) {
				str = username + " " + std::to_string(score);
			}
			new_record = false;
		}
		data.push_back(str);
	}
	
	if (new_record) {
		data.push_back(username + " " + std::to_string(score));
	}
	record_file.close();

	record_file.open(filename, std::ios::out);
	for(int i=0; i<data.size(); i++) {
		std::cout << data[i]<<std::endl;
		record_file.clear();
		record_file<<data[i]<<std::endl;
	}
	record_file.close();
	return 0;
}

int read_score(std::string filename) {
	std::fstream record_file;

	record_file.open(filename, std::ios::in);
	if (!record_file.is_open()) {
		std::cout << "Failed to open file for read: " << filename << "!" << std::endl;
		return 1;
	}
	std::vector<std::string> data;
	std::string str;
	while(getline(record_file, str)) {
		data.push_back(str);
	}
	record_file.close();

	std::cout << "High scores table:" << std::endl;
	for(int i=0; i<data.size(); i++) {
		std::cout << data[i] << std::endl;
	}

	return 0;
}