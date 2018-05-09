/*
2018年4月28日15:40:44
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree{1,#,2,3},

   1
    \
     2
    /
   3

return[1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what"{1,#,2,3}"means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as"{1,2,3,#,#,4,#,#,5}".
*/

//inorder   --->>>>中序遍历
//preorder  --->>>>先序遍历
//postorder --->>>>后序遍历
#include "iostream"
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution_demo17 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int>res;
		if(root==NULL)
			return res;
		stack<TreeNode *>my_stack;
		my_stack.push(root);
		TreeNode *last_pop = root;
		while(!my_stack.empty())
		{
			TreeNode *top = my_stack.top();
			if(top->left!=NULL && top->left!=last_pop && top->right!=last_pop)            //push left
			{
				my_stack.push(top->left);
			}
			else
				if(top->right!=NULL && top->right!=last_pop && (top->left ==NULL||top->left == last_pop))             //push right
				{
					my_stack.push(top->right);
					res.push_back(top->val);                                 //visit top
				}
				else
				{
					my_stack.pop();
					last_pop = top;
					if(top->right == NULL)                //visit top
						res.push_back(top->val);
				}
		}
		return res;
        
    }
};

void main_demo17()
{
	Solution_demo17 s1;
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8),t9(9);
	t1.left = &t2;
	t1.right = &t3;

	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;

	t5.left = &t8;
	t6.right = &t9;
	vector<int>res;
	res = s1.inorderTraversal(&t1);
	vector<int>::iterator it;
	for(it=res.begin();it!=res.end();++it)
		cout<<*it<<ends;
	cout<<endl;
	system("pause");
}