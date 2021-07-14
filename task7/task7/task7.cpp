#include"sharepoint.h"

int main()
{
	sharepoint<int> ptr(new int (1));
    cout << ptr.use_count() << endl;
	sharepoint<int> ptr1;
	ptr1 = ptr;
    cout << ptr.use_count() << endl;
    cout << *ptr << " " << *ptr1 << endl;
    cout << ptr.get() << *ptr.get() << endl;
    a* b;
    sharepoint<a> ptr3(new a{ 1 });
    cout << ptr3->get() << endl;
    sharepoint<int> ptr4;
    if(ptr4)
        cout << "indead" << endl;
    if (ptr3)
        cout << "indead" << endl;
	return 0;
}

