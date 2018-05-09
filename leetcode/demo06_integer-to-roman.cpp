/*
2018年4月22日21:56:06
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
#include "iostream"
#include <string>
#include <vector>
using namespace std;

/*
解题思路：
先将每一位的数字的罗马数字表示形式列出来
根据输入数字的每一位 去找对应的罗马数字 
最后将所有位的有拼接起来 
append() 添加文本常用方法
1、直接添加一个完整的字符串
2、添加另一个字符串的某一段字串
3、添加几个相同的字符
*/
class Solution_demo06 {
public:
    string intToRoman(int num) {
		if(num<1||num>3999)
			return NULL;
        char* c[4][10]={
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
        string roman;
        roman.append(c[3][num / 1000 % 10]);        //千位
        roman.append(c[2][num / 100 % 10]);			//百位
        roman.append(c[1][num / 10 % 10]);			//十位
        roman.append(c[0][num % 10]);				//个位
        return roman;
    }
};

void main_demo06()
{
	string res;
	Solution_demo06 s1;
	res = s1.intToRoman(2);
	cout<<res<<endl;
	system("pause");
}