#include<iostream>
using namespace std;
class Book							// å Ŭ����
{
private:
	const char* title;			
	const char* isbn;
	const int price;
public :
	Book(const char* a, const char* b, int c) : title(a), isbn(b), price(c) {	// ������
	}							// ������� �����ϴ°Ŵϱ� const�� �ޱ�-> 6~8�� �ٵ� constȭ.

	void ShowBookInfo() {
		cout << "����: " << title << endl;
		cout << "ISBM: " << isbn << endl;
		cout << "����: " << price << endl;
	}

};

class EBook : public Book	// ����å Ŭ����
{
private:
	const char* DRMkey;		// ����å�� ���ԵǴ� ���� ���� Ű ����
public :
	EBook(const char* title, const char* isbn, int price, const char* key) : Book(title, isbn, price) {	//�θ� Ŭ���� title, isbn,price�� �ʱ�ȭ.
																			//�θ� Ŭ������ �����ڸ� �̿��ؾ� �θ�Ŭ������ private �������� �ʱ�ȭ�� �� �ֱ� ����.
		DRMkey = key;
	}

	void ShowEBookInfo() {
		ShowBookInfo();		//��ӹ޾����� �θ� �Լ��� public �Լ� ��� ����
		cout << "����Ű: " << DRMkey << endl;
	}

};

int main()
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx920i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}