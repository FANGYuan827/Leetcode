/*
2018��5��29��16:43:18
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
*/
#include <iostream>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//������������������������������;
class Solution_demo36 {
public:
    void recoverTree(TreeNode *root) {
        
    }
};

void InTree(TreeNode *root)
{
	if(!root)
		return;
	if(root)
	{
		InTree(root->left);
		cout<<root->val<<ends;
		InTree(root->right);
	}
}
int main(int argc,char **argv)
{



	system("pause");
	return 0;
}