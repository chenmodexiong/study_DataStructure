#define  _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu(void)
{
	printf("********************************************\n");
	printf("****** 1.add(添加)      2.del(删除)    ******\n");
	printf("****** 3.search(查找)   4.modify(修改) ******\n");
	printf("****** 5.show(显示)     0.exit(退出)   ******\n");
	printf("********************************************\n");
}

int check_capacity(Contact* pc)
{
	assert(pc);
	if (pc->sz == pc->capacity)
	{
		//扩容
		printf("联系人已满\n");
		int num = 0;
		printf("请输入要增加的联系人个数:>");
		scanf("%d", &num);
		PeoInfo* ptr=(PeoInfo*)realloc(pc->date,(pc->capacity + num) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("check_capacity::realloc");
			return -1;
		}		
		pc->capacity += num;
		pc->date = ptr;
	}
	return 1;
}

//静态版
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	memset(pc->date, 0, sizeof(pc->date));
//	pc->sz = 0;
//}

//动态版
void InitContact(Contact* pc)
{
	assert(pc);
	PeoInfo* ptr = (PeoInfo*)calloc(DEFAULT_MIN,sizeof(PeoInfo));
	if (ptr == NULL)
	{
		perror("InitContact::calloc");
		return;
	}
	pc->date = ptr;
	ptr = NULL;
	pc->sz = 0;
	pc->capacity = DEFAULT_MIN;

	//加载文件中联系人信息
	LoadContact(pc);

}

int FindByName(const Contact* pc,char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->date[i].name, name) == 0)
		{
			return i;
		}
	}
	return EOF;
}

//静态的版本
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	//增加一个人的信息
//	printf("请输入名字:>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入年龄:>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入性别:>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入地址:>");
//	scanf("%s", pc->data[pc->sz].addr);
//	printf("请输入电话:>");
//	scanf("%s", pc->data[pc->sz].tele);
//
//	pc->sz++;
//}

//动态版
void AddContact(Contact* pc)
{
	assert(pc);	
	int ret=check_capacity(pc);
	if (ret == -1)
	{
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", pc->date[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &pc->date[pc->sz].age);
	printf("请输入性别:>");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入地址:>");
	scanf("%s", pc->date[pc->sz].addr);
	printf("请输入电话:>");
	scanf("%s", pc->date[pc->sz].tele);
	pc->sz++;
	printf("添加成功\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	printf("%-10s %-5s %-5s %-10s %-10s\n", "姓名","年龄","性别","地址","电话");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-10s %-5d %-5s %-10s %-10s\n", pc->date[i].name, pc->date[i].age, 
			pc->date[i].sex, pc->date[i].addr, pc->date[i].tele);
	}
}

void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除的人姓名:>");
	scanf("%s", &name);
	//找到要删除的人
	int ret=FindByName(pc,name);
	if (EOF == ret)
	{
		printf("没有找到要删除的人\n");
		return;
	}
	//删除
	memmove(pc->date + ret, pc->date + (ret + 1), sizeof(PeoInfo) * (pc->sz - ret - 1));
	pc->sz--;
	printf("删除成功\n");
	ShowContact(pc);
}

void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	printf("请输入要查找的人:>");
	scanf("%s", name);
	int ret=FindByName(pc, name);
	if (EOF == ret)
	{
		printf("没有找到要查找的人\n");
		return;
	}
	int pos = ret;
	printf("%-10s %-5s %-5s %-10s %-10s\n", "姓名", "年龄", "性别", "地址", "电话");
	printf("%-10s %-5d %-5s %-10s %-10s\n", pc->date[pos].name, pc->date[pos].age,
			pc->date[pos].sex, pc->date[pos].addr, pc->date[pos].tele);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	printf("请输入要修改的联系人:>");
	scanf("%s", name);
	int ret=FindByName(pc, name);
	if (EOF == ret)
	{
		printf("没有找到要修改的人\n");
		return;
	}
	//修改
	int pos = ret;
	printf("请输入姓名:>");
	scanf("%s", pc->date[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &pc->date[pos].age);
	printf("请输入性别:>");
	scanf("%s", pc->date[pos].sex);
	printf("请输入地址:>");
	scanf("%s", pc->date[pos].addr);
	printf("请输入电话:>");
	scanf("%s", pc->date[pos].tele);
	printf("修改成功\n");
	//修改完成打印一下
	printf("%-10s %-5s %-5s %-10s %-10s\n", "姓名", "年龄", "性别", "地址", "电话");
	printf("%-10s %-5d %-5s %-10s %-10s\n", pc->date[pos].name, pc->date[pos].age,
		pc->date[pos].sex, pc->date[pos].addr, pc->date[pos].tele);
}

void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
	pc->sz = 0;
	pc->capacity = 0;
	pc = NULL;
}


void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("Contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->date + i, sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
	printf("保存成功\n");
}

void LoadContact(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("Contact.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//读数据
	PeoInfo tmp = {0};
	int i = 0;
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//增容
		check_capacity(pc);
		pc->date[i] = tmp;
		pc->sz++;
		i++;
	}
	fclose(pf);
	pf = NULL;
}


