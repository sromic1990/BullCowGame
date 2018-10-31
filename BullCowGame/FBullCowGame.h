#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//two integers initialized to 0
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

class FBullCowGame
{
public:
	FBullCowGame(); //ctor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); //TODO make a more rich return value
	bool CheckGuessValidity(FString);
	BullCowCount SubmitGuess(FString);

private:
	//See ctor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
