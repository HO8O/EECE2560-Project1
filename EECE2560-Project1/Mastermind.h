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
	Code HumanGuess()const;
	Response GetResponse(const Code &secret, const Code &guess)const;
	void PlayGame();
};

