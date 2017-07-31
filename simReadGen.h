#ifndef SIMREADGEN_H
#define SIMREADGEN_H
#include<string>
using namespace std;

void setSubsBase(int i, string *totalLine, string subsLine, int subsNum, int * randBaseLoc);
string subsInsert(int i, string *totalLine, int * randBaseLoc );
void subsSeq (int subsLineNum, int simReadNum, int * randSubsLine);
void simReadLen(int j, string totalLineStr, int & randStart, int & randRange, int & randEnd, string &randStartStr, string &randEndStr);

#endif
