cmake_minimum_required(VERSION 3.5)

project(03.homework)

add_executable(
	guess_the_number
	argument.cpp
	argument.h
	guess_the_number.cpp
	check_value.cpp
	check_value.h
	high_scores.cpp
	high_scores.h
	random_value.cpp
	random_value.h
)
