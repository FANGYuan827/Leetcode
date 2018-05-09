/*
2018��4��22��21:56:06
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
#include "iostream"
#include <string>
#include <vector>
using namespace std;

/*
����˼·��
�Ƚ�ÿһλ�����ֵ��������ֱ�ʾ��ʽ�г���
�����������ֵ�ÿһλ ȥ�Ҷ�Ӧ���������� 
�������λ����ƴ������ 
append() ����ı����÷���
1��ֱ�����һ���������ַ���
2�������һ���ַ�����ĳһ���ִ�
3����Ӽ�����ͬ���ַ�
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
        roman.append(c[3][num / 1000 % 10]);        //ǧλ
        roman.append(c[2][num / 100 % 10]);			//��λ
        roman.append(c[1][num / 10 % 10]);			//ʮλ
        roman.append(c[0][num % 10]);				//��λ
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