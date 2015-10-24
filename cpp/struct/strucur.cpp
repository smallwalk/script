#include <iostream>

struct student
{
    char name[20];
    double price;
};

struct students 
{
    students *left_s;
    students *right_s;
    student s;
};

void preOrder(students *s);
void inOrder(students *s);
void postOrder(students *s);

int main() 
{
    using namespace std;

    students G = 
    { 
        NULL,
        NULL,
        {
            "G",
            13,
        },
    };

    students H = 
    { 
        NULL,
        NULL,
        {
            "H",
            11,
        },
    };

    students D = 
    { 
        &G,
        &H,
        {
            "D",
            12,
        },
    };

    students B = 
    {
        &D,
        NULL,
        {
            "B",
            18,
        },
    };

    students I = 
    {
        NULL,
        NULL,
        {
            "I",
            18,
        },
    };

    students E = 
    {
        NULL,
        &I,
        {
            "E",
            12,
        },
    };

    students F = 
    {
        NULL,
        NULL,
        {
            "F",
            98,
        },
    };

    students C = 
    {
        &E,
        &F,
        {
            "C",
            93,
        },
    };

    students A = 
    {
        &B,
        &C,
        {
            "A",
            3,
        },
    };


    //preOrder(&A);
    //inOrder(&A);
    postOrder(&A);
    return 0;
}

void preOrder(students *stu)
{
    if (stu == NULL) {
        return;
    }

    std::cout << stu->s.name << std::endl;
    preOrder(stu->left_s);
    preOrder(stu->right_s);
}

void inOrder(students *stu) 
{
    if (stu == NULL) {
        return;
    }
    inOrder(stu->left_s);
    std::cout << stu->s.name << std::endl;
    inOrder(stu->right_s);
}

void postOrder(students *stu)
{
    if (stu == NULL) {
        return;
    }
    postOrder(stu->left_s);
    postOrder(stu->right_s);
    std::cout << stu->s.name << std::endl;
}
