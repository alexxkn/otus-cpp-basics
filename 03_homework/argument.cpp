#include "argument.h"
#include "high_scores.h"
#include <getopt.h>
#include <iostream>
#include <string>

int max_num = 100;
int level = 0;

void print_help() {
    std::cout <<
			"                     Without arguments, the game will start with a hidden number not exceeding 100\n"
            "--help:              Show help\n"
            "--level <n>:         Set the difficulty level: 1 - max number 10, 2 - max number 100, 3 - max number 1000\n"
            "--max <n>:           Set the maximum value for the hidden number\n"
            "--table:             Show record table\n";
    exit(1);
}

int handling_argument(int argc, char** argv) {
	const char* const short_opts = "m:l:th";
    const option long_opts[] = {
            {"max", required_argument, nullptr, 'm'},
            {"table", no_argument, nullptr, 't'},
            {"level", required_argument, nullptr, 'l'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt) {
            case 'm':
                max_num = std::stoi(optarg);
                std::cout << "The maximum value for the hidden number: " << max_num << std::endl;
                break;

            case 't':
                read_score();
                exit(0);

            case 'l':
                level = std::stoi(optarg);
                std::cout << "Difficulty level set to: " << level << std::endl;
                if (level == 1) {
                    max_num = 10;
                }
                else if (level == 2) {
                    max_num = 100;
                }
                else if (level == 3) {
                    max_num = 1000;
                }
                else {
                    std::cout << "Wrong level: you shoud set 1, 2 or 3" << std::endl;
                    exit(1);
                };
                std::cout << "Set the maximum value for the hidden number to: " << max_num << std::endl;
                break;

            case 'h':
            case '?':
            default:
                print_help();
                break;
        }
    }
    return max_num;
}