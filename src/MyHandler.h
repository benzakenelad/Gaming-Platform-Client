/*
 * MyHandler.h
 *
 *  Created on: Sep 3, 2017
 *      Author: elad
 */

#ifndef MYHANDLER_H_
#define MYHANDLER_H_

#include <Handler.h>

namespace networkingLab {

class MyHandler: public Handler {
public:
	MyHandler();
	/**
     * In case of login answer
	 */
	virtual void onLogin(bool answer);

	/**
	 * In case of registration answer
	 */
	virtual void onRegister(bool answer);

	/**
	 * In case the username we enter is already logged in
	 */
	virtual void onUserNameAlreadyLoggedIn(string userName);

	/**
	 * In case received A game request
	 */
	virtual void onReciveGameRequest(string opponentUserName);

	/**
	 * In case the server failed to start a game
	 */
	virtual void onFailedToStartGame();

	/**
	 * In case there is no available player
	 */
	virtual void onNoAvailablePlayer();

	/**
	 * In case the opponent accepted the game request
	 */
	virtual void onGameStarted(string opponentUserName);

	/**
	 * In case the opponent declined the game request
	 */
	virtual void onGameRquestDeclined(string opponentUserName);

	/**
	 * score = WINNER / LOSER / DRAW / CANCELED
	 * In end of a match we receive all the details
	 */
	virtual void onEndOfGame(string player1, string player2, int score, int points);

	/**
	 * Vector of available players username
	 */
	virtual void onGetListOfUsers(vector<string> users);

	/**
	 * Vector of Record object
	 * Record object contains userName and score record
	 */
	virtual void onGetScoreBoard(vector<Record> records);

	/**
	 * When disconnected from server
	 */
	virtual void onDisconnect();

	/**
	 * When server no recognize the command we sent him
	 */
	virtual void onInvalidCommand(int num);

	/**
	 * return 2 integers,
	 * 1 is the status, WINNER / LOSER / DRAW / CANCELED
	 * 2 is the amount of points
	 */
	virtual int* gamePlatfrom();


	int convertStringToInt(string str) {
		int num = 0;
		sscanf(str.c_str(), "%d", &num);
		return num;
	}
	virtual ~MyHandler();
};

} /* namespace networkingLab */

#endif /* MYHANDLER_H_ */
