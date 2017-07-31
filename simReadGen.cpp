#include "simReadGen.h"
#include "random.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void setSubsBase(int i,string *totalLine, string subsLine, int subsNum, int * randBaseLoc){
    int j;
    for (j=0; j<subsNum; j++){
        randBaseLoc[j]=rand()% (totalLine[i].length()-1);
        if (j>0){
            while(checkRandLine(randBaseLoc, j)){
                randBaseLoc[j]=rand()% (totalLine[i].length()-1);
            }
        }
        // cout<<randBaseLoc[j]<<"\t";
    }
    int* end = randBaseLoc + subsNum;
    sort(randBaseLoc, end);
}

string subsInsert(int i, string *totalLine, int * randBaseLoc ){
    string subsLine="", tempLine="";
    char tempChar;
    int j, k;
    tempLine=totalLine[i];
    k=0;
    for(j=0; j<totalLine[i].length(); j++){
        if(randBaseLoc[k]==j){
            tempChar=randomBase();
            while(tempChar==tempLine[j]){
                tempChar=randomBase();
            }
            tempLine[j]=tempChar;
            ++k;
        }
        subsLine+=tempLine[j];
    }
return subsLine;
}

void subsSeq (int subsLineNum, int simReadNum, int * randSubsLine){
    int j;
        for(j=0; j<subsLineNum; j++){
        randSubsLine[j]=rand() % simReadNum;
        if (j>0){
            while(checkRandLine(randSubsLine, j)){
                randSubsLine[j]=rand() % simReadNum;
            }
        }
    }
    int * end = randSubsLine + subsLineNum;
	sort(randSubsLine,end);
}

void simReadLen(int j, string totalLineStr, int & randStart, int & randRange, int & randEnd, string &randStartStr, string &randEndStr){
    switch (totalLineStr.length()){
            case 17:
                randRange=16;
                randStart=0;
                break;
            case 18:
                randRange=rand() % 2+16;
                randStart=rand() % 2;
                break;
            case 19:
                randRange=rand() % 3+16;
                randStart=rand() % 3;
                break;
            case 20:
                randRange=rand() % 4+16;
                randStart=rand() % 4;
                break;
            case 21:
                randRange=rand() % 5+16;
                randStart=rand() % 5;
                break;
            case 22:
                randRange=rand() % 6+16;
                randStart=rand() % 6;
                break;
        }

        randEnd=randStart+randRange;
        if(randEnd>=totalLineStr.length()-1){
            randEnd=totalLineStr.length()-1;
        }

}