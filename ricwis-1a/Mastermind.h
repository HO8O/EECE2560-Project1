#pragma once
#include "Code.h"
#include "Response.h"

class Mastermind
{
public:
	Mastermind();
	~Mastermind();
private:
	Code mySecretCode;
	Response currentResponse;
public:
	void PrintSecretCode();
	Code HumanGuess()const;
	Response GetResponse(const Code &guess)const;
	void PlayGame();
	friend std::ostream &operator<<(std::ostream &ostr, const Mastermind &m);
};
