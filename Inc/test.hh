#ifndef TEST1234
#define TEST1234

struct Test{
    int x;
    int y;
    float* p;
    public:
    Test();
    Test(int x, int y);
    Test(int x, int y, float *p);
    Test(Test const &t);
    // Test(Test const &t) = delete;
    // ~Test() = delete;
};


#endif