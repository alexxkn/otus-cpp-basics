#include "argument.h"
#include "check_value.h"
#include "high_scores.h"
#include "random_value.h"
#include <string>
#include <iostream>

int main(int argc, char **argv) {
    int max_hidden_number = handling_argument(argc, argv);

	std::string stdin_username = "";
	std::cout << "Enter your name:" << std::endl;
	std::getline(std::cin, stdin_username);
	std::cout << "Hello, " << stdin_username << "! Let's play a game!" << std::endl;
	std::cout << "Please, guess the number I guessed." << std::endl;

    int score = check_value(get_random_value(max_hidden_number));

    save_score(stdin_username, score);
    // read_score();
    return 0;
}
