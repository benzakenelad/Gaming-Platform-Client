//============================================================================
// Name        : clientCLI.cpp
// Author      : Elad Ben Zaken
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include "MyHandler.h"
#include "CLIent.h"
using namespace std;
using namespace networkingLab;

int main() {
	MyHandler* handler = new MyHandler();
	CLIent* cli = new CLIent(handler);

	cli->start();

	return 0;
}
