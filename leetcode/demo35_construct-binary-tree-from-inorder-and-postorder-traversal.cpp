/*
2018��5��29��15:40:31
Given inorder and postorder traversal of a tree, construct the binary tree.   //��������������кͺ���������У����������
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
����˼·��
���ݺ���������ص㣺����������������ģ�
���ݺ�������ҵ����ڵ���������������е�λ�ã����ֳ�������������������
���������У�����ͬ���ķ�ʽ�ҳ�����㣬���ֳ�����������
���������У�����ͬ���ķ�ʽ�ҳ�����㣬���ֳ�����������
���õݹ�ķ�ʽ�������;
*/
class Solution_demo35 {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if(inorder.size()!=postorder.size()||inorder.size()==0||postorder.size()==0)
			return NULL;
		int root_pos = 0;
		//ȷ��������λ��
		for(int i=0;i<inorder.size();++i)
		{
			if(postorder[postorder.size()-1]==inorder[i])
			{
				root_pos = i;
				break;
			}
		}
		vector<int>left_in,left_post,right_in,right_post;
		
		//�ҳ�������������������� �������������������
		for(int i=0;i<root_pos;++i)
			left_in.push_back(inorder[i]);
		for(int i=root_pos+1;i<inorder.size();++i)
			right_in.push_back(inorder[i]);

		//�ҳ��������ĺ����������  �������ĺ����������
		for(int i=root_pos;i<=(int)(postorder.size()-2);++i)        //�������������(int) �ͻ���ʾ����Խ�磬�������оͻ�������˾��ÿ����ǣ��з��ź��޷�����������
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
	cout<<"���������������������Ϊ:"<<endl;
	PreTree(root);
	cout<<endl;
	system("pause");
	return 0;
}