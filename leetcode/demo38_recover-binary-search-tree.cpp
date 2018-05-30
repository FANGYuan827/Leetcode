/*
2018年5月30日15:42:34
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.    //路径可以是从任何节点开始 任何节点结束
For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6.
*/
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution_demo38 {
public:
    int maxPathSum(TreeNode *root) {
        if(!root)
			return 0;
		int maxsum= 0 ;
		vector<int>tmp;
		vector<vector<int> >res;
		FindPath(root,tmp,res);
		return maxsum;
    }
private:
	void FindPath(TreeNode *root,vector<int>&tmp,vector<vector<int> >&res)
	{
		if(!root)
			return;
		if(root->left==NULL&&root->right==NULL)
		{
			tmp.push_back(root->val);
			res.push_back(tmp);
			tmp.pop_back();             //删除最后一个元素
			return;
		}
		if(root)
		{
			tmp.push_back(root->val);
			FindPath(root->left,tmp,res);
			FindPath(root->right,tmp,res);
			tmp.pop_back();
		}
	}
};


int main(int argc,char **argv)
{
	Solution_demo38 s1;
	TreeNode t1(4),t2(2),t3(-3),t4(11),t5(-6),t6(25),t7(-7);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;

	int res = s1.maxPathSum(&t1);
	cout<<"该树的最大路径和为:"<<res<<endl;
	system("pause");
	return 0;
}