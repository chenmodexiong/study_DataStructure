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

//��ϵ����Ϣ
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;

//��̬��
//typedef struct Contact
//{
//	PeoInfo date[PEPO_MAX];//�����ϵ�˵���Ϣ
//	int sz;//�Ѿ������ϵ�˵ĸ���
//}Contact;

//��̬��
typedef struct Contact
{
	PeoInfo* date;//ָ������ϵ�˵���Ϣ��ָ��
	int sz;//�Ѿ������ϵ�˵ĸ���
	int capacity;//��ǰ�������
}Contact;

//��ӡ�˵�
extern void menu(void);

//��ʼ��ͨѶ¼
extern void InitContact(Contact* pc);

//Ѱ����ϵ��
extern int FindByName(const Contact* pc, char* name);

//�����ϵ��
extern void AddContact(Contact* pc);

//��ʾ��ϵ��
extern void ShowContact(const Contact* pc);

//ɾ����ϵ��
extern void DelContact(Contact* pc);

//������ϵ��
extern void SearchContact(const Contact* pc);

//�޸���ϵ��
extern void ModifyContact(Contact* pc);

//��鵱ǰ����
extern int check_capacity(Contact* pc);

//����ͨѶ¼
extern void DestroyContact(Contact* pc);

//����ͨѶ¼��Ϣ
extern void SaveContact(Contact* pc);

//������ϵ����Ϣ��ͨѶ¼
extern void LoadContact(Contact* pc);
