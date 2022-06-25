/*
	题：
	设将n（n>1）个整数存放到一维数组R中，设计一个算法，将R中的序列循环左移P（0<P<n）个位置,
	即将R中的数据由{X0,X1,...,Xn-1}变换为{Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1}
	分析：
	先将R中前P个元素逆置，再将剩下的元素逆置，最后将R所有的元素再整体做一次逆置。
*/
#include<stdio.h>
#define N 50
/*
* 将数组的R[l]到R[r]元素进行逆置
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
	if (p <= 0 || p >= n)//移动位数小于等于0或大于数组元素个数
		printf("ERROR");
	else
	{
		Reverse(R, 0, p - 1);//逆置数组R前p个元素
		Reverse(R, p, n - 1);//逆置数组R剩下元素
		Reverse(R, 0, n - 1);//逆置整个数组
	}
	return;
}
int main()
{
	int p, i;
	int R[N], n;
	scanf_s("%d", &p);//移动位数
	scanf_s("%d", &n);//数组元素个数
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