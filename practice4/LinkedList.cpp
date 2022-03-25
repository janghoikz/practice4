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

bool Delete(MonsterList& list, const char* name)
{
	Monster* pCurrent = list.pHead;
	Monster* pPrevious{};
	while (pCurrent != nullptr)
	{
		if (strcmp(pCurrent->name, name) == 0)
		{
			break;
		}
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	if (pCurrent == nullptr)
	{
		return false;
	}
	if (list.pHead == list.pTail)
	{
		//원소 하나만 있을때
		list.pHead = list.pTail = nullptr;
	}
	else if (list.pHead == pCurrent)
	{
		//첫번쨰 원소
		list.pHead = pCurrent->pNext;
	}
	else if(list.pTail == pCurrent)
	{
		//마지막 원소
		list.pTail = pPrevious;
		pPrevious->pNext = nullptr;
	}
	else
	{
		pPrevious->pNext = pCurrent->pNext;
	}
	delete pCurrent;
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



//////////////////////////////////////////////////////////////////

Monster2* CreateMonster(MonsterList2& list, const char* name, int hp)
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

int getCountMonsterList(const MonsterList2& list)
{
	return 0;
}

void PrintMonsterList(const MonsterList2& list)
{
}

void PrintListRecursive(Monster2* monster)
{
}

Monster2* FindMonster(const MonsterList2& list, const char* name)
{
	return nullptr;
}

bool Delete(MonsterList2& list, const char* name)
{
	return false;
}

void DeleteAll(MonsterList2& list)
{
}
