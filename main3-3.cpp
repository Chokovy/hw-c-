#include<iostream>
using namespace std;
class Book							// 책 클래스
{
private:
	const char* title;			
	const char* isbn;
	const int price;
public :
	Book(const char* a, const char* b, int c) : title(a), isbn(b), price(c) {	// 생성자
	}							// 상수값을 전달하는거니까 const로 받기-> 6~8번 줄도 const화.

	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBM: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

};

class EBook : public Book	// 전자책 클래스
{
private:
	const char* DRMkey;		// 전자책에 삽입되는 보안 관련 키 정보
public :
	EBook(const char* title, const char* isbn, int price, const char* key) : Book(title, isbn, price) {	//부모 클래스 title, isbn,price를 초기화.
									       //부모 클래스의 생성자를 이용해야 부모클래스의 private 변수들을 초기화할 수 있기 때문.
		DRMkey = key;
	}

	void ShowEBookInfo() {
		ShowBookInfo();		//상속받았으니 부모 함수의 public 함수 사용 가능
		cout << "인증키: " << DRMkey << endl;
	}

};

int main()
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx920i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}
