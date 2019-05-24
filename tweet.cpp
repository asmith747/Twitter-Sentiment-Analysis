//tweet.cpp

#include "tweet.h"
#include "dsstring.h"
#include <iostream>
#include <fstream>
#include <array>
//#include <cmath>

using namespace std;

//These words came from Time's article "The 500 Most Frequently Used Words on Twitter"
DSString Tweet::words[] = {DSString("!"), DSString("start"), DSString("like"), DSString("good"), DSString("how"), DSString("love"), DSString("lol"), DSString("work"), DSString("thanks"), DSString("great"), DSString("still"),
                           DSString("why"), DSString("can't"), DSString("working"), DSString("happy"),  DSString("live"), DSString("feel"), DSString("never"), DSString("bad"), DSString("free"), DSString("long"), DSString("sleep"),
                           DSString("awesome"), DSString("cool"), DSString("old"), DSString("help"), DSString("die"), DSString("haha"), DSString("wow"), DSString("thank"), DSString("pretty"), DSString("school"), DSString("finally"),
                           DSString("god"), DSString("weekend"), DSString("hate"), DSString("win"), DSString("hard"), DSString("wish"), DSString("sorry"), DSString("already"), DSString("stop"), DSString("play"), DSString("cold"),
                           DSString("the"), DSString("nothing"), DSString("top"), DSString("friend"), DSString("feeling"), DSString("amazing"), DSString("lost"), DSString("end"), DSString("funny"), DSString("glad"), DSString("blog"),
                           DSString("morning"), DSString("tonight"), DSString("news"), DSString("myself"), DSString("sounds"), DSString("omg"), DSString("want"), DSString("OMG"), DSString("LOL"), DSString("beautiful"), DSString("right"),
                           DSString("ass"), DSString("home"), DSString("took"), DSString("sister"), DSString("dog"), DSString("bro"), DSString("tho"), DSString("men"), DSString("always")};

//Holds the score for each word, [0][0] = positive, [0][1] = negative
int Tweet::scores[75][2];

//Count of time's numbers show
int Tweet::testScores[75];


int Tweet::length[2];

Tweet::Tweet()
{

}

void Tweet::parseTrain(char * const *& arg)
{
    ifstream train(arg[1]);     //Open train dat file and check if successfull
    if (!train.is_open())
        cout << "Train file could not be opened";


    ifstream target(arg[2]);     //Open train target file and check if successfull
    if (!target.is_open())
        cout << "Target file could not be opened";

    //Temporary holders
    char num[8], id[11], user[16], tweet[750], score[2], targetNum[8];

    //Pass char into DSString
    DSString tw;

    int count = 0; //Counts the number of tweets

    //Ignore header
    train.getline(user, 16, '\n');
    target.getline(user, 16, '\n');

//    for(int i=0; i<500; i++){

    cout << "Parsing train files..." << endl;
    //Parse through file until last tweet
     while(train.getline(num, 8, ',')){
            count++;
//            train.getline(num, 8, ',');
            train.getline(id, 11, ',');       //tweet id
            train.getline(user, 16, ',');     //user
            train.getline(tweet, 750, '\n');  //tweet

            tw.setData(tweet);

            target.getline(num, 8, ',');     //number from target
            target.getline(score, 2, ',');   //score from target
            target.getline(id, 11, '\n');    //id from target

            classify(tweet, score[0]); //Score the words if found in tweet
     }
     //Close files
     train.close();
     target.close();



     ifstream data(arg[3]);     //Open files and check if open is successful
     ifstream testTarget(arg[4]);
     if (!data.is_open())
        cout << "Train file could not be opened";
     if (!testTarget.is_open())
        cout << "Target file could not be opened";


     count = 0;
     char targ;
     int correct = 0;

     data.getline(user, 16, '\n');
     testTarget.getline(user, 16, '\n');

     cout << "Analyzing test files..." << endl << endl;
     while(data.getline(num, 8, ',')){
     count++;

     data.getline(id, 11, ',');        //tweet id
     data.getline(user, 16, ',');      //user
     data.getline(tweet, 750, '\n');   //tweet

//                tw.setData(tweet);

     testTarget.getline(targetNum, 8, ',');   //number
     testTarget.getline(score, 2, ',');       //score
     testTarget.getline(id, 11, '\n');        //tweet id

     //Analyze and score tweet
     targ = analyze(tweet);

     //If score was correct, increment
     if(targ == score[0])
            correct++;
     }

     cout << "Results: ";
      //Print out amount correct correct and total
     cout << endl << "Amount Correct: "<<correct << "  Total: " << count << endl;
     double perc;
     perc = (double)correct/(double)count;
     cout << "Percent Correct: " << perc*100 << "%" << endl << endl;;

     //Close files
     data.close();
     testTarget.close();


//     getScoreValues(count); //Print out word values
}


void Tweet::classify(DSString tweet, char score)
{
    //Loop through all 75 words
    for(int p = 0; p<75; p++){
        bool ch = tweet.contains(words[p].getData());

        if(ch && score == '0'){
            length[0] = length[0] + tweet.getLength();
            scores[p][1]++;
        }

        if(ch && score == '4'){
            length[1] = length[1] + tweet.getLength();
            scores[p][0]++;
        }
    }
}

//Function to score the tweets
char Tweet::analyze(DSString tw)
{
    int sum = 0;
    for(int p = 0; p<75; p++){
        bool ch = tw.contains(words[p]);
        if(ch){
            sum += scores[p][0] - scores[p][1];
            testScores[p]++;
        }
    }
    if(sum == 0){
//        std::cout << "Nothing found in  " << tw.getData() << std::endl;
        return '4';
    }
    if(sum >=0)
        return '4';

    if(sum < 0)
        return '0';

    return '4';
}


//Print values for the array of words
void Tweet::getScoreValues(int cnt)
{
    std::cout << std::endl <<"scores  "<< cnt <<std::endl;
    for(int p = 0; p<75; p++)
        std::cout << words[p].getData()<<":  " << scores[p][0]<<" " << scores[p][1] <<std::endl;

    std::cout << std::endl << std::endl << "test values" << std::endl;
    for(int p = 0; p<75; p++)
        std::cout << words[p].getData()<<":  " << testScores[p]<<std::endl;
}


Tweet::~Tweet()
{

}
