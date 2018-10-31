#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

void FBullCowGame::Reset()
{
	constexpr int32 MY_CURRENT_TRY = 1;
	FBullCowGame::MyCurrentTry = MY_CURRENT_TRY;
	
	constexpr int32 MY_MAX_TRIES = 8;
	FBullCowGame::MyMaxTries = MY_MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	FBullCowGame::MyHiddenWord = HIDDEN_WORD;
	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

//Receives a valid guess. Increements turn and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//Increement the turn number
	MyCurrentTry++;
	//Setup a return variable
	BullCowCount BullCowCount;

	//Loop through all letters in the guess
		//Compare letters against the input
	
	return BullCowCount;
}
