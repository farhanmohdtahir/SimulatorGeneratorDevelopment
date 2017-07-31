#ifndef FASTQCONV_H
#define FASTQCONV_H
#include<string>
using namespace std;

string fastqSeqWrite(int i, int j, int * randSubsLine, string fastqStr, string *headLine, string randStartStr,string randEndStr,int randStart,int randEnd, string subsLine, string totalLineStr, string randBaseLocStr);
#endif
