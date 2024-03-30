//
//  main.cpp
//  ROCK PAPER SCISSORS Game
//
//  Created by Nipuna Lakruwan
//

#include <iostream>
#include <ctime>

using namespace std;

// Enum to represent choices
enum Choice { ROCK = 'r', PAPER = 'p', SCISSORS = 's', EXIT = 'e'};

// Function to get the user's choice
Choice getUserChoice();

// Function to get the computer's choice
Choice getComputerChoice();

// Function to display the choice (rock, paper, scissors)
void showChoice(Choice choice);

// Function to determine the winner and display the result
void chooseWinner(Choice player, Choice computer);

int main(int argc, const char * argv[]) {

    // Declare variables to store user and computer choices
    Choice player;
    Choice computer;

    // Get user's choice
    player = getUserChoice();
    cout << "Your choice: ";
    showChoice(player);

    // Get computer's choice
    computer = getComputerChoice();
    cout << "Computer's choice: ";
    showChoice(computer);

    // Determine and display the winner
    chooseWinner(player, computer);

    return 0;
}

// Function to get the user's choice
Choice getUserChoice() {

    // Declare variable to store user's choice
    char choiceChar;

    // Display game instructions and get user input until a valid choice is made
    do {
        cout << "Rock-Paper-Scissors Game!\n";
        cout << "Choose one of the following\n";
        cout << "*************************\n";
        cout << "'r' for rock\n";
        cout << "'p' for paper\n";
        cout << "'s' for scissor\n";
        cout << "'e' for Exit\n";
        cin >> choiceChar;
    } while (choiceChar != 'r' && choiceChar != 'p' && choiceChar != 's' && choiceChar != 'e');

    // Convert the char to the corresponding Choice enum
    Choice player;
    switch (choiceChar) {
        case 'r':
            player = ROCK;
            break;
        case 'p':
            player = PAPER;
            break;
        case 's':
            player = SCISSORS;
            break;
        case 'e':
            player = EXIT;
    }

    return player;
}


// Function to get the computer's choice
Choice getComputerChoice() {

    // Generate a random number to represent the computer's choice (1-3)
    srand(static_cast<unsigned int>(time(0)));
    int num = rand() % 3 + 1;

    // Map the random number to a specific choice
    switch (num) {
        case 1: return ROCK;
        case 2: return PAPER;
        case 3: return SCISSORS;
    }

    return ROCK; // Default choice (not likely to be reached)
}

// Function to display the choice (rock, paper, scissors)
void showChoice(Choice choice) {

    // Display the corresponding choice based on the enum value
    switch (choice) {
        case ROCK:
            cout << "Rock\n";
            break;
        case PAPER:
            cout << "Paper\n";
            break;
        case SCISSORS:
            cout << "Scissor\n";
            break;
    }
}

// Function to determine the winner and display the result
void chooseWinner(Choice player, Choice computer) {

    // Compare user and computer choices to determine the winner
    if (player == computer) {
        cout << "It's a tie!\n";
    } else if ((player == ROCK && computer == SCISSORS) ||
               (player == PAPER && computer == ROCK) ||
               (player == SCISSORS && computer == PAPER)) {
        cout << "You win!\n";
    } else {
        cout << "You lose!\n";
    }
}
