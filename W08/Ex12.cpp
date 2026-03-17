#include <iostream>
using namespace std;

void savespace(char* s, int* space, int i, int& j, int ssize)
{
	if (s[i] == '\0')
	{
		return;
	}
	if (s[i] == ' ')
	{
		space[j] = i;
		j += 1;
		savespace(s, space, i + 1, j, ssize);
	}
	else
		savespace(s, space, i + 1, j, ssize);
}
int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}
void Search(char* s, char* name, int namesize, int* space, int k, int fullnamesize, int count)
{
	int start;
	int end;
	int distance;
	if (k == -1)
	{
		start = 0;
		if (count > 0) end = space[0];
		else end = fullnamesize;
	}
	else if (k == count - 1)
	{
		start = space[k] + 1;
		end = fullnamesize;
	}
	else
	{
		start = space[k] + 1;
		end = space[k + 1];
	}
	distance = end - start;
	if (distance == namesize)
	{
		for (int j = 0; j < namesize; j++)
		{
			if (s[start + j] != name[j] && s[start + j] != name[j] + 32 && s[start + j] != name[j] - 32)
			{
				if (k < count - 1)
					Search(s, name, namesize, space, k + 1, fullnamesize, count);
				return;
			}
		}
		cout << "Correct";
		return;
	}
	else
	{
		if (k < count - 1)
			Search(s, name, namesize, space, k + 1, fullnamesize, count);
		else
		{
			cout << "Incorrect";
			return;
		}

	}

}
int main()
{
	char* fullname = new char[1000];
	cin.getline(fullname, 1000);
	char* givenname = new char[1000];
	cin.getline(givenname, 1000);
	int namesize = size(givenname, 0);
	int* space = new int[1000];
	int fullnamesize = size(fullname, 0);
	int count = 0;
	savespace(fullname, space, 0, count, fullnamesize);
	Search(fullname, givenname, namesize, space, -1, fullnamesize, count);
	delete[] fullname;
	delete[] givenname;
	delete[] space;
	return 0;

}