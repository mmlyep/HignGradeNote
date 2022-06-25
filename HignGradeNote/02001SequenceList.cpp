#define maxSize 100 //这里定义一个整型常量，值为100
typedef struct
{
	int data[maxSize]; //存放顺序表元素的数组（默认是int型，可根据题目要求将int换成其他类型） 
	int length;//存放顺序表的长度
}Sqlist;