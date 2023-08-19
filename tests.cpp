// Amaan Shah, UIC, Spring 2021
// test.cpp
//
// Test file for public member functions using Google Test Framework.

#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"

TEST(grid, defaultConstructor){
    int n = 50;
    for (int i = 0; i < n; i++){
        Grid<int> intTest;
        ASSERT_EQ (intTest.numrows(), 4);
        for (int j = 0; j < intTest.numrows(); j++) {
            ASSERT_EQ (intTest.numcols(j), 4);
        }
    }
    for (int i = 0; i < n; i++) {
        Grid<string> strTest;
        ASSERT_EQ (strTest.numrows(), 4);
        for (int j = 0; j < strTest.numrows(); j++) {
            ASSERT_EQ (strTest.numcols(j), 4);
        }
    }
    for (int i = 0; i < n; i++) {
        Grid<double> dbTest;
        ASSERT_EQ (dbTest.numrows(), 4);
        for (int j = 0; j < dbTest.numrows(); j++) {
            ASSERT_EQ (dbTest.numcols(j), 4);
        }
    }
    for (int i = 0; i < n; i++) {
        Grid<float> flTest;
        ASSERT_EQ (flTest.numrows(), 4);
        for (int j = 0; j < flTest.numrows(); j++) {
            ASSERT_EQ (flTest.numcols(j), 4);
        }
    }
}

TEST(grid, paramConstructor) {
    int n = 50;
    for (int i = 0; i < n; i++){
        Grid<int> intTest(2,3);
        ASSERT_EQ (intTest.numrows(), 2);
        for (int j = 0; j < intTest.numrows(); j++) {
            ASSERT_EQ (intTest.numcols(j), 3);
        }
    }
    for (int i = 0; i < n; i++) {
        Grid<string> strTest(10,15);
        ASSERT_EQ (strTest.numrows(), 10);
        for (int j = 0; j < strTest.numrows(); j++) {
            ASSERT_EQ (strTest.numcols(j), 15);
        }
    }
    for (int i = 0; i < n; i++) {
        Grid<double> dbTest(100,200);
        ASSERT_EQ (dbTest.numrows(), 100);
        for (int j = 0; j < dbTest.numrows(); j++) {
            ASSERT_EQ (dbTest.numcols(j), 200);
        }
    }
    for (int i = 0; i < n; i++) {
        Grid<float> flTest(300,400);
        ASSERT_EQ (flTest.numrows(), 300);
        for (int j = 0; j < flTest.numrows(); j++) {
            ASSERT_EQ (flTest.numcols(j), 400);
        }
    }
}

TEST(grid, size) {
    int n = 100;
    size_t x = 0;
    for (int i = 0; i < n; i++) {
        Grid<int> test;
        x = test.size();
        ASSERT_EQ (x, 16);
    }
    for (int i = 0; i < n; i++) {
        Grid<string> test2(9,10);
        x = test2.size();
        ASSERT_EQ (x, 90);
    }
    for (int i = 0; i < n; i++) {
        Grid<double> test3(20, 30);
        x = test3.size();
        ASSERT_EQ (x, 600);
    }
    for (int i = 0; i < n; i++) {
        Grid<float> test4(25,25);
        x = test4.size();
        ASSERT_EQ (x, 625);
    }
}

TEST(grid, numRows_numCols) {
    int n = 50;
    for (int i = 0; i < n; i++){
        Grid<int> intTest;
        ASSERT_EQ (intTest.numrows(), 4);
        for (int j = 0; j < intTest.numrows(); j++) {
            ASSERT_EQ (intTest.numcols(j), 4);
        }
    }
    for (int i = 0; i < n; i++) {
        Grid<string> strTest(10,15);
        ASSERT_EQ (strTest.numrows(), 10);
        for (int j = 0; j < strTest.numrows(); j++) {
            ASSERT_EQ (strTest.numcols(j), 15);
        }
    }
    for (int i = 0; i < n; i++) {
        Grid<double> dbTest(100,200);
        ASSERT_EQ (dbTest.numrows(), 100);
        for (int j = 0; j < dbTest.numrows(); j++) {
            ASSERT_EQ (dbTest.numcols(j), 200);
        }
    }
    for (int i = 0; i < n; i++) {
        Grid<float> flTest(300,400);
        ASSERT_EQ (flTest.numrows(), 300);
        for (int j = 0; j < flTest.numrows(); j++) {
            ASSERT_EQ (flTest.numcols(j), 400);
        }
    }
}

TEST(grid, parenthOP) {
    Grid<int> test;
    int count = 1;
    int testCount = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            test(i,j) = count ;
            count++;
        }
    }
    for (int i = 0; i < test.numrows(); i++) {
        for (int j = 0; j < test.numcols(i); j++) {
            ASSERT_EQ (test(i,j), testCount);
            testCount++;
        }
    }
    Grid<string> test2(10,15);
    count = 1;
    testCount = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            test2(i,j) = to_string(count);
            count++;
        }
    }
    for (int i = 0; i < test2.numrows(); i++) {
        for (int j = 0; j < test2.numcols(i); j++) {
            ASSERT_EQ (test2(i,j), to_string(testCount));
            testCount++;
        }
    }
    Grid<double> test3(7,9);
    double c = 1.0;
    double tc = 1.0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 9; j++) {
            test3(i,j) = c;
            c = c + 0.25;
        }
    }
    for (int i = 0; i < test3.numrows(); i++) {
        for (int j = 0; j < test3.numcols(i); j++) {
            ASSERT_EQ (test3(i,j), tc);
            tc = tc + 0.25;
        }
    }
}

