#ifndef DO_OTHER_STUFF_HH
#define DO_OTHER_STUFF_HH
#include <string>

namespace other {
    template<typename T>
    class Other {
        T x;
        public:
        Other(T x);
        ~Other();
        bool isAt(T t);
        bool operator==(Other<T> &other);
    };
    class Neither {
        int x;
        public:
        void operator()(int (*)(const char *));

    };
    
}
namespace chapter51 {
    template<typename T>
    class Point {
        protected:
        T x;
        
        public:
        Point();
        Point(T);
        ~Point();
        T getX();
        void setX(T);
        template<typename U>
        friend U operateOn(const Point<U>&);
    };
    template<typename T>
    class Point2D : public Point<T> {
        protected:
        T y;
        
        public:
        Point2D();
        Point2D(T, T);
        ~Point2D();
        T getY();
        void setY(T);
        void setXY(T, T);
    };

    template<typename T>
    class Point3D : public Point2D<T> {
        protected:
        T z;
        
        public:
        Point3D();
        Point3D(T, T, T);
        ~Point3D();
        T getZ();
        void setZ(T);
        void setXYZ(T, T, T);
    };
    template<typename T>
        T operateOn(const Point<T>&);

}
namespace ch52 {
    template<typename T>
    class Animal {
        protected:
        T voice = "kzrwt";

        public:
        Animal(T);
        ~Animal();
        T speak();
    };
    template<typename T>
    class Dog : public Animal<T>::Animal {
        public:
        Dog(T);
        ~Dog();
    }; 
}//namespace ch52
#endif