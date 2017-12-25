/*
 * CLIent.h
 *
 *  Created on: Sep 3, 2017
 *      Author: elad
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include "gameAPI.h"


namespace networkingLab {

class CLIent {
	gameAPI* API;
public:
	CLIent(Handler* handler); // c'tor

	/**
	 * start CLI
	 */
	void start();

	void printInstructions();

	virtual ~CLIent(); // d'tor
};

} /* namespace networkingLab */

#endif /* CLIENT_H_ */
