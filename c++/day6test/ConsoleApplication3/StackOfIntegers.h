#pragma once
template<class T>
class StackOfIntegers {
private:
	T elements[100];
	int size{ 0 };
public:
	bool empty();
	T peek();
	T push(T value);
	T pop();
	int getSize();
};

template<class T>
bool StackOfIntegers<T>::empty() {
    return (size == 0 ? true : false);
}

template<class T>
int StackOfIntegers<T>::getSize() {
    return size;
}

template<class T>
T StackOfIntegers<T>::peek() {
    return elements[size - 1];
}

template<class T>
T StackOfIntegers<T>::pop() {
    T temp = elements[size - 1];
    elements[size - 1] = 0;
    size--;
    return temp;
}

template<class T>
T StackOfIntegers<T>::push(T value) {
    elements[size] = value;
    size++;
    return value;
}