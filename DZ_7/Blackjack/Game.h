#ifndef  __GAME_H__
#define __HAME_H__
#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include "Player.h"
#include "House.h"
#include "Deck.h"


class Game
{
	Deck deck_;
	House house_;
	vector<Player> players_;
	const int START_CARDS = 2;
public:

	Game(vector<string>& player_names);

	void Play();
};

#endif 