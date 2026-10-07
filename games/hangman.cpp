#include "hangman.h"
#include <algorithm> // لتضمين std::find
#include <iostream>  // لتضمين std::cout و std::cin
#include <cctype>    // لتضمين std::toupper و std::isalpha
#include <vector>    // لتضمين std::vector
#include <cctype>
#include <iostream>
#include <vector>

#include "../common/ui.h"



namespace hangman {
    using namespace std;
    // ==========================================
    //  الشخص الثاني (Person 2 Task)
    //  المطلوب: read a letter, reject repeats
    // ==========================================

    char readValidLetter(const std::vector<char>& alreadyGuessed) {
        char input;
        while (true) {
            std::cout << "Enter a letter: ";
            std::cin >> input;
            input = std::toupper(input);

            if (!std::isalpha(input)) {
                std::cout << "Invalid input! Please enter a valid letter.\n";
                continue;
            }

            if (std::find(alreadyGuessed.begin(), alreadyGuessed.end(), input) != alreadyGuessed.end()) {
                std::cout << "You already guessed that letter! Try another one.\n";
                continue;
            }

            return input;
        }
    }


}  