/*
	�⣺
	�轫n��n>1����������ŵ�һά����R�У����һ���㷨����R�е�����ѭ������P��0<P<n����λ��,
	����R�е�������{X0,X1,...,Xn-1}�任Ϊ{Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1}
	������
	�Ƚ�R��ǰP��Ԫ�����ã��ٽ�ʣ�µ�Ԫ�����ã����R���е�Ԫ����������һ�����á�
*/
#include<stdio.h>
#define N 50
/*
* �������R[l]��R[r]Ԫ�ؽ�������
*/
void Reverse(int R[], int l, int r)
{
	int i, j;
	int temp;
	for (i = l, j = r; i < j; ++i, --j)
	{
		temp = R[i];
		R[i] = R[j];
		R[j] = temp;
	}
	return;
}
void RCR(int R[], int n, int p)
{
	if (p <= 0 || p >= n)//�ƶ�λ��С�ڵ���0���������Ԫ�ظ���
		printf("ERROR");
	else
	{
		Reverse(R, 0, p - 1);//��������Rǰp��Ԫ��
		Reverse(R, p, n - 1);//��������Rʣ��Ԫ��
		Reverse(R, 0, n - 1);//������������
	}
	return;
}
int main()
{
	int p, i;
	int R[N], n;
	scanf_s("%d", &p);//�ƶ�λ��
	scanf_s("%d", &n);//����Ԫ�ظ���
	for (i = 0; i <= n - 1; ++i)
	{
		scanf_s("%d", &R[i]);
	}
	RCR(R, n, p);
	for (i = 0; i <= n - 1; ++i)
	{
		printf("%d ", R[i]);
	}
	return 0;
}