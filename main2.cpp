#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)				//멤버 이니셜라이저.  num = n;
	{
		cout << "객체생성" << endl;
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;					//자기 자신의 참조에 사용가능	
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;					//마찬가지									
	}
	/*void ShowTwoNumber() {
		cout << num << endl;
	}*/
};

int main(void)
{
	SelfRef obj(3);						//멤버 이니셜라이저에 의해 obj - num에 3이 저장됨.											// 출력 : 객체생성
	SelfRef &ref = obj.Adder(2);		//self-reference. num에 기존의 3에 +2해서 5가 저장됨  (obj.num == ref.num)
										//ref 객체가 obj 객체의 참조자가 되어서 멤버변수 num에 대한 영향을 같이 받고 있음.

	

	obj.ShowTwoNumber();				//출력함수 호출																				// 출력 : 5
	ref.ShowTwoNumber();																											// 출력 : 5

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();		//num +=1 , 출력, num +=2 출력										// 출력 : 6
																																	//		  8


	  
	// 만약 함수의 원형이 SelfRef ShowTwoNumber() {} 라면, *this를 반환할 때 임시객체가 새로 생성되기 때문에, 반드시 참조를 반환해야함.(== 반환형이 참조자여야 함)
	// 따라서 반환형이 SelfRef 여서는 안 되고 SelfRef& 여야 함.		


	// +) ShowTwoNumber() 함수가 그냥 출력만 해주길래 void형으로 한 번 써봤었는데  마지막줄 ref에 빨간줄 뜨면서 [식에 클래스 형식이 있어야하는데 void형식이 있음] 이라고 오류뜸
	// -> 만약에 ShowTwoNumber()를 void형으로 썼을 때,  ref.ShowTwoNumber();만 하면 문제 없음. 자기참조 함수인 Adder& 까지 같이 부르니까 문제 생기는 듯.
	/*
	ref.Adder(1);
	ref.ShowTwoNumber();
	ref.Adder(2);
	ref.ShowTwoNumber();					이렇게 Adder랑 ShowTwoNumber랑 한 줄로 안 부르면 문제 없음	
	*/

	return 0;
}
