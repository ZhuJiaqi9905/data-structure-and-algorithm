#include<iostream>
#include "./list/ArrayList.h"
int main(){
    //std::cout << "hello world" << std::endl;
    ArrayList<double> list;
    //增
    for(int i = 0; i < 20; ++i){
        list.add(0.01 * i);
    }
    list.output(std::cout);
    std::cout << list.get(1) << std::endl;
    list.add(10, 10.0);
    list.output(std::cout);
    //删
    list.remove(0);
    list.remove(0.03);
    list.output(std::cout);
    //查
    std::cout << list.indexOf(0.05) << std::endl;
    std::cout << list.getSize() << std::endl;
    
}
