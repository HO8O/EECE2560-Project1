#pragma once
#include <vector>

//defined so there are no magic numbers in code
#define INVALID_CODE -1

class Code
{
public:
	Code();
	~Code();
private:
	std::vector<int> secretCode;
public:
	int CheckIncorrect(Code &guess);
	int CheckCorrect(const Code &guess)const;
	std::vector<int> GetSecretCode()const;
	void SetSecretCode(std::vector<int> newCode);
};

