#include "test.hh"

Test::Test() : x{0}, y{0} {}
Test::Test(int x, int y) : x{x}, y{y} {}
Test::Test(int x, int y, float *p) : x{x}, y{y}, p{p} {}
Test::Test(Test const &t) : x{t.x}, y{t.y}, p{t.p} {}
