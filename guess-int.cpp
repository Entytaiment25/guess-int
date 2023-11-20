#include "includes.h"
#include <iostream>
#include <random>

namespace cpp {

    template <typename T>
    T getRandomNumber(T min, T max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> distribution(min, max);
        return distribution(gen);
    }

}

constexpr int MAX_TRIES = 5;
constexpr int RANGE_MIN = 1;
constexpr int RANGE_MAX = 100;

int getUserGuess() {
    int guess;
    std::cout << "Enter your guess (" << RANGE_MIN << "-" << RANGE_MAX << "): ";

    while (true) {
        // Try to read an integer
        if (std::cin >> guess) {
            // Check if the input is within the specified range
            if (guess >= RANGE_MIN && guess <= RANGE_MAX) {
                break; // Valid input, exit the loop
            } else {
                std::cout << "Please enter a valid integer within the specified range.\n";
            }
        } else {
            std::cout << "Invalid input. Please enter a valid integer.\n";
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters in the input buffer
        }
    }

    return guess;
}

void provideFeedback(const int guess, const int secretNumber, const int tries) {
    if (guess > secretNumber) {
        std::cout << "Too high! ";
    } else if (guess < secretNumber) {
        std::cout << "Too low! ";
    } else {
        std::cout << "Congratulations! You guessed the secret number in " << tries << " tries.\n\n";
        std::exit(0);
    }

    std::cout << "Tries left: " << MAX_TRIES - tries << "\n";

    if (std::abs(guess - secretNumber) <= 10) {
        std::cout << "You're getting close!\n\n";
    }
}

int main() {
    const int secretNumber = cpp::getRandomNumber(RANGE_MIN, RANGE_MAX);
    int tries = 0;

    std::cout << "Welcome to the integer guessing game!\n\n";

    while (tries < MAX_TRIES) {
        const int guess = getUserGuess();
        tries++;
        provideFeedback(guess, secretNumber, tries);
    }

    std::cout << "Sorry, you have reached the maximum number of tries. The secret number was " << secretNumber << ".\n\n";

    return 0;
}
