/*
2018年5月23日21:07:51
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
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


class Solution_demo30 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root)
			return false;
		vector<int>tmp;
		vector<vector<int> >res;
		FindPath(root,sum,tmp,res);
		if(res.size()!=0)
			return true;
		else
			return false;
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
				input.pop_back();           //删除最后一个元素
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

int main_demo30(int argc,char **argv)
{
	Solution_demo30 s1;
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8),t9(9);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	t5.left = &t8;
	t8.right = &t9;
	bool res = s1.hasPathSum(&t1,131);
	if(res)
		cout<<"有"<<endl;
	else
		cout<<"没有"<<endl;

	system("pause");
	return 0;
}
