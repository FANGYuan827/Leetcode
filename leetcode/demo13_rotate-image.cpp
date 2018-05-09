/*
2018年4月25日19:49:02
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include "iostream"
#include <vector>
using namespace std;

class Solution_demo13 {
public:
    void rotate(vector<vector<int> > &matrix) {         //暴力解题 算法复杂度O(n^2)
		if(matrix.size()<1)
			return;
		vector<vector<int> >res;
		vector<int> tmp;
		int row = matrix.size();        //取出列数
		int col = matrix[0].size();	   //取出列数
		for(int i = 0;i<col;++i)
		{
			for(int j = row-1;j>=0;--j)
			{
				tmp.push_back(matrix[j][i]);
			}
			res.push_back(tmp);
			tmp.clear();
		}
		matrix = res;
    }
	
	//翻转法
	//解题思路:先按照y轴交换 再按照副对角线交换
	void rotate_1(vector<vector<int> > &matrix) {  
		if(matrix.size()<1)
			return;
		int length = matrix.size();
		//先按照y轴进行交换
		for(int i=0;i<length/2;++i)
		{
			for(int j=0;j<length;++j)
			{
				my_swap(matrix[j][i],matrix[j][length-i-1]);
			}
		}
		//再按照副对角线进行交换
		for(int i=0;i<length;++i)
		{
			for(int j=0;j<length-i-1;++j)
			{
				my_swap(matrix[i][j],matrix[length-j-1][length-i-1]);
			}
		}
	}
private:
	template<typename T>        //定义模板的格式 可以定义模板类 或者 模板函数
	void my_swap(T &num1,T &num2)
	{
		T tmp;
		tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
};


void main_demo13()
{
	Solution_demo13 s1;
	vector<vector<int> >input;
	vector<int> tmp;
	vector<vector<int> >::iterator it_2;
	vector<int>::iterator it_1;
	for(int i=0;i<16;++i)
	{
		tmp.push_back(i+1);
		if((i+1)%4==0)
		{
			input.push_back(tmp);
			tmp.clear();
		}
	}
	cout<<"Before:"<<endl;
	for(it_2=input.begin();it_2!=input.end();++it_2)
	{
		for(it_1 = (*it_2).begin();it_1!=(*it_2).end();++it_1)
		{
			cout<<*it_1<<ends;
		}
		cout<<endl;
	}
	s1.rotate_1(input);
	cout<<"After:"<<endl;
	for(it_2=input.begin();it_2!=input.end();++it_2)
	{
		for(it_1 = (*it_2).begin();it_1!=(*it_2).end();++it_1)
		{
			cout<<*it_1<<ends;
		}
		cout<<endl;
	}

	system("pause");
}