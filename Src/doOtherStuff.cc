#include "doOtherStuff.hh"
#include <string>
//#include <iostream>
namespace other {
    template<typename T>
        Other<T>::Other(T x) : x{x} {}
    template<typename T>
        Other<T>::~Other() {}
    template class Other<int>;
    template<typename T>
        bool Other<T>::isAt(T t) {return t == x;}
    template<typename T>
    bool Other<T>::operator==(Other<T> &other){return this->x == other.x;}

    void Neither::operator()(int (*p)(const char *__s)){p( "I'm a function operator");}
    
    
    //template class Point<int>;//Explicit template instantiation
}
namespace chapter51 {
    template<typename T>
        Point<T>::Point(){Point(0);}
    template<typename T>
        Point<T>::Point(T x) : x{x} {}
    template<typename T>
        Point<T>::~Point(){}
    template<typename T>
        T Point<T>::getX(){return x;}
    template<typename T>
        void Point<T>::setX(T x){this -> x = x;}

    template<typename T>
        Point2D<T>::Point2D(T x, T y) : Point<T>::Point(x), y{y}{}
    template<typename T>
        T Point2D<T>::getY(){return y;}
    template<typename T>
        void Point2D<T>::setY(T y){this -> y = y;}
    template<typename T>
        void Point2D<T>::setXY(T x, T y) {Point<T>::setX(x); setY(y);}  
    template<typename T>
        Point2D<T>::~Point2D(){}
    
    template<typename T>
        Point3D<T>::Point3D(T x, T y, T z) : 
            Point2D<T>::Point2D(x, y), z{z}{}
    template<typename T>
        T Point3D<T>::getZ(){return z;}
    template<typename T>
        void Point3D<T>::setZ(T z){this -> z = z;}
    template<typename T>
        void Point3D<T>::setXYZ(T x, T y, T z) {
            Point2D<T>::setXY(x, y); setZ(z);}  
    template<typename T>
        Point3D<T>::~Point3D(){}
    template<typename T>
        T operateOn(const Point<T> &point) {
    /*error: ‘int chapter51::Point<int>::x’ is private within this context
    * Solved by adding template<typename U> to the friend declaration
    */
            return point.x;
        }

    template class Point<int>;
    template class Point2D<int>;
    template class Point3D<int>;
    template class Point<double>;
    template class Point2D<double>;
    /* undefined reference to: 
    * int chapter51::operation<int>(chapter51::Point<int>)
    *  Problem was missing '&' in param type declaration
    */
    template int operateOn(const Point<int>&);
}
namespace ch52 {
    template<typename T>
        Animal<T>::Animal(T sound) : voice{sound}{}
    template<typename T>
        Animal<T>::~Animal(){}
    template<typename T>
        T Animal<T>::speak(){return voice;}

    template<typename T>
        Dog<T>::Dog(T bark) : Animal<T>::Animal(bark) {}
    template<typename T>
        Dog<T>::~Dog() {}

   template class Animal<std::string>;
   template class Dog<std::string>;
}//namespace ch52