/*
This is the Console executible that makes use of bull cow class.
This acts as a view in a MVC pattern and is responsible for all user interaction.
For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame BCGame; //instantiate a new game

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetValidGuess();
void PrintGameSummary();

//the entry point for our application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	}
	while (AskToPlayAgain());
	return 0;
}

//introduce the game
void PrintIntro()
{
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}

//Loop continually until the user gives a valid guess
FText GetValidGuess()
{
	EGuessWordStatus status = EGuessWordStatus::INVALID_STATUS;
	FText Guess = "";
	do
	{
		//Get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try "<<CurrentTry<<". Enter your Guess: ";
		std::getline(std::cin, Guess);

		status = BCGame.CheckGuessValidity(Guess);
		switch (status)
		{
		case EGuessWordStatus::NOT_ISOGRAM:
			std::cout << "Please enter a word without repeating letters!\n";
			break;
		case EGuessWordStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word\n";
			break;
		case EGuessWordStatus::NOT_LOWERCASE:
			std::cout << "Please enter all lowercase letters!\n";
			break;
		default:
			break;
		}
	}
	while (status != EGuessWordStatus::OK); // Keep looping until we get no errors
	return Guess;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop asking for guesses
	//and there are still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << "\n";
		std::cout << "Cows = " << BullCowCount.Cows << "\n";

		std::cout << "Your Guess was: " << Guess << "\n";
	}

	//TODO Summerise game here
	PrintGameSummary();
	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon)
	{
		std::cout << "WELL DONE! - YOU WIN! \n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}

	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}