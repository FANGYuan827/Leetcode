/*
2018��5��24��10:44:57
Given preorder and inorder traversal of a tree, construct the binary tree.    //�������������������� ���¸��������
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
1���ȴ�����������ҳ�����㣬�ٸ��ݸ��������������е�λ�ã����ֳ����ڵ����������������
2���ظ��������裨���õݹ��˼�룩
   �����������ҳ����������ĸ���㣨����������������ң�--->>>ת����1
   �����������ҳ����������ĸ���㣨����������������ң�--->>>ת����1
*/
class Solution_demo34 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if(preorder.size()!=inorder.size()||preorder.size()==0||inorder.size()==0)
			return NULL;
		int root_pos = 0;
		for(int i=0;i<inorder.size();++i)
		{
			if(inorder[i]==preorder[0])
			{
				root_pos = i;
				break;
			}
		}
		vector<int>left_pre,right_pre,left_in,right_in;     //�����ĸ���̬���������洢:���ң��������������С����ң��������������У�
		//�ָ� �����������
		for(int i=1;i<=root_pos;++i)
		{
			left_pre.push_back(preorder[i]);
			//right_pre.push_back(preorder[i+root_pos]);
		}
		for(int i=root_pos+1;i<preorder.size();++i)
		{
			right_pre.push_back(preorder[i]);
		}

		//�ָ� �����������
		for(int i=0;i<root_pos;++i)
		{
			left_in.push_back(inorder[i]);
			//right_in.push_back(inorder[i+1+root_pos]);
		}
		for(int i=root_pos+1;i<inorder.size();++i)
		{
			right_in.push_back(inorder[i]);
		}
		TreeNode *root = new TreeNode(inorder[root_pos]);
		root->left = buildTree(left_pre,left_in);
		root->right = buildTree(right_pre,right_in);
		return root;
    }
};

void PostTree(TreeNode *root)
{
	if(!root)
		return;
	if(root)
	{
		PostTree(root->left);
		PostTree(root->right);
		cout<<root->val<<ends;
	}
}
int main_demo34(int argc,char **argv)
{
	Solution_demo34 s1;
	vector<int>preorder;
	vector<int>inorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(6);
	preorder.push_back(7);

	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(6);
	inorder.push_back(3);
	inorder.push_back(7);

	TreeNode *root = s1.buildTree(preorder,inorder);
	cout<<"�ؽ����������ĺ������Ϊ:"<<endl;
	PostTree(root);
	system("pause");
	return 0;
}