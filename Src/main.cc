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
    virtual void noice() {}
    // virtual MyVirtual() =0;//A constructor can not be virtual!
    virtual ~MyVirtual() {}//
};
class MyConcrete : public MyVirtual {
    public:
    MyConcrete() {}
    ~MyConcrete() override {}
    void nonsense() override {}
    void noice() override {}
};
void manipulate(MyVirtual &mv) {
    
}
int main(int argc, char **argv) {
    // ch52::Dog<std::string> rufus{"Woof woof"};
    // std::cout << rufus.speak() << std::endl;
    // MyVirtual mv;
    MyConcrete mc;
    manipulate(mc);

    return 0;
}