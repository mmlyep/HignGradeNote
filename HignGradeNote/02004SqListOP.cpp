#include<stdio.h>
#include "02001SequenceList.cpp"
/*
* 初始化顺序表的算法
*/
void initList(Sqlist& L)
{
	L.length = 0;
}
/*
* 求指定位置元素
*/
int getElem(Sqlist L, int p, int &e)//e要改变，所以用引用型
{
	if (p<0 || p>L.length - 1)
		return 0;//p值越界，返回0
	e = L.data[p];
	return 1;
}
/*
* 查找第一个值等于e的元素，并返回其下标，查找失败返回-1。
*/
int findElem(Sqlist L, int e)
{
	int i;
	for (i = 0; i < L.length; i++)
		if (e == L.data[i])
			return i;//找到，返回下标
	return -1;//未找到，返回-1，作为失败标记
}
/*
*在顺序表L的第p(0<=p<=length)个位置上插入新的元素e。
*如果p的输入不正确，则返回0，代表插入失败；
*如果p的输入正确，则将顺序表第p个元素及以后元素后移一个位置，
*腾出一个空位插入新元素，顺序表长度增加1，插入操作成功，返回1。
*/
int insertElem(Sqlist& L, int p, int e)
{
	int i;
	if (p<0 || p>L.length || L.length == maxSize)
		return 0;//位置错误或表长达到顺序表的最大允许值，插入不成功，返回0
	for (i = L.length - 1; i >= p; --i)
		L.data[i + 1] = L.data[i];//从后往前，逐个将元素往后移动一个位置
	L.data[p] = e;//将e放在第p个位置上
	++(L.length);//表长自增1
	return 1;
}
/*
* 尾插法
*/
int insertElemR(Sqlist& L, int e)
{
	if (L.length == maxSize)
		return 0;//表长达到顺序表的最大允许值，插入不成功，返回0
	L.data[L.length] = e;//将e放在所有元素后
	++(L.length);//表长自增1
	return 1;
}
/*
* 删除指定下标元素
*/
int deleteElem(Sqlist& L, int p, int& e)//需要改变的变量用引用型
{
	if (p < 0 || p >= L.length)
		return 0;//下标越界返回0
	e = L.data[p];//将被删除元素赋值给e
	int i;
	for (i = p; i < L.length; i++)
		L.data[i] = L.data[i + 1];//p下标后面的的元素逐个往前移一个位置
	--(L.length);
	return 1;
}
int main02004()
{
	Sqlist L;
	initList(L);
	int i;
	for (i = 0; i < 5; i++)
		insertElemR(L, i);//尾插
	for (i = 5; i < 10; i++)
		insertElem(L, 0, i);
	for (i = 0; i < L.length; i++)
		printf("%d", L.data[i]);
	printf("\n");
	int e = -1;
	int exist = getElem(L, 8, e);//e赋值为在顺序表中下标为8的值
	printf("是否成功查找下标为8的元素？0失败，1成功：%d\n", exist);
	printf("顺序表9876501234下标为8的元素：%d\n", e);
	printf("顺序表9876501234值为%d的下标：%d\n", e, findElem(L, e));//在顺序表值等于e的下标
	deleteElem(L, 5, e);
	printf("删除下标为5的元素%d后顺序表结果为：",e);
	for (i = 0; i < L.length; i++)
		printf("%d", L.data[i]);
	return 0;
}