#include "stdafx.h"
#include "Agent.h"

/*
*	Function : Agent()
*	Summary : Constructs the Agent object
*	Params : N/A
*	Returns : void
*/
Agent::Agent()
{
}


/*
*	Function : ~Agent()
*	Summary : Deconstructs the Agent object
*	Params : N/A
*	Returns : void
*/
Agent::~Agent()
{
}


/*
*	Function : consistentWithAllPreviousGuesses()
*	Summary : Checks whether the new guess is consistent with each of the previous guesses
*	Params : the Code object guess
*	Returns : a bool on whether the guess is consistent
*/
bool Agent::consistentWithAllPreviousGuesses(const Code &guess)const
{
	for each(Guess p in myGuessList)
	{
		if (guess.CheckCorrect(p.code) != p.response.GetCorrect() ||
			guess.CheckIncorrect(p.code) != p.response.GetIncorrect())
		{
			return false;
		}
	}
	return true;
}


/*
*	Function : ComputerScore()
*	Summary : Assigns a score to a guess
*	Params : A Code object guess
*	Returns : a double that is the score for the guess
*/
double Agent::ComputeScore(const Code &guess)
{
	Guess temp = { guess, Response(0, 0) };
	double score = 0;
	std::vector<Guess> tempList = myGuessList;
	tempList.push_back(temp);

	//For all 15 possible responses
	for (int i = 0; i < 15; i++)
	{
		Code tempCode = Code(std::vector < int > {0, 0, 0, 0});
		//for all possible codes
		for each (Code code in consistentCodes)
		{
			//check how many are consistent
			for each(Guess guess in tempList)
			{
				if (code.CheckCorrect(guess.code) != guess.response.GetCorrect() ||
					code.CheckIncorrect(guess.code) != guess.response.GetIncorrect())
				{
					score++;
				}
			}
			tempCode.Increment();
		}
		//increment tempGuess.response
		tempList.back().response.Increment();
	}
	return score;
}


/*
*	Function : UpdateConsistentCodes
*	Summary : Clears the consistentCodes vector and updates it with new codes that are checked with the consistentWithAllPreviousGuesses function
*	Params : N/A
*	Returns : void
*/
void Agent::UpdateConsistantCodes()
{
	consistentCodes.clear();
	Code temp = Code(std::vector < int > {0, 0, 0, 0});

	for (int i = 0; i < 1554; i++)
	{
		if (consistentWithAllPreviousGuesses(temp))
		{
			consistentCodes.push_back(temp);
		}
		temp.Increment();
	}
}


/*
*	Function : AgentGuess
*	Summary : Runs the agent through the process of making its next guess
*	Params : N/A
*	Returns : a Code with the Agents guess
*/
Code Agent::AgentGuess()
{
	if (myGuessList.size() != 0)
	{
		PotentialGuess newPotentialGuess =
		{
			Code(std::vector < int > {0, 0, 0, 0}),
			1554 * 15
		};

		newPotentialGuess.code.Increment();
		newPotentialGuess.score = ComputeScore(newPotentialGuess.code);

		PotentialGuess temp = newPotentialGuess;

		for(int i = 0; i < 1554; i++)//Not sure how to stop this loop
		{
			if (consistentWithAllPreviousGuesses(temp.code))
			{
				temp.score = ComputeScore(temp.code);
				if (temp.score < newPotentialGuess.score)
				{
					newPotentialGuess = temp;
				}
			}
			//std::cout << i;
			temp.code.Increment();
		}
		//Add this code to guess list

		Guess newGuess = {
			newPotentialGuess.code,
			Response()
		};

		myGuessList.push_back(newGuess);
		std::cout << "\nAgent Guessed:" << newGuess.code;
		return newGuess.code;
	}
	else
	{
		Code firstGuess = Code(std::vector<int>{ 0, 0, 0, 0 });
		Guess newGuess = {
			firstGuess,
			Response()
		};
		myGuessList.push_back(newGuess);
		std::cout << "\nAgent Guessed:" << firstGuess;
		return firstGuess;
	}
}


/*
*	Function : GiveResponse()
*	Summary : adds the new response to myGuessList and runs the UpdateConsistentCodes function
*	Params : a Response
*	Returns : void
*/
void Agent::GiveResponse(const Response newResponse)
{
	myGuessList.back().response = newResponse;
	UpdateConsistantCodes();
}