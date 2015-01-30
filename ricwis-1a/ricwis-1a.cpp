// ricwis-1a
// Derek Richardson
// William Wisheart

#include "stdafx.h"
#include <iostream>
#include "Mastermind.h"


int main()
{
	bool playOn = true;
	std::cout << "MASTERMIND!";
	Mastermind myGame = Mastermind();
	while (playOn)
	{
		myGame.PlayGame2();
		bool validInput = false;
		char response;
		std::cout << "\nDo you want to play again? [Y/N] : ";
		while (!validInput)
		{
			std::cin >> response;
			if (response == 'Y' || response == 'y')
			{
				validInput = true;
			}
			else if (response == 'N' || response == 'n')
			{
				validInput = true;
				playOn = false;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid response try again!";
			}
		}
	}
	return 0;
}

