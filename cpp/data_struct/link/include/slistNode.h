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
        //unsigned int length(); //链表元素个数 
        void traversal(); //遍历整个链表并打印
        //bool isEmpty(); //判断链表是否为空
        //slistNode<T>* find(T x); //查找第一个值为x的节点，返回节点的地址，找不到返回NULL
        void Add(T x); //表尾添加元素
        //void Delete(T x); //删除第一个值为x的节点
        //void Insert(T x, slistNode<T>* p); //在p节点后插入值为x的节点
        //void InsertHead(T x); //在链表头部插入节点
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

//表尾添加元素
template<class T>
void myslist<T>::Add(T x) 
{
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
        std::cout << node->data.name << std::endl;    
    }
    std::cout << std::endl;
}

template class slistNode<student>;
template class myslist<student>;

#endif
