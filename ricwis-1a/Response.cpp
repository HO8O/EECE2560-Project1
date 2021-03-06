#include "stdafx.h"
#include <iostream>
#include "Response.h"

/*
*	Function : Response()
*	Summary : Initializes a new Response with data values set to 0
*	Params : void
*	Returns : N/A
*/
Response::Response()
{
	correct = 0;
	incorrect = 0;
}

Response::Response(int cor, int incor)
{
	correct = cor;
	incorrect = incor;
}

/*
*	Function : ~Response()
*	Summary : Deconstructs Response
*	Params : void
*	Returns : N/A
*/
Response::~Response()
{
}

/*
*	Function : SetCorrect()
*	Summary : Sets the data value correct to an input integer
*	Params : integer with the number of correct digits in the correct place
*	Returns : N/A
*/
void Response::SetCorrect(int numOfCorect)
{
	correct = numOfCorect;
}


/*
*	Function : SetIncorrect()
*	Summary : Sets the data value incorrect to an input integer
*	Params : integer with the number of correct digits in the incorrect place
*	Returns : N/A
*/
void Response::SetIncorrect(int numOfIncorrect)
{
	incorrect = numOfIncorrect;
}


/*
*	Function : GetCorrect()
*	Summary : Returns the data value correct
*	Params : void
*	Returns : an integer with the number correct in the correct place
*/
int Response::GetCorrect()const
{
	return correct;
}

/*
*	Function : GetIncorrect()
*	Summary : Returns the data value incorrect
*	Params : void
*	Returns : an integer with the number correct in the incorrect place
*/
int Response::GetIncorrect()const
{
	return incorrect;
}

/*
*	Function : IsCorrect()
*	Summary : Checks the data value correct if all four digits were correct
*	Params : void
*	Returns : a bool on whether the guess was correct
*/
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

/*
*	Function : PrintStoredResponse()
*	Summary : Prints the response to the screen
*	Params : void
*	Returns : N/A
*/
void Response::PrintStoredResponse()
{
	std::cout << "\nCorrect Values:" << correct << " Incorect Values:" << incorrect << "\n";
}

/*
*	Function : CompareResponse()
*	Summary : Compares the data values of the response to the data values of another response
*	Params : a seperate Response
*	Returns : a bool on whether the data values of the two responses are equal
*/
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


/*
*	Function : operator<<()
*	Summary : Overloads the ostream << operator to print the response correct and incorrect values
*	Params : ostr and a Response
*	Returns : ostr
*/
std::ostream &operator<<(std::ostream &ostr, const Response &r)
{
	ostr << "Correct : " << r.GetCorrect() << " Incorect : " << r.GetIncorrect();
	return ostr;
}


/*
*	Function : operator=()
*	Summary : Overloads the = operation to store the correct and incorrect Respnse values
*	Params : a Response
*	Returns : this Response
*/
Response Response::operator=(const Response r)
{
	correct = r.GetCorrect();
	incorrect = r.GetIncorrect();
	return *this;
}


/*
*	Function : Increment()
*	Summary : Increments through the 15 possible responses
*	Params : N/A
*	Returns : void
*/
void Response::Increment()
{
    if ((correct + incorrect) < 4){
        incorrect++;
    }
    else if (correct != 4){
        correct++;
        incorrect = 0;
    }
    else {
        correct = 0;
        incorrect = 0;
    }
}


/*
*	Function : Operator==()
*	Summary : Compares the whether two responses are identical
*	Params : Two Responses
*	Returns : bool on whether they are identical or not
*/
bool operator==(const Response &r1, const Response &r2)
{
	return ((r1.GetCorrect() == r2.GetCorrect()) && (r1.GetIncorrect() == r2.GetIncorrect()));
}
