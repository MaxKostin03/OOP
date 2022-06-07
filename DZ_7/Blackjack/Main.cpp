

#include "Game.h"

using namespace std;


int main()
{
	vector<string> player_names;

	char another_player;

	do
	{
		string name;

		cout << "Enter your name: ";
		getline(cin, name);

		player_names.push_back(name);

		cout << endl << "Would you like to add another player? (y/n)\n";
		another_player = tolower(foolProtection<char>());

	} while (another_player != 'n');

	Game start(player_names);

	start.Play();
}