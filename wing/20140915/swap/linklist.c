#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data_;
    struct Node *next_;
}Node, *NodePtr;

//初始化链表，分配一个头结点
void create_list(Node **L)
{
    *L = (Node *)malloc(sizeof(Node));
}

int main(int argc, const char *argv[])
{
    NodePtr L = NULL; 
    return 0;
}
