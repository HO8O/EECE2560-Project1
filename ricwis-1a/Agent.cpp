#include "stdafx.h"
#include "Agent.h"


Agent::Agent()
{
}


Agent::~Agent()
{
}

bool Agent::consistentWithPreviousGuesses(const Code &guess)const
{
	return false;
}

Code Agent::AgentGuess()
{
	return Code();
}