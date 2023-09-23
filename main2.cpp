#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)				//��� �̴ϼȶ�����.  num = n;
	{
		cout << "��ü����" << endl;
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;					//�ڱ� �ڽ��� ������ ��밡��	
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;					//��������									-> �ٵ� �� ���⿡ �̰� ��ߵǴ��� ��Ȯ�ϰ� �𸣰���. ������ϸ� ���� ��
	}
};

int main(void)
{
	SelfRef obj(3);						//��� �̴ϼȶ������� ���� obj - num�� 3�� �����.											// ��� : ��ü����
	SelfRef &ref = obj.Adder(2);		//self-reference. num�� ������ 3�� +2�ؼ� 5�� �����  (obj.num == ref.num)
										//ref ��ü�� obj ��ü�� �����ڰ� �Ǿ ������� num�� ���� ������ ���� �ް� ����.

	

	obj.ShowTwoNumber();				//����Լ� ȣ��																				// ��� : 5
	ref.ShowTwoNumber();																											// ��� : 5

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();		//num +=1 , ���, num +=2 ���										// ��� : 6
																																	//		  8

	// +) ShowTwoNumber() �Լ��� �׳� ��¸� ���ֱ淡 void������ �� �� ��þ��µ�  �������� ref�� ������ �߸鼭 [�Ŀ� Ŭ���� ������ �־���ϴµ� void������ ����] �̶�� ������
																										//�����ڿ���? 
	return 0;
}