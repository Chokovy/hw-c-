#include <iostream>
#include<string>
using namespace std;


class NameCard {

private:
	char* name;
	char* company;
	char* phone;


public:

	NameCard() {	//�⺻ ������
	}


	NameCard(char* a, char* b, char* c) {
		name = new char[strlen(a) + 1];			//���̿� �°� new�� �����Ҵ�
		strcpy(name, a);						//���ڿ� ����

		company = new char[strlen(b) + 1];
		strcpy(company, b);

		phone = new char[strlen(c) + 1];
		strcpy(phone, c);
	}


	//��� ��� �Լ�
	void ShowNameCardInfo() {
		cout << "�̸� : " << name << endl;
		cout << "ȸ�� : " << company << endl;
		cout << "��ȭ��ȣ : " << phone << endl;
		cout << endl;
	}


	~NameCard() {	//�Ҹ��� �Լ�
		delete[] name;						//��ȯ �߽��ϴ�
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