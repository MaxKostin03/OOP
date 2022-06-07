#ifndef __DECK_H__
#define __DECK_H__
#include "Hand.h"
#include "GenericPlayer.h"
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>

class Deck : public Hand
{
public:

	Deck();

	void Populate();

	void Shuffle();

	void Deal(Hand& hand);

	void DealAdditionalCards(GenericPlayer& player);
};

#endif