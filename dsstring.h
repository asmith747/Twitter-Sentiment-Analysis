//DSString header file

#ifndef DSSTRING_H
#define DSSTRING_H
#include <iostream>

class DSString
{

public:
    DSString();  //default
    DSString(const char*);
    DSString(const DSString&);  //copy constructor
    ~DSString();  //destructor

    void setData(char*);
    int getLength();
    char* getData();

    bool operator==(const DSString&)const;

    DSString& operator= (const char*);
    DSString& operator=(const DSString& str);
    DSString operator+ (const DSString&);
    bool operator== (const char*);
    bool operator== (const DSString&);
    bool operator> (const DSString&) const;
    bool operator< (const DSString&) const;
    char& operator[] (const int);

    friend std::ostream& operator<< (std::ostream&, const DSString&);

//    * param start - the index of where to start
//    * param numChars - the number (count) of characters to copy into
    DSString substring(int start, int numChars);
    bool contains(DSString);


private:
    char* data;
    int len;
    char* ch;

    DSString sent();
    DSString sch();
};


#endif // DSSTRING_H
