#include <cstring>
#include <iostream>
#include "LinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, int hp)
{
	Monster* pNew = new Monster{};

	strcpy_s(pNew->name, NAME_LENGTH, name);
	pNew->hp = hp;

	if (list.pTail == nullptr)
	{
		list.pHead = pNew;
		list.pTail = pNew;
	}
	else
	{
		list.pTail->pNext = pNew;
		list.pTail = pNew;
	}
	

	return nullptr;
}

int getCountMonsterList(const MonsterList& list)
{
	Monster* p = list.pHead;
	int count{};

	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count;
}

void PrintMonsterList(const MonsterList& list)
{
	Monster* p = list.pHead;
	while (p != NULL)
	{
		std::cout << p->name << " : " << p->hp << std::endl;
		p = p->pNext;
	}
}

void PrintListRecursive(Monster* monster)
{
	if (monster == nullptr)
	{
		return;
	}
	std::cout << monster->name << " : " << monster->hp << std::endl;

	PrintListRecursive(monster->pNext);
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
	Monster* p = list.pHead;

	for (Monster* p = list.pHead; p != nullptr; p = p->pNext)
	{
		if (strcmp(p->name,name) == 0)
		{
			return p;
		}
	}

	return nullptr;
}

void DeleteAll(MonsterList& list)
{
	Monster* p = list.pHead;
	Monster* pNext{};

	while (p != nullptr)
	{
		pNext = p->pNext;
		delete p;

		p = pNext;
	}
	list.pHead = nullptr;
	list.pTail = nullptr;
}
