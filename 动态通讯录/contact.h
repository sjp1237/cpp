#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADRR_MAX 30
#define MAX 1000
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
//描述一个人信息的结构体
struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char adrr[ADRR_MAX];
};

//描述一个通讯录
typedef struct phone
{
	struct PeoInfo* data;//r
	int sz;//表示通讯录中存放了多少个人的信息
	int capacity;//表示通讯录当前最大容量
} phone;

//函数的声明
void Initphone(phone* pc);//通讯录的初始化

void Addcontact(phone* pc);//增加一个人的信息

void Showcontact(phone* pc);//打印一个人的信息

void Delcontact(phone* pc);//删除一个人的信息

void Searchcontact(phone* pc);//查找一个人的信

void Modifycontact(phone* pc);//修改信息

void SortContact(phone* con);//排序

void Destorycontact(phone* pc);//销毁通讯录

void SaveContact(phone* pc);//将信息保存在文件中