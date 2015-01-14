#pragma once
class Code
{
public:
	Code();
	~Code();
private:
	int secretCode[4];
public:
	int CheckIncorrect(Code guess);
	int CheckCorrect(Code guess);
};

