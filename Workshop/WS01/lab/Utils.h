#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H


#include <iostream>
namespace seneca {

	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);


}
#endif 