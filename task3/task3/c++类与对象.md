#### c++类与对象

###### this

this指针为const不可以被改变。this is a const pointer, so there is an error in line "this = t;"

this不可以指向static成员函数，变量等等

不可以用delete删除

👍

###### Constructor构造函数

```
t4 = t3;   // Assignment operator call 
```

###### 深浅拷贝

**总结：浅拷贝只是对指针的拷贝，拷贝后两个指针指向同一个内存空间，深拷贝不但对指针进行拷贝，而且对指针指向的内容进行拷贝，经深拷贝后的指针是指向两个不同地址的指针。**

###### static methods

**静态函数是一种特殊的函数类型，它只用于访问静态数据，任何其他正常数据都不能通过静态函数访问。与静态数据一样，静态函数也是一个类函数，它与任何类对象都没有关联。静态方法重载和静态方法只能访问静态成员。**

