#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* makeNode(int x)
{
	Node* tmp = new Node();
	tmp->data = x;
	tmp->next = nullptr;
	return tmp;
}
void addNode(Node* &a,int x)
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
long long sumBinary(Node* a)
{
	int sum = 0;
	for (int i = 0; ; i++)
	{
		if (a == nullptr)
			break;
		sum += a->data * (int)pow(2, i);
		a = a->next;
	}
	return sum;
}
Node* reverseList(Node* a)
{
	Node* pre = nullptr;
	Node* cur = a;
	Node* p;
	while (cur != nullptr)
	{
		Node* nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	p = pre;
	return p;
}
Node* addBinary(Node* a, Node* b)
{
	Node* p1 = reverseList(a);
	Node* p2 = reverseList(b);
	Node* result = nullptr;
	int remember = 0;
	while (p1 != nullptr && p2 != nullptr)
	{
		int res = p1->data + p2->data + remember;;
		if (res==2)
		{
			res = 0;
			remember = 1;
			addNode(result, res);
		}
		else if (res == 3)
		{
			res = 1;
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
		int sum = p1->data + remember;
		if (sum == 2)
		{
			sum = 0;
			remember = 1;
		}
		else if (sum == 1)
			remember = 0;
		addNode(result,sum );
		p1 = p1->next;
	}
	while (p2 != nullptr)
	{
		int sum = p2->data + remember;
		if (sum == 2)
		{
			sum = 0;
			remember = 1;
		}
		else if (sum == 1)
			remember = 0;
		addNode(result, sum);
		p2 = p2->next;
	}
	if (remember == 1)
		addNode(result, remember);
	return result;
}
void printLList(Node* a)
{
	while (a != nullptr)
	{
		cout << a->data;
		a = a->next;
	}
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
		cout << "5.Binary and decimal add" << endl;
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
			Node* res = addBinary(a, b);
			long long demical = sumBinary(res);
			Node* resreal = reverseList(res);
			cout << "Decimal: " << demical << endl;
			printLList(resreal);
		}
	}
}