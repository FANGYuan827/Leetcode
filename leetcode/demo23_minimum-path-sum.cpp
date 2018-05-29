/*
2018年5月15日16:26:36
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time
*/
#include <iostream>
#include <vector>
using namespace std;



/*     //自己写的代码 不行，当左边和上边有相等的数就不能能用了
		int row = grid.size();           // 二维数组的行
		int col = grid[0].size();		//	二维数组的列
		int res = grid[row-1][col-1];
		int i=row-1,j=col-1;
		while(i>=1&&j>=1)
		{
			if(grid[i-1][j]>=grid[i][j-1])
			{
				res+=grid[i][j-1];
				--j;
			}
			else     
			{
				res+=grid[i-1][j];
				--i;
			}
		}
		if(i==0&&j!=0)
		{
			--j;
			for(;j>=0;--j)
				res+=grid[i][j];
		}
		if(j==0&&i!=0)
		{
			--i;
			for(;i>=0;--i)
				res+=grid[i][j];
		}
		return res;
*/

/*
二维动态规划的问题，从[0][0]出发，到达每一个元素的路径和都需要计算 并且将其保存起来 ,可以保存在一个二维数组中，或者保存到输入数组中，将原数组元素给破坏掉。
如果是保存在另外一个二维数组中（该二维数组的维度和输入数组的维度要相同）的话，那么这个二维数组中的所有元素代表的意思就是：从[0][0]出发，到达该点元素所经过路径的和；
*/
class Solution_demo23 {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int row = grid.size();           // 二维数组的行
		int col = grid[0].size();		//	二维数组的列
		for(int i=0;i<row;++i)
		{
			if(i-1>=0)             //从第二行开始，每一行的第一个元素只能是从该元素的上方到达-->>>第一列元素只能经由该元素的上方元素到达
				grid[i][0] +=grid[i-1][0];
			for(int j=1;j<col;++j)
			{
				if(i-1>=0)        
					grid[i][j] +=min(grid[i-1][j],grid[i][j-1]);
				else
					grid[i][j] +=grid[i][j-1];            //针对第一行元素，这一行的元素只能是从该元素的左边到达，不可能是经由该元素的上方到达的。
			}
		}
		return grid[row-1][col-1];                  
    }
};

int main_demo23(int argc,char**argv)
{
	Solution_demo23 s1;
	int res = 0;
	vector<vector<int> >two;
	vector<int>one;
	//one.push_back(1);
	//two.push_back(one);
	one.push_back(1);
	one.push_back(4);
	one.push_back(8);
	one.push_back(6);
	one.push_back(2);
	one.push_back(2);
	one.push_back(1);
	one.push_back(7);
	two.push_back(one);
	one.clear();
	one.push_back(4);
	one.push_back(7);
	one.push_back(3);
	one.push_back(1);
	one.push_back(4);
	one.push_back(5);
	one.push_back(5);
	one.push_back(1);
	two.push_back(one);
	one.clear();

	one.push_back(8);
	one.push_back(8);
	one.push_back(2);
	one.push_back(1);
	one.push_back(1);
	one.push_back(8);
	one.push_back(0);
	one.push_back(1);
	two.push_back(one);
	one.clear();

	one.push_back(8);
	one.push_back(9);
	one.push_back(2);
	one.push_back(9);
	one.push_back(8);
	one.push_back(0);
	one.push_back(8);
	one.push_back(9);
	two.push_back(one);
	one.clear();

	one.push_back(5);
	one.push_back(7);
	one.push_back(5);
	one.push_back(7);
	one.push_back(1);
	one.push_back(8);
	one.push_back(5);
	one.push_back(5);
	two.push_back(one);
	one.clear();

	one.push_back(7);
	one.push_back(0);
	one.push_back(9);
	one.push_back(4);
	one.push_back(5);
	one.push_back(6);
	one.push_back(5);
	one.push_back(6);
	two.push_back(one);
	one.clear();

	one.push_back(4);
	one.push_back(9);
	one.push_back(9);
	one.push_back(7);
	one.push_back(9);
	one.push_back(1);
	one.push_back(9);
	one.push_back(0);
	two.push_back(one);
	one.clear();
   /*
	for(int i=0;i<20;++i)
	{
		one.push_back(i+1);
		if((i+1)%5==0)
		{
			two.push_back(one);
			one.clear();
		}
	}
	*/
	
	res = s1.minPathSum(two);
	cout<<"最小路径的值为:"<<res<<endl;
	system("pause");
	return 0;
}