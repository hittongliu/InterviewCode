#include <stdlib.h>
#include <stdio.h>

typedef struct Tree
{
    int data;
    Tree *left;
    Tree *right;
}TreeNode;

// 判断t2是否是t1的子树
bool isTree(TreeNode *t1, TreeNode *t2) {
    if (t2 == NULL)
        return true;
    if (t1 == NULL)
        return false;
    if (t1->data == t2->data)
        return isTree(t1->left, t2->left)&&isTree(t1->right, t2->right);
    return isTree(t1->left, t2) || isTree(t1->right,t2);
}

// 中序遍历打印
void fistprint(TreeNode *tree) {
    if (tree == NULL)
        return;
    printf("%d \n", tree->data);
    fistprint(tree->left);
    fistprint(tree->right);
}

// 判断二叉树是否是平衡树，也就是左右子树的深度差是否大于1
// 利用getHeight函数得到高度值，然后遍历
int getHeight(TreeNode *head, int level, bool *balance) {
    if (head == NULL)
        return level;
    int left = getHeight(head->left, level+1, balance);
    if (!*balance)
        return level;
    int right = getHeight(head->right, level+1, balance);
    if (!*balance)
        return level;

    if (((left - right) > 1) || ((right - left) > 1)) {
        *balance = false;
        return level;
    }

    return (left > right)?left:right;

}
// 公共子祖先问题
TreeNode* getFather(TreeNode *head, TreeNode *o1, TreeNode *o2) {
    if ((head == NULL) || (head == o1) || (head == o2))
        return head;
    TreeNode *left = getFather(head->left,o1,o2);
    TreeNode *right = getFather(head->right, o1, o2);
    if ((left != NULL) && (right != NULL))
        return head;
    return left != NULL?left,right;
}
int main()
{
    printf("hello\n");
    TreeNode *t1 = new TreeNode();
    t1->data = 1;
    TreeNode *t2 = new TreeNode();
    t2->data = 2;
    TreeNode *t3 = new TreeNode();
    t3->data = 3;
    TreeNode *t4 = new TreeNode();
    t4->data = 3;
    t1->left = t2;
    t1->right = NULL;
    t2->left = NULL;t2->right = t3;
    t3->left = NULL;t3->right = NULL;
    t4->left = NULL;t4->right = NULL;
    bool b1 = isTree(t1, t2);
    printf("%d\n", b1);
    fistprint(t1);
    bool *balance = new bool();
    *balance = true;
    getHeight(t1, 1, balance);
    printf("%d\n", *balance);


}