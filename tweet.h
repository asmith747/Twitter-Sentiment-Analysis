//tweet header file

#ifndef TWEET_H
#define TWEET_H
#include "dsstring.h"

#include <iostream>

using namespace std;

class Tweet
{
    public:
        Tweet();
        virtual ~Tweet();

        void classify(DSString tweet, char score);
        void getScoreValues(int);
        char analyze(DSString tw);
        void parseTrain(char* const*&);

    protected:

    private:
        static  DSString words[];
        static int scores[][2];
        static int testScores[];
        static int length[];

};

#endif // TWEET_H
