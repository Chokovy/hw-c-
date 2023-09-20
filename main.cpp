#include <iostream>
#include<string>
using namespace std;


class NameCard {

private:
	char* name;
	char* company;
	char* phone;


public:

	NameCard() {	//기본 생성자
	}


	NameCard(char* a, char* b, char* c) {
		name = new char[strlen(a) + 1];			//길이에 맞게 new로 동적할당
		strcpy(name, a);						//문자열 복사

		company = new char[strlen(b) + 1];
		strcpy(company, b);

		phone = new char[strlen(c) + 1];
		strcpy(phone, c);
	}


	//출력 담당 함수
	void ShowNameCardInfo() {
		cout << "이름 : " << name << endl;
		cout << "회사 : " << company << endl;
		cout << "전화번호 : " << phone << endl;
		cout << endl;
	}


	~NameCard() {	//소멸자 함수
		delete[] name;						//반환 했습니다
		delete[] company;
		delete[] phone;
	}
};

int main() {

	NameCard manClerk("Lee", "ABCEng", "010-1111-2222");
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444");
	NameCard manAssist("KIM", "SoGoodComp", "010-5555-6666");

	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}