#pragma once
// Small helpers shared by every game.

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

// Thrown when the input stream ends (Ctrl+D / Ctrl+Z or a closed pipe).
// main() catches it so the program exits cleanly instead of looping forever.
struct InputClosed {};

inline void clearScreen() {
#ifdef _WIN32
    int result = std::system("cls");
#else
    int result = std::system("clear");
#endif
    (void)result;  // we do not care if clearing the screen fails
}

// Reads one full line. Always use this instead of `cin >> x`,
// because it never leaves the input stream in a broken state.
inline std::string readLine() {
    std::string line;
    if (!std::getline(std::cin, line)) throw InputClosed{};
    if (!line.empty() && line.back() == '\r') line.pop_back();
    return line;
}

// (Named waitForEnter, not pause, because pause() already exists on Linux/macOS.)
inline void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cout.flush();
    readLine();
}

inline std::string trim(const std::string& s) {
    std::size_t a = 0, b = s.size();
    while (a < b && std::isspace(static_cast<unsigned char>(s[a]))) ++a;
    while (b > a && std::isspace(static_cast<unsigned char>(s[b - 1]))) --b;
    return s.substr(a, b - a);
}

// Safe text -> int. Returns false for anything that is not a whole number.
inline bool parseInt(const std::string& text, int& out) {
    std::string s = trim(text);
    if (s.empty() || s.size() > 9) return false;
    std::size_t start = (s[0] == '-') ? 1 : 0;
    if (start == s.size()) return false;
    for (std::size_t i = start; i < s.size(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    out = std::stoi(s);
    return true;
}

inline std::mt19937& rng() {
    static std::mt19937 gen{std::random_device{}()};
    return gen;
}

// Random integer in [low, high], both included.
inline int randomInt(int low, int high) {
    std::uniform_int_distribution<int> dist(low, high);
    return dist(rng());
}
