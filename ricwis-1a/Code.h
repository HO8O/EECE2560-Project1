/*
 *	File : Code.h
 *	Description : Class declaration for the Code class
 *	Written By : Derek Richardson
*/

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
	int CheckIncorrect(const Code &guess)const;
	int CheckCorrect(const Code &guess)const;
	std::vector<int> GetSecretCode()const;
	void SetSecretCode(std::vector<int> newCode);
	void Increment();
};
bool operator==(const Code &c1, const Code &c2);
std::ostream &operator<<(std::ostream &ostr, const Code &c);
