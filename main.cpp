#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "random.h"
#include "simReadGen.h"
#include "fastqConv.h"
using namespace std;

int main(){
	int i=0, j=0, k=0, m=0, subsNum=5, subsLineNum=30, simReadNum=100, randBaseLoc[subsNum], randSubsLine[subsLineNum], randRange, randStart, randEnd, lineNum=6000;
    string in="test.fa", out="output.fastq";
    ifstream infile;
    ofstream outfile;
	string line, totalLine[lineNum], totalLineStr, headLine[lineNum], subsLine, fastqStr="", randStartStr, randEndStr, randBaseLocChar, 
        randBaseLocStr, subsLineRng, totalLineRng;

infile.open(in.c_str());
	while(getline(infile, line)){	 
		if(line[i]!='>'){
            totalLine[j]=line;
            ++j;
	}	
    else {
        headLine[k]=line;
        k++;
    }
    }
	infile.close();

for (i=0; i<lineNum; i++){
totalLineStr=totalLine[i];
if (totalLine[i]=="")break;
//--------------------------------------------------------------------------------------------------------set substitution location
    setSubsBase(i, totalLine, subsLine, subsNum, randBaseLoc);
//--------------------------------------------------------------------------------------------------------applying substitution
    subsLine=subsInsert(i, totalLine, randBaseLoc);
//--------------------------------------------------------------------------------------------------------set number of line that contain substituted base
    subsSeq (subsLineNum, simReadNum, randSubsLine);
//--------------------------------------------------------------------------------------------------------set range of simulated read
    for(j=0; j<simReadNum; j++){
        simReadLen(j, totalLineStr, randStart, randRange, randEnd, randStartStr, randEndStr);
//--------------------------------------------------------------------------------------------------------convert into fastq format

        randStartStr=to_string(randStart+1);
        randEndStr=to_string(randEnd+1);
        randBaseLocStr="";
        for(k=0; k<subsNum; k++){
            m=randBaseLoc[k]+1;
            randBaseLocChar=to_string(m);
            randBaseLocStr+=randBaseLocChar+" "+totalLineStr[m-1]+">"+subsLine[m-1]+", ";
        }
        fastqStr=fastqSeqWrite(i, j, randSubsLine, fastqStr, headLine, randStartStr,randEndStr,randStart,randEnd,subsLine, totalLineStr, randBaseLocStr); 
    }
}
//---------------------------------------------------------------------------------------------------------produce output FASTQ file
outfile.open(out.c_str());
    outfile<<fastqStr;
outfile.close();
    return 0;
}