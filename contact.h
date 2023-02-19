#pragma once

#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 20
#define TELE_MAX 12
#define PEPO_MAX 100
#define DEFAULT_MIN 3

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW
};

//联系人信息
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;

//静态版
//typedef struct Contact
//{
//	PeoInfo date[PEPO_MAX];//存放联系人的信息
//	int sz;//已经存放联系人的个数
//}Contact;

//动态版
typedef struct Contact
{
	PeoInfo* date;//指向存放联系人的信息的指针
	int sz;//已经存放联系人的个数
	int capacity;//当前最大容量
}Contact;

//打印菜单
extern void menu(void);

//初始化通讯录
extern void InitContact(Contact* pc);

//寻找联系人
extern int FindByName(const Contact* pc, char* name);

//添加联系人
extern void AddContact(Contact* pc);

//显示联系人
extern void ShowContact(const Contact* pc);

//删除联系人
extern void DelContact(Contact* pc);

//查找联系人
extern void SearchContact(const Contact* pc);

//修改联系人
extern void ModifyContact(Contact* pc);

//检查当前容量
extern int check_capacity(Contact* pc);

//销毁通讯录
extern void DestroyContact(Contact* pc);

//保存通讯录信息
extern void SaveContact(Contact* pc);

//加载联系人信息到通讯录
extern void LoadContact(Contact* pc);
