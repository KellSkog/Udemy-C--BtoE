#include <iostream>
#include <vector>
#include <ctime>
#include <array>
#include <vector>
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
void specialize() {
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
}
void pointerAndRefs() {
    int x = 999;
    int *px = &x;
    int * const * const cpcpx = & px;//Const pointer to const pointer
    int * * const pcpx = & px;//Const pointer to const pointer
    *pcpx = nullptr;
    int * const * cppx = & px;//Const pointer to const pointer
    //pcpx = nullptr; cannot assign to cons pointer
    int *const & rcpx = px;//Reference to a const pointer to x
    //int * & const crpx = px;//Const Reference to a pointer to x
    cout << rcpx << endl;//Adr of x
    //cout << *crpx << endl;//x
    //rpx = px+1; Illegal, rpx is a const
}
void aBitRandom() {
    srand(time(nullptr));
    cout << rand() << endl << (RAND_MAX + 1u) << endl;
    // RAND_MAX is the maximum value returned by rand(), giving RAND_MAX + 1 possible values
    constexpr int noOfRandoms = 6;
    int oneInSixRandom = rand() / (RAND_MAX + 1u) / noOfRandoms;//[0 6] exclusive 6
}
int getBall(int totalBalls) {
    return rand() / ((RAND_MAX + 1u) / totalBalls);
}
void lottery(vector<int> &balls, int ballCnt, int totalBalls) {
    srand(time(nullptr));
    int rnd;
    bool isDuplicate;
    for(int i = 0; i < ballCnt; i++) {
        do {
            rnd = getBall(totalBalls);
            // cout << rnd << "; ";
            isDuplicate = false;
            for(int ball : balls) {
                if(ball == rnd) {
                    isDuplicate = true;
                    break;
                }
            }
        } while(isDuplicate);
        balls.push_back(rnd);
        // cout << ballCnt << ", ";
    }
}
void playLottery() {
    constexpr int noOfBalls = 6;
    constexpr int TotalBalls = 39;
    vector<int>a1;
    lottery(a1, noOfBalls, TotalBalls);
    for(int ball : a1) {
        cout << ball << ", ";
    }
    cout << endl;
}
namespace AA{
    struct A{
    void a() {cout << "Playing" << endl;}
    static void b() {cout << "Also playing" << endl;}
};
}
int main(int argc, char **argv) {
    AA::A a;
    a.a();
    AA::A::b();

    return 0;
}