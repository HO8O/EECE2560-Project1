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
}


void Response::SetIncorrect(int numOfIncorrect)
{
}


int Response::GetCorrect()
{
	return 0;
}


int Response::GetIncorrect()
{
	return 0;
}


bool Response::IsCorrect()
{
	return false;
}


void Response::PrintStoredCode()
{
}


bool Response::CompareResponse(Response response)
{
	return false;
}
