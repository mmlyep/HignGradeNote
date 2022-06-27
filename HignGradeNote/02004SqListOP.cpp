#include<stdio.h>
#include "02001SequenceList.cpp"
/*
* ��ʼ��˳�����㷨
*/
void initList(Sqlist& L)
{
	L.length = 0;
}
/*
* ��ָ��λ��Ԫ��
*/
int getElem(Sqlist L, int p, int &e)//eҪ�ı䣬������������
{
	if (p<0 || p>L.length - 1)
		return 0;//pֵԽ�磬����0
	e = L.data[p];
	return 1;
}
/*
* ���ҵ�һ��ֵ����e��Ԫ�أ����������±꣬����ʧ�ܷ���-1��
*/
int findElem(Sqlist L, int e)
{
	int i;
	for (i = 0; i < L.length; i++)
		if (e == L.data[i])
			return i;//�ҵ��������±�
	return -1;//δ�ҵ�������-1����Ϊʧ�ܱ��
}
/*
*��˳���L�ĵ�p(0<=p<=length)��λ���ϲ����µ�Ԫ��e��
*���p�����벻��ȷ���򷵻�0���������ʧ�ܣ�
*���p��������ȷ����˳����p��Ԫ�ؼ��Ժ�Ԫ�غ���һ��λ�ã�
*�ڳ�һ����λ������Ԫ�أ�˳���������1����������ɹ�������1��
*/
int insertElem(Sqlist& L, int p, int e)
{
	int i;
	if (p<0 || p>L.length || L.length == maxSize)
		return 0;//λ�ô������ﵽ˳�����������ֵ�����벻�ɹ�������0
	for (i = L.length - 1; i >= p; --i)
		L.data[i + 1] = L.data[i];//�Ӻ���ǰ�������Ԫ�������ƶ�һ��λ��
	L.data[p] = e;//��e���ڵ�p��λ����
	++(L.length);//������1
	return 1;
}
/*
* β�巨
*/
int insertElemR(Sqlist& L, int e)
{
	if (L.length == maxSize)
		return 0;//���ﵽ˳�����������ֵ�����벻�ɹ�������0
	L.data[L.length] = e;//��e��������Ԫ�غ�
	++(L.length);//������1
	return 1;
}
/*
* ɾ��ָ���±�Ԫ��
*/
int deleteElem(Sqlist& L, int p, int& e)//��Ҫ�ı�ı�����������
{
	if (p < 0 || p >= L.length)
		return 0;//�±�Խ�緵��0
	e = L.data[p];//����ɾ��Ԫ�ظ�ֵ��e
	int i;
	for (i = p; i < L.length; i++)
		L.data[i] = L.data[i + 1];//p�±����ĵ�Ԫ�������ǰ��һ��λ��
	--(L.length);
	return 1;
}
int main02004()
{
	Sqlist L;
	initList(L);
	int i;
	for (i = 0; i < 5; i++)
		insertElemR(L, i);//β��
	for (i = 5; i < 10; i++)
		insertElem(L, 0, i);
	for (i = 0; i < L.length; i++)
		printf("%d", L.data[i]);
	printf("\n");
	int e = -1;
	int exist = getElem(L, 8, e);//e��ֵΪ��˳������±�Ϊ8��ֵ
	printf("�Ƿ�ɹ������±�Ϊ8��Ԫ�أ�0ʧ�ܣ�1�ɹ���%d\n", exist);
	printf("˳���9876501234�±�Ϊ8��Ԫ�أ�%d\n", e);
	printf("˳���9876501234ֵΪ%d���±꣺%d\n", e, findElem(L, e));//��˳���ֵ����e���±�
	deleteElem(L, 5, e);
	printf("ɾ���±�Ϊ5��Ԫ��%d��˳�����Ϊ��",e);
	for (i = 0; i < L.length; i++)
		printf("%d", L.data[i]);
	return 0;
}