TEST(grid, copyConst) {
    //default test    
    Grid<int> a;
    int count = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a(i,j) = count;
            count++;
        }
    }
    Grid<int> b(a);
    for (int i = 0; i < b.numrows(); i++) {
        for (int j = 0; j < b.numcols(i); j++) {
            ASSERT_EQ (b(i,j), a(i,j));
        }
    }
    // A little larger test
    Grid<double> c(10, 10);
    double num = 1.5;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            c(i,j) = num;
            num = num + 0.01;
        }
    }
    Grid<double> d(c);
    for (int i = 0; i < d.numrows(); i++) {
        for (int j = 0; j < d.numcols(i); j++) {
            ASSERT_EQ (d(i,j), c(i,j));
        }
    }
    // large test
    Grid<string> test1(100, 10);
    count = 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            test1(i,j) = to_string(count);
            count++;
        }
    }
    Grid<string> test2(test1);
    for (int i = 0; i < test2.numrows(); i++) {
        for (int j = 0; j < test2.numcols(i); j++) {
            ASSERT_EQ (test2(i,j), test1(i,j));
        }
    }
}

TEST(grid, copyOpEq) {
    //default test    
    Grid<int> a;
    int count = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a(i,j) = count;
            count++;
        }
    }
    Grid<int> b;
    b = a;
    for (int i = 0; i < b.numrows(); i++) {
        for (int j = 0; j < b.numcols(i); j++) {
            ASSERT_EQ (b(i,j), a(i,j));
        }
    }
    //default test where a = a
    Grid<int> t;
    count = 1;
    int testCount = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            t(i,j) = count;
            count++;
        }
    }
    t = t;
    for (int i = 0; i < t.numrows(); i++) {
        for (int j = 0; j < t.numcols(i); j++) {
            ASSERT_EQ (t(i,j), testCount);
            testCount++;
        }
    }
    // A little larger test
    Grid<double> c(10, 10);
    double num = 1.5;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            c(i,j) = num;
            num = num + 0.01;
        }
    }
    Grid<double> d;
    d = c;
    for (int i = 0; i < d.numrows(); i++) {
        for (int j = 0; j < d.numcols(i); j++) {
            ASSERT_EQ (d(i,j), c(i,j));
        }
    }
    // large test
    Grid<string> test1(100, 10);
    count = 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            test1(i,j) = to_string(count);
            count++;
        }
    }
    Grid<string> test2;
    test2 = test1;
    for (int i = 0; i < test2.numrows(); i++) {
        for (int j = 0; j < test2.numcols(i); j++) {
            ASSERT_EQ (test2(i,j), test1(i,j));
        }
    }
}

// Provided Test: sample maze from handout
TEST(maze, basic) {
    vector<string> textMaze;

    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);

    MazeCell* start = m.getStart(2, 2);

    EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
    EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
    EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));

    EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
    EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

    EXPECT_FALSE(isPathToFreedom(start, "WW"));
    EXPECT_FALSE(isPathToFreedom(start, "NN"));
    EXPECT_FALSE(isPathToFreedom(start, "EE"));
    EXPECT_FALSE(isPathToFreedom(start, "SS"));
}

TEST(maze, advanced) {
    vector<string> textMaze;
    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);
    int n = 50;
    
    for (int i = 0; i < n; i++) {
        MazeCell* start = m.getStart(0, 0);
    
        EXPECT_TRUE(isPathToFreedom(start, "SENEWSSENSENNSSSNWSWWNSEENN"));
        start = m.getStart(0,3);
        EXPECT_TRUE(isPathToFreedom(start, "SSSNWNSSNWNNEWSWNSESESWWN"));
        start = m.getStart(2, 0);
        EXPECT_TRUE(isPathToFreedom(start, "SEENESNNNSSWWNNE"));
        
        start = m.getStart(2, 2);
        EXPECT_FALSE(isPathToFreedom(start, "WWW"));
        EXPECT_FALSE(isPathToFreedom(start, "NSNN"));
        EXPECT_FALSE(isPathToFreedom(start, "WEEE"));
    
        start = m.getStart(0, 2);
        EXPECT_FALSE(isPathToFreedom(start, "WSWNSESEESNN"));
        EXPECT_FALSE(isPathToFreedom(start, "WSSESWWN"));
        EXPECT_FALSE(isPathToFreedom(start, "WSWN"));
        EXPECT_FALSE(isPathToFreedom(start, "WSSEENNW"));
    }
}

