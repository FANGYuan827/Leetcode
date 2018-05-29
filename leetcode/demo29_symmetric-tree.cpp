/*
2018年5月23日20:31:00
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*/
#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution_demo29 {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root)
			return true;
		return Symmetric(root->left,root->right);
    }
private:
	bool Symmetric(TreeNode *t1,TreeNode *t2)
	{
		if(t1==NULL&&t2==NULL)
			return true;
		if((t1==NULL)||(t2==NULL))
		{
			return false;
		}
		if(t1->val!=t2->val)
			return false;
		else
			return Symmetric(t1->left,t2->right)&&Symmetric(t1->right,t2->left);
	}
};
int main_demo29(int argc,char **argv)
{
	Solution_demo29 s1;
	TreeNode t1(1),t2(3),t3(3),t4(4),t5(5),t6(5),t7(5),t8(8),t9(9);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	//t4.left = &t8;
	//t8.right = &t9;
	bool res = s1.isSymmetric(&t1);
	if(res)
		cout<<"是关于自身镜像"<<endl;
	else
		cout<<"不是关于自身镜像"<<endl;
	system("pause");
	return 0;
}
