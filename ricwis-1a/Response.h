#pragma once
#include <iostream>

class Response
{
public:
	Response();
	Response(int cor, int incor);
	~Response();
private:
	int correct;
	int incorrect;
public:
	void SetCorrect(int numOfCorect);
	void Increment();
	void SetIncorrect(int numOfIncorrect);
	int GetCorrect()const;
	int GetIncorrect()const;
	bool IsCorrect()const;
	void PrintStoredResponse();
	bool CompareResponse(const Response &response)const;
	Response operator=(const Response r);
};

std::ostream &operator<<(std::ostream &ostr, const Response r);
bool operator==(const Response &r1, const Response &r2);
