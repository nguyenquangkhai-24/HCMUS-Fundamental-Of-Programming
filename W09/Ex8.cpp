#include <iostream>
using namespace std;

struct Node
{
	int digit;
	Node* next;
};
Node* makeNode(int x)
{
	Node* tmp = new Node();
	tmp->digit = x;
	tmp->next = nullptr;
	return tmp;
}
void addNode(Node*& a, int x)
{
	Node* tmp = makeNode(x);
	if (a == nullptr)
		a = tmp;
	else
	{
		Node* p = a;
		while (p->next != nullptr)
			p = p->next;
		p->next = tmp;
	}
}
void printLList(Node* a)
{
	while (a != nullptr)
	{
		cout << a->digit;
		a = a->next;
	}
}
Node* reverse(Node* a)
{
	Node* pre = nullptr;
	Node* cur = a;
	while (cur != nullptr)
	{
		Node* nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	Node* p = pre;
	return p;
}
Node* addList(Node* a, Node* b)
{
	Node* p1 = reverse(a);
	Node* p2 = reverse(b);
	Node* result = nullptr;
	int remember = 0;
	while (p1 != nullptr && p2 != nullptr)
	{
		int res = p1->digit + p2->digit+remember;
		if (res >= 10)
		{
			res -= 10;
			remember = 1;
			addNode(result, res);
		}
		else
		{
			remember = 0;
			addNode(result, res);
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1 != nullptr)
	{
		int res = p1->digit+remember;
		if (res >= 10)
		{
			res -= 10;
			remember = 1;
			addNode(result, res);
		}
		else
		{
			remember = 0;
			addNode(result, res);
		}
		p1 = p1->next;
	}
	while (p2 != nullptr)
	{
		int res = p2->digit + remember;
		if (res >= 10)
		{
			res -= 10;
			remember = 1;
			addNode(result, res);
		}
		else
		{
			remember = 0;
			addNode(result, res);
		}
		p2 = p2->next;
	}
	if (remember == 1)
		addNode(result, remember);
	Node* rresult = reverse(result);
	return rresult;
}
Node* copy(Node* a)
{
	Node* tmphead = makeNode(a->digit);
	Node* tmptail = tmphead;
	a = a->next;
	while (a != nullptr)
	{
		tmptail->next = makeNode(a->digit);
		tmptail = tmptail->next;
		a = a->next;
	}
	return tmphead;
}
int size(Node* a)
{
	int count = 0;
	while (a != nullptr)
	{
		count++;
		a = a->next;
	}
	return count;
}
Node* multiplyList(Node* a, Node* b)
{
	int* count = new int[size(a) + size(b)];
	int n = size(a);
	int m = size(b);
	for (int i = 0; i < size(a) + size(b); i++)
		count[i] = 0;
	Node* result = nullptr;
	for (int i = 0; i < n; i++)
	{
		Node* p = b;
		for (int j = 0; j < m; j++)
		{
			count[i + j] += p->digit * a->digit;
			p = p->next;
		}
		a = a->next;
	}
	for (int i = n+m - 1; i > 0; i--)
	{
		count[i] %= 10;
		count[i - 1] += count[i] / 10;
	}
	for (int i = n+m - 1; i >= 0; i--)
	{
		addNode(result, count[i]);
	}
	delete[] count;
	return result;
	
}
int main()
{
	Node* a = nullptr;
	Node* b = nullptr;
	while (1)
	{
		cout << endl;
		cout << "0. Exit" << endl;
		cout << "1.Create singly linked list a from given integer values." << endl;
		cout << "2.Create singly linked list b from given integer values. " << endl;
		cout << "3. Print list 1" << endl;
		cout << "4. Print list 2" << endl;
		cout << "5.Add lists" << endl;
		cout << "6.Multiply lists" << endl;
		int n;
		cout << "Nhap lua chon: ";
		cin >> n;
		if (n == 0)
			break;
		else if (n == 1)
		{
			int x;
			cout << "Nhap gia tri can them: ";
			cin >> x;
			addNode(a, x);
		}
		else if (n == 2)
		{
			int x;
			cout << "Nhap gia tri can them: ";
			cin >> x;
			addNode(b, x);
		}
		else if (n == 3)
		{
			printLList(a);
		}
		else if (n == 4)
		{
			printLList(b);
		}
		else if (n == 5)
		{
			Node* acopy = copy(a);
			Node* bcopy = copy(b);
			Node* aNode = addList(acopy, bcopy);
			printLList(aNode);
		}
		else if (n == 6)
		{
			Node* acopy = copy(a);
			Node* bcopy = copy(b);
			Node* mNode = multiplyList(acopy, bcopy);
			printLList(mNode);
		}
	}
}