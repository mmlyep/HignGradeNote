typedef struct DLNode
{
	int data;//data�д�Ž��������Ĭ����int�ͣ�
	struct DLNode* prior;//ָ��ǰ������ָ��
	struct DLNode* next;//ָ���̽���ָ��
}DLNode;//����˫����������