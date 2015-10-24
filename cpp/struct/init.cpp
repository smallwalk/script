#include <iostream>

using namespace std;

struct BiNode {
    char data;
    BiNode *lchild;
    BiNode *rchild;
};

BiNode *T;

void CreateBiTree(BiNode * &T);
void PreOrder(BiNode * T);

int main() 
{
    cout << "创建一颗树，A->Z字符代表树的数据，用'#'表示空树:" << endl;
    //char array[] = {'E', 'A', '#', 'C', 'B', '#', '#', 'D', '#', '#', 'G', 'F', '#', '#', '#'};
    //BiNode *T传T 和 BiNode T，传&T的区别是？
    //BiNode *T表示T是一个存放BiNode数据的指针变量。TiNode T表示T是一个存储BiNode数据的变量，&T表示这个变量的地址(地址是不能变的)
    CreateBiTree(T);
    cout << "preOrder" << endl;
    PreOrder(T);
}

/**
 * 传址
 */
void PreOrder(BiNode * T) 
{
    if (T == NULL) {
        return;
    }
    cout << T->data << endl;
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

/**
 * 创建二叉树
 * 传址
 */
void CreateBiTree(BiNode * &T) 
{
    char ch;
    cin >> ch;
    if (ch == '#') {
        T = NULL;
    }
    else {
        //申请一个BiNode结构类型的内存，返回该内存块的地址
        T = new BiNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
