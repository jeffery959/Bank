#ifndef Scrible_1_2_23_2026_prompt_prints
#define Scrible_1_2_23_2026_prompt_prints

#include <stddef.h>
#include <array>
#include <string_view>
//Prints Options
template <std::size_t N>
inline void printOptions(const std::array<std::string_view, N>& arr) {

	for (std::size_t i{ 0 }; i < std::size(arr); ++i) {
		std::cout << i << "." << arr[i] << '\n';
	}
}


//Takes a int and prints a line(_) x amoumt time consecutive.
 void printLine(int length);

//Takes in a list of Options and prompts the user for an input

template <std::size_t T>
inline char promptNOptions(const std::array<std::string_view, T>& Options) {


	char x{};
	std::cout << '\n';
	printOptions(Options);
	std::cout << "Enter Options: ";
	while (true) {
		std::cin >> x;

		if (!std::cin.eof() && std::cin.peek() != '\n') {
			std::cout << "Too many inputs: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;

		}

		if (!std::cin) {
			if (std::cin.eof()) {
				std::exit(0);
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;

		}

		if (x<'0' || x>((std::size(Options) - 1) + '0')) {
			std::cout << "Invalid Option: ";
			continue;
		}
		//No extra inputs , not in a failed state or selected a good choice exit loop
		break;
	}

	return x;

}

//Clears terminal screeen
 void clearScreen();









#endif
