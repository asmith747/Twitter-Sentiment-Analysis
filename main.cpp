/* Austin Smith
 * Data Structures Program Assignment 1
 *
 * This project determines whether a tweet is positive or negative by using a basic
 * sentiment analysis.
 * dev-train-data.csv dev-train-target.csv dev-test-data.csv dev-test-target.csv
*/

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <fstream>
#include "tweet.h"

#define TEST false
using namespace std;


//function to run test case on DSString
int runCatchTests(int argc, char* const argv[])
{
    return Catch::Session().run(argc, argv);
}


int main(int argc, char* const argv[] )
{
    if (TEST)
    {
        return runCatchTests(argc, argv);
    }

    //Parse files
    Tweet t1;
    t1.parseTrain(argv);

    return 0;
}

