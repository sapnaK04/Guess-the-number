#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;
    const int maxAttempts = 10;

    cout << "Welcome to the Guess the Number Game!\n";
    cout << "I have selected a number between 1 and 100. Try to guess it.\n";

    while (attempts < maxAttempts) {
        cout << "Enter your guess: ";
        cin >> guess;

        // Check if the guess is correct
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number.\n";
            break;
        } else {
            cout << "Wrong guess. ";
            if (guess < secretNumber) {
                cout << "Try a higher number.\n";
            } else {
                cout << "Try a lower number.\n";
            }
        }

        attempts++;

        // Display remaining attempts
        cout << "Attempts left: " << maxAttempts - attempts << endl;
    }

    // If the player couldn't guess the number in time
    if (attempts == maxAttempts) {
        cout << "Sorry, you've run out of attempts. The correct number was: " << secretNumber << endl;
    }

    return 0;
}
