#pragma once
class Mastermind
{
public:
	Mastermind();
	~Mastermind();
private:
	Code mySecretCode;
public:
	void PrintSecretCode();
	Code humanGuess();
	Response GetResponse(Code secret, Code guess);
	void PlayGame();
};

