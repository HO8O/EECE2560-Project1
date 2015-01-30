#include "stdafx.h"
#include "Agent.h"


Agent::Agent()
{
}


Agent::~Agent()
{
}

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

void Agent::GiveResponse(const Response newResponse)
{
	myGuessList.back().response = newResponse;
	UpdateConsistantCodes();
}