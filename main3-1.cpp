#include <iostream>
using namespace std;

class Simple {
private:
    int num;
public:
    Simple(int n) : num(n) { }

    Simple(const Simple& copy) : num(copy.num)          //���� ������
    {
        cout << "Called Simple(const Simple& copy)" << endl;
        //cout << &copy << endl;
    }
    Simple& AddNum(int n) {         //�ڱ� ���� �Լ�
        num += n;
        return *this;               //�ڱ� �ڽ��� ��ȯ
    }
    void ShowData() {
        cout << "num : " << num << endl;
    }
};



Simple SimpleFuncObj(Simple obj) {
    cout << "return ����" << endl;
    return obj;
}

int main() {
    Simple obj(7);                                  //��ü ����, ������ ȣ��-> obj.num = 7
    //cout << &obj << endl;
    SimpleFuncObj(obj).AddNum(30).ShowData();       //SimpleFuncObj �Ű����� �κп� ���� ��������ڰ� ȣ���. ���� 7�� 30�� ���� 37 ���.
    obj.ShowData();                                 //37�� �Ȱ� obj�� ��������ڷ� ������ ��ü�̰�, obj�� �״�� 7�� ��µ�.
    
    return 0;
}


/*

 <���>
 Called Simple(const Simple& copy)    -> SinpleFuncObj() �Լ��� obj��ü�� �Ѱ��ָ鼭 ��������ڰ� ȣ���.
 return ����                          -> SimpleFuncObj() ���� ���
 Called Simple(const Simple& copy)    -> return obj;���� obj�� ��ȯ�ϸ鼭 ��������ڰ� �� �� �� ȣ��Ǵµ�.?
 num : 37                                -> �Ű��������� �����Ǵ� obj�� ��ȯ�ϴ� obj�� �� �ٸ� ��ü�ΰ���.. �ּҰ� �޶��..                   
 num : 7

 -----------------------------------

 ��������� : ��ü�� ������ �μ��� ���޹޾�, �� ������ ������ �ڽ��� �ʱ�ȭ�ϴ� ���.
 ���� main() �� ���� obj�� SimpleFuncObj()�� �Ű������� �Ѱ��� obj�� ��������. �ּҰ� ����. 
 SimpleFuncObj()���� return obj �� �� �� �ٽ� �� �� ���� �����ڰ� ȣ��Ǹ鼭 �������� ��ü ����(?).



 +) �ַ� ��������ڸ� ����ϴ� ���
   1. ��ü�� �Լ��� �μ��� ���޵� ��
   2. �Լ��� ��ü�� ��ȯ������ ��ȯ�� ��
   3. ���ο� ��ü�� ���� Ŭ���� Ÿ���� ���� ��ü�� �Ȱ��� �ʱ�ȭ�� ��

   ���.. 

*/