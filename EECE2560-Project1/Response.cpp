#include "stdafx.h"
#include <iostream>
#include "Response.h"


Response::Response()
{
	correct = 0;
	incorrect = 0;
}


Response::~Response()
{
}


void Response::SetCorrect(int numOfCorect)
{
	correct = numOfCorect;
}


void Response::SetIncorrect(int numOfIncorrect)
{
	incorrect = numOfIncorrect;
}


int Response::GetCorrect()const
{
	return correct;
}


int Response::GetIncorrect()const
{
	return incorrect;
}


bool Response::IsCorrect()const
{
	if (correct == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Response::PrintStoredResponse()
{
	std::cout << "\nCorrect Values:" << correct << " Incorect Values:" << incorrect << "\n";
}


bool Response::CompareResponse(const Response &response)const
{
	if (correct == response.GetCorrect() && incorrect == response.GetIncorrect())
	{
		return true;
	}
	else
	{
		return false;
	}
}
