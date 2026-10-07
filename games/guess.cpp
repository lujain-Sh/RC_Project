#include "guess.h"

#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

#include "../common/ui.h"

using namespace std;

namespace guess {

namespace {

struct Level {
    string name;
    int maxNumber;
    int maxAttempts;
};

void showBanner() {
    cout << "=====================================\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "=====================================\n\n";
}
}  // namespace

void play() {

}

}  // namespace guess