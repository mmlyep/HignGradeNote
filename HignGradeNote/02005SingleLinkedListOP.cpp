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