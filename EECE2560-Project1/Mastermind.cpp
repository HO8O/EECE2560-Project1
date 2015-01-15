#include "stdafx.h"
#include "Code.h"
#include "Response.h"
#include "Mastermind.h"


Mastermind::Mastermind()
{
	mySecretCode = Code();
}


Mastermind::~Mastermind()
{
}


void Mastermind::PrintSecretCode()
{
	printf("%d %d %d %d", mySecretCode.GetSecretCode()[0], mySecretCode.GetSecretCode()[1], 
		mySecretCode.GetSecretCode()[2], mySecretCode.GetSecretCode()[3]);
}


Code Mastermind::HumanGuess()const
{
	return Code();
}


Response Mastermind::GetResponse(const Code &secret, const Code &guess)const
{
	return Response();
}


void Mastermind::PlayGame()
{
	for (int i = 0; i < 10; i++)
	{

	}
	printf("Failed");
}
