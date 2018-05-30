/*
2018年5月29日16:43:18
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

//二叉搜索树的中序遍历正好是升序的;
class Solution_demo36 {
public:
	TreeNode *pre,*first,*second;
    void recoverTree(TreeNode *root) {
        if(!root)
            return;
		pre = first = second = NULL;
        InorderTree(root);
        if(first&&second)
            swap(first->val,second->val);
    }
private:
    //中序遍历 这就是个普通的递归法中序遍历（只不过在处理根结点的时候进行了选择比较）
    void InorderTree(TreeNode *root)
    {
        if(!root)
            return;
        InorderTree(root->left);
        if(pre&&pre->val>root->val)      //如果前一个节点的val值大于根节点的val值，就将当前根节点的前一个节点以及当前根节点保存下来;
        {
            if(!first)
                first = pre;            //将当前节点的前一个节点保存下来
			second = root;          //如果出现第二个这种情况，那么再将当前根节点保存下来   //else  不能加上 不然只有两个节点的情况就会报错
        }
        pre = root;
        InorderTree(root->right);
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
int main_demo36(int argc,char **argv)
{
	TreeNode t1(4),t2(2),t3(3),t4(1),t5(6),t6(5),t7(7);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	cout<<"该树的中序遍历为:"<<endl;
	InTree(&t1);
	cout<<endl;
	Solution_demo36 s1;
	s1.recoverTree(&t1);
	cout<<"调整之后该树的中序遍历为:"<<endl;
	InTree(&t1);
	cout<<endl;
	system("pause");
	return 0;
}