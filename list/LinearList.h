#include<iostream>
template<class T>
class LinearList{
    public:
        virtual ~LinearList(){};
        virtual void add(const T& element) = 0;
        virtual void add(int index, const T& element) = 0;
        virtual int indexOf(const T& element) const = 0;
        virtual T& get(int index) const = 0;
        virtual T& remove(int index) = 0;
        virtual bool remove(const T& element) = 0;
        virtual bool isEmpty() const = 0;
        virtual int getSize() const = 0;
        virtual void output(std::ostream& out) const = 0;
};