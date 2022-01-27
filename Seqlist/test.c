#define _CRT_SECURE_NO_WARNINGS 1

#include"Seqlist.h"

//void test1()
//{
//	Seqlist s;
//	SeqlistInit(&s);
//	SeqlistPushBack(&s, 1);
//	SeqlistPushBack(&s, 2);
//	SeqlistPushBack(&s, 3);
//	SeqlistPrint(&s);
//	SeqlistPushFront(&s, 0);
//	SeqlistPushFront(&s, -1);
//	SeqlistPrint(&s);
//	SeqlistPopBack(&s);
//	SeqlistPrint(&s);
//	SeqlistPopFront(&s);
//	SeqlistPopFront(&s);
//	SeqlistPopFront(&s);
//	SeqlistPrint(&s);
//}
void test2()
{
	Seqlist s;
	SeqlistInit(&s);
	SeqlistPushBack(&s, 1);
	SeqlistPushBack(&s, 2);
	SeqlistPushBack(&s, 3);
	SeqlistPrint(&s);
	SeqlistInster(&s, 1, 30);
	SeqlistPrint(&s);
	SeqlistErase(&s, 2);
	SeqlistPrint(&s);


}




int main()
{
	test2();
	return 0;
}