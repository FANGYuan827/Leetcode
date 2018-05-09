/*
2018年4月27日20:44:47

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/
#include "iostream"
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
自己写的代码还可以继续优化 可以不需要借助stack这个数据结构
*/
class Solution_demo16 {
public:
    bool isBalanced(TreeNode *root) {
		if(root==NULL)
			return true;
		stack<TreeNode *>my_stack;
		DLR(root,my_stack);
		while(!my_stack.empty())
		{
			TreeNode *tmp = my_stack.top();
			my_stack.pop();
			int left = TreeDeepth(tmp->left);
			int right = TreeDeepth(tmp->right);
			if(abs(left-right)>1)
				return false;
		}
		return true;
        
    }
private:
	int TreeDeepth(TreeNode *root)
	{
		if(root==NULL)
			return 0;
		int deepth_left = TreeDeepth(root->left)+1;
		int deepth_right = TreeDeepth(root->right)+1;
		return deepth_left>deepth_right?deepth_left:deepth_right;
	}
	void DLR(TreeNode *root,stack<TreeNode *>&my_stack)
	{
		if(root==NULL)
			return ;
		my_stack.push(root);
		DLR(root->left,my_stack);
		DLR(root->right,my_stack);
	}
};

void main_demo16()
{
	Solution_demo16 s1;
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	t4.left = &t8;
	bool res = s1.isBalanced(&t1);
	if(res)
		cout<<"是高度平衡二叉树"<<endl;
	else
		cout<<"不是高度平衡二叉树"<<endl;
	system("pause");
}