#ifndef __PILA_HPP__
#define __PILA_HPP__
#include <vector>
using namespace std;

template <class T>
class Pila{
private:
    vector<T> data;
public:
    Pila() {
        data = vector<T>();
    };
    ~Pila() {};
    void push(T dat);
    T &top();
    T &operator[](int i);
    T pop();
    int size();

};
template<class T>
int Pila<T>::size()
{
    return data.size();
}

template<class T>
void Pila<T>::push(T dat)
{
    data.push_back(dat);
}

template<class T>
T &Pila<T>::top()
{
    int size = data.size()-1;
    return data[size];
}

template<class T>
T &Pila<T>::operator[](int i)
{
    int size = data.size()-1;
    return data[size-i];
}

template<class T>
T Pila<T>::pop(){
    int size = data.size()-1;
    T dato = data[size];
    data.pop_back();
    return dato;
}

#endif // !__PILA_HPP__