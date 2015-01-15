#include "stdafx.h"
#include "Code.h"
#include <time.h>


Code::Code()
{
	std::srand(time(NULL));
	secretCode.resize(4);
	for (int i = 0; i <= 3; i++)
	{
		secretCode[i] = (std::rand() % 6);
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

int Code::CheckIncorrect(const Code &guess)const
{
	int NumIncorrect = 0;
	std::vector<int> temp;
	temp.resize(4);
	temp = guess.GetSecretCode();
	for (int i = 0; i <= 3; i++)
	{
		if (secretCode[i] != temp[i])
		{
			for (int j = 0; j <= 3; j++)
			{
				if (secretCode[i] == temp[j] && i != j)
				{
					NumIncorrect++;
					//sets to invalid to not be counted again
					temp[j] = INVALID_CODE;
					break;
				}
			}
		}
	}
	//Maybe deinit guess here?
	return NumIncorrect;
}


int Code::CheckCorrect(const Code &guess)const
{
	int NumCorrect = 0;
	for (int i = 0; i <= 3; i++)
	{
		if (secretCode[i] == guess.GetSecretCode()[i])
		{
			NumCorrect++;
		}
	}
	return NumCorrect;
}
