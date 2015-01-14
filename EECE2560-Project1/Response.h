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
	int GetCorrect();
	int GetIncorrect();
	bool IsCorrect();
	void PrintStoredCode();
	bool CompareResponse(Response response);
};

