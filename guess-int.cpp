#include "fxmanifest.h" // Include the header file

using namespace cpp;

int main()
{
	srand(time(nullptr)); // seed random number generator
	const int MAX_TRIES = 5;
	int secretNumber = rand() % 100 + 1; // random number between 1 and 100
	int tries = 0;

	cout << "Welcome to the integer guessing game!\n\n";

	while (tries < MAX_TRIES)
	{
		int guess;
		cout << "Enter your guess (1-100): ";
		cin >> guess;
		tries++;

		if (guess > secretNumber)
		{
			cout << "Too high! Try again.\n\n";
		}
		else if (guess < secretNumber)
		{
			cout << "Too low! Try again.\n\n";
		}
		else
		{
			cout << "Congratulations! You guessed the secret number in " << tries << " tries.\n\n";
			return 0;
		}

		if (abs(guess - secretNumber) <= 10)
		{
			cout << "You're getting close!\n\n";
		}
	}

	cout << "Sorry, you have reached the maximum number of tries. The secret number was " << secretNumber << ".\n\n";

	return 0;
}
