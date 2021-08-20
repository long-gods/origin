c++并不是一个带有一组守则的一体语言，它是由四个次语言（c，Object-Oriented C++,Template C++,STL)组成的联邦政府。

###### explicit 声明：

阻止他们被用来执行隐式类型转换，但仍被用来进行显式类型转换；



![image-20210729102318565](image\image-20210729102318565.png)

Widget w3=w1                                 //调用copy构造函数

pass-by-value（值传递）意味“调用copy构造函数”

以值传递用户自定义类型通常是bad idea。

![image-20210729103103409](image\image-20210729103103409.png)

一般而言，可以合理假设只有内置类型和STL的迭代器和函数对象可以用值传递。其他任何东西都尽量用const 引用传递。

![image-20210729114907499](image\image-20210729114907499.png)

 const std::vector<int>::iterator iter;//iter指向的值可以改变，iter不能改变

std::vector<int>::const_iterator iter;

const 函数（）//修饰的是返回值，表示返回的是指针所指向值是常量

int hanshu() const//只读函数，不允许修改其中的值

 

![image-20210729174216393](image\image-20210729174216393.png)

![image-20210729173724522](image\image-20210729173724522.png)

mutable（可变） int   //这样声明在const 函数中也可以被更改



#### 确定对象被使前已先被初始化

![image-20210730093755219](image\image-20210730093755219.png)

![image-20210730093729535](image\image-20210730093729535.png)

为了避免需要记住成员变量合适必须在成员初值列中初始化，何时不需要，最简单的做法就是：总是使用成员初值列。



​		许多classs拥有多个构造函数，每个构造函数有自己的成员初值列。这种类又存在许多成员变量和基类。在这种情况下可以合理地在初值列中遗漏那些“赋值表现像初始化一样好”的成员变量，改用它们的赋值操作，并将那些赋值操作移往某个函数（通常是private)，供所有构造函数调用。这种做法在“成员变量的初值系由文件或数据库读入”时特别有用。然而，比起经由赋值操作完成的“伪初始化”( pseudo-initialization)，通过成员初值列(memberinitialization list）完成的“真正初始化”通常更加可取。

为避免阅读者看你的代码迷惑和出现错误（某些成员变量的初始化带有次序性，如数组在初始化时需要指定大小，因此代表大小的那个成员变量必须先初始化。），在初值列中条列各个成员时，最好总是以声明次序为次序。

​	为内置型对象进行手工初始化，因为c++不保证初始化他们。

​	为免除“跨编译单元之初始化次序”问题，以local static对象替换non-local static对象。

#### 了解C++默默编写并调用哪些函数

​	引用自身不可被改动，C++拒绝编译关于引用的赋值动作。

​	编译器可以暗自为class创建default构造函数，copy构造函数，copy assignment操作符，以及析构函数。

#### 若不想使用编译器自动生成的函数，就应该明确拒绝

​	编译器产出的函数都是public，为阻止他们被创建出来，可以自行声明他们并将它们声明为private，使得阻止被调用。

​	函数参数名称并非必要（可以不写）：void a（const int&）

​	使用像Uncopyable这样的base class也是一种做法。

```c++
class Uncopyable{
    protected:
    Uncopyable(){}
    ~Uncopyable(){}
    private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
}

class HomeForSale:private Uncopyable{...};
```

#### 为多态基类声明virtual析构函数

​	当derived class对象经由一个base class指针被删除，而基类带着一个non-virtual析构函数，其结果未有定义--实际执行时通常发生的是对象的derived成分没被销毁。造成一个诡异的“局部销毁”对象。这会导致资源泄漏，败坏数据结构，在调试器上浪费许多时间。

​	![20210818220514](image\20210818220514.png)



```c++
class AWOV{
    public:
    virtual ~AWOV()=0;//必须为这个纯虚函数提供一份定义
}

AWOV::~AWOV(){}//纯虚析构函数的定义
```

​	析构函数的运作方式是，最深层派生的那个class的析构函数最先被调用，然后是其每一个base class的析构函数被调用。编译器会在AWOV的派生类的析构函数中创建一个对~AWOV的调用动作，所以必须为这个函数提供一份定义。不然连接器会报错。

​	classed的设计目的如果不是作为base class 使用，或不是为了具备多态性，就不该声明virtual析构函数。

