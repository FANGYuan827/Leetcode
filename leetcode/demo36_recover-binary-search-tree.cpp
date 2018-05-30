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
    //������� ����Ǹ���ͨ�ĵݹ鷨���������ֻ�����ڴ��������ʱ�������ѡ��Ƚϣ�
    void InorderTree(TreeNode *root)
    {
        if(!root)
            return;
        InorderTree(root->left);
        if(pre&&pre->val>root->val)      //���ǰһ���ڵ��valֵ���ڸ��ڵ��valֵ���ͽ���ǰ���ڵ��ǰһ���ڵ��Լ���ǰ���ڵ㱣������;
        {
            if(!first)
                first = pre;            //����ǰ�ڵ��ǰһ���ڵ㱣������
			second = root;          //������ֵڶ��������������ô�ٽ���ǰ���ڵ㱣������   //else  ���ܼ��� ��Ȼֻ�������ڵ������ͻᱨ��
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
	cout<<"�������������Ϊ:"<<endl;
	InTree(&t1);
	cout<<endl;
	Solution_demo36 s1;
	s1.recoverTree(&t1);
	cout<<"����֮��������������Ϊ:"<<endl;
	InTree(&t1);
	cout<<endl;
	system("pause");
	return 0;
}