#include "stdafx.h"
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
	return false;
}


void Response::PrintStoredCode()
{
}


bool Response::CompareResponse(const Response &response)const
{
	return false;
}
