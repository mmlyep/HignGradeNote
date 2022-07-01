#include<stdio.h>
#include <stdlib.h>
#include "02002LNode.cpp"


/*
* ������n��Ԫ���Ѿ��洢������a�У���β�巨��������C
*/
void createlistR(LNode *&C, int a[], int n)
{
	LNode* s, * r;//s����ָ��������Ľ�㣬rʼ��ָ��C���ն˽��
	int i;
	C = (LNode*)malloc(sizeof(LNode));//����C��ͷ���ռ�
	C->next = NULL;
	r = C;//rָ��ͷ��㣬��Ϊ��ʱͷ�������ն˽��
	for (i = 0; i < n; ++i)//ѭ������n���������������a�е�Ԫ��
	{
		s = (LNode*)malloc(sizeof(LNode));//sָ����������
		s->data = a[i];//��������Ľ���������a�е�һ��Ԫ��
		r->next = s;//��r�������½��
		r = r->next;//rָ���ն˽�㣬�Ա��ڽ�����һ�������Ľ��
	}
	r->next = NULL;//����a�е�����Ԫ�ض��Ѿ���װ������C�У�
				   //C���ն˽���ָ������ΪNULL��C�������
}
/*
* ͷ�巨��������
*/
void createlistF(LNode*& C, int a[], int n)
{
	int i;
	LNode* s;//s����ָ��������Ľ��
	C = (LNode*)malloc(sizeof(LNode));//����C��ͷ���ռ�
	C->next = NULL;
	for (i = 0; i < n; ++i) {
		s = (LNode*)malloc(sizeof(LNode));//�����½��
		s->data = a[i];//��������һ��Ԫ��
		s->next = C->next;//s��ָ���½���ָ����nextָ��C�Ŀ�ʼ���
		C->next = s;//ͷ����ָ����nextָ��s��ʹs��Ϊ�µĿ�ʼ���
	}

}
/*
* A��B��Ԫ�ص�������ĵ�����(����ͷ���)����A��B�鲢Ϊ�ݼ��ĵ�����C
*/
void merge(LNode* A, LNode* B, LNode*& C)
{
	LNode* p = A->next;
	LNode* q = B->next;
	LNode* s;
	C = A;
	C->next = NULL;
	free(B);
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			s = p;
			p = p->next;//������ڱ��У���������һ��������һ������ı�p��nextָ����
			s->next = C->next; 
			C->next = s; 
		}
		else
		{
			s = q; 
			q = q->next;
			s->next = C->next;
			C->next = s;
		}
	}
	while (p != NULL)
	{
		s = p; 
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q != NULL)
	{
		s = q; 
		q = q->next;
		s->next = C->next;
		C->next = s; 
	}
}
/*
* ���ҵ�ֵΪx�Ľ����ɾ���ý��
*/
int findAndDelete(LNode* C, int x)
{
	LNode* p, * q;
	p = C;
	while (p->next != NULL)//����
	{
		if (p->next->data == x)
			break;//�ҵ�Ԫ��
		p = p->next;
	}
	if (p->next == NULL)
		return 0;//δ�ҵ���Ԫ�أ�ɾ��ʧ��
	else
	{
		q = p->next;
		p->next = p->next->next;
		free(q);//�ͷ�q��ָ�����ڴ�ռ�
		return 1; //ɾ���ɹ�
	}
}
void printList(LNode* C) {
	LNode* p = C->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main02005()
{
	int a[10], b[20];
	int i;
	for (i = 0; i < 10; ++i)
	{
		a[i] = i;
	}
	for (i = 0; i < 20; ++i)
	{
		b[i] = i;
	}
	LNode* A, * B, * C;
	createlistR(A, a, 10);
	createlistR(B, b, 20);
	printList(A);
	printList(B);
	merge(A, B, C);
	printList(C);
	findAndDelete(C, 10);
	printList(C);
	return 0;
}