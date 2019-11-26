#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class chests {chest1, chest2, chest3, numOfChests};
enum class codeState {choosingChest, inspectInventory, options, exit};

int main() {
	codeState state = codeState::options;
	chests chestInUse = chests::numOfChests;
	vector <string> inventory = { "Health Potion", "Fire Sword", "Ice Wand", "Magic Flask", "Titans Plate" };

	vector <string> options1 = { "0. Choose Chests", "1. Inspect Inventory", "2. Exit" };
	vector <string> chestList = { "Chest #0", "Chest #1", "Chest#2" };
	vector <vector<string>> chests;

	int choiceNum;

	cout << "Hello to The Hero Inventory System!\n";

	cout << "Here we are going to test out how to choose items from specifc chest and place them into the inventory.\n" <<
		"You will also be able to store items in the chests.\n";

	cout << "The items in your inventory are:\n";

	for (int i = 0; i < inventory.size(); i++) {
		cout << i << ". " << inventory[i] << endl;
	}

	cout << "Press 'Enter' to continue:";
	cin.get();

	do {

		if (state == codeState::options) {
			cout << "\nOPTIONS\n";
			for (int i = 0; i < options1.size(); i++) {
				cout << options1[i] << endl;
			}

			int check1 = 0;
			do {
				if(check1 > 0){
					cout << "Please enter one of the valid options.\n";
				}
				cout << "Enter an option: ";
				cin >> choiceNum;
				check1++;
			} while (choiceNum < 0 || choiceNum > 2);

			switch (choiceNum) {
			case 0:
				state = codeState::choosingChest;
				break;
			case 1:
				state = codeState::inspectInventory;
				break;
			case 2:
				state = codeState::exit;
				break;
			}
		}

		if (state == codeState::choosingChest) {
			cout << "\nCHESTS\n";

			for (int i = 0; i < chestList.size(); i++) {
				cout << chestList[i] << endl;
			}

			cout << "Please choose a chest:";
			cin >> choiceNum;

			switch (choiceNum) {
			case 0:
				chestInUse = chests::chest1;
				break;
			case 1:
				chestInUse = chests::chest2;
				break;
			case 2:
				chestInUse = chests::chest3;
				break;
				}

		}




	} while (state != codeState::exit);


	return 0;
}