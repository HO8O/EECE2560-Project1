#pragma once
#include "Response.h"
#include "Code.h"
#include <vector>

struct Guess
{
	Code code;
	Response response;
};

struct PotentialGuess
{
	Code code;
	double score;
};

class Agent
{
private:
	std::vector < Guess >  myGuessList;
	std::vector < Code > consistentCodes;
public:
	Agent();
	~Agent();
	Code AgentGuess();
	void UpdateConsistantCodes();
	double ComputeScore(const Code &guess);
	bool consistentWithAllPreviousGuesses(const Code &guess)const;
	void Agent::GiveResponse(const Response newResponse);
};
