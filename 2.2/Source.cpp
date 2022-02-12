#include <iostream>
#include <map>
#include <string>
#include <string_view>

using namespace std;

/*
* ������� ���-�������, ������������� ������� ������������
* ��� ������������� �������� ��������� ������� ���������� 32-��������� ���-��������,
*	���������� ���-������ ���������. ���� �������� ������������ � ���-�������x � ���������� ��������,
* � ����� � ���������� �������� ��������������� ������ ��� ������ ������������ �����������.
* � ��������� ����� ��� ������� ������������ � ������� ����� ELF Linux,
* ��������� ���������� �������� ������ � Unix-�������� ��������.
*
* ��������: https://ru.wikipedia.org/wiki/PJW-32
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

	// ��������� ������������� ����� ������
	while (str[0] != '.')
	{
		cout << "\nEnter a string: ";
		cin >> str;

		// ������������ ������ ������ � ������ ���� ���� ��� ������������
		if (str[0] != '\0' && str[0] != '.') // ��������� ���� ��������� ;)
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