/*
2018年5月14日19:38:54
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return[0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note: 
For a given n, a gray code sequence is not uniquely defined.

For example,[0,2,3,1]is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


//考查n位格雷码的生成
class Solution_demo22 {
public:
    vector<int> grayCode(int n) {      //n表示格雷码的位数
        vector<int> res;
		if(n<1)
        {
            res.push_back(0);
            return res;
        }
		vector<string> graycode;
		string aa = "0";
		string bb = "1";
		graycode.push_back(aa);
		graycode.push_back(bb);
		if(n>1)
		{
			for(int i=2;i<=n;++i)
			{
				vector<string> tmpgraycode;
				for(int k=0;k<graycode.size();++k)
				{
					tmpgraycode.push_back(graycode[k]);
				}
				int tmpgraycodesize = tmpgraycode.size();
				for(int k=0;k<tmpgraycodesize;++k)
				{
					string tmpbitzero = "0";
					tmpbitzero +=tmpgraycode[k];
					graycode[k] = tmpbitzero;
				}

				for(int k=tmpgraycodesize-1;k>=0;--k)
				{
					string tmpbitone = "1";
					tmpbitone +=tmpgraycode[k];
					graycode.push_back(tmpbitone);
				}
				tmpgraycode.clear();
			}
		}
		for(int i=0;i<graycode.size();++i)
		{
			int num = stoi(graycode[i],0,2);
			res.push_back(num);
		}
		return res;
    }
	vector<int>grayCode_1(int n);
};

//网上大神的解法
//位运算
vector<int> Solution_demo22::grayCode_1(int n)
{
	vector<int> res;
	res.push_back(0);
	for(int i=0;i<n;++i)
	{
		const int height_bit = 1<<i;
		for(int j=res.size()-1;j>=0;--j)
			res.push_back(height_bit | res[j]);
	}
	return res;
}
int main_demo22(int argc,char **argv)
{

	Solution_demo22 s1;
	vector<int> res;
	res = s1.grayCode_1(3);
	vector<int>::iterator it;
	for(it = res.begin();it!=res.end();++it)
		cout<<*it<<ends;
	cout<<endl;
	system("pause");
	return 0;
}