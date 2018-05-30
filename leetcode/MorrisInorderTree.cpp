/*
2018��5��30��14:41:06
*/
#include <iostream>
using namespace std;


struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//Morris������� ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
void MorrisInorderTree(TreeNode *root)
{
	if(!root)
		return;
	TreeNode *pre(NULL);
	while(root)
	{
		//������Ϊ�� ֱ�ӷ��ʸýڵ� Ȼ�����������    ��ڵ�--->>>���ڵ�--->>>�ҽڵ㣺�������
		if(root->left==NULL)
		{
			cout<<root->val<<ends;
			root = root->right;
			continue;                 //ֱ����������Ĳ��� ������һ��ѭ��
		}
		//��root��ǰ���ڵ�
		for(pre = root->left;pre->right&&pre->right!=root;pre=pre->right);    //��ѭ��
		
		//��һ�η���root ��������
		if(pre->right==NULL)
		{
			pre->right = root;
			root = root->left;
		}
		//�ڶ��η��� ˵���������Ѿ����ʹ���
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
	cout<<"�����������Ϊ:"<<endl;
	MorrisInorderTree(&t1);
	cout<<endl;
	system("pause");
	return 0;
}