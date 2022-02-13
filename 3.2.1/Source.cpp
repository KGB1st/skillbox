#include <iostream>
#include <random>

#include <math.h>

using namespace std;

template<typename T>
class MyVector
{
    T* vec;
    unsigned int _size;

public:

    class MyIterator;

    MyVector(unsigned int num = 1) : _size(num)
    {
        vec = new T[num];
    };

    MyIterator begin()
    {
        return vec;
    }

    MyIterator end()
    {
        return vec + _size;
    }

    T& operator[] (const unsigned int& num)
    {
        return vec[num];
    }

    friend ostream& operator<< (ostream& s, const MyVector<T>& n);
    friend ostream& operator<< (ostream& s, const MyVector<T>* n);

    class MyIterator
    {
        T* _ptr;
    public:
        MyIterator(T* begin) : _ptr(begin) {};

        T& operator* () { return *_ptr; };

        T& operator+ (int num) { return *(_ptr + num); };
        T& operator- (int num) { return *(_ptr - num); };

        T& operator++ (int) { return *_ptr++; };
        T& operator-- (int) { return *_ptr--; };
        T& operator++ () { return *++_ptr; };
        T& operator-- () { return *--_ptr; };

        bool operator!= (const MyIterator& it) { return _ptr != it._ptr; };
        bool operator== (const MyIterator& it) { return _ptr == it._ptr; };

    };
};

template <typename T>
ostream& operator<<(ostream& s, const MyVector<T>& n)
{
    return (s << MyVector<T>::vec[n]);
}

template <typename T>
ostream& operator<<(ostream& s, const MyVector<T>* n)
{
    return (s << MyVector<T>::vec[n]);
}

int main(int argc, char* argv[])
{
    MyVector<unsigned int> vec(numeric_limits<unsigned int>::max());

    auto it = MyVector<unsigned int>::MyIterator(vec.begin());
    unsigned int len = 0;

    while (it != vec.end())
    {
        //cout << "Cell: " << *it << endl;
        ++len;
        ++it;
    }

    printf("Vector length: %u (uint) elements\n", len);

    auto begin = vec.begin();
    printf("Beginning vector pointer: %p\n", begin);
    auto end = vec.end();
    printf("Vector end pointer: %p\n", end);

    printf("Array commit memory: %.2f GB\n", (len * sizeof(unsigned int) / pow(1024, 3)));

    cin.get();

    return 0;
};