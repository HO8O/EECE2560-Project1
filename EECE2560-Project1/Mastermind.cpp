#include "stdafx.h"
#include "Code.h"
#include "Response.h"
#include "Mastermind.h"

#include <iostream>


Mastermind::Mastermind()
{
	mySecretCode = Code();
	currentResponse = Response();
}


Mastermind::~Mastermind()
{
}


void Mastermind::PrintSecretCode()
{
	printf("\n%d %d %d %d", mySecretCode.GetSecretCode()[0], mySecretCode.GetSecretCode()[1], 
		mySecretCode.GetSecretCode()[2], mySecretCode.GetSecretCode()[3]);
}


Code Mastermind::HumanGuess()const
{
	Code guess = Code();
	std::vector<int> codeGuess;
	codeGuess.resize(4);
	int tempInt = INVALID_CODE;
	int current = 0;
	while (current != 4)
	{
		std::cout << "\nEnter code value " << current << ":";
		std::cin >> tempInt;
		if (tempInt <= 5 && tempInt >= 0)
		{
			codeGuess[current] = tempInt;
			current++;
		}
		else
		{
			std::cout << "\nError: Value must be in rang [0,5]!!!";
		}
	}
	guess.SetSecretCode(codeGuess);
	return guess;
}


Response Mastermind::GetResponse(const Code &guess)const
{
	Response myResponse = Response();
	myResponse.SetCorrect(mySecretCode.CheckCorrect(guess));
	myResponse.SetIncorrect(mySecretCode.CheckIncorrect(guess));
	return myResponse;
}


void Mastermind::PlayGame()
{
	mySecretCode = Code();
	PrintSecretCode();
	int turnNum = 1;
	bool hasWon = false;

	while (turnNum < 11 && hasWon == false)
	{
		std::cout << "\nGuess: " << turnNum;
		currentResponse = GetResponse(HumanGuess());
		currentResponse.PrintStoredResponse();
		hasWon = currentResponse.IsCorrect();
		turnNum++;
	}

	if (hasWon)
		std::cout << "\nYou Win!!!";
	else
		std::cout << "\nYou lose.";
}
