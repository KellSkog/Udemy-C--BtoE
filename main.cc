#include <iostream>
#include<vector>
// #include<string>//getline
using namespace::std;

void user_input_stuff() {
    int age;
    cout << "Give me your age:" <<endl;
    cin >> age;
    cin.ignore(); // it ignores just enter without arguments being sent. it's same as cin.ignore(1, '\n') 
    cout << "Your age is" << age << endl;
    
    
    string nameAndSurname;
    cout << "Give me your name and surname:"<< endl;
    // getline(cin, nameAndSurname);
    
    cout << "Hello, " << nameAndSurname << endl;
}
void dynamic_mem() {
    constexpr int SIZE = 100;
    int* ptr_p = new int[SIZE];//Don't use, insted: std::vector<int>
    std::vector<int> myVec;
    cout << ptr_p[0] << endl;
    for(int i = 0; i < SIZE; i++) ptr_p[i] = i;
    delete []ptr_p;
    for(int i = 0; i < SIZE; i++) ptr_p[i] = i;
    ptr_p = nullptr;
}
struct myInt { int x;};
struct myChar{char x0, x1, x2, x3;};
void stringAlong() {
    myInt anInt{0x41424344};
    myChar* c_ptr = reinterpret_cast<myChar*>(&anInt);
    cout << c_ptr->x3 << c_ptr->x2 << c_ptr->x1 << c_ptr->x0 << endl;
    string zzz = "H";
    cout << zzz.size() << endl;
    for(string::iterator it = zzz.begin(); it < zzz.end(); it++)
        cout << *it;
    cout << endl;
}
template<typename T>
struct Point{
    T x;
    T y;
    Point operator+ (Point p) {
        return Point{x + p.x, y + p.y};
    }
    Point add(Point a, Point b);
};
template<typename T>
Point<T> Point<T>::add(Point a, Point b) {
        return a + b;
}
template<class T>
    T add(T a, T b) {
        return a + b;
    }
template<>
struct Point<char>{//Template specialization
    // char x;
};
template<typename Metanoia>
struct Point<Metanoia*> {
    Point() {
        cout << "Metanoia" << endl;
    }
};
int main(int argc, char **argv) {
    Point <int>p1{3,4};
    Point <int>p2{10,20};
    Point <int>p3 = p1 + p2;
    cout << p3.x << ", " << p3.y << endl;
    cout << add(p1,p2).x << endl;

    using pointInt = Point<int>;
    pointInt pint{3, 14};
    cout << pint.x << endl;
//Now with template specialization
    Point<char> p;
    cout << sizeof(p) << endl;

    Point<char*> pp;
    return 0;
}