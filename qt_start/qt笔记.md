#### 窗口——QWidget

QWdiget(QWidget *parent=0，Qt::WindowFlags f=0);

其中参数 parent 指向父窗口，如果这个参数为 0，则窗口就成为一个顶级窗口  
       参数 f 是构造窗口的标志，主要用于控制窗口的类型和外观等，有以下常用值。  
       1）Qt::FramelessWindowHint：没有边框的窗口。  
       2）Qt::WindowStaysOnTopHint：总是最上面的窗口。  
       3）Qt::CustomizeWindowHint：自定义窗口标题栏，以下标志必须与这个标志一起使用才有效，否则窗口将有默认的标题栏。  
       4）Qt::WindowTitleHint：显示窗口标题栏。  
       5）Qt::WindowSystemMenuHint：显示系统菜单。  
       6）Qt::WindowMinimizeButtonHint：显示最小化按钮。  
       7）Qt::WindowMaximizeButtonHint：显示最大化按钮。  
       8）Qt::WindowMinMaxbuttonHint：显示最小化按钮和最大化按钮。  
       9）Qt::WindowCloseButtonHint：显示关闭按钮。



#### 内置部件-按钮



#### 内置部件-行编辑与文本编辑框

textChanged()信号与textEdited()信号的区别：与textEdited()信号不同，当在程序中，通过调用函数改变
文本中内容时，例如，调用setText()函数，textChanged()信号依然会被发射出来，
而textEdited()信号则不会被发射出来。

