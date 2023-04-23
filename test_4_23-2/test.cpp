#include <iostream>

//力扣
//965.单值二叉树
//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//只有给定的树是单值二叉树时，才返回 true；否则返回 false

class Solution {
public:
    bool isUnivalTree(TreeNode* root)
    {
        if (root == NULL)
            return true;//走到空还没结束说明是单值二叉树
        if ((root->left) && root->left->val != root->val)
            return false;
        if ((root->right) && root->right->val != root->val)
            return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

//104.二叉树最大深度
//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

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


//226.翻转二叉树
//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
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

//100.相同的树
//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

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


//144.二叉树的前序遍历
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
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

//101.对称二叉树
//给你一个二叉树的根节点 root ， 检查它是否轴对称。
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

//572.另一棵树的子树
//给你两棵二叉树 root 和 subRoot 。
//检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
//如果存在，返回 true ；否则，返回 false 。
//二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。
//tree 也可以看做它自身的一棵子树。
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

//牛客：KY11:二叉树遍历
//描述
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
//建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
//输入描述：
//输入包括1行字符串，长度不超过100。
//输出描述：
//可能有多组测试数据，对于每组数据， 
//输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。 
//每个输出结果占一行。
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








