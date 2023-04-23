#include <iostream>

//����
//965.��ֵ������
//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
//ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false

class Solution {
public:
    bool isUnivalTree(TreeNode* root)
    {
        if (root == NULL)
            return true;//�ߵ��ջ�û����˵���ǵ�ֵ������
        if ((root->left) && root->left->val != root->val)
            return false;
        if ((root->right) && root->right->val != root->val)
            return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

//104.������������
//����һ�����������ҳ��������ȡ�
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
};


//226.��ת������
//����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
            return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//100.��ͬ����
//�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        bool retleft = isSameTree(p->left, q->left);
        bool rightleft = isSameTree(p->right, q->right);
        return retleft && rightleft;

        // return isSameTree(p->left,q->left)
        // &&isSameTree(p->right,q->right);
    }
};


//144.��������ǰ�����
//����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������
int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int leftsize = TreeSize(root->left);
    int rightsize = TreeSize(root->right);
    return leftsize + rightsize + 1;
}
void _preorderTraversal(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;
    a[(*pi)++] = root->val;
    _preorderTraversal(root->left, a, pi);
    _preorderTraversal(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _preorderTraversal(root, a, &i);
    return a;
}

//101.�Գƶ�����
//����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        return _isSymmetric(root->left, root->right);
    }
    bool _isSymmetric(TreeNode* leftroot, TreeNode* rightroot)
    {
        if (leftroot == nullptr && rightroot == nullptr)
            return true;
        if (leftroot == nullptr || rightroot == nullptr)
            return false;
        if (leftroot->val != rightroot->val)
            return false;
        return _isSymmetric(leftroot->left, rightroot->right) &&
            _isSymmetric(leftroot->right, rightroot->left);
    }
};

//572.��һ����������
//�������ö����� root �� subRoot ��
//���� root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������
//������ڣ����� true �����򣬷��� false ��
//������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣
//tree Ҳ���Կ����������һ��������
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr)
            return false;
        if (isSametree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot);
    }
    bool isSametree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;
        if (root == nullptr || subRoot == nullptr)
            return false;
        if (root->val != subRoot->val)
            return false;
        return isSametree(root->left, subRoot->left) &&
            isSametree(root->right, subRoot->right);
    }
};

//ţ�ͣ�KY11:����������
//����
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
//�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
//������˶������Ժ��ٶԶ������������������������������
//����������
//�������1���ַ��������Ȳ�����100��
//���������
//�����ж���������ݣ�����ÿ�����ݣ� 
//����������ַ���������������������������У�ÿ���ַ����涼��һ���ո� 
//ÿ��������ռһ�С�
#include <iostream>
using namespace std;

class Tree
{
public:
    Tree* CreateTree(char* a, int* pi)
    {
        if (a[*pi] == '#')
        {
            (*pi)++;
            return nullptr;
        }
        Tree* root = (Tree*)malloc(sizeof(Tree));
        root->val = a[(*pi)++];
        root->left = CreateTree(a, pi);
        root->right = CreateTree(a, pi);
        return root;
    }
    void InOrder(Tree* root)
    {
        if (root == nullptr)
            return;
        InOrder(root->left);
        cout << root->val << ' ';
        InOrder(root->right);
    }
private:
    Tree* left;
    Tree* right;
    char val;
};
int main()
{
    char a[100];
    cin >> a;
    int i = 0;
    Tree s1;
    Tree* root = s1.CreateTree(a, &i);
    s1.InOrder(root);
    return 0;
}








