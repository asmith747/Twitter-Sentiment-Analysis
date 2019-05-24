//DSString cpp

#include "dsstring.h"
#include <iostream>
#include <cstring>

//Default Constructor
DSString::DSString()
{
    data = new char[1];
    data[0] = '\0';
    len = 0;
}

//Constructor
DSString::DSString(const char* dsstr)
{
        int n = 0;
        while (dsstr[n] != '\0'){
            n++;
        }
        len = n;
        data = new char[n];
        for(int j=0; j<n; j++){
            data[j] = dsstr[j];
        }
}

//Copy constructor
DSString::DSString(const DSString& copy)
{
    data = new char[copy.len +1];
    strcpy(data, copy.data);
    len = copy.len;
}


//Destructor
DSString::~DSString()
{
    delete[] data;
}

//Changes member data in object
void DSString::setData(char* chr){
    delete[] data;
    int n = 0;
    while (chr[n] != '\0'){
        n++;
    }
    len = n;
    data = new char[n];
    for(int h=0; h<n; h++){
        data[h] = chr[h];
    }
}

//Get length
int DSString::getLength()
{
    return len;
}

//Get data
char* DSString::getData()
{
    return data;
}

//Checks if DSString is a sub of a different DSString
bool DSString::contains(DSString sub)
{

    //Holds length
    int subLen = sub.getLength();
    int sentLen = this->getLength();

    //Holds position
    int posSub = 0;
    int posSent = 0;

    for(int g= 0; posSent < sentLen - subLen; ++posSent){
        if(this->getData()[posSent] == sub.getData()[posSub]){
            //If a character matches it checks again for the next char until the whole word is matched
            ++posSub;
            if(posSub == subLen)
               return true;
            //if not matched, reset the count
        }else{
            posSent = posSent - posSub;
            posSub = 0;
        }
    }
    return false;
}


//Overloaded assignment operator
DSString& DSString::operator=(const DSString& str)
{
    if(this != &str){
    delete[] data;
    data = new char[str.len+1];
    strcpy(data, str.data);
    len = str.len;
    }
    return *this;
}

//Overloaded less than operator
bool DSString::operator<(const DSString& str) const {
    return (strcmp(data, str.data) < 0);
}

//Overloaded comparison operator
bool DSString::operator==(const DSString& equals)const{
    return !strcmp(data, equals.data);
}



