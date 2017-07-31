#include "random.h"
#include <iostream>
using namespace std;

static const char base[4]={'A', 'T', 'G', 'C'};

char randomBase(){
	int randNum;
	randNum=rand() % 4;
	return base[randNum];
}

bool checkRandNum (int numBef, int numAft){
	bool test;
        if (numAft==numBef){
            test=true;
        }
        else test=false;
        return test;
}

bool checkRandLine(int * randSubsLine, int itr){
	bool test;
	for(int i=itr-1; i>=0; i--){
		if (randSubsLine[itr]==randSubsLine[i]){
			test=true;
			break;
		}
		test=false;
	}
return test; 
}