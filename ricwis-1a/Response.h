#pragma once
class Response
{
public:
	Response();
	~Response();
private:
	int correct;
	int incorrect;
public:
	void SetCorrect(int numOfCorect);
	void SetIncorrect(int numOfIncorrect);
	int GetCorrect()const;
	int GetIncorrect()const;
	bool IsCorrect()const;
	void PrintStoredResponse();
	bool CompareResponse(const Response &response)const;
};

