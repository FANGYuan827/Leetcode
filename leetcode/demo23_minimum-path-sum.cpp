/*
2018��5��15��16:26:36
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time
*/
#include <iostream>
#include <vector>
using namespace std;



/*     //�Լ�д�Ĵ��� ���У�����ߺ��ϱ�����ȵ����Ͳ���������
		int row = grid.size();           // ��ά�������
		int col = grid[0].size();		//	��ά�������
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
��ά��̬�滮�����⣬��[0][0]����������ÿһ��Ԫ�ص�·���Ͷ���Ҫ���� ���ҽ��䱣������ ,���Ա�����һ����ά�����У����߱��浽���������У���ԭ����Ԫ�ظ��ƻ�����
����Ǳ���������һ����ά�����У��ö�ά�����ά�Ⱥ����������ά��Ҫ��ͬ���Ļ�����ô�����ά�����е�����Ԫ�ش������˼���ǣ���[0][0]����������õ�Ԫ��������·���ĺͣ�
*/
class Solution_demo23 {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int row = grid.size();           // ��ά�������
		int col = grid[0].size();		//	��ά�������
		for(int i=0;i<row;++i)
		{
			if(i-1>=0)             //�ӵڶ��п�ʼ��ÿһ�еĵ�һ��Ԫ��ֻ���ǴӸ�Ԫ�ص��Ϸ�����-->>>��һ��Ԫ��ֻ�ܾ��ɸ�Ԫ�ص��Ϸ�Ԫ�ص���
				grid[i][0] +=grid[i-1][0];
			for(int j=1;j<col;++j)
			{
				if(i-1>=0)        
					grid[i][j] +=min(grid[i-1][j],grid[i][j-1]);
				else
					grid[i][j] +=grid[i][j-1];            //��Ե�һ��Ԫ�أ���һ�е�Ԫ��ֻ���ǴӸ�Ԫ�ص���ߵ���������Ǿ��ɸ�Ԫ�ص��Ϸ�����ġ�
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
	cout<<"��С·����ֵΪ:"<<res<<endl;
	system("pause");
	return 0;
}