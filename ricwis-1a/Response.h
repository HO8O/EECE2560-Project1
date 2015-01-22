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
	Response operator=(const Response r);
};

std::ostream &operator<<(std::ostream &ostr, const Response r);
bool operator==(const Response &r1, const Response &r2);