// Provided Test: don't allow going through walls
TEST(maze, tryingToGoThroughWalls) {
    vector<string> textMaze;

    textMaze.push_back("* S *");
    textMaze.push_back("     ");
    textMaze.push_back("W * P");
    textMaze.push_back("     ");
    textMaze.push_back("* * *");

    Maze m(textMaze);

    MazeCell* start = m.getStart(1, 1);

    EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
    EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
    EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
    EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
}

TEST(maze, goingThruWallsAgain) {
    vector<string> textMaze;
    textMaze.push_back("* S *");
    textMaze.push_back("     ");
    textMaze.push_back("W * P");
    textMaze.push_back( "     ");
    textMaze.push_back( "* * *");

    Maze m(textMaze);
    int n = 50;
    for (int i = 0; i < n; i++) {
        MazeCell* start = m.getStart(1, 1);
        EXPECT_FALSE(isPathToFreedom(start, "NNESSWWSSE"));
        EXPECT_FALSE(isPathToFreedom(start, "WNESSSES"));
        EXPECT_FALSE(isPathToFreedom(start, "ENNWS"));
        EXPECT_FALSE(isPathToFreedom(start, "SWSEENNW"));
    }
}

// Provided Test: Works when starting on an item
TEST(maze, startOnItem) {
    vector<string> textMaze;

    textMaze.push_back("P-S-W");

    Maze m(textMaze);
    MazeCell* start = m.getStart(0, 0);

    EXPECT_TRUE(isPathToFreedom(start, "EE"));
    start = m.getStart(0, 1);
    EXPECT_TRUE(isPathToFreedom(start, "WEE"));
    start = m.getStart(0, 2);
    EXPECT_TRUE(isPathToFreedom(start, "WW"));
}

TEST(maze, startOnItemNew) {
    vector<string> textMaze;
    textMaze.push_back("*-P-*-*-S-*-*-*-W-*-*");

    Maze m(textMaze);
    int n = 50;
    for (int i = 0; i < n; i++) {
        MazeCell* start = m.getStart(0,0);
        EXPECT_FALSE(isPathToFreedom(start, "WNE"));
        EXPECT_TRUE(isPathToFreedom(start, "EEEEEEWWEEEEEEW"));
        start = m.getStart(0, 6);
        EXPECT_TRUE(isPathToFreedom(start, "WWWWWEEEEEEEEE"));
        EXPECT_FALSE(isPathToFreedom(start, "EEWWWWSEN"));
        start = m.getStart(0, 8);
        EXPECT_TRUE(isPathToFreedom(start, "WWWWWWW"));
    }
}

// Provided Test: Reports errors if given illegal characters.
TEST(maze, invalidChar) {
    vector<string> textMaze;

    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);
    MazeCell* start = m.getStart(0, 0);

    /* These paths contain characters that aren't even close to permissible. */
    EXPECT_FALSE(isPathToFreedom(start, "Q"));
    EXPECT_FALSE(isPathToFreedom(start, "X"));
    EXPECT_FALSE(isPathToFreedom(start, "!"));
    EXPECT_FALSE(isPathToFreedom(start, "?"));

    EXPECT_FALSE(isPathToFreedom(start, "n"));
    EXPECT_FALSE(isPathToFreedom(start, "s"));
    EXPECT_FALSE(isPathToFreedom(start, "e"));
    EXPECT_FALSE(isPathToFreedom(start, "w"));

    ///* These are tricky - they're legal paths that happen to have an unexpected
    // * character at the end.
    start = m.getStart(2, 2);
    EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWNQ"));
    EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES!!!"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENES??"));
}

TEST(maze, invalidCharAgain) {
    vector<string> textMaze;
    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);
    int n = 25;
    for (int i = 0; i < n; i++) {
        MazeCell* start = m.getStart(0, 0);
        EXPECT_FALSE(isPathToFreedom(start, "123"));
        EXPECT_FALSE(isPathToFreedom(start, "-_<>"));
        EXPECT_FALSE(isPathToFreedom(start, "!"));
        EXPECT_FALSE(isPathToFreedom(start, "?"));
        EXPECT_FALSE(isPathToFreedom(start, "north"));
        EXPECT_FALSE(isPathToFreedom(start, "south"));
        EXPECT_FALSE(isPathToFreedom(start, "east"));
        EXPECT_FALSE(isPathToFreedom(start, "west"));
    
        start = m.getStart(3, 3);
        EXPECT_FALSE(isPathToFreedom(start, "NWSWWNSEENWNNEV"));
        EXPECT_FALSE(isPathToFreedom(start, "NWAWNRDQ"));
        EXPECT_FALSE(isPathToFreedom(start, "HELLO_WORLD!"));
    }
}

// Provided Test: This tests your personalized regular maze to see if you were
// able to escape.
TEST(maze, escapeRegularMaze) {
    Maze m(4, 4);
    MazeCell* start = m.mazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
}

// Provided Test: This tests your personalized twisty maze to see if you were
// able to escape.
TEST(maze, escapeTwistyMaze) {
    Maze m(4, 4);
    MazeCell* start = m.twistyMazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
}

