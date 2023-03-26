#include<stdio.h>
#include<malloc.h>
typedef struct Node {
	int data;
	struct Node* next;
}PNode; //PNode就等价于struct Node 
typedef struct LinkedStack {
	PNode* top;
}*PLinkedStack;
PLinkedStack createEmptyStack_link(void);//创建链接栈 此时链表还未形成
int isEmptyStack_link(PLinkedStack p);   //判断是否为空
void push_link(PLinkedStack p, int x);		//进栈操作
void pop_link(PLinkedStack p);
int top_link(PLinkedStack p);			//取栈顶元素
PLinkedStack createEmptyStack_link(void) {
	//创建一个链接栈
	PLinkedStack p = (PLinkedStack)malloc(sizeof(struct LinkedStack));
	if (p) 
		p->top = NULL;
	else
		printf("创建失败");
	return p;
}
int isEmptyStack_link(PLinkedStack p) {
	return !(p->top);
}
void push_link(PLinkedStack p, int x) {
	PNode* node = (PNode*)malloc(sizeof(PNode));
	if (node == NULL)printf("Out of space!");
	else {
		node->data = x;
		node->next = p->top;
		p->top = node;
	}
}
void pop_link(PLinkedStack p) {
	if (isEmptyStack_link(p)) printf("Empty stack");
	else {
		PNode* t = p->top->next;
		free(p->top);
		p->top = t;
	}
}
int top_link(PLinkedStack p) {
	if (isEmptyStack_link(p)) return EOF;
	else {
		return p->top->data;
	}
}