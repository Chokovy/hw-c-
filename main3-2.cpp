#include <iostream>
using namespace std;

class Simple {
public:
    static const int KOREA = 1234;
    static const int RUSSIA = 2345;
    static const int CHINA = 3456;

    //static const 멤버 변수는 클래스 내에서 초기화 가능. 한 번 초기화한 후엔 변경 불가.
                                          // const는 값이 컴파일 타임에 결정되기 때문.

    //inner function 어쩌고 하는 것도 봤는데 그건 좀 복잡하고 잘 안 쓰는 것 같아서 자세히 안 봄.
};

int main() {
    cout << "우리나라의 면적: " << Simple::KOREA << "km" << endl;
    cout << "러시아의 면적: " << Simple::RUSSIA << "km" << endl;
    cout << "중국의 면적: " << Simple::CHINA << "km" << endl;
    return 0;
}