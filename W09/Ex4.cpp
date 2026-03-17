#include <iostream>
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
void printNode(Node* a)
{
	while (a != nullptr)
	{
		cout << a->data << " ";
		a = a->next;
	}
}
Node* copy(Node* a)
{
	Node* tmphead = makeNode(a->data);
	Node* tmptail = tmphead;
	a = a->next;
	while (a != nullptr)
	{
		tmptail->next = makeNode(a->data);
		tmptail = tmptail->next;
		a = a->next;
	}
	return tmphead;
}
Node* spilitNode(Node* a)
{
	Node* poshead = nullptr;
	Node* postail = nullptr;
	Node* zerohead = nullptr;
	Node* zerotail = nullptr;
	Node* neghead = nullptr;
	Node* negtail = nullptr;
	while (a != nullptr)
	{
		Node* nxt = a->next;
		a->next = nullptr;
		if (a->data > 0)
		{
			if (poshead == nullptr)
			{
				poshead = a;
				postail = a;
			}
			else
			{
				postail->next = a;
				postail = postail->next;
			}
		}
		if (a->data == 0)
		{
			if (zerohead == nullptr)
			{
				zerohead = a;
				zerotail = a;
			}
			else
			{
				zerotail->next = a;
				zerotail = zerotail->next;
			}
		}
		if (a->data < 0)
		{
			if (neghead == nullptr)
			{
				neghead = a;
				negtail = a;
			}
			else
			{
				negtail->next = a;
				negtail = negtail->next;
			}
		}
		a = nxt;
	}
	zerotail->next = neghead;
	if (poshead != nullptr)
		postail->next = zerohead;
	else
		return zerohead;
	return poshead;
}
int main()
{
	Node* a = nullptr;
	while (true)
	{
		cout << endl;
		cout << "0. Exit" << endl;
		cout << "1.Create a singly linked list from given integer values." << endl;
		cout << "2.Print the elements in the list." << endl;
		cout << "3. Rearrange the values in a singly linked." << endl;
		int n;
		cout << "Nhap lua chon: ";
		cin >> n;
		if (n == 0)
			break;
		else if (n == 1)
		{
			int x;
			cout << "Nhap gia tri can them: ";
			cin >>x;
			addNode(a, x);
		}
		else if (n == 2)
		{
			printNode(a);
		}
		else if (n == 3)
		{
			Node* acopy = copy(a);
			Node* sNode = spilitNode(acopy);
			cout << "Sau khi sap xep: ";
			printNode(sNode);
		}
	}
	return 0;
}