#include "doStuff.hh"
//I know, I know, using std:cout is apalling, but this is exploratory
int main(int argc, char **argv) {
    Thing<int> num{42};
    if(num != 42)
        cout << "Go to hell" << endl;
    num = 666;
    num += Thing<int>(8);
    cout << num.val << endl;
    
    return 0;
}