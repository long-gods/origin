#include <memory>
#include <iostream>
using namespace std;

struct a {
    int data;
    int get() {
        return data;
    }
};
template<typename T>
class sharepoint {
private:
    T* _ptr;
    int* _count; //reference counting
public:
    //构造函数
    sharepoint(T* ptr = nullptr) :_ptr(ptr) {
        if (_ptr) {
            _count = new int(1);
        }
        else {
            _count = new int(0);
        }
    }

    //拷贝构造
    sharepoint(const sharepoint& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;

            (*this->_count)++;
        }
    }

    //重载operator=
    sharepoint operator=(const T* ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }
        this->_ptr = _ptr;
        return *this;
    }
    //重载operator=
    sharepoint operator=(const sharepoint& ptr) {
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
        return *this;
    }

    //operator*重载
    T* operator*() {
            return this->_ptr;
    }

    //operator->重载
    T* operator->() {
            return _ptr;
    }
    //T& operator->() {
    //    return _ptr;
    //}
    //析构函数
    ~sharepoint() {
        (*this->_count)--;
        if (*this->_count == 0) {
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
    T* get() {
        return &this->_ptr;
    }
    //return reference counting
    int use_count() {
        return *this->_count;
    }
};
int main()
{
	sharepoint<int> ptr(new int (1));
	sharepoint<int> ptr1;
	ptr1 = ptr;
    cout << *ptr << " " << *ptr1 << endl;
    a* b;
    sharepoint<a> ptr3(new a{ 1 });
    cout << ptr3->get() << endl;
    if (ptr1.isempty())
        cout << "indead" << endl;
	return 0;
}


