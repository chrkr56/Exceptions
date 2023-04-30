#include <iostream>
#include <cctype>

class invalidRangeException : public std::exception {
};

class invalidCharacterException : public std::exception {
};

char character(char, int);

int main() {
	char inputChar;
	int inputOffset;
	while (true) {
		try {
		std::cout << "Input a character:> ";
		std::cin >> inputChar;
		std::cout << "Input an offset:> ";
		std::cin >> inputOffset;

		std::cout << "Resulting Character: " << character(inputChar, inputOffset) << '\n';
		}
		catch (invalidRangeException exception) {
			std::cout << "Caught InvalidRangeException\n";
			std::cout << "ERROR: Result Out of Range\n";
		}
		catch (invalidCharacterException exception) {
			std::cout << "Caught InvalidCharacterException\n";
			std::cout << "ERROR: Input Character Out of Range\n";
		}
	}
}

char character(char start, int offset) {
	if (!isalpha(start)) {
		throw invalidCharacterException();
	}
	if (!isalpha(start + offset) || islower(start) && isupper(start+offset) || isupper(start) && islower(start + offset)) {
		throw invalidRangeException();
	}
	return (start + offset);
}