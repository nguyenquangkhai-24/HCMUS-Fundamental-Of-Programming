#include <iostream>
using namespace std;

struct Node
{
	double coefficient;
	int exponent;
	Node* next;
};
Node* makeNode(double a, int i)
{
	Node* tmp = new Node();
	tmp->coefficient = a;
	tmp->exponent = i;
	tmp->next = nullptr;
	return tmp;
}
void addNode(Node*& a, double co, int i)
{
	Node* tmp = makeNode(co, i);
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
Node* sortNode(Node*& a)
{
	Node* tmp = a;
	for (Node* p = a; p->next != nullptr; p = p->next)
	{
		for (Node* q = p->next; q != nullptr; q = q->next)
		{
			if (p->exponent < q->exponent)
			{
				double tmp1 = p->coefficient;
				int tmp2 = p->exponent;
				p->coefficient = q->coefficient;
				p->exponent = q->exponent;
				q->coefficient = tmp1;
				q->exponent = tmp2;
			}
		}
	}
	return tmp;
}

Node* addPolynomial(Node* a, Node* b)
{
	sortNode(a);
	sortNode(b);
	Node* result = nullptr;
	Node* p1 = a;
	Node* p2 = b;
	while (p1 != nullptr&&p2!=nullptr)
	{
		if (p1->exponent > p2->exponent)
		{
			addNode(result, p1->coefficient, p1->exponent);
			p1 = p1->next;
		}
		else if (p2->exponent > p1->exponent)
		{
			addNode(result, p2->coefficient, p2->exponent);
			p2 = p2->next;
		}
		else
		{
			double sum = p1->coefficient + p2->coefficient;
			if (sum != 0)
				addNode(result, sum, p1->exponent);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if (p1 != nullptr)
	{
		addNode(result, p1->coefficient, p1->exponent);
		p1 = p1->next;
	}
	else if (p2 != nullptr)
	{
		addNode(result, p2->coefficient, p2->exponent);
		p2 = p2->next;
	}

	return result;
}
void insertNode(Node*& a, double co, int ex)
{
	if (co == 0)
		return;
	Node* pre = nullptr;
	Node* p = a;
	if (a == nullptr)
	{
		a = makeNode(co,ex);
		return;
	}
	while (p!= nullptr)
	{
		if (p->exponent == ex)
		{
			p->coefficient += co;
			return;
		}
		pre = p;
		p = p->next;
	}
	Node* tmp = makeNode(co, ex);
	pre->next = tmp;
}
Node* mutiplePolymial(Node* a, Node* b)
{
	sortNode(a);
	sortNode(b);
	Node* result = nullptr;
	for (Node* p = a; p != nullptr; p = p->next)
	{
		for (Node* q = b; q != nullptr; q = q->next)
		{
			double co = p->coefficient * q->coefficient;
			int ex = p->exponent + q->exponent;
			insertNode(result, co, ex);
		}
	}
	return result;
}
void printLList(Node* a)
{
	while (a != nullptr)
	{
		cout << a->coefficient<<"x^"<<a->exponent;
		if (a->next != nullptr&& a->coefficient>0)
			cout << "+";
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
		cout << "5.Add the two singly linked lists." << endl;
		cout << "6.Multiply the two singly linked lists." << endl;
		int n;
		cout << "Nhap lua chon: ";
		cin >> n;
		if (n == 0)
			break;
		else if (n == 1)
		{
			double x;
			cout << "Nhap he so: ";
			cin >> x;
			int n;
			cout << "Nhap so mu: ";
			cin >> n;
			addNode(a, x, n);
		}
		else if (n == 2)
		{
			double x;
			cout << "Nhap he so: ";
			cin >> x;
			int n;
			cout << "Nhap so mu: ";
			cin >> n;
			addNode(b, x, n);
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
			Node* add = addPolynomial(a, b);
			printLList(add);
		}
		else if (n == 6)
		{
			Node* mul = mutiplePolymial(a, b);
			printLList(mul);
		}
	}
	return 0;
	
}