#include <iostream>

using namespace std;
//一般的树都可以通过逆时针旋转90度，变成二叉树
typedef struct _binary_tree_node
{
    int data;
    _binary_tree_node *pLeft;
    _binary_tree_node *pRight;
} BinaryTreeNode, BinaryTree, __node;

//二叉树的递归(recursive)遍历分三种，即前中后序遍历，所谓的前中后是相对根(root)来说的
//其实遍历经过节点的顺序是一样的，只是访问元素内容的时间不一样

//递归遍历
void preOrderTraversal(BinaryTree *root)
{
    if (root)
    {
        cout << root->data << endl; //前序遍历 1 这行代码的位置决定遍历顺序
        preOrderTraversal(root->pLeft);
        //cout<< root->data<<endl;//中序遍历 2
        preOrderTraversal(root->pRight);
        //cout<< root->data<<endl;//后序遍历 3
    }
}

//非递归中序遍历 下面是前序和中序遍历的方法
//使用链表栈存储树节点
#include "../stack/link_stack.hpp"
void notRecursiveTraversal(BinaryTreeNode *const root)
{
    LinkStack<BinaryTreeNode *> stack;
    BinaryTreeNode *node = root;
    while (node || !stack.isEmpty())
    {
        while (node)
        {
            cout << node->data << endl; //前序遍历
            stack.push(node);
            node = node->pLeft;
        }
        if (!stack.isEmpty())
        {
            node = stack.pop();
            // cout<<node->data<<endl;//中序遍历
            node = node->pRight;
        }
    }
}

//非递归后序遍历  后序遍历比较麻烦,一直搞了一天才写出来,太扯淡了
void notRecursiveTraversal2(BinaryTreeNode *const root)
{
    LinkStack<BinaryTreeNode *> stack,s;
    BinaryTreeNode *lastvisit = NULL;
    BinaryTreeNode *p = root;
    while (p || !s.isEmpty())
    {
        if (p)
        {
            s.push(p);
            p = p->pLeft;
        }
        else
        {
            p = s.pop();//一直向左下角走到最后一个
            s.push(p);
            //这个时候的p的左孩子节点肯定是 (没有或者已经访问过)
            //如果p没有右孩子节点，或者已经访问过右孩子，则访问之
            if (!p->pRight || p->pRight == lastvisit)
                {
                    s.pop();
                    cout << p->data<<endl;
                    lastvisit = p;//记标记
                    p = NULL;
                    continue;//从头再来，继续出栈
                }
            p = p->pRight;
        }
    }
}

int main()
{
    BinaryTreeNode root;
    root.data = 0;

    BinaryTreeNode node1;
    node1.data = 1;
    root.pLeft = &node1;

    BinaryTreeNode node2;
    node2.data = 2;
    root.pRight = &node2;

    BinaryTreeNode node3;
    node3.data = 3;
    node1.pLeft = &node3;
    node1.pRight = NULL;
    node3.pLeft = NULL;
    node3.pRight = NULL;

    BinaryTreeNode node4;
    node4.data = 4;
    node2.pRight = &node4;
    node2.pLeft = NULL;
    node4.pLeft = NULL;
    node4.pRight = NULL;

    BinaryTreeNode node5;
    node5.data = 5;
    node1.pRight = &node5;
    node5.pLeft = NULL;
    node5.pRight = NULL;

    BinaryTreeNode node6;
    node6.data = 6;
    node2.pLeft = &node6;
    node6.pLeft = NULL;
    node6.pRight = NULL;

    notRecursiveTraversal(&root);
    cout << "------------------非递归后序遍历-------------------" << endl;
    notRecursiveTraversal2(&root);

    return 0;
}
