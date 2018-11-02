#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//two integers initialized to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EGuessWordStatus
{
	INVALID_STATUS,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE
};

class FBullCowGame
{
public:
	FBullCowGame(); //ctor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessWordStatus CheckGuessValidity(FString) const;
	
	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	//See ctor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
};
