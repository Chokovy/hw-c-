#include <iostream>
using namespace std;

class Simple {
public:
    static const int KOREA = 1234;
    static const int RUSSIA = 2345;
    static const int CHINA = 3456;

    //static const ��� ������ Ŭ���� ������ �ʱ�ȭ ����. �� �� �ʱ�ȭ�� �Ŀ� ���� �Ұ�.
                                          // const�� ���� ������ Ÿ�ӿ� �����Ǳ� ����.

    //inner function ��¼�� �ϴ� �͵� �ôµ� �װ� �� �����ϰ� �� �� ���� �� ���Ƽ� �ڼ��� �� ��.
};

int main() {
    cout << "�츮������ ����: " << Simple::KOREA << "km" << endl;
    cout << "���þ��� ����: " << Simple::RUSSIA << "km" << endl;
    cout << "�߱��� ����: " << Simple::CHINA << "km" << endl;
    return 0;
}