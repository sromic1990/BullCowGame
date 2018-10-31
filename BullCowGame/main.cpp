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
FText GetGuess();

//the entry point for our application
int main()
{
	PrintIntro();
	do
	{
		PlayGame();
	}
	while (AskToPlayAgain());
	return 0;
}

//introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	//Get a guess from the player
	FText Guess = "";
	std::cout << "Try "<<CurrentTry<<". Enter your Guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns asking for guesses
	//TODO Change from FOR to WHILE loop  once we are validating tries
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess();//TODO make loop checking valid
		
		//Submit valid guess to the game
		//Print number of bulls and cows

		std::cout << "Your Guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	//TODO Summerise game here
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}