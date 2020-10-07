#include "./LinearList.h"

template <class T>
class ArrayList : public LinearList<T>{
    public:
        ArrayList(int initialCapacity = 10){
            if(initialCapacity <= 0){
                initialCapacity = 10;
            }
            arrLength = initialCapacity;
            size = 0;
            arr = new T[arrLength];
        }
        ArrayList(const LinearList<T>& list);
        virtual ~ArrayList(){delete[] arr;};
        virtual void add(const T& element);
        virtual void add(int index, const T& element);
        virtual int indexOf(const T& element) const;
        virtual T& get(int index) const;
        virtual T& remove(int index);
        virtual bool remove(const T& element);
        virtual bool isEmpty()const {return this->size == 0;}
        virtual int getSize() const {return this->size;};
        virtual void output(std::ostream& out) const;
    private:
        void checkIndex(int index) const; //如果index无效，抛出异常
        T* arr;
        int size;//元素个数
        int arrLength;//数组的容量
        void checkAndExpandArray();

};

template<class T>
ArrayList<T>::ArrayList(const LinearList<T>& list){
    this->size = list.size();
    this->arrLength = this->size;
    this->arr = new T[size];
    for(int i = 0; i < this->size; ++i){
        this->arr[i] = list.get(i);
    }
    return;
}
template<class T>
void ArrayList<T>::add(const T& element) {

    this->size++;
    this->checkAndExpandArray();
    this->arr[this->size - 1] = element;
}

template<class T>
void ArrayList<T>::add(int index, const T& element){
    this->checkIndex(index);
    this->size++;
    this->checkAndExpandArray();
    //从后向前拷贝元素
    for(int i = this->size; i > index; i--){
        this->arr[i] = this->arr[i - 1];
    }
    
    this->arr[index] = element;
}
template<class T>
int ArrayList<T>::indexOf(const T& element) const{
    for(int i = 0; i < this->size; i++){
        if(element == this->arr[i]){
            return i;
        }
    }
    return -1;
}
template<class T>
T& ArrayList<T>::get(int index) const{
    checkIndex(index);
    return this->arr[index];
}
template<class T>
T& ArrayList<T>::remove(int index){
    checkIndex(index);
    T& element = this->arr[index];
    this->size--;
    for(int i = index; i < this->size;i++){
        this->arr[i] = this->arr[i + 1];
    }
    return element;
}
template<class T>
bool ArrayList<T>::remove(const T& element){
    int index = -1;
    for(int i = 0; i < this->size; i++){
        if(this->arr[i] == element){
            index = i;
            break;
        }
    }
    if(index == -1){
        return false;
    }else{
        this->remove(index);
        return true;
    }
}


template<class T>
void ArrayList<T>::output(std::ostream& out) const{
    for(int i = 0; i < this->size; i++){
        out << this->arr[i] << " ";
    }
    out << std::endl;
}
template<class T>
void ArrayList<T>::checkIndex(int index) const {
    if(index < 0 || index >= this->size){
        //抛出异常
    }
}

template<class T>
void ArrayList<T>::checkAndExpandArray(){
    if(this->size <= this->arrLength){
        return;
    }
    T* tmpArr = new T[this->arrLength * 2];
    for(int i = 0; i < this->arrLength; i++){
        tmpArr[i] = this->arr[i];
    }
    this->arrLength *= 2;
    T* tmp = this->arr;
    this->arr = tmpArr;
    delete[] tmp;
}

