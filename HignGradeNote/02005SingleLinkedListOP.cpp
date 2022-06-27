#include<stdio.h>
#include <stdlib.h>
#include "02002LNode.cpp"


/*
* 假设有n个元素已经存储在数组a中，用尾插法建立链表C
*/
void createlistR(LNode *&C, int a[], int n)
{
	LNode* s, * r;//s用来指向新申请的结点，r始终指向C的终端结点
	int i;
	C = (LNode*)malloc(sizeof(LNode));//申请C的头结点空间
	C->next = NULL;
	r = C;//r指向头结点，因为此时头结点就是终端结点
	for (i = 0; i < n; ++i)//循环申请n个结点来接收数组a中的元素
	{
		s = (LNode*)malloc(sizeof(LNode));//s指向新申请结点
		s->data = a[i];//用新申请的结点接收数组a中的一个元素
		r->next = s;//用r来接纳新结点
		r = r->next;//r指向终端结点，以便于接纳下一个到来的结点
	}
	r->next = NULL;//数组a中的所有元素都已经被装入链表C中，
				   //C的终端结点的指针域置为NULL，C建立完成
}
/*
* 头插法建立链表
*/
void createlistF(LNode*& C, int a[], int n)
{
	int i;
	LNode* s;//s用来指向新申请的结点
	C = (LNode*)malloc(sizeof(LNode));//申请C的头结点空间
	C->next = NULL;
	for (i = 0; i < n; ++i) {
		s = (LNode*)malloc(sizeof(LNode));//申请新结点
		s->data = a[i];//接收数组一个元素
		s->next = C->next;//s所指向新结点的指针域next指向C的开始结点
		C->next = s;//头结点的指针域next指向s，使s成为新的开始结点
	}

}
/*
* A和B是元素递增有序的单链表(带表头结点)，将A和B归并为递减的单链表C
*/
void merge(LNode* A, LNode* B, LNode* &C)
{
	LNode* p = A->next;
	LNode* q = B->next;
	C = (LNode*)malloc(sizeof(LNode));
	C->next = NULL;
	LNode* s;
	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			s = p;
			s->next = C->next;
			C->next = s;
			p = p->next;
		}
		else
		{
			s = q;
			q->next = C->next;
			C->next = s;
			q = q->next;
		}
	}
	while (p != NULL)
	{
		s = p;
		s->next = C->next;
		C->next = s;
		p = p->next;
	}
	while (p != NULL)
	{
		s = q;
		q->next = C->next;
		C->next = s;
		q = q->next;
	}
}
int main()
{
	return 0;
}