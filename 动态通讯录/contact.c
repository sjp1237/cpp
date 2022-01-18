#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void LoadContact(phone* pc)
{
	//打开文件
	FILE* pfIn = fopen("contact.text", "r");
	if (pfIn == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}	
	while((fscanf(pfIn, "%s",pc->data[pc->sz].name)!= EOF)&&
			(fscanf(pfIn, "%d", &pc->data[pc->sz].age)!= EOF)&&
			(fscanf(pfIn, "%s", pc->data[pc->sz].sex) != EOF)&&
			(fscanf(pfIn, "%s", pc->data[pc->sz].adrr) != EOF)&&
			(fscanf(pfIn, "%s", pc->data[pc->sz].tele) != EOF))
		{
		if (pc->sz == pc->capacity-1)
			{
			phone* pa = (phone*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
				if (pa == NULL)
				{
					printf("开辟空间失败\n");
					return;
				}
				else
				{
					printf("增容成功\n");
					pc->capacity += 2;
				}
			}
			pc->sz++;
	    }
	printf("加载成功\n");
	//关闭文件
	fclose(pfIn);
	pfIn = NULL;
}

void Initphone(phone* pc)//初始化通讯录
{
	pc->sz = 0;//通讯录创建好的时候，联系人为0
	pc->capacity = 3;//通讯录创建好的时候，默认能放3个人的信息
	pc->data=(struct PeoInfo *)malloc((pc->capacity) * sizeof(struct PeoInfo));
	if (pc->data == NULL)
	{
		printf("开辟空间失败\n");//开辟失败，退出程序
		exit(1);

	}
	LoadContact(pc);
}

void Addcontact(phone* pc)
{
	if (pc->sz == pc->capacity)
	{
		//通讯录满的时候进行增容
		phone* pa = (phone*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
		if (pa == NULL)
		{
			printf("开辟空间失败\n");
			return;
		}
		else
		{
			printf("增容成功\n");
			pc->capacity += 2;
		}
	}
		printf("请输入添加人的名字：");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入添加人的性别：");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入添加人的年龄：");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("请输入添加人的地址：");
		scanf("%s", pc->data[pc->sz].adrr);
		printf("请输入添加人的电话：");
		scanf("%s", pc->data[pc->sz].tele);
		pc->sz++;
		printf("添加成功\n");
}

void Showcontact(phone* pc)//打印一个人的信息
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-20s\t%-20s\n", "名字", "性别", "年龄", "地址", "电话");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-20s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].adrr,
			pc->data[i].tele);
	}
}

static int find(phone* pc, char pa[])//查找的函数
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, pa) == 0)
		{
			return i;
		}
	}
	//找不到用户信息
	return  -1;
}

void Delcontact(phone* pc)//删除一个人的信息
{
	int i = 0;
	char name[20];
	printf("请输入要查找的联系人\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("找不到该联系人");
	}
	else
	{
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}



void Searchcontact(phone* pc)//查找一个人的信息
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("找不到该联系人\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-20s\t%-20s\n", "名字", "性别", "年龄", "地址", "电话");
		printf("%-20s\t%-5s\t%-5d\t%-20s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].sex,
			pc->data[pos].age,
			pc->data[pos].adrr,
			pc->data[pos].tele);

	}
}
enum contact
{
	name = 1,
	age,
	sex,
	addr,
	tele
};
void MenuContact()
{
	printf("-----------------------------------------\n");
	printf("*                                       *\n");
	printf("*    1.名字          2.年龄             *\n");
	printf("*    3.性别          4.地址             *\n");
	printf("*             5.电话                    *\n");
	printf("*---------------------------------------*\n");
	printf("*             0.退出修改                *\n");
	printf("-----------------------------------------\n");
}

void print(phone* pc, int pos)
{
	printf("%-20s\t%-5s\t%-5s\t%-20s\t%-20s\n", "名字", "性别", "年龄", "地址", "电话");
	printf("%-20s\t%-5s\t%-5d\t%-20s\t%-20s\n",
		pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].adrr,
		pc->data[pos].tele);
}
void Modifycontact(phone* pc)//修改信息
{
	int input = 0;
	char name[NAME_MAX];
	printf("请输入要修改的联系人\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("找不到该联系人\n");
	}
	else
	{
		do
		{
			print(pc, pos);
			MenuContact();
			printf("请输入要修改信息:>\n");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("请输入修改后联系人的名字：");
				scanf("%s", pc->data[pos].name);
				print(pc, pos);
				printf("修改成功\n");
				break;
			case age:
				printf("请输入修改后联系人的年龄：");
				scanf("%d", &(pc->data[pos].age));
				print(pc, pos);
				printf("修改成功\n");
				break;
			case sex:
				printf("请输入修改后联系人的性别：");
				scanf("%s", pc->data[pos].sex);
				print(pc, pos);
				printf("修改成功\n");
				break;
			case addr:
				printf("请输入修改后联系人的地址：");
				scanf("%s", pc->data[pos].adrr);
				print(pc, pos);
				printf("修改成功\n");
				break;
			case tele:
				printf("请输入修改后联系人的电话：");
				scanf("%s", pc->data[pos].tele);
				print(pc, pos);
				printf("修改成功\n");
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
			case 0:
				printf("退出修改\n");
			}
		} while (input);

	}
}

void strcmp_name(phone* s1, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		if ((strcmp(s1->data[i].name, s1->data[i + 1].name)) > 0)
		{
			char arr[NAME_MAX];
			strcpy(arr, s1->data[i].name);
			strcpy(s1->data[i].name, s1->data[i + 1].name);
			strcpy(s1->data[i + 1].name, arr);
		}
	}
}
void strcmp_age(phone* s1, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (s1->data[i].age > s1->data[i + 1].age)
		{
			int mid = s1->data[i].age;
			s1->data[i].age = s1->data[i + 1].age;
			s1->data[i + 1].age =mid;
		}
	}
}

void SortContact(phone* con)//排序
{
	int input = 0;
	printf("*------------------------------------------*\n");
	printf("*                                          *\n");
	printf("*        1.年龄        2.名字              *\n");
	printf("*                                          *\n");
	printf("*------------------------------------------*\n");
	printf("请选择什么类型排序：>");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		//按年龄排序
		strcmp_age(con, con->sz);
		Showcontact(con);
		break;
	case 2:
		//按名字排序
		strcmp_name(con, con->sz);
		Showcontact(con);
		break;
	default:
		printf("选择错误，请重新选择|\n");
		break;
	}
}

void Destorycontact(phone* pc)//销毁通讯录
{
	free(pc);
	pc = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void SaveContact(phone* pc)//将信息保存在文件中
{
	FILE* pcOut = fopen("contact.text", "w");
	if (pcOut == NULL)
	{
		return 1;
	}
	for (int i = 0; i < pc->sz; i++)
	{
		fprintf(pcOut, "%s\t%d\t%s\t%s\t%s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].adrr, 
			pc->data[i].tele);
	}
	//关闭文件
	printf("保存成功\n");
	fclose(pcOut);
	pcOut = NULL;
}

