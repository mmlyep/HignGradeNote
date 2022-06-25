typedef struct DLNode
{
	int data;//data中存放结点数据域（默认是int型）
	struct LNode* prior;//指向前驱结点的指针
	struct LNode* next;//指向后继结点的指针
}DLNode;//定义双链表结点类型