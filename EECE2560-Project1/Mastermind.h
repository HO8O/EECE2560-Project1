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
	Response GetResponse();
	void PlayGame();
};

