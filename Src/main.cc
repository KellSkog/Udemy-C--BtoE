#include "doStuff.hh"
#include "doOtherStuff.hh"

//I know, I know, using std:cout is apalling, but this is exploratory
void hell() {
    Thing<int> num{42};
    if(num != 42)
        cout << "Go to hell" << endl;
    num = 666;
    num += Thing<int>(8);
    cout << num.val << endl;

    other::Neither n;
    auto func = []() -> bool {cout << "I'm a lLambda"<<endl;};
    n(puts);
    func();
}
int main(int argc, char **argv) {

    return 0;
}