#include "stdafx.h"
#include "Code.h"
#include "Response.h"
#include "Mastermind.h"
#include "Agent.h"

#include <iostream>

/*
*	Function : Mastermind()
*	Summary : Initializes a new Mastermind and initializes the datavalue currentResponse
*	Params : void
*	Returns : N/A
*/
Mastermind::Mastermind()
{
	currentResponse = Response();
}

/*
*	Function : ~Mastermind()
*	Summary : Deconstructs Mastermind
*	Params : void
*	Returns : N/A
*/
Mastermind::~Mastermind()
{
}

/*
*	Function : PrintSecretCode()
*	Summary : Prints out the secret code
*	Params : void
*	Returns : N/A
*/
void Mastermind::PrintSecretCode()
{
	printf("\n%d %d %d %d", mySecretCode.GetSecretCode()[0], mySecretCode.GetSecretCode()[1],
		mySecretCode.GetSecretCode()[2], mySecretCode.GetSecretCode()[3]);
}

/*
*	Function : HumanGuess()
*	Summary : Takes in a four digit input from the user.
*	Params : void
*	Returns : a guess from the user
*/
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
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	guess.SetSecretCode(codeGuess);
	return guess;
}

/*
*	Function : GetResponse()
*	Summary : Creates a response using an input guess
*	Params : a guess from the user
*	Returns : a response created from the guess input
*/
Response Mastermind::GetResponse(const Code &guess)const
{
	Response myResponse = Response();
	myResponse.SetCorrect(mySecretCode.CheckCorrect(guess));
	myResponse.SetIncorrect(mySecretCode.CheckIncorrect(guess));
	return myResponse;
}

/*
*	Function : playGame()
*	Summary : Creates a new secret code and runs through one game of Mastermind
*	Params : void
*	Returns : N/A
*/
void Mastermind::PlayGame()
{
	mySecretCode = Code();
	//PrintSecretCode();
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


/*
*	Function : PlayGame2()
*	Summary : Allows the user to create a secret code and calls the Agent class to guess the code
*	Params : N/A
*	Returns : void
*/
void Mastermind::PlayGame2()
{
    mySecretCode = HumanGuess();
    std::cout << mySecretCode;
    Agent a = Agent();
    bool hasWon = false;
    int turnNum = 1;
    while(!hasWon && turnNum < 11)
    {
        std::cout << "\nGuess: " << turnNum;
		currentResponse = GetResponse(a.AgentGuess());
		currentResponse.PrintStoredResponse();
		a.GiveResponse(currentResponse);
		hasWon = currentResponse.IsCorrect();
		turnNum++;
    }
}


/*
*	Function : Operator<<()
*	Summary : Outputs the secretCode within Mastermind
*	Params : an ostr and a Mastermind object
*	Returns : an ostr
*/
std::ostream &operator<<(std::ostream &ostr, const Mastermind &m)
{
	ostr << m.mySecretCode;
	return ostr;
}
