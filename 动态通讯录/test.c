#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("------------------------------------——--------------------\n");
	printf("*                                                          *\n");
	printf("*       1.增加联系人               2.删除联系人            *\n");
	printf("*                                                          *\n");
	printf("*       3.查找联系人               4.修改联系人信息        *\n");
	printf("*                                                          *\n");
	printf("*       5.显示通讯录               6.排序联系人信息        *\n");
	printf("*                                                          *\n");
	printf("*       7.保存到文件               0.退出通讯录            *\n");
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
	Initphone(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择>:\n");
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
			
			printf("退出通讯录\n");
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