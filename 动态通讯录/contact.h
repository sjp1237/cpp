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
//����һ������Ϣ�Ľṹ��
struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char adrr[ADRR_MAX];
};

//����һ��ͨѶ¼
typedef struct phone
{
	struct PeoInfo* data;//r
	int sz;//��ʾͨѶ¼�д���˶��ٸ��˵���Ϣ
	int capacity;//��ʾͨѶ¼��ǰ�������
} phone;

//����������
void Initphone(phone* pc);//ͨѶ¼�ĳ�ʼ��

void Addcontact(phone* pc);//����һ���˵���Ϣ

void Showcontact(phone* pc);//��ӡһ���˵���Ϣ

void Delcontact(phone* pc);//ɾ��һ���˵���Ϣ

void Searchcontact(phone* pc);//����һ���˵���

void Modifycontact(phone* pc);//�޸���Ϣ

void SortContact(phone* con);//����

void Destorycontact(phone* pc);//����ͨѶ¼

void SaveContact(phone* pc);//����Ϣ�������ļ���