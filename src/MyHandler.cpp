/*
 * MyHandler.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: elad
 */

#include "MyHandler.h"
#include "Protocol.h"

namespace networkingLab {

MyHandler::MyHandler() {

}

void MyHandler::onRegister(bool answer) {
	if (answer == true)
		cout << "You have successfully registered" << endl;
	else
		cout << "Registration failed" << endl;
}

void MyHandler::onLogin(bool answer) {
	if (answer == true)
		cout << "You have succesfully logged in" << endl;
	else
		cout << "Login failed" << endl;
}

void MyHandler::onGetListOfUsers(vector<string> users) {
	cout << endl << "<< List of available users >>" << endl;
	int size = users.size();
	for (int i = 0; i < size; i++)
		cout << users[i] << endl;
}

void MyHandler::onReciveGameRequest(string opponentUserName) {
	cout << "The user " << opponentUserName << " sent you a game request"
			<< endl;
}

void MyHandler::onFailedToStartGame() {
	cout << "Failed to start game" << endl;
}

void MyHandler::onNoAvailablePlayer() {
	cout << "The is no available player" << endl;
}

void MyHandler::onGameStarted(string opponentUserName) {
	cout << "Game started with " << opponentUserName << endl;
}

void MyHandler::onGameRquestDeclined(string opponentUserName) {
	cout << "The user " << opponentUserName << " declined your game request"
			<< endl;
}

void MyHandler::onGetScoreBoard(vector<Record> records) {
	cout << endl << "<< Record list >>" << endl;
	int size = records.size();
	for (int i = 0; i < size; i++)
		cout << "User Name : " << records[i].getUserName() << "  Scored : "
				<< records[i].getScore() << endl;
}

void MyHandler::onEndOfGame(string player1, string player2, int score,
		int points) {
	switch (score) {
	case WINNER:
		cout << player1 << " WON " << player2 << " and earned " << points
				<< " points" << endl;
		break;
	case LOSER:
		cout << player2 << " WON " << player1 << " and earned " << points
				<< " points" << endl;
		break;
	case DRAW:
		cout << "DRAW between " << player1 << " to " << player2 << endl;
		break;
	case CANCALED:
		cout << "The game between " << player1 << " to " << player2
				<< " was canceled" << endl;
		break;
	default:
		cout << "INVALID COMMAND MyHandler onEndOfGame" << endl;
		break;
	}
}

void MyHandler::onDisconnect() {
	cout << "Disconnected from server" << endl;
}

void MyHandler::onInvalidCommand(int num) {
	cout << "invalid command from server" << endl;
}

void MyHandler::onUserNameAlreadyLoggedIn(string userName) {
	cout << userName << " is Already logged in" << endl;
}

// game implementation
int* MyHandler::gamePlatfrom() {
	msn->send("123");
	msn->recv();

	cout << "<< < < Welcome to Even or Odd game > > >>" << endl;

	if (iStartTheGame == true) {
		string msg;
		cout << "You go first, choose Even or Odd" << endl;
		cout << "Enter 0 for Even, and 1 for Odd" << endl;
		int cmd;
		bool even = false;
		while (true) {
			cin >> cmd;
			if (cmd == 0) {
				even = true;
				break;
			} else if (cmd == 1) {
				even = false;
				break;
			} else
				cout << "Invalid command, Enter 0 for Even, and 1 for Odd"
						<< endl;

		}
		if (even == true)
			msn->send("Even");
		else
			msn->send("Odd");

		cout << "Please choose number between 0 to 5" << endl;
		int val;
		while (true) {
			cin >> val;
			if (val >= 0 && val <= 5)
				break;
			cout << "Invalid input, Please choose number between 0 to 5"
					<< endl;
		}

		msg = msn->recv();
		int opponentVal = msg[0] - '0';
		int ans = (val + opponentVal) % 2;
		int* finalAns = new int[2];

		if (((even == true) && (ans == 0)) || ((even == false) && (ans == 1))) {
			finalAns[0] = WINNER;
			finalAns[1] = 5;
		} else {
			finalAns[0] = LOSER;
			finalAns[1] = 5;
		}
		msn->send("123");
		msn->recv();
		return finalAns;
	} else {
		string msg;
		cout << "Waiting for opponent to choose Even or Odd" << endl;
		msg = msn->recv();
		cout << "Your opponent chose " << msg << endl;
		cout << "Please choose number between 0 to 5" << endl;


		while (true) {
			cin >> msg;
			if (msg == "0" || msg == "1" || msg == "2" || msg == "3" || msg == "4" || msg == "5")
				break;
			cout << "Invalid input, Please choose number between 0 to 5"
					<< endl;
		}
		msn->send(msg);
		msn->send("123");
		msn->recv();
		return NULL;
	}

}

MyHandler::~MyHandler() {
}

} /* namespace networkingLab */

