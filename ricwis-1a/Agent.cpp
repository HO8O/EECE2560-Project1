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

double ComputeScore(const Code &guess)
{
	return 0;
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
	PotentialGuess newGuess =
	{
		myGuessList.back().code,
		1554
	};

	newGuess.code.Increment();
	newGuess.score = ComputeScore(newGuess.code);

	PotentialGuess temp = newGuess;

	while (temp.code.GetSecretCode() != std::vector<int>{0,0,0,0})//Not sure how to stop this loop
	{
		if (consistentWithAllPreviousGuesses(temp.code))
		{
			temp.score = ComputeScore(temp.code);
			if (temp.score < newGuess.score)
			{
				newGuess = temp;
			}
		}
		temp.code.Increment();
	}
	return newGuess.code;
}