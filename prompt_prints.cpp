#include <array>
#include <iostream>
#include<iomanip>
#include "prompt_prints.h"


//Takes a length and prints a line according to that length.
void printLine(int length) {
	std::cout << std::setw(10);
	for (int i{ 0 }; i < length; ++i)
		std::cout << '_';
	std::cout << "\n";
}




 void clearScreen() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}
