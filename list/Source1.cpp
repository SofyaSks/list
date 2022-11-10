// Двусвязный список

#include <iostream>
using namespace std;


struct Element {
	int data;
	Element* Next, *Prev; // указатель на элемент справа и слева
};

class List {

	Element* Head, * Tail; // указатели на голову и хвост
	int count;

public:
	List();
	~List();
	void AddHead(int _data);
	void AddTail(int _data);
	void Insert(int pos = 0);
	void Del(int pos = 0);
	void DelAll();
	void Print();
	void Print(int pos);
	int GetCount();
};


int main() {
	srand(time(NULL));

	List l2;
	const int size = 10;
	int arr[size] = { 3, 67, 3, 8, 6, 35, 7, 2, 8, 1 };
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0) {
			l2.AddTail(arr[i]);
		}
		else
			l2.AddHead(arr[i]);
	}
	l2.Print();

	return 0;
}

List::List()
{
	Head = Tail = NULL;
	count = 0;
}

List::~List()
{
	DelAll();
}

void List::AddHead(int _data)
{
	Element* temp = new Element;
	temp->data = _data;
	temp->Prev = NULL;
	temp->Next = Head; // замена головы
	if (Head != NULL) {
		Head->Prev = temp;
	}
	if (count == 0) {
		Head = Tail = temp;
	}
	else {
		Head = temp;
	}
	count++;
}

void List::AddTail(int _data)
{
	Element* temp = new Element;
	temp->Next = NULL;
	temp->data = _data;
	temp->Prev = Tail;
	if (Tail != 0) {
		Tail->Next = temp;
	}
	if (count == 0) {
		Head = Tail = temp;
	}
	else {
		Tail = temp;
	}
	count++;
}

void List::Insert(int pos)
{
	if (pos == 0) {
		cout << "Enter position: \n";
		cin >> pos;
	}
	if (pos < 0 || pos > count + 1) {
		cout << "Error.\n";
	}
	int i = 1;
	Element* ins = Head;
	while (i < pos) {
		ins = ins->Next;
		i++;
	}
	Element* PrevIns = ins->Prev;
	Element* temp = new Element;
	temp->data = rand() % 50;

	if (PrevIns != 0 && count != 1)
		PrevIns->Next = temp;
	temp->Next = ins;
	temp->Prev = PrevIns;
	ins->Prev = temp;
	count++;
}

void List::Del(int pos)
{
	if (pos == 0) {
		cout << "Enter position: \n";
		cin >> pos;
	}

	if (pos < 1 || pos > count) {
		cout << "Error.\n";
	}

	int i = 1;
	Element *del = Head;
	while (i < pos) {
		del = del->Next;
		i++;
	}

	Element* PrevDel = del->Prev;
	Element* AfterDel = del->Next;
	if (PrevDel != 0 && count != 1) {
		PrevDel->Next = AfterDel;
	}
	if (pos == 1) {
		Head = AfterDel;
	}
	if (pos == count) {
		Tail == PrevDel;
	}
	delete del;
	count--;
}

void List::DelAll()
{
	while (Head != 0) {
		Del(1);
		count = 0;
	}
}

void List::Print()
{
	Element* temp = Head;
	while (temp->Next != NULL) {
		cout << temp->data << " ";
		temp = temp->Next;
	}
	cout << temp->data << endl;
	cout << endl << endl;
}

void List::Print(int pos)
{
	Element* temp;

	if (pos < 0 || pos > count + 1) {
		cout << "Error.\n";
	}

	if (pos <= count / 2) {
		temp = Head;
		int i = 1;
		while (i < pos) {
			temp = temp->Next;
			i++;
		}
	}
	else {
		temp = Tail;
		int i = 1;
		while (i < count - pos) {
			temp = temp->Prev;
			i++;
		}
	}
	cout << pos << " " << temp->data << endl;
}

int List::GetCount()
{
	return count;
}