/*
2018年5月30日11:04:23
*/
#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x):val(x),left(NULL),right(NULL){}
};

class Solution_demo37 {
public:
    TreeNode *pre,*first,*second;
    bool isValidBST(TreeNode *root) {
         if(!root)
            return true;
		pre = first = second = NULL;
        InorderTree(root);
        if(first&&second)
            return false;
        else
            return true;
    }
private:
    //中序遍历
    void InorderTree(TreeNode *root)
    {
        if(!root)
            return;
        InorderTree(root->left);
        if(pre&&pre->val>=root->val)
        {
            if(!first)
                first = pre;
            second = root;
        }
        pre = root;
        InorderTree(root->right);
    }
};

int main_demo37(int argc,char **argv)
{
	TreeNode t1(4),t2(2),t3(6),t4(1),t5(3),t6(5),t7(7);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	Solution_demo37 s1;
	bool res = s1.isValidBST(&t1);
	if(res)
		cout<<"是二叉搜索树"<<endl;
	else
		cout<<"不是二叉搜索树"<<endl;
	system("pause");
	return 0;
}