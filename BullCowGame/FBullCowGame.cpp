#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }
int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

void FBullCowGame::Reset()
{
	constexpr int32 MY_CURRENT_TRY = 1;
	const FString HIDDEN_WORD = "planet";
	constexpr int32 MY_MAX_TRIES = 8;
	
	FBullCowGame::MyCurrentTry = MY_CURRENT_TRY;
	FBullCowGame::MyMaxTries = MY_MAX_TRIES;
	FBullCowGame::MyHiddenWord = HIDDEN_WORD;
	FBullCowGame::bGameIsWon = false;

	return;
}


EGuessWordStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (false)//if the guess isn't an isogram,
	{
		//return an error
		return EGuessWordStatus::NOT_ISOGRAM;
	}
	else if (false)//if the guess isn't lowercase,
	{
		//return an error
		return EGuessWordStatus::NOT_LOWERCASE;
	}
	else if (guess.length() != GetHiddenWordLength())//if the guess length is wrong
	{
		//return an error
		return EGuessWordStatus::WRONG_LENGTH;
	}
	else//otherwise
	{
		//return ok
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
