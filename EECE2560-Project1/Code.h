#pragma once
class Code
{
public:
	Code();
	~Code();
private:
	int secretCode[4];
public:
	int CheckIncorrect(Code &guess);
	int CheckCorrect(const Code &guess)const;
	int GetSecretCodeAtIndex(int index)const;
	void SetSecretCodeAtIndex(int index, int value);
};

