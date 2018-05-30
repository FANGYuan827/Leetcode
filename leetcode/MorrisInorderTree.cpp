/*
2018年5月30日14:41:06
*/
#include <iostream>
using namespace std;


struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//Morris中序遍历 时间复杂度O(n) 空间复杂度O(1)
void MorrisInorderTree(TreeNode *root)
{
	if(!root)
		return;
	TreeNode *pre(NULL);
	while(root)
	{
		//左子树为空 直接访问该节点 然后访问右子树    左节点--->>>根节点--->>>右节点：中序遍历
		if(root->left==NULL)
		{
			cout<<root->val<<ends;
			root = root->right;
			continue;                 //直接跳过下面的步骤 进入下一个循环
		}
		//找root的前驱节点
		for(pre = root->left;pre->right&&pre->right!=root;pre=pre->right);    //空循环
		
		//第一次访问root 建立线索
		if(pre->right==NULL)
		{
			pre->right = root;
			root = root->left;
		}
		//第二次访问 说明左子树已经访问过了
		else
		{
			pre->right = NULL;
			cout<<root->val<<ends;
			root = root->right;
		}
	}
}


int main_demoMorris(int argc,char **argv)
{
	TreeNode t1(4),t2(2),t3(6),t4(1),t5(3),t6(5),t7(7);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	cout<<"树的中序遍历为:"<<endl;
	MorrisInorderTree(&t1);
	cout<<endl;
	system("pause");
	return 0;
}