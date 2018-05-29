/*
2018年5月24日10:44:57
Given preorder and inorder traversal of a tree, construct the binary tree.    //给定先序和中序遍历序列 重新改造二叉树
*/
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
解题思路：
1、先从先序遍历中找出根结点，再根据根结点在中序遍历中的位置，区分出根节点的左子树和右子树
2、重复上述步骤（利用递归的思想）
   在左子树中找出该左子树的根结点（在先序遍历序列中找）--->>>转步骤1
   在右子树中找出该右子树的根结点（在先序遍历序列中找）--->>>转步骤1
*/
class Solution_demo34 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if(preorder.size()!=inorder.size()||preorder.size()==0||inorder.size()==0)
			return NULL;
		int root_pos = 0;
		for(int i=0;i<inorder.size();++i)
		{
			if(inorder[i]==preorder[0])
			{
				root_pos = i;
				break;
			}
		}
		vector<int>left_pre,right_pre,left_in,right_in;     //定义四个动态数组用来存储:左（右）子树的先序序列、左（右）子树的中序序列；
		//分割 先序遍历序列
		for(int i=1;i<=root_pos;++i)
		{
			left_pre.push_back(preorder[i]);
			//right_pre.push_back(preorder[i+root_pos]);
		}
		for(int i=root_pos+1;i<preorder.size();++i)
		{
			right_pre.push_back(preorder[i]);
		}

		//分割 中序遍历序列
		for(int i=0;i<root_pos;++i)
		{
			left_in.push_back(inorder[i]);
			//right_in.push_back(inorder[i+1+root_pos]);
		}
		for(int i=root_pos+1;i<inorder.size();++i)
		{
			right_in.push_back(inorder[i]);
		}
		TreeNode *root = new TreeNode(inorder[root_pos]);
		root->left = buildTree(left_pre,left_in);
		root->right = buildTree(right_pre,right_in);
		return root;
    }
};

void PostTree(TreeNode *root)
{
	if(!root)
		return;
	if(root)
	{
		PostTree(root->left);
		PostTree(root->right);
		cout<<root->val<<ends;
	}
}
int main_demo34(int argc,char **argv)
{
	Solution_demo34 s1;
	vector<int>preorder;
	vector<int>inorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(6);
	preorder.push_back(7);

	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(6);
	inorder.push_back(3);
	inorder.push_back(7);

	TreeNode *root = s1.buildTree(preorder,inorder);
	cout<<"重建出来的树的后序遍历为:"<<endl;
	PostTree(root);
	system("pause");
	return 0;
}