#include <cstdlib>
#include "stdafx.h"
#include "Code.h"


Code::Code()
{
	secretCode.resize(4);
	for (int i = 0; i <= 3; i++)
	{
		secretCode[i] = ((std::rand() % 6) - 1);
	}
}


Code::~Code()
{
	for (int i = 0; i <= 3; i++)
	{
		secretCode[i] = INVALID_CODE;
	}
}

std::vector<int> Code::GetSecretCode()const
{
	return secretCode;
}

void Code::SetSecretCode(std::vector<int> newCode)
{
	secretCode = newCode;
}

int Code::CheckIncorrect(Code &guess)
{
	int NumIncorrect = 0;
	std::vector<int> temp = guess.GetSecretCode();
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; i <= 3; j++)
		{
			if (secretCode[i] == temp[j] && i != j)
			{
				NumIncorrect++;
				//sets to invalid to not be counted again
				temp[j] = INVALID_CODE;
			}
		}
	}
	//Maybe deinit guess here?
	return NumIncorrect;
}


int Code::CheckCorrect(const Code &guess)const
{
	int NumCorrect = 0;
	for (int i = 0; i < 3; i++)
	{
		if (secretCode[i] == guess.GetSecretCode()[i])
		{
			NumCorrect++;
		}
	}
	return NumCorrect;
}
