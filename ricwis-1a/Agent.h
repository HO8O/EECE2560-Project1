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
public:
	Agent();
	~Agent();
	Code AgentGuess();
	bool consistentWithAllPreviousGuesses(const Code &guess)const;
};