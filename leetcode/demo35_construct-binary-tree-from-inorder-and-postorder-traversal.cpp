/*
2018年5月29日15:40:31
Given inorder and postorder traversal of a tree, construct the binary tree.   //根据中序遍历序列和后序遍历序列，构造二叉树
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
根据后序遍历的特点：根结点是在最后遍历的，
根据后序遍历找到根节点在中序遍历序列中的位置，区分出树的左子树和右子树
在左子树中，利用同样的方式找出根结点，区分出左右子树；
在右子树中，利用同样的方式找出根结点，区分出左右子树；
利用递归的方式构造出树;
*/
class Solution_demo35 {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if(inorder.size()!=postorder.size()||inorder.size()==0||postorder.size()==0)
			return NULL;
		int root_pos = 0;
		//确定根结点的位置
		for(int i=0;i<inorder.size();++i)
		{
			if(postorder[postorder.size()-1]==inorder[i])
			{
				root_pos = i;
				break;
			}
		}
		vector<int>left_in,left_post,right_in,right_post;
		
		//找出左子树的中序遍历序列 右子树的中序遍历序列
		for(int i=0;i<root_pos;++i)
			left_in.push_back(inorder[i]);
		for(int i=root_pos+1;i<inorder.size();++i)
			right_in.push_back(inorder[i]);

		//找出左子树的后序遍历序列  右子树的后序遍历序列
		for(int i=root_pos;i<=(int)(postorder.size()-2);++i)        //这里如果不加上(int) 就会提示数组越界，程序运行就会出错。个人觉得可能是：有符号和无符号数的问题
			right_post.push_back(postorder[i]);
		for(int i=0;i<root_pos;++i)
			left_post.push_back(postorder[i]);

		TreeNode *root = new TreeNode(postorder[postorder.size()-1]);
		root->left = buildTree(left_in,left_post);
		root->right = buildTree(right_in,right_post);
		return root;
	}
};


void PreTree(TreeNode *root)
{
	if(!root)
		return;
	if(root)
	{
		cout<<root->val<<ends;
		PreTree(root->left);
		PreTree(root->right);
	}	
}
int main_demo35(int argc,char **argv)
{
	Solution_demo35 s1;
	vector<int>inorder,postorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(6);
	inorder.push_back(3);
	inorder.push_back(7);

	postorder.push_back(4);
	postorder.push_back(5);
	postorder.push_back(2);
	postorder.push_back(6);
	postorder.push_back(7);
	postorder.push_back(3);
	postorder.push_back(1);

	TreeNode *root = s1.buildTree(inorder,postorder);
	cout<<"所构造树的先序遍历序列为:"<<endl;
	PreTree(root);
	cout<<endl;
	system("pause");
	return 0;
}