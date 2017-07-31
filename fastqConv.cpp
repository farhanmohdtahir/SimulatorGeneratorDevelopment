#include <iostream>
#include <string>
using namespace std;

string fastqSeqWrite(int i, int j, int * randSubsLine, string fastqStr, string *headLine, string randStartStr,string randEndStr,int randStart,int randEnd,string subsLine, string totalLineStr, string randBaseLocStr){
        string qtyLine="", subsLineRng="",totalLineRng="";

        int l=0, k=0; 
        if (j==randSubsLine[l]){
        fastqStr+=headLine[i]+"; "+randStartStr+ ":" + randEndStr+"; "+ randBaseLocStr+"\n";
            for(k=randStart; k<=randEnd; k++){
                subsLineRng+=subsLine[k];
            }
        for(k=0; k<subsLineRng.length(); k++){
            qtyLine+="f";
        }
        fastqStr+=subsLineRng+"\n+\n"+qtyLine+"\n";
        ++l;
        }
        
        else{
        fastqStr+=headLine[i]+"; "+randStartStr+ ":" + randEndStr+"; "+"\n";
            for(k=randStart; k<=randEnd; k++){
                totalLineRng+=totalLineStr[k];
            }
        for(k=0; k<totalLineRng.length(); k++){
            qtyLine+="f";
        }
        fastqStr+=totalLineRng+"\n+\n"+qtyLine+"\n";            
        }
        return fastqStr;
}