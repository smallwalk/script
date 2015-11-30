#ifndef SLIST_NODE_HXX
#define SLIST_NODE_HXX
#include <string>
#include <iostream>
#include "student.h"
template<class T>
class slistNode
{
    public:
        slistNode() {next=NULL;}
        T data;
        slistNode* next;
};

template<class T>
class myslist
{
    private :
        unsigned int list_length; //链表长度
        slistNode<T>* node; //临时节点
        slistNode<T>* last_node; //尾结点
        slistNode<T>* head_node; //头结点
    public :
        myslist(); //初始化
        unsigned int length(); //链表元素个数 
        void traversal(); //遍历整个链表并打印
        bool isEmpty(); //判断链表是否为空
        slistNode<T>* find(T x); //查找第一个值为x的节点，返回节点的地址，找不到返回NULL
        void Add(T x); //表尾添加元素
        void Delete(T x); //删除第一个值为x的节点
        void Insert(T x, slistNode<T>* p); //在p节点后插入值为x的节点
        void InsertHead(T x); //在链表头部插入节点
};

//构造函数
template<class T>
myslist<T>::myslist() 
{
   node = NULL;
   last_node = NULL;
   head_node = NULL;
   list_length = 0;
}

//返回链表长度
template<class T>
unsigned int myslist<T>::length() 
{
    return list_length;
}

//链表是否为空
template<class T>
bool myslist<T>::isEmpty() 
{
    return list_length == 0;
}

//表尾添加元素
template<class T>
void myslist<T>::Add(T x) 
{
    //new node
    node = new slistNode<T>(); 
    node->data = x;
    //没有尾节点，链表为空
    if (last_node == NULL) {
        last_node = node;
        head_node = node;
    }
    else {
        last_node->next = node; 
        last_node = node;
    }
    ++list_length;
}

//遍历元素并打印
template<class T>
void myslist<T>::traversal() 
{
    node = head_node;
    while (node != NULL) {
        std::cout << "name:" << node->data.name 
            << " age:" << node->data.age 
            << " gender:" << node->data.gender
            << " height:" << node->data.height
            << " weight:" << node->data.weight
            << std::endl;    
        node = node->next;
    }
    std::cout << std::endl;
}

//查找特定元素
template<class T>
slistNode<T>* myslist<T>::find(T x)
{
    node = head_node;
    while (node != NULL && node->data.name != x.name) {
        node = node->next;
    }
    return node;
}

//删除特定元素
template<class T>
void myslist<T>::Delete(T x) 
{
    node = head_node;
    //临时申请
    slistNode<T> * pre_node = head_node;
    while (node != NULL) {
        if (node->data.name == x.name) {
            if (node == head_node) {
                head_node = node->next;
            }
            else {
                pre_node->next = node->next;
            }
            --list_length;
        }
        pre_node = node;
        node = node->next; 
    }
}


//在p节点后插入值为x的节点
template<class T>
void myslist<T>::Insert(T x, slistNode<T>* p) 
{
    node = head_node;    
    while (node != NULL) {
        if (p->data.name == node->data.name) {
            slistNode<T> * new_node = new slistNode<T>(); 
            new_node->data = x;
            new_node->next = node->next;
            node->next = new_node;
            ++list_length;
            break;
        }
        node = node->next;
    }
}

//在链表头部插入节点
template<class T>
void myslist<T>::InsertHead(T x)
{
    // new node
    slistNode<T> * new_node = new slistNode<T>();
    new_node->data = x;
    new_node->next = head_node;
    head_node = new_node;
    ++list_length;
}

template class slistNode<student>;
template class myslist<student>;

#endif
