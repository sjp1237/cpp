#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>	



typedef int SeqDatasize;//�����Ժ����͵ı任
typedef struct SeqList
{
	SeqDatasize* a;//�����ָ��
	int size;//��Ч���ݵĸ���
	int capcity;//��ǰ���������
}SeqList;

//�ڴ��й������ݽṹ��ɾ��Ľӿ�
void SeqListPushBack(SeqList* pc, SeqDatasize x);
void SeqListPushFront(SeqList* pc, SeqDatasize x);
void SeqListPopBack(SeqList* pc);
void SeqListPopFront(SeqList* pc);
void SeqListInit(SeqList* pc);
void SeqListDestory(SeqList* pc);
void SeqListPrint(SeqList* pc);
void SeqListInsert(SeqList* pc, int pos, SeqDatasize x);
void SeqListErase(SeqList* pc, int pos);


