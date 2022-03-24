#include <iostream>
#include "LinkedList.h"

int main()
{
	MonsterList myList{};

	CreateMonster(myList, "wolf", 10);
	CreateMonster(myList, "slime", 20);
	CreateMonster(myList, "Demon", 30);

	std::cout << getCountMonsterList(myList) << std::endl;
	PrintMonsterList(myList);
	PrintListRecursive(myList.pHead);

	std::cout << ((FindMonster(myList, "slime") == nullptr) ? "Not Found" : "Found") << std::endl;
}