// Односвязный список

//#include <iostream>
//using namespace std;
//
//// y tail адрес = 0
//// добавление в конец, удалять из начала
//// перебор элементов только с головы (так как указатель на правый(следующий) элемент)
//
//struct Element {
//	char data;
//	Element* Next; // указатель на элемент
//};
//
//class List {
//
//	Element* Head, * Tail; // указатели на голову и хвост
//	int count;
//
//public:
//	List();
//	~List();
//	void Add(char _data);
//	void Del();
//	void DelAll();
//	void Print();
//	int GetCount();
//};
//
//
//int main() {
//	srand(time(NULL));
//
//	List l1;
//	char s[] = "Hello, C++ !!!";
//	cout << s << endl;
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//		l1.Add(s[i]);
//	l1.Print();
//	l1.Del();
//	cout << "****************" << endl;
//	l1.Print();
//
//
//	return 0;
//}
//
//List::List()
//{
//	Head = Tail = NULL;
//	count = 0;
//}
//
//List::~List()
//{
//	DelAll();
//}
//
//void List::Add(char _data)
//{
//	Element* temp = new Element;
//	temp->data = _data;
//	temp->Next = NULL;
//	if (Head != NULL) {
//		Tail->Next = temp;
//		Tail = temp;
//	}
//	else {
//		Head = Tail = temp;
//	}
//	count++;
//}
//
//void List::Del()
//{
//	Element* temp = Head;
//	Head = Head->Next;
//	delete temp;
//	count--;
//}
//
//void List::DelAll()
//{
//	while (Head != 0) {
//		Del();
//	}
//}
//
//void List::Print()
//{
//	Element* temp = Head;
//	while (temp != NULL) {
//		cout << temp->data << " ";
//		temp = temp->Next;
//	}
//	cout << endl << endl;
//}
//
//int List::GetCount()
//{
//	return count;
//}
