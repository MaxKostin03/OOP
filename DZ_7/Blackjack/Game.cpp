#include "Game.h"


Game::Game(vector<string>& player_names)
{
	for (int i = 0; i < player_names.size(); i++)
	{
		players_.push_back(Player(player_names.at(i)));
	}

	srand(static_cast<unsigned int>(time(0)));

	deck_.Populate();
	deck_.Shuffle();
}

void Game::Play()
{
	for (int i = 0; i < START_CARDS; i++)
	{
		for (int j = 0; j < players_.size(); j++)
		{
			deck_.Deal(players_.at(j));
		}
		deck_.Deal(house_);
	}

	house_.FlipFirstCard();

	for (int j = 0; j < players_.size(); j++)
	{
		cout << players_.at(j) << endl;
	}

	cout << house_ << endl;

	for (int j = 0; j < players_.size(); j++)
	{
		deck_.DealAdditionalCards(players_.at(j));
	}

	house_.FlipFirstCard();
	cout << house_ << endl;

	deck_.DealAdditionalCards(house_);

	if (house_.IsBusted())
	{
		for (int j = 0; j < players_.size(); j++)
		{
			if (players_.at(j).IsBusted() == false)
				players_.at(j).Win();
		}
	}
	else
	{
		for (int j = 0; j < players_.size(); j++)
		{
			if (players_.at(j).IsBusted() == false)
			{
				if (players_.at(j).GetValue() > house_.GetValue())
				{
					players_.at(j).Win();
				}
				else if (players_.at(j).GetValue() < house_.GetValue())
				{
					players_.at(j).Lose();
				}
				else
				{
					players_.at(j).Push();
				}
			}
		}
	}

	for (int j = 0; j < players_.size(); j++)
	{
		players_.at(j).Clear();
	}
	house_.Clear();
}