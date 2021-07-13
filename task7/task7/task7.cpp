#include <memory>
#include <iostream>
using namespace std;

template<typename T>
class smart {
private:
    T* _ptr;
    int* _count; //reference counting
public:
    //构造函数
    smart(T* ptr = nullptr) :_ptr(ptr) {
        if (_ptr) {
            _count = new int(1);
        }
        else {
            _count = new int(0);
        }
        cout << *_count << endl;
    }

    //拷贝构造
    smart(const smart& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;

            (*this->_count)++;
        }
        cout << *_count << endl;
    }

    //重载operator=
    smart operator=(const smart& ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }
        if (this->_ptr) {
            (*this->_count)--;
            if (this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        cout << *_count << endl;
        return *this;
    }

    //operator*重载
    T& operator*() {
        if (this->_ptr) {
            return *(this->_ptr);
        }
    }

    //operator->重载
    T& operator->() {
        if (this->_ptr) {
            return this->_ptr;
        }
    }
    //析构函数
    ~smart() {
        (*this->_count)--;
        cout << *_count << endl;
        if (*this->_count == 0) {
            cout << *_count << endl;
            delete this->_ptr;
            delete this->_count;
        }
    }
    bool isempty() {
        if (_ptr)
            return true;
        else
            return false;
    }
    //return reference counting
    int use_count() {
        return *this->_count;
    }
};
int main()
{
	smart<int> ptr(new int (1));
	smart<int> ptr1;
	ptr1 = ptr;
    if (ptr1.isempty())
        cout << "indead" << endl;
	return 0;
}


