#include<stdio.h>
#include "LinkedQueue.cpp"
PLinkedQueue createEmptyQueue_link();//创建队列
int isEmptyQueue_link(PLinkedQueue p);//判断队列是否为空
void enQueue_link(PLinkedQueue p, int x);//进队列运算
void deQueue_link(PLinkedQueue p);//出队列运算
int frontQueue_link(PLinkedQueue p);//取头部元素运算