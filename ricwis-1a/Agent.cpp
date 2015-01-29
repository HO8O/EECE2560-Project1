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
		for (int j = 0; j < 1554; j++)
		{
			//check how many are consistent
			for each(Guess guess in tempList)
			{
				if (tempCode.CheckCorrect(guess.code) != guess.response.GetCorrect() ||
					tempCode.CheckIncorrect(guess.code) != guess.response.GetIncorrect())
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
	PotentialGuess newPotentialGuess =
	{
		Code(std::vector < int > {0, 0, 0, 0}),
		0
	};

	newPotentialGuess.code.Increment();
	newPotentialGuess.score = ComputeScore(newPotentialGuess.code);

	PotentialGuess temp = newPotentialGuess;

	while (temp.code.GetSecretCode() != std::vector<int>{0,0,0,0})//Not sure how to stop this loop
	{
		if (consistentWithAllPreviousGuesses(temp.code))
		{
			temp.score = ComputeScore(temp.code);
			if (temp.score < newPotentialGuess.score)
			{
				newPotentialGuess = temp;
			}
		}
		temp.code.Increment();
	}
	//Add this code to guess list
	
	Guess newGuess = {
		newPotentialGuess.code,
		Response()
	};
	myGuessList.push_back(newGuess);
	std::cout << newGuess.code;
	return newGuess.code;
}

void Agent::GiveResponse(const Response newResponse)
{
	myGuessList.back().response = newResponse;
}