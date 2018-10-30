#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); //ctor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); //TODO make a more rich return value
	bool CheckGuessValidity(std::string);
	//Provide a method for counting bulls and cows and increementing/increasing try #

private:
	//See ctor for initialization
	int MyCurrentTry;
	int MyMaxTries;
};
