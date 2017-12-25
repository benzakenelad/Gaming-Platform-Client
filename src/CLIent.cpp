/*
 * CLIent.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: elad
 */

#include "CLIent.h"

namespace networkingLab {

CLIent::CLIent(Handler* handler) {
	API = new gameAPI(handler);
}

void CLIent::start() {

	while (true) {
		if (API->isLoggedIn() == true)
			break;
		string userName;
		string passWord;
		printInstructions();
		int cmd;
		cin >> cmd;
		switch (cmd) {
		case 1:
			cout << "Enter UserName : ";
			cin >> userName;
			cout << "Enter Password : ";
			cin >> passWord;
			API->login(userName, passWord);
			break;
		case 2:
			cout << "Enter UserName : ";
			cin >> userName;
			cout << "Enter Password : ";
			cin >> passWord;
			API->registerr(userName, passWord);
			break;
		case 3:
			API->disconnect();
			return;
		default:
			cout << "Invalid command, Try again" << endl;
			break;
		}
		usleep(100000);
	}
	while (true) {

		if(API->isPlaying() == true)
			API->startGamePlatform();

		printInstructions();
		int cmd;
		string userName;
		cin >> cmd;

		switch (cmd) {
		case 1:
			while (true) {
				cout << "Enter 1 for auto start game" << endl;
				cout << "Enter 2 for enter partner's username" << endl;
				cin >> cmd;
				if (cmd == 1) {
					API->autoStartGame();
					break;
				} else if (cmd == 2) {
					cout << "Enter partner's username : ";
					cin >> userName;
					API->startGame(userName);
					break;
				} else
					cout << "Invalid command, Try again" << endl;
			}
			break;
		case 2:
			API->acceptGameRequest();
			break;
		case 3:
			API->declineGameRequest();
			break;
		case 4:
			if(API->isPlaying() == true)
				API->startGamePlatform();
			else
				cout << "There is no approved match" << endl;
			break;
		case 5:
			API->getUserList();
			break;
		case 6:
			API->getScoreBoard();
			break;
		case 7:
			API->disconnect();
			usleep(50000);
			return;
		default:
			cout << "Wrong command, Try again" << endl;
			break;
		}
		usleep(200000);
	}
}

void CLIent::printInstructions() {
	if (API->isLoggedIn() == false) {
		cout << endl << endl;
		cout << "Enter 1 to Login" << endl;
		cout << "Enter 2 to Registration" << endl;
		cout << "Enter 3 to Disconnect" << endl;
	} else {
		cout << endl << endl;
		cout << "Enter 1 to Start a Game" << endl;
		cout << "Enter 2 to Accept a Game" << endl;
		cout << "Enter 3 to Declined a Game" << endl;
		cout << "Enter 4 to enter the game platform" << endl;
		cout << "Enter 5 to get List of Available Users" << endl;
		cout << "Enter 6 to get Score Board" << endl;
		cout << "Enter 7 to Disconnect" << endl;
	}
}

CLIent::~CLIent() {

}

} /* namespace networkingLab */
