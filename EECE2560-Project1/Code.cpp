#include <cstdlib>
#include "stdafx.h"
#include "Code.h"


Code::Code()
{
	for (int i = 0; i <= 3; i++)
	{
		secretCode[i] = ((std::rand() % 6) - 1);
	}
}


Code::~Code()
{
	for (int i = 0; i <= 3; i++)
	{
		secretCode[i] = 0;
	}
}

int Code::GetSecretCodeAtIndex(int index)const
{
	if (index <= 3)
	{
		return secretCode[index];
	}
	else
	{
		return 0;
	}
}

void Code::SetSecretCodeAtIndex(int index, int value)
{
	secretCode[index] = value;
}

int Code::CheckIncorrect(Code &guess)
{
	int NumIncorrect = 0;
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; i <= 3; j++)
		{
			if (secretCode[i] == guess.GetSecretCodeAtIndex(j))
			{
				NumIncorrect++;
				guess.SetSecretCodeAtIndex(j, -1);
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
		if (secretCode[i] == guess.GetSecretCodeAtIndex[i])
		{
			NumCorrect++;
		}
	}
	return NumCorrect;
}
