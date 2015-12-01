#ifndef DLIST_HXX
#define DLIST_HXX

using namespace std;

template<class T>
class listNode 
{
    public:
        listNode() {pre = NULL; next = NULL;}
        T data;
        listNode* pre;
        listNode* next;
};

template<class T>
class dlist
{
    private: 
        unsigned int list_length;
        listNode<T>* node; //临时节点
        listNode<T>* head_node; //头节点
        listNode<T>* last_node; //尾节点

    public:
        dlist();
        unsigned int length(); //链表长度
        void traversal(); //遍历整个链表并打印
        bool isEmpty(); //链表是否为空
        listNode<T>* find(T x); //查找第一个值为x的节点，返回节点的地址
        bool Insert(T x, listNode<T>* p); //在p节点后插入值为x的节点
        bool Add(T x); //表尾添加元素
        bool Delete(T x); //删除第一个值为x的节点
};

//构造函数
template<class T>
dlist<T>::dlist()
{
    list_length = 0;
    node = NULL;
    head_node = NULL;
    last_node = NULL;
}

//返回链表长度
template<class T>
unsigned int dlist<T>::length() 
{
    return list_length;
}

//遍历整个链表并打印
template<class T>
void dlist<T>::traversal() 
{
    node = head_node;
    while (node != NULL) {
        cout << "姓名:" << node->data.name 
            << " 性别:" << node->data.gender
            << " 年龄:" << node->data.age
            << endl;
        node = node->next;
    }
    cout << endl;
}

//链表是否为空
template<class T>
bool dlist<T>::isEmpty()
{
    return list_length == 0;
}

//查找给定x的值置
template<class T>
listNode<T>* dlist<T>::find(T x)
{
    node = head_node; 
    while (node != NULL && node->data.name != x.name) {
        node = node->next;
    }
    return node;
}

//在p节点后插入值为x的节点
template<class T>
bool dlist<T>::Insert(T x, listNode<T>* p)
{
    node = head_node;
    while (node != NULL) {
        if (p->data.name == x.name) {
            //新节点
            listNode<T> * new_node = new listNode<T>();
            new_node->data = x;
            new_node->pre = node;
            new_node->next = node->next;

            node->next = new_node;
            ++list_length;
            return true;
        }
        node = node->next;
    }
    return false;
}

//表尾添加节点
template<class T>
bool dlist<T>::Add(T x)
{
    listNode<T>* new_node = new listNode<T>();
    new_node->next = NULL;
    new_node->data = x;
    if (list_length == 0) {
        //空节点
        new_node->pre = NULL;
        head_node = new_node;
    }
    else {
        new_node->pre = last_node;
        last_node->next = new_node;
    }
    last_node = new_node;
    ++list_length;
    return true;
}

//删除第一个值是x的节点
template<class T>
bool dlist<T>::Delete(T x)
{
    node = head_node;
    while (node != NULL) {
        if (node->data.name == x.name) {
            if (node->pre == NULL) {
                //删除表头。如果就一个节点：head_node = NULL；如果大于一个节点:node->next变为表头
                if (node->next == NULL) {
                    //就一个节点
                    head_node = NULL;
                }
                else {
                    head_node = node->next; 
                    node->next->pre = NULL;
                }
            }
            else {
                //删除非表头。如果是尾结点：node->pre->next = NULL,last_node = node->pre，如果不是尾结点：node->pre->next = node->next, node->next->pre = node->pre
                //如果只是一个节点，走上一个判断     
                if (node->next == NULL) {
                    //尾结点  
                    node->pre->next = NULL;
                    last_node = node->pre;
                }
                else {
                    //非尾结点
                    node->pre->next = node->next;
                    node->next->pre = node->pre;
                }
            }
            --list_length;
            return true;
        }
        node = node->next;
    }
    return false;
}



#endif
