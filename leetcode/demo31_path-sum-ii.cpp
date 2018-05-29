/*
2018年5月23日22:03:41

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution_demo31 {
public:
     vector<vector<int> > hasPathSum(TreeNode *root, int sum) {
        vector<vector<int> >res;
		if(!root)
			return res;
		vector<int>tmp;
		FindPath(root,sum,tmp,res);
		return res;
    }
private:
	void FindPath(TreeNode *root,int sum,vector<int> &input,vector<vector<int> >&res)
	{
		if(root!=NULL&&root->left==NULL&&root->right==NULL)    //当走到叶子结点的时候
		{
			input.push_back(root->val);
			if(Sum(input)==sum)
			{
				res.push_back(input);	
			}
			else
			{	input.pop_back();           //删除最后一个元素
		
			}
			input.pop_back();
			return;
		}
		if(root!=NULL)
		{
			input.push_back(root->val);
			FindPath(root->left,sum,input,res);
			FindPath(root->right,sum,input,res);
			input.pop_back();
		}
	}
	int Sum(vector<int> &input)
	{
		int sum = 0;
		vector<int>::iterator it;
		for(it=input.begin();it!=input.end();++it)
		{
			sum+=*it;
		}
		return sum;
	}
};

int main_demo31(int argc,char **argv)
{
	Solution_demo31 s1;
	TreeNode t1(0),t2(1),t3(1),t4(4),t5(5),t6(6),t7(7),t8(8),t9(9);
	t1.left = &t2;
	t1.right = &t3;
	//t2.left = &t4;
	//t2.right = &t5;
	//t3.left = &t6;
	//t3.right = &t7;
	//t5.left = &t8;
	//t8.right = &t9;
	vector<vector<int> >res;
	res = s1.hasPathSum(&t1,1);
	vector<vector<int> >::iterator it_2;
	for(it_2=res.begin();it_2!=res.end();++it_2)
	{
		vector<int>::iterator it_1;
		for(it_1=(*it_2).begin();it_1!=(*it_2).end();++it_1)
			cout<<*it_1<<ends;
		cout<<endl;
	}
	system("pause");
	return 0;
}