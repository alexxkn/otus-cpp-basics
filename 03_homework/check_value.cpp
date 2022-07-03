#include "check_value.h"
#include <iostream>
#include <limits>

int check_value(int hidden_number) {

	bool user_win = false;
	int current_value = 0;
	int score = 0;
	int target_value = hidden_number;

	do {
		score++;
		bool valid_input = false;
		std::cout << "Enter your number:" << std::endl;
		do {
			std::cin >> current_value;
			if (std::cin.good()) {
				valid_input = true;
			} else {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				std::cout << "Invalid input, please re-enter integer." << std::endl;
			}
		} while (!valid_input);

		if (current_value < target_value) {
			std::cout << "My hidden number is greater than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "My hidden number is less than " << current_value << std::endl;
		}
		else {
			std::cout << "Congratulations! You win in " << score << " steps!" << std::endl;
			user_win = true;
			break;
		}

	} while(!user_win);

	return score;
}