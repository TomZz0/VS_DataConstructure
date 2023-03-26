#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct Node {
	int data;
	struct Node* next;
}PNode;
typedef struct LinkedQueue {
	PNode* head;
	PNode* rear;
}*PLinkedQueue;

PLinkedQueue createEmptyQueue_link() {
	PLinkedQueue p = new struct LinkedQueue;
	if (p!=NULL) {
		p->head = p->rear = NULL;
		return p;
	}
	else {
		printf("创建失败");
	}
}
int isEmptyQueue_link(PLinkedQueue p) {
	return p->head == NULL || p->rear == NULL ? 1 : 0;
}
void enQueue_link(PLinkedQueue p, int x) {
	PNode* node = new struct Node;
	if (node == NULL) {
		printf("Out of Space!");
		return;
	}
	node->data = x;
	node->next = NULL;
	//如果队列为空 需要将头指针也赋值
	//否则将尾指针的后继结点设置为新添加的node
	if (p->head == NULL) p->head = node;
	else p->rear->next = node;
	//将尾指针设置为node
	p->rear = node;
}
void deQueue_link(PLinkedQueue p) {
	if (p->head == NULL) {
		printf("Empty Queue");
		return;
	}
	PNode* t = p->head;
	p->head = p->head->next;
	delete(t);
}
int frontQueue_link(PLinkedQueue p) {
	if (isEmptyQueue_link(p)) return NULL;
	return p->head->data;
}