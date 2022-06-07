#include <iostream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;
//=============================================================================
int getIntNumber() {
    
    int num;
    cout << "Enter an integer value: ";
    while (!(cin >> num) || cin.get() != '\n')
    {
            cin.clear();
            cin.ignore(32767, '\n');
            cin.sync();
            cout << "Error. Please enter an integer number!" << endl;
    }
    return num;
}
//==============================================================================
ostream& endll(ostream& stream)
{
	stream.put(stream.widen('\n'));
	stream.put(stream.widen('\n'));
	stream.flush();
	return stream;
}
//==============================================================================
class Card
{
protected:

	enum Suit { DIAMONDS, SPADES, CLUBS, HEARTS };
	enum Value { ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13 };
	bool Position = false;
	Value value;
	Suit suit;

	Suit initSuit()
	{
		Suit suit = static_cast<Suit>(rand() % 3);
		return suit;
	}

	Value initValue()
	{
		Value value = static_cast<Value>((rand() % 12) + 1);
		return value;
	}

public:

	Card()
	{
		srand(time(0));
		value = initValue();
		suit = initSuit();
	}

	void Flip()
	{
		if (Position)
			Position = false;
		else if (!Position)
			Position = true;
	}

	Value getEnumValue() const
	{
		return value;
	}

	string getStringSuit() const
	{
		switch (suit)
		{
		case DIAMONDS:
			return "Diamonds";
			break;
		case SPADES:
			return "Spades";
			break;
		case CLUBS:
			return "Clubs";
			break;
		case HEARTS:
			return "Hearts";
			break;
		}
	}

	string getStringValue() const
	{
		if (value == KING)
			return "King";
		else if (value == QUEEN)
			return "Queen";
		else if (value == JACK)
			return "Jack";
		else if (value == ACE)
			return "Ace";
		else
			return to_string(value);
	}

	bool getPosition() const
	{
		return Position;
	}

	int getCardValue() const
	{
		if (value == KING || value == QUEEN || value == JACK)
			return 10;
		else
			return value;
	}

//================================Task5===============================
	

	friend ostream& operator <<(ostream& out, Card& card);

};

ostream& operator <<(ostream& out, Card& card)
{
	if (card.Position)
		out << "Card: " << card.getStringValue() << " of " << card.getStringSuit();
	else
		out << "Card: XX";

	return out;
}

//=====================================================================

class Hand : public Card
{
protected:

	vector<Card*> hand;

public:

	void add(Card* card)
	{
		hand.push_back(card);
	}

	void clear()
	{
		for (int i = 0; i < hand.size(); i++)
			delete hand.at(i);
		hand.clear();
	}

	int getValue() const
	{
		assert(hand.size() != 0);
		int sum = 0;

		for (int i = 0; i < hand.size(); i++)
		{
			if (hand.at(i)->getEnumValue() == ACE && sum + 11 < 21)
				sum += 11;
			else if (hand.at(i)->getPosition() == false)
				continue;
			else
				sum += hand.at(i)->getCardValue();
		}
		return sum;
	}
};

class GenericPlayer : public Hand
{
protected:

	string name;

	GenericPlayer(string s_name)
		:name(s_name)
	{}

	virtual bool isHitting() const = 0;

	bool isBoosted()
	{
		return this->getValue() > 21;
	}

	void boost()
	{
		cout << this->name << " has an overdraw!\n\n";
	}

//================================Task5===============================
	
	friend ostream& operator<<(ostream& out, GenericPlayer& player);
};

ostream& operator<<(ostream& out, GenericPlayer& player)
{
	out << "Name: " << player.name << "\n\n";
	for (int i = 0; i < player.hand.size(); i++)
		out << *player.hand.at(i) << endl;
	out << "Sum of cards: " << player.getValue();
	return out;
}

//================================Task3===============================


class Player : public GenericPlayer
{
public:

	Player(string name)
		:GenericPlayer(name) {}

	int getAnswer() {

		char i;
		
		while (!(cin >> i) || cin.get() != '\n') {
			cin.clear();
			cin.ignore(32767, '\n');
			cin.sync();
			
		}
		return i;
	}
	virtual bool isHitting() 
	{
		char answer;
		do
		{
			cout << "Would you like to take one more card? (y/n) ";

			answer = getAnswer();
			if (answer == 'y')
				return true;
			else if (answer == 'n')
				return false;
			else
				cout << "Wrong input! Expected 'y' or 'n'! Try again." << endll;
		} while (answer != 'y' && answer != 'n');
	}

	void win() const
	{
		cout << this->name << " has won! Congratulations!" << endll;
	}

	void lose() const
	{
		cout << this->name << " has lost! :(" << endll;
	}

	void push() const
	{
		cout << this->name << ", it's a draw!" << endll;
	}
};

//================================Task4===============================


class House : public GenericPlayer
{
public:

	House(string name = "Dealer")
		:GenericPlayer(name) {}

	virtual bool isHitting() const override
	{
		return this->getValue() < 16;
	}

	void flipFirstCard()
	{
		this->hand.at(0)->Flip();
	}

};

int main() {

//================================Task1===============================
    cout << "Your int number: " << getIntNumber() << endl;

//================================Task2===============================
    cout << "Hello" << endll << "world!" << endl;
    
	
    return 0;

}

