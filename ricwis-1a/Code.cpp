/*
 *	File : Code.cpp
 *	Description : Memember function implementation for the Code class
 *	Written By : Derek Richardson
*/
#include "stdafx.h"
#include "Code.h"
#include <time.h>
#include <iostream>

/*
 *	Function : Code()
 *	Summary : Initializes a new Code with random values
 *	Params : void
 *	Returns : N/A
*/
Code::Code()
{
	std::srand(time(NULL));
	secretCode.resize(4);
	for (int i = 0; i <= 3; i++)
	{
		secretCode[i] = (std::rand() % 6);
	}
}

/*
 *	Function : ~Code()
 *	Summary : Deinitializes a Code with INVALID_CODE as each value
 *	Params : void
 *	Returns : N/A
*/
Code::~Code()
{
	for (int i = 0; i <= 3; i++)
	{
		secretCode[i] = INVALID_CODE;
	}
}

/*
 *	Function : Code::GetSecretCode()
 *	Summary : Returns the secret code
 *	Params : void
 *	Returns : the stored secret code
*/
std::vector<int> Code::GetSecretCode()const
{
	return secretCode;
}

/*
 *	Function : Code::SetSecretCode()
 *	Summary : Sets the secret code
 *	Params : vector<int> newCode - new code to be stored
 *	Returns : the stored secret code
*/
void Code::SetSecretCode(std::vector<int> newCode)
{
	secretCode = newCode;
}

/*
 *	Function : Code::Checkincorrect()
 *	Summary : Returns the number of values that are in secret code but in wrong place
 *	Params : Code &guess - the code to compare to secret code
 *	Returns : the number of incorrect values
*/
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

/*
 *	Function : Code::CheckCorrect()
 *	Summary : Returns the number of values that are in secret code and in correct place
 *	Params : Code &guess - the code to compare to secret code
 *	Returns : the number of correct values
*/
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

std::ostream &operator<<(std::ostream &ostr, const Code &c)
{
	ostr << c.GetSecretCode()[0] << c.GetSecretCode()[1] << c.GetSecretCode()[2] << c.GetSecretCode()[3];
	return ostr;
}

bool operator==(const Code &c1, const Code &c2)
{
	return ((c1.GetSecretCode() == c2.GetSecretCode()));
}

void Code::Increment()
{
	bool carry = false;
	int index = 3;
	while(!carry)
	{
		if(index >= 0)
		{
			if(secretCode[index] == 5)
			{
				carry = true;
				secretCode[index] = 0;
			}
			else
			{
				secretCode[index]++;
			}
			index--;
		}
		else
		{
			return;
		}
	}
}
