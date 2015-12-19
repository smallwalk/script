#ifndef MYSTACK_H
#define MYSTACK_H


template<class T>
class stackNode
{
    public:
        stackNode() : next(NULL) {}
        T data; //值
        stackNode* next; //指向下一节点的指针
};

template<class T>
class mystack
{
    private:
        unsigned int stack_length;
        stackNode<T>* node; //临时节点
        stackNode<T>* head_node; //头结点

    public:
        mystack();
        unsigned int length();
        bool push(T x);
        bool isEmpty();
        bool pop();
        T top();
        bool clear();
};

template<class T>
mystack<T>::mystack()
{
    stack_length = 0; 
    node = NULL;
    head_node = NULL;
}

template<class T>
unsigned int mystack<T>::length() 
{
    return stack_length;
}

template<class T>
bool mystack<T>::isEmpty()
{
    return stack_length == 0;
}

template<class T>
bool mystack<T>::push(T x) 
{
    //新节点
    stackNode<T>* new_node = new stackNode<T>(); 
    new_node->data = x;
    new_node->next = head_node;
    head_node = new_node; 
    stack_length++;
    return true;
}

template<class T>
bool mystack<T>::pop()
{
    if (isEmpty()) {
        return false;
    }
    node = head_node;
    head_node = head_node->next;
    //删除头节点
    delete(node);
    stack_length--;
    return true;
}

template<class T>
T mystack<T>::top()
{
    if (!isEmpty()) {
        return head_node->data;
    }
}

template<class T>
bool mystack<T>::clear()
{
    while(head_node != NULL) {
        node = head_node;
        head_node = head_node->next;
        delete(node);
    }
    node = NULL;
    head_node = NULL;
    stack_length = 0;
    return true;
}

#endif
