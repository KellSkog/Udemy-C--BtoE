//#include "doStuff.hh"
#include <string>
#include <iostream>
#include "doOtherStuff.hh"

//I know, I know, using std:cout is apalling, but this is exploratory
// void hell() {
//     Thing<int> num{42};
//     if(num != 42)
//         cout << "Go to hell" << endl;
//     num = 666;
//     num += Thing<int>(8);
//     cout << num.val << endl;

//     other::Neither n;
//     auto func = []() -> bool {cout << "I'm a lLambda"<<endl;};
//     n(puts);
//     func();
// }
class MyVirtual {//One pure virtual function makes the class virtual
    public:
    virtual void nonsense() =0;
    virtual void noice() {std::cout << "Base"<<std::endl;}
    // virtual MyVirtual() =0;//A constructor can not be virtual!
    virtual ~MyVirtual() {}//
};
class MyConcrete : public MyVirtual {
    public:
    MyConcrete() {}
    ~MyConcrete() override {}
    void nonsense() override {}
    void noice() override {std::cout << "Child"<<std::endl;}
};
void manipulate(MyVirtual &mv) {
    mv.noice();//mv is base type
}
class UnexpectedException {

};
void doStuff() noexcept(false) {
    throw UnexpectedException();
}
void doStuff2() throw() {// warning: throw will always call terminate() [-Wterminate]
    throw UnexpectedException();
}
void doStuff3() noexcept {// warning: throw will always call terminate() [-Wterminate]
    throw UnexpectedException();
}
void doStuff4() noexcept(true) {// warning: throw will always call terminate() [-Wterminate]
    throw UnexpectedException();
}
void chap_56() {
    MyConcrete mc;
    manipulate(mc);
    try {
        doStuff();
        doStuff2();
        doStuff3();
        doStuff4();
    } catch(int q) {std::cout << "FortyTwo" << std::endl;}
    catch(...) {std::cout << "NotFortyTwo" << std::endl;}
}
//std::basic_ostream<char, std::char_traits<char>>
// template <char, std::char_traits<char>>
struct MyEndl{
    std::string txt;
    // std::basic_ostream<char, std::char_traits<char>> &out;
    MyEndl() : txt("\n\n\n") {}
    // std::basic_ostream<char, std::char_traits<char>> &operator<<{txt}
};
std::basic_ostream<char, std::char_traits<char>> &operator<<(
        std::basic_ostream<char, std::char_traits<char>> &out, MyEndl obj){
        out << obj.txt;
        return out;
    }
MyEndl myendl;
namespace A {
    int a = 1;
}
namespace B {
    int a = 2;
}
// std::ostream &std::endl<char, std::char_traits<char>>(std::ostream &__os)
void chap_57() {
    using namespace std;

    int a = 42;
    cout << a << myendl;
}
int main(int argc, char **argv) {
    // ch52::Dog<std::string> rufus{"Woof woof"};
    // std::cout << rufus.speak() << std::endl;
    // MyVirtual mv;
    //chap_56();
    chap_57();

    return 0;
}