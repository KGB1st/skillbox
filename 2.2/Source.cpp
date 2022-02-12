#include <iostream>
#include <map>
#include <string>
#include <string_view>

using namespace std;

/*
* Хорошая хеш-функция, разработанная Питером Вэйнбергером
* Для произвольного входного сообщения функция генерирует 32-разрядное хеш-значение,
*	называемое хеш-суммой сообщения. Этот алгоритм используется в хеш-таблицаx и декартовых деревьях,
* а также в процедурах проверки регистрационных ключей при защите программного обеспечения.
* В настоящее время эта функция используется в формате файла ELF Linux,
* выбранном стандартом бинарных файлов в Unix-подобных системах.
*
* Источник: https://ru.wikipedia.org/wiki/PJW-32
*/
unsigned int PJWHash(const char* str, const unsigned int m)
{
	unsigned int hash = 0;
	unsigned int test = 0;

	for (; *str; str++) {
		hash = (hash << 4) + (unsigned char)(*str);

		if ((test = hash & 0xf0000000) != 0) {
			hash = ((hash ^ (test >> 24)) & (0xfffffff));
		}
	}
	return hash % m;
}


int main()
{
	map<unsigned int, string> StdMap;
	char str[255];
	unsigned int pos = -1;

	// Прерывает зацикленность ввода данных
	while (str[0] != '.')
	{
		cout << "\nEnter a string: ";
		cin >> str;

		// Обрабатываем данные только в случае если есть что обрабатывать
		if (str[0] != '\0' && str[0] != '.') // Обработка ради обработки ;)
		{
			cout << "You entered " << str << ", hashed as: " << (pos = PJWHash(str, sizeof(str))) << endl;
			cout << "\n======== PRINT MAP =====" << endl;

			StdMap.insert(pair<unsigned int, string>(pos, str));

			map<unsigned int, string>::iterator it = StdMap.begin();

			while (it != StdMap.end())
			{
				cout << it->first << ", " << it->second << " " << endl;
				++it;
			}

			cout << "\n======== END OF PRINT =====" << endl;
		}
	}

	return 0;
}