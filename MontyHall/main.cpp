#include "stdafx.h"
#include <iostream>
#include "LetsMakeADeal.h"
#include <string>


int main(int const argc, unsigned argv[], std::string strat)
{
	if(argc < 3 || argc > 4)
	{
		std::cout << "The arguement order should be [0] number of games you want to run";
		std::cout << ", [1] number of doors in the game, [2] number of doors you would like to be opened";
		std::cout << ", [3] your strategy 'switch' or 'stay'.\nPlease rerun the program with the correct argument format.";
	}
	else if (strat != "switch" || strat != "stay" )
	{
		std::cout << "It appears you entered an invalid strategy, case is important.\n";
		std::cout << "Please rerun the program with argument[3] being 'switch' or 'stay'.";
	}
	else
	{
		unsigned const games{argv[0]};
		unsigned const doors{argv[1]};
		unsigned const open_doors{argv[2]};
		unsigned const total_doors{doors - open_doors};
		auto wins{0.0};
		for(int i = 0; i < games;i++)
		{
			LetsMakeADeal game(doors, open_doors,strat);
			if(game.run_game() == true){++wins;}
		}
		auto win_percent{wins / games};
		double probability{1/total_doors};
	}

	// test code
	/*unsigned games{0};
	std::cin >> games;
	unsigned doors{0};
	std::cin>>doors;
	unsigned open_doors{0};
	std::cin >> open_doors;*/
    return 0;
}

