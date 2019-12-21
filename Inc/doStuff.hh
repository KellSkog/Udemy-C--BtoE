#ifndef DO_STUFF_HH
#define DO_STUFF_HH

#include <iostream>
#include <vector>
#include <ctime>
#include <array>
#include <vector>
#include "PrimalConfig.h"

// #include<string>//getline
using namespace::std;

void user_input_stuff();
void dynamic_mem();
struct myInt { int x;};
struct myChar{char x0, x1, x2, x3;};
void stringAlong();
template<typename T>
struct Point{
    T x;
    T y;
    Point(T x, T y);
    Point operator+ (Point p);
    Point add(Point a, Point b);
};
// template<typename T>
// Point<T> Point<T>::add(Point a, Point b);
template<class T>
    T add(T a, T b);
template<>
struct Point<char>;//Template specialization
    // char x;

template<typename Metanoia>
struct Point<Metanoia*> {
    Point();
};
void specialize();
void pointerAndRefs();
void aBitRandom();
int getBall(int totalBalls);
void lottery(vector<int> &balls, int ballCnt, int totalBalls);
void playLottery();
namespace AA{
    struct A{
    void a();
    static void b();
};
}
void dobedoo();

struct BB {
    void bb();
    void  bc() const;
    friend void holabaloa(BB bb);
    private:
    int x = 0;
};
void holabaloa(BB bb);
void constant();
class AAA;
class BBB{
    friend class AAA;//Now private x become available to AAA
    int x;
    public:
    BBB(int x);
};
class AAA{
    public:
    static void print(BBB b);// {cout << b.x << endl;}
};
void playWithFriends();

void copyConstructor();
template<typename T>
struct Thing {
    T val;
    Thing(T val);// {}
    operator T();//{return val;}
    T operator +=(const Thing<T> &t);// {val = val + t; return val;}
    bool operator==(const T & t);
};
#endif