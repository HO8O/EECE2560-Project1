#pragma once
#include "Response.h"
#include "Code.h"
#include <vector>

struct Guess
{
	Code code;
	Response response;
};

class Agent
{
private:
	std::vector < Guess >  myGuessList;
public:
	Agent();
	~Agent();
	Code AgentGuess();
	bool consistentWithPreviousGuesses(const Code &guess)const;
};
