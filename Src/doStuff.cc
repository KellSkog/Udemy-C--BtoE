#include "doStuff.hh"

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
    Point<T>::Point(T a, T b) : x{a}, y{b} {}
template<typename T>
Point<T> Point<T>::add(Point a, Point b) {
        return a + b;
}
template<class T>
    T add(T a, T b) {
        return a + b;
    }
template<class T>    
    Point<T> Point<T>::operator+(Point<T> p){return Point{x+p.x, y+p.y};}
template<>
struct Point<char>{//Template specialization
    // char x;
};
template<typename Metanoia>
//struct Point<Metanoia*> {
    Point<Metanoia*>::Point() {
        cout << "Metanoia" << endl;
    }
//};
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

    void A::a() {cout << "Playing" << endl;}
    void A::b() {cout << "Also playing" << endl;}

}
void dobedoo() {
    AA::A a;
    a.a();
    AA::A::b();
}

    void BB::bb() {}
    void  BB::bc() const{}


void holabaloa(BB bb) {
    bb.x = 0;
}
void constant() {
    BB const b;
    //b.bb(); //can only call a const function of a const object!
    BB c;
    c.bb();
    c.bc();
    b.bc();
}

    BBB::BBB(int x) : x{x} {}

    void AAA::print(BBB b) {cout << b.x << endl;}

void playWithFriends() {
    BBB b(666);
    AAA::print(b);
}

void copyConstructor() {
    // Test t;
    // float f = 3.14, g = 6.28;
    // Test t2{3, 14, &f};
    // // Test t3(t);
    // Test tt = t2;
    // *tt.p = g;
    // cout << tt.x << ", " << tt.y << endl;
    // cout << *tt.p << ", " << *t2.p << endl;
}

template<typename T>
    Thing<T>::Thing(T val) : val{val} {}
template struct Thing<int>;//Instantiate a template


template<typename T>
    Thing<T>::operator T(){return val;}
//template operator Thing<int>::operator T()

template<typename T>
    T Thing<T>::operator +=(const Thing<T> &t) {val += t.val; return val;}
template<typename T>
    bool Thing<T>::operator==(const T & t){return t == val;}