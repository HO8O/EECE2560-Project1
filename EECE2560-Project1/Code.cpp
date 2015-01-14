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

int Code::CheckIncorrect(const Code &guess)const
{
	return 0;
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
