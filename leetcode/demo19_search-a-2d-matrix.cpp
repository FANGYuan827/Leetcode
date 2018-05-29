/*
2018年5月14日16:01:37
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,
Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target =3, returntrue.
*/
#include <iostream>
#include <vector>
using namespace std;


//从左下角开始寻找
class Solution_demo19 {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int row = matrix[0].size();   //二维数组的列数
		int col = matrix.size();     //二维数组的行数
		for(int j=0,i=col-1;i>=0&&j<row;)
		{
			if(matrix[i][j]==target)
				return true;
			if(matrix[i][j]>target)
				--i;
			else
				++j;
		}
		return false;
    }
	bool searchMatrix_1(vector<vector<int> >matrix,int target);
};

//由于有序查找的问题 可以采用二分法查找.
bool Solution_demo19::searchMatrix_1(vector<vector<int> >matrix,int target)	
{
	int row = matrix[0].size();   //二维数组的列数
	int col = matrix.size();     //二维数组的行数
	int start = 0,end = row*col -1;
	while(start<=end)
	{
		int mid = start+(end-start)/2;
		if(target>matrix[mid/row][mid%row])
			start = mid+1;
		else
			if(target==matrix[mid/row][mid%row])
				return true;
			else
				end = mid -1;
	}
	return false;
}
//二分法查找
/*
public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return false;
        int m = matrix.length, n = matrix[0].length;
        int start = 0, end = m * n - 1;
        // 二分查找
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int value = matrix[mid / n][mid % n];
            if (target > value) {
                start = mid + 1;
            } else if (target < value)
                end = mid - 1;
            else
                return true;
        }
        return false;
    }
*/
int main_demo19(int argc,char **argv)
{
	Solution_demo19 s1;
	vector<int>one;
	vector<vector<int> >two;
	for(int i=0;i<12;++i)
	{
		one.push_back(i+1);
		if(one.size()==4)
		{
			two.push_back(one);
			one.clear();
		}
	}
	bool res = false;
	res = s1.searchMatrix_1(two,13);
	if(res)
		cout<<"存在target"<<endl;
	else
		cout<<"不存在target"<<endl;
	system("pause");
	return 0;
}