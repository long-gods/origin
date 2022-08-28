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



#### 4，确定对象被使前已先被初始化

![image-20210730093755219](image\image-20210730093755219.png)

![image-20210730093729535](image\image-20210730093729535.png)

为了避免需要记住成员变量合适必须在成员初值列中初始化，何时不需要，最简单的做法就是：总是使用成员初值列。



​		许多classs拥有多个构造函数，每个构造函数有自己的成员初值列。这种类又存在许多成员变量和基类。在这种情况下可以合理地在初值列中遗漏那些“赋值表现像初始化一样好”的成员变量，改用它们的赋值操作，并将那些赋值操作移往某个函数（通常是private)，供所有构造函数调用。这种做法在“成员变量的初值系由文件或数据库读入”时特别有用。然而，比起经由赋值操作完成的“伪初始化”( pseudo-initialization)，通过成员初值列(memberinitialization list）完成的“真正初始化”通常更加可取。

为避免阅读者看你的代码迷惑和出现错误（某些成员变量的初始化带有次序性，如数组在初始化时需要指定大小，因此代表大小的那个成员变量必须先初始化。），在初值列中条列各个成员时，最好总是以声明次序为次序。

​	为内置型对象进行手工初始化，因为c++不保证初始化他们。

​	为免除“跨编译单元之初始化次序”问题，以local static对象替换non-local static对象。

#### 5，了解C++默默编写并调用哪些函数

​	引用自身不可被改动，C++拒绝编译关于引用的赋值动作。

​	编译器可以暗自为class创建default构造函数，copy构造函数，copy assignment操作符，以及析构函数。

​	copy构造函数，赋值函数是浅拷贝。

#### 6，若不想使用编译器自动生成的函数，就应该明确拒绝

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

#### 7，为多态基类声明virtual析构函数

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

#### 8，别让异常逃离析构函数

###### 	如果close抛出异常就结束程序，通常调用abort完成：

```c++
DBConn::~DBConn()
{
    try{db.close();}
    catch(...){
        //制作运转记录，记下对close的调用失败
        std::abort();//强迫结束程序
    }
}
```

​	如果程序遭遇一个“在析构期间发生的错误”后无法继续执行，“强迫结束程序”是个合理选项。毕竟它可以阻止异常从析构函数传播出去（导致不明确的行为）。调用abort可以抢先置“不明确行为”于死地。

###### 	吞下调用close而发生的异常：

```c++
DBConn::~DBConn()
{
    try{db.close();}
    catch(...){
        //制作运转记录，记下对close的调用失败
    }
}
```

​	一般而言，将异常吞掉是一个坏主意，因为它压制了“某些动作的失败”的重要信息！然而有时候吞下异常也比负担“草率结束程序”或“不明确行为带来的风险好”。为了让这成为一个可行方案，程序必须能够继续可靠地执行，即使在遭遇并忽略一个错误之后。

​	

```c++
class DBConn{
    public:
    void close()
    {
		db.close();
        closed=true;
    }
    ~DBConn()
    {
		if(!closed)	{
            try{
                db.close();
            }
            catch(...){
                制作运转记录，记下对close的调用失败；
                ...
            }
        }
    }
    private:
    DBConnection db;
    bool closed;
}
```

​	如果某个操作可能在失败的时候抛出异常，而又存在某种需要必须处理该异常，那么这个异常必须来自析构函数以外的某个函数。

​	如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class因该提供一个普通函数（而非在析构函数中）执行该操作。

​	析构函数绝对不要突出异常。如果一个被析构函数调用的函数可能抛出异常，析构函数应该捕捉任何异常，然后吞下他们或结束程序。

#### 9，绝不在构造和析构过程中调用virtual函数

​	

```c++
class Transaction{
    public:
    	Transaction();
    	virtual void logTransaction() const=0;
    ...
}

Transaction::Transaction()
{
    ...
    logTransaction();
}

class BuyTransaction:public Transaction{
    public:
    virtual void logTransaction() const;
    ...
}

class SellTransaction:public Transaction{
    public:
    virtual void logTransaction() const;
    ...

```

​	如果执行以下代码

```c++
BuyTransaction b;
```

​	无疑会有一个BuyTransaction构造函数被调用，但首先Transaction构造函数一定会被更早调用

这时候Transaction构造函数调用的logTransaction是base class中的版本。

​	base class构造期间virtual函数绝不会下降到derived class阶层。取而代之的是，对象的作为就像隶属base类型一样。非正式的说法，在base class构造期间，virtual函数不是virtual函数。

一个好理由：

​	由于base class构造函数的执行更早于derived class构造函数，当base class构造函数执行时derived class的成员尚未初始化。如果此期间调用的virtual函数下降至derived class阶层，要知道derived class的函数几乎必然取用local成员变量，而那些成员变量尚未初始化。这将是一张通往不明确行为和彻夜调试大会串的直达车票。“要求使用对象内部尚未初始化的成分”是危险的代名词，所以c++不让你走这条路。

根本原因：

​	在derived class对象的base class构造期间，对象的类型是base class而不是derived class。不只virtual函数会被编译器解析至base class，若使用运行期类型信息（如dynamic_cast和typeid）也会把对象视为base class类型。

​	对象在derived class构造函数开始执行前不会成为一个derived class对象。

  同样的在析构函数中，一旦你derived class析构函数开始执行，对象内的derived class成员便成现未定义值。进入base class析构函数后对象就成为一个base class对象，而c++的任何部分包括virtual函数，dynamic_casts等等都这么看他

​	

```c++
class Transaction{
    public:
    	explicit Transaction(const std::string& logInfo);
    	void logTransaction(const std::string& logInfo) const;
};

Transaction::Transaction(const std::string& logInfo){
    logTransaction(logInfo);
}

class BuyTransaction:public Transaction{
    public:
		BuyTransaction(parameters):Transaction(createLogString(parameters)){...}
	private:
    	static std::string createLogString(parameters);
};
```

​	在class Transaction内将logTransaction函数改为non-virtual，然后要求derived class构造函数传递不要的信息给Transaction构造函数，然后那个构造函数便可安全地调用non-virtual logTransaction。

​	如无法使用virtual函数从基类向下调用，则可以将必要的信息向上传递至base class构造函数。

###### 在构造和析构期间不要调用virtual函数，因为这类调用从不下降至derived class。

#### 10，令operator=返回一个reference 同 *this

```c++
class Widget{
    public:
    Widget& operator=(const Widget& rhs){
		return *this;
    }
}
```

为了实现连锁赋值：x=y=z=10;

#### 11，在operato=中处理“自我赋值”

widget w;

w=w;

看起来很蠢，但合法，所以不要认定客户不会这么做。

还有比如潜在的自我赋值。

```c++
a[i]=a[j]
*px=*py
```

这些并不明显的自我赋值是别名带来的结果：所谓别名就是“有一个以上的方法指称某对象”。实际上两个对象只要来自同一个继承体系，甚至不需要声明为相同类型就可能造成“别名”，因为一个base class的引用或指针可以指向一个derived class对象。

```c++
class Base{...};
class Derived:public Base{...};
Base& rb;
Derived* pd;
```

```c++
class Bitmap{...};
class Widget{
    private:
    	Bitmap* pb;
};

Widget& Widget::operator=(const Widget& rhs)
{
	delete pb;
    pb=new Bitmap(*rhs.pb);
    return *this;
}
```

​	如果*this和rhs是同一个对像，delete就不只删除当前对象的bitmap也销毁了rhs的bitmap。结果是发现自己持有的一个指针指向一个已经被删除的对象。

​	想要阻止错误可以在前面加一个“证同测试”

```c++
if((this==&rhs))
    return *this;
```

或者注意：在复制pb所指东西前别删除pb：

```c++
Widget& Widget::operator=(const Widget& rhs){
    Bitmap* pOrig=pb;
    pb=new Bitmap(*rhs.pb);
    delete pOrig;
    return *this;
}
```

 关于效率问题，跟据“自我赋值”发生的频率有多高，因为这项预测也需要成本。他会使代码变大一些（包括原始代码和目标代码）并导入一个新的控制流分支，两者都会降低执行速度。

​	一个替代方案：使用所谓的copy and swap技术。实现手法：

```c++
class Widget{
    void swap(Widget& rhs);
    
};

Widget& Widget::operator=(const Widgets& rhs){
    Widget temp(rhs);
    swap(temp);
    return *this;
}
```

(1)某class的copy assignment操作符可能被声明为“以by value方式接受实参”；

(2)以by value方式传递东西会造成一份附件/副本：

```c++
Widget& Widget::operator=(Widget rhs)
{
    swap(rhs);
    return *this;
}
```

它为了伶俐巧妙的修补牺牲了清晰性。然后而将“copy动作”从函数本体内移至“函数参数构造阶段”却可以令编译器有时生成更高效的代码。

###### 确保当对象自我赋值时operator=有良好的行为。其中技术包括比较“来源对象”和“目标对象”的地址，精心周到的语句顺序，以及copy-and-swap.

###### 确定任何函数如果操作一个以上的对象，而其中多个对象，是同一个对象时，其行为仍然正确。

#### 12，复制对象时勿忘记其每一个成分

​	如果你为class添加一个成员变量，你必须同时修改copying函数。（也需要修改class的所有构造函数以及任何非标准形式的operator=（条款10）。如果你忘记，编译器不太可能提醒你。）

​	一旦发生继承，子类的复制构造函数并没有指定实参传递给base构造函数，因此子类对象的父类成分会被不带实参的父类构造函数初始化。默认构造函数对成员变量执行缺省的初始化动作（父类）。

​	当你编写一个copying函数，请确保（1）复制所有local成员变量，（2）调用所有base classes内适当的copying函数。

​	令copy assignment操作符调用copy构造函数是不合理的，因为这就像试图构造一个已经存在的对象。所以不该令上述情况发生（反方向同样无意义）。

##### 	如果你发现你的copy构造函数和copy assignment操作符有相近的代码，建立一个新的成员函数给两者调用，此函数往往是private并被命名为init。

##### 当你编写一个copying函数，请确保（1）复制所有local成员变量，（2）调用所有base classes内适当的copying函数。

#### 13，以对象管理资源

​	把资源放进对象内，我们便可依赖c++的析构函数自动调用机制“确保资源被释放。

------

##### 智能指针：shared_ptr,unique_ptr,weak_ptr.（包含在头文件《memory》中

1,shared_ptr

原理：1）的多个对象指向同一个指针（大多是new出来的空间指针），该指针使用引用计数，每使用一次，内部计数器加1，每析构一次，内部引用计数器减一，减为0的时候自动删除指向的堆内存。

2）不要用一个原始指针初始化多个shared_ptr，否则会造成二次释放同一内存。

3）注意避免循环使用。

2，unique_ptr

​	”唯一“拥有所指对象，同一时刻只能有一个unique_ptr指向给定对象（禁止使用拷贝语义，只能用移动语义将其移动）。对比原始指针，也是利用了RALL的特性。用户可以定义delete操作。

```c++
int main()
{
	unique_ptr<int> uptr(new int(20));
    unique_ptr<int> uptr1=move(uptr);
    return 0;
}
```

3,weak_ptr,配合shared_ptr而引入的智能指针，是弱引用，相对于shared_ptr强引用来说的。看似就像一个观察者，观测资源的使用情况。weak_ptr可以从一个shared_ptr获取另一个weak_ptr来构造，获取资源的观察权。并不会引起计数加的情况，成员有use_count()，查看资源的引用计数，expired（），判断是否指向的资源被释放，当返回为true的时候，这个资源的引用计数为0，相当与被释放。lock（）返回当前分享指针，计数器并加一。

------



```c++
void f()
{
    std::auto_ptr<Investment> pInv(createInvestment);
    
}
```

两个关键想法：

###### 获得资源后立刻放进管理对象内。

###### 管理对象运用析构函数确保资源被释放

#### 14，在资源管理类中小心copy行为

```c++
void lock(Mutex* pm);
void unlock(Mutex* pm);

//建立一个class用来管理机锁

class Lock{
    public:
    	explicit Lock(Mutex* pm):mutexPtr(pm)
        {lock(mutexPtr);}
    ~lock(){unlock(mutexPtr);}
    private:
    	Mutex *mutexPtr;
};

```

**禁止复制**，许多时候允许RALL对象被复制并不合理。对一个像lock这样的class这是有可能的，因为很少能够合理拥有”同步化基础器物“的副本。如果复制动作对RALL class并不合理，你便应该禁止。

**对底层资源祭出”引用计数法**，有时候我们希望保有资源，直到它的最后使用者被销毁。

**复制底部资源**，有时候，只要你喜欢，可以针对一份资源拥有其任意数量的复件。

**转移底部资源的拥有权**某些罕见的场合下你可能希望确保永远只有一个RALL对象 指向一个未加工资源，即使RALL对像被复制依然如此。

##### 复制RALL对象必须一并复制它所管理的资源，所以资源的copying行为决定RALL对象的copying行为。

##### 普遍而常见的RALL class copying行为是：抑制copying，施行引用计数法。不过其他行为也可能被实现。

#### 15，在资源管理类中提供对原始资源的访问

##### APIs往往要求访问原始资源，所以每一个RALL　class应该提供一个“取得其所管理之资源”的办法。

##### 对原始资源的访问可能经由显式转换或隐式转换。一般而言显示转换比较安全，但隐式转换对客户比较方便。

#### 16，成对使用new和delete时要采用相同的形式

```C++
std::string* stringArray=new std::string[100];

delete stringArrany;
```

​	这个程序行为不明确(未有定义).最低限度,stringArray所含的100个string对象中的99个不太可能被删除,因为他们的析构函数可能没被调用.

​	当你使用new,有两件事发生.第一,内存被分配出来(通过名为operator new的函数).第二,针对此内存会有一个(或多个)构造函数被调用.当你使用delete,也有两件事发生:针对此内存会有一个或多个析构函数被调用,然后内存才被释放(通过名为operator delete的函数).delete的最大问题在于:即将被删除的内存之内究竟存有多少对象?

​	当你对着一个指针使用delete，唯一能够让delete知道内存中是否存在一个”数组大小记录“的办法就是：你来告诉它。使用delete时加上中括号（【】）

delete便认定指针指向一个数组，否则它便认定指针指向单一对象

```c++
std::string* stringArray=new std::string[100];

delete[] stringArrany;
```

​	如果对stringPtr1使用“delete[]”会发生什么？结果不定，但可能不太好。delete可能会读取若干内存并向它解释为数组大小，然后开始多次调用析构函数，浑然不知它所处理的那块内存不但不是个数组，也或许并未持有它正忙着销毁的那种类型的对象。

```c++
typedef std::string AddressLines[4];

std::string* pal=new AddressLines;

delete pal;//行为未有定义
delete [] pal;//good
```

##### 如果你在new表达式中使用[],必须在相应的delete表达式中也使用[]。不使用则都不使用。

#### 17，以独立语句将newed对象置入智能指针

```c++
int priority();
void processWidget(std::tr1::shared_ptr<Widget> pw,int priority);

processWidget(new Widget,priority());//不能通过编译
```

tr1::shared_ptr构造函数需要一个原始指针，但该构造函数是个explicit构造函数，无法进行隐式转换，将得自 new Widget 的原始指针转换为processWidget所要求的tr1::shared_ptr。

```c++
processWidget(std::tr1::shared_ptr<Widget>(new Widget),priorty());
```

​	 编译器产出一个processWidget调用码前必须首先核算即将被传递的各个实参。上述第二实参只是一个单纯的对priority函数的调用，但第一实参std::tr1::shared_ptr<Widget>(new Widget)由两部分组成：

​	执行"new Widget"表达式

​	调用tr1::shared_ptr构造函数

于是在调用processWidget之前，编译器必须创建代码，做以下三件事：

​	调用priority

​	执行“new Widget"

​	调用tr1::shared_ptr构造函数

C++编译器不会一定的次序完成这件事，如果可以确定的是”new Widget“一定执行与tr1::share_ptr构造函数之前，因为这个表达式的结果还要被传递作为tr1::shared_ptr的一个实参，但对priority的调用则可以排在第一第二或第三执行。如果编译器选择以第二顺位执行它（说不定可以因此生成更高效的代码，最终获得这样的操作序列：

1，执行”new Widget“

2，调用priority

3，调用tr1::shared_ptr构造函数

​	万一对priority的调用导致异常，”new Widget“返回的指针将会遗失，因为它尚未被置入tr1::share_ptr内，后者是我们期盼用来防卫资源泄露的武器。是的，在对processWidget的调用中可能引发资源泄露，因为在”资源被创建（经由“new Widget”）“和”资源被转换为资源管理对象“两个时间点之间有可能发生异常干扰。

​	避免这类问题的方法很简单：使用分离语句，分别写出（1）创建WIdge，（2）将它置入一个智能指针内，然后再把那个智能指针传给processWidget：

​	

```c++
std::tr1::shared_ptr<Widget> pw(new Widget);//在单独语句内以智能指针存储newd所得对象

processWidget(pw,priority());
```

​	上述之所以行得通，因为编译器对于”跨越语句的各项操作“没有重新排列的自由（只有在语句内它才拥有那个自由度）。在上述修订后代码内

