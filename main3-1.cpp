#include <iostream>
using namespace std;

class Simple {
private:
    int num;
public:
    Simple(int n) : num(n) { }

    Simple(const Simple& copy) : num(copy.num)          //복사 생성자
    {
        cout << "Called Simple(const Simple& copy)" << endl;
        //cout << &copy << endl;
    }
    Simple& AddNum(int n) {         //자기 참조 함수
        num += n;
        return *this;               //자기 자신을 반환
    }
    void ShowData() {
        cout << "num : " << num << endl;
    }
};



Simple SimpleFuncObj(Simple obj) {
    cout << "return 이전" << endl;
    return obj;
}

int main() {
    Simple obj(7);                                  //객체 생성, 생성자 호출-> obj.num = 7
    //cout << &obj << endl;
    SimpleFuncObj(obj).AddNum(30).ShowData();       //SimpleFuncObj 매개변수 부분에 의해 복사생성자가 호출됨. 기존 7에 30을 더해 37 출력.
    obj.ShowData();                                 //37이 된건 obj의 복사생성자로 생성된 객체이고, obj는 그대로 7이 출력됨.
    
    return 0;
}


/*

 <출력>
 Called Simple(const Simple& copy)    -> SinpleFuncObj() 함수에 obj객체를 넘겨주면서 복사생성자가 호출됨.
 return 이전                          -> SimpleFuncObj() 내용 출력
 Called Simple(const Simple& copy)    -> return obj;에서 obj를 반환하면서 복사생성자가 한 번 더 호출되는듯.?
 num : 37                                -> 매개변수에서 생성되는 obj랑 반환하는 obj는 또 다른 객체인가봐.. 주소가 달라요..                   
 num : 7

 -----------------------------------

 복사생성자 : 객체의 참조를 인수로 전달받아, 그 참조를 가지고 자신을 초기화하는 방법.
 따라서 main() 맨 위의 obj와 SimpleFuncObj()에 매개변수로 넘겨준 obj는 같은거임. 주소가 같음. 
 SimpleFuncObj()에서 return obj 를 할 때 다시 한 번 복사 생성자가 호출되면서 독립적인 객체 생성(?).



 +) 주로 복사생성자를 사용하는 경우
   1. 객체가 함수에 인수로 전달될 때
   2. 함수가 객체를 반환값으로 반환할 때
   3. 새로운 객체를 같은 클래스 타입의 기존 객체와 똑같이 초기화할 때

   등등.. 

*/