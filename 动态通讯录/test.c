#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("------------------------------------����--------------------\n");
	printf("*                                                          *\n");
	printf("*       1.������ϵ��               2.ɾ����ϵ��            *\n");
	printf("*                                                          *\n");
	printf("*       3.������ϵ��               4.�޸���ϵ����Ϣ        *\n");
	printf("*                                                          *\n");
	printf("*       5.��ʾͨѶ¼               6.������ϵ����Ϣ        *\n");
	printf("*                                                          *\n");
	printf("*       7.���浽�ļ�               0.�˳�ͨѶ¼            *\n");
	printf("------------------------------------------------------------\n");
}
enum option
{
	add=1,
	del,
	search,
	modify,
	show,
	sort
};
void test()
{
	int input = 0;
	phone con;
	Initphone(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��>:\n");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Addcontact(&con);
			break;
		case del:
			Delcontact(&con);
			break;
		case search:
			Searchcontact(&con);
			break;
		case modify:
			Modifycontact(&con);
			break;
		case show:
			Showcontact(&con);
			break;
		case sort:
			SortContact(&con);
			break;
		case 7:
			SaveContact(&con);
			break;
		case 0:
			
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			break;
		}
	} while (input);
	Destorycontact(&con);
}

int main()
{
	test();
	return 0;
}