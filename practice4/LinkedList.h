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

void DeleteAll(MonsterList& list);
