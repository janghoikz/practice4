#pragma once
#include "Monster.h"

struct MonsterList
{
	Monster* pHead;
	Monster* pTail;
};

Monster* CreateMonster(MonsterList& list,const char* name, int hp);
int getCountMonsterList(const MonsterList& list);
void PrintMonsterList(const MonsterList& list);
void PrintListRecursive(Monster* monster);
Monster* FindMonster(const MonsterList& list, const char* name);
bool Delete(MonsterList& list, const char* name);
void DeleteAll(MonsterList& list);

struct MonsterList2
{
	Monster2* pHead;
	Monster2* pTail;
};

Monster2* CreateMonster(MonsterList2& list, const char* name, int hp);
int getCountMonsterList(const MonsterList2& list);
void PrintMonsterList(const MonsterList2& list);
void PrintListRecursive(Monster2* monster);
Monster2* FindMonster(const MonsterList2& list, const char* name);
bool Delete(MonsterList2& list, const char* name);
void DeleteAll(MonsterList2& list);
