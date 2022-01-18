#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void LoadContact(phone* pc)
{
	//���ļ�
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
					printf("���ٿռ�ʧ��\n");
					return;
				}
				else
				{
					printf("���ݳɹ�\n");
					pc->capacity += 2;
				}
			}
			pc->sz++;
	    }
	printf("���سɹ�\n");
	//�ر��ļ�
	fclose(pfIn);
	pfIn = NULL;
}

void Initphone(phone* pc)//��ʼ��ͨѶ¼
{
	pc->sz = 0;//ͨѶ¼�����õ�ʱ����ϵ��Ϊ0
	pc->capacity = 3;//ͨѶ¼�����õ�ʱ��Ĭ���ܷ�3���˵���Ϣ
	pc->data=(struct PeoInfo *)malloc((pc->capacity) * sizeof(struct PeoInfo));
	if (pc->data == NULL)
	{
		printf("���ٿռ�ʧ��\n");//����ʧ�ܣ��˳�����
		exit(1);

	}
	LoadContact(pc);
}

void Addcontact(phone* pc)
{
	if (pc->sz == pc->capacity)
	{
		//ͨѶ¼����ʱ���������
		phone* pa = (phone*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
		if (pa == NULL)
		{
			printf("���ٿռ�ʧ��\n");
			return;
		}
		else
		{
			printf("���ݳɹ�\n");
			pc->capacity += 2;
		}
	}
		printf("����������˵����֣�");
		scanf("%s", pc->data[pc->sz].name);
		printf("����������˵��Ա�");
		scanf("%s", pc->data[pc->sz].sex);
		printf("����������˵����䣺");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("����������˵ĵ�ַ��");
		scanf("%s", pc->data[pc->sz].adrr);
		printf("����������˵ĵ绰��");
		scanf("%s", pc->data[pc->sz].tele);
		pc->sz++;
		printf("��ӳɹ�\n");
}

void Showcontact(phone* pc)//��ӡһ���˵���Ϣ
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "��ַ", "�绰");
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

static int find(phone* pc, char pa[])//���ҵĺ���
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, pa) == 0)
		{
			return i;
		}
	}
	//�Ҳ����û���Ϣ
	return  -1;
}

void Delcontact(phone* pc)//ɾ��һ���˵���Ϣ
{
	int i = 0;
	char name[20];
	printf("������Ҫ���ҵ���ϵ��\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("�Ҳ�������ϵ��");
	}
	else
	{
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�\n");
	}
}



void Searchcontact(phone* pc)//����һ���˵���Ϣ
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ��\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("�Ҳ�������ϵ��\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "��ַ", "�绰");
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
	printf("*    1.����          2.����             *\n");
	printf("*    3.�Ա�          4.��ַ             *\n");
	printf("*             5.�绰                    *\n");
	printf("*---------------------------------------*\n");
	printf("*             0.�˳��޸�                *\n");
	printf("-----------------------------------------\n");
}

void print(phone* pc, int pos)
{
	printf("%-20s\t%-5s\t%-5s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "��ַ", "�绰");
	printf("%-20s\t%-5s\t%-5d\t%-20s\t%-20s\n",
		pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].adrr,
		pc->data[pos].tele);
}
void Modifycontact(phone* pc)//�޸���Ϣ
{
	int input = 0;
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ���ϵ��\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("�Ҳ�������ϵ��\n");
	}
	else
	{
		do
		{
			print(pc, pos);
			MenuContact();
			printf("������Ҫ�޸���Ϣ:>\n");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("�������޸ĺ���ϵ�˵����֣�");
				scanf("%s", pc->data[pos].name);
				print(pc, pos);
				printf("�޸ĳɹ�\n");
				break;
			case age:
				printf("�������޸ĺ���ϵ�˵����䣺");
				scanf("%d", &(pc->data[pos].age));
				print(pc, pos);
				printf("�޸ĳɹ�\n");
				break;
			case sex:
				printf("�������޸ĺ���ϵ�˵��Ա�");
				scanf("%s", pc->data[pos].sex);
				print(pc, pos);
				printf("�޸ĳɹ�\n");
				break;
			case addr:
				printf("�������޸ĺ���ϵ�˵ĵ�ַ��");
				scanf("%s", pc->data[pos].adrr);
				print(pc, pos);
				printf("�޸ĳɹ�\n");
				break;
			case tele:
				printf("�������޸ĺ���ϵ�˵ĵ绰��");
				scanf("%s", pc->data[pos].tele);
				print(pc, pos);
				printf("�޸ĳɹ�\n");
				break;
			default:
				printf("�����������������\n");
				break;
			case 0:
				printf("�˳��޸�\n");
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

void SortContact(phone* con)//����
{
	int input = 0;
	printf("*------------------------------------------*\n");
	printf("*                                          *\n");
	printf("*        1.����        2.����              *\n");
	printf("*                                          *\n");
	printf("*------------------------------------------*\n");
	printf("��ѡ��ʲô��������>");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		//����������
		strcmp_age(con, con->sz);
		Showcontact(con);
		break;
	case 2:
		//����������
		strcmp_name(con, con->sz);
		Showcontact(con);
		break;
	default:
		printf("ѡ�����������ѡ��|\n");
		break;
	}
}

void Destorycontact(phone* pc)//����ͨѶ¼
{
	free(pc);
	pc = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void SaveContact(phone* pc)//����Ϣ�������ļ���
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
	//�ر��ļ�
	printf("����ɹ�\n");
	fclose(pcOut);
	pcOut = NULL;
}

