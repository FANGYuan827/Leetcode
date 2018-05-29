/*
2018Äê5ÔÂ15ÈÕ21:31:54
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/
#include <iostream>
#include <string>
using namespace std;

class Solution_demo24 {
public:
    int minDistance(string word1, string word2) {    //word1---->>>>word2
        return 0;
    }
};


int main_demo24(int argc,char **argv)
{
	Solution_demo24 s1;
	string word1 = "hello";
	string word2 = "word";
	int res = 0;
	res = s1.minDistance(word1,word2);
	system("system");
	return 0;
}