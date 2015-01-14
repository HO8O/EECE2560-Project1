#pragma once
class Code
{
public:
	Code();
	~Code();
private:
	int secretCode[4];
public:
	int CheckIncorrect(const Code &guess)const;
	int CheckCorrect(const Code &guess)const;
	int GetSecretCodeAtIndex(int index)const;
};

