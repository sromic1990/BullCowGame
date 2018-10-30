#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

void FBullCowGame::Reset()
{
	constexpr int MY_CURRENT_TRY = 1;
	constexpr int MY_MAX_TRIES = 8;
	
	FBullCowGame::MyCurrentTry = MY_CURRENT_TRY;
	FBullCowGame::MyMaxTries = MY_MAX_TRIES;
	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
