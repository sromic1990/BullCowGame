#pragma once
#include "FBullCowGame.h"
#include <map>

#define TMap std::map // to make syntax Unreal friendly

FBullCowGame::FBullCowGame() { Reset(); } //default CTor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 lettered words as isogram
	if (Word.length() <= 1) return true;
	
	//setup the map
	TMap<char, bool> LetterSeen;
	//loop through all the letters of the word
	for (auto letter : Word) // for all letters of the word
	{
		letter = tolower(letter); //handle mixed case
		//if the letter is in the map
		if (LetterSeen[letter])
		{
			//we do NOT have an isogram
			return false;
		}
		//otherwise
		else
		{
			//add the letter to the map as seen
			LetterSeen[letter] = true;
		}

	}
	return true; //for example in cases where /0 is entered.
}
bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto letter : Word)
	{
		if (!islower(letter))
		{
			return false;
		}
	}

	return true;
}

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 7}, {5,10}, {6,16}, {7, 20} };
	return WordLengthToMaxTries[GetHiddenWordLength()];
}

void FBullCowGame::Reset()
{
	constexpr int32 MY_CURRENT_TRY = 1;
	const FString HIDDEN_WORD = "planet"; // this MUST be an isogram
	
	FBullCowGame::MyCurrentTry = MY_CURRENT_TRY;
	FBullCowGame::MyHiddenWord = HIDDEN_WORD;
	FBullCowGame::bGameIsWon = false;

	return;
}


EGuessWordStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!IsIsogram(guess))
	{
		return EGuessWordStatus::NOT_ISOGRAM;
	}
	else if (guess.length() != GetHiddenWordLength())
	{
		return EGuessWordStatus::WRONG_LENGTH;
	}
	else if (!IsLowercase(guess))
	{
		return EGuessWordStatus::NOT_LOWERCASE;
	}
	else
	{
		return EGuessWordStatus::OK;
	}
}

//Receives a VALID guess. Increements turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	//Increement the turn number
	MyCurrentTry++;
	//Setup a return variable
	FBullCowCount BullCowCount;
	
	//Assuming the same length as guess 
	int32 WordLength = MyHiddenWord.length();
	//Loop through all letters in the hidden word
	for (int32 MyHiddenWordCharacter = 0; MyHiddenWordCharacter < WordLength; MyHiddenWordCharacter++)
	{
		//Loop through all letters in the guessed word
		for (int32 GuessCharacter = 0; GuessCharacter < WordLength; GuessCharacter++)
		{
			//Compare letters against the input, if they match then
			if (Guess[GuessCharacter] == MyHiddenWord[MyHiddenWordCharacter])
			{
				//if they are in the same place
				if (MyHiddenWordCharacter == GuessCharacter)
				{
					//increement bulls if they are in the same place
					BullCowCount.Bulls++;
				}
				else
				{
					//increement cows otherwise
					BullCowCount.Cows++;
				}
			}
		}
	}
	
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}
