#include "mycalculator.h"
#include "ui_mycalculator.h"

void Change(const char *S,char OPS[],int &len);
void EXchange(char B[], int len, double &result,bool &flag);


//构造函数
MyCalculator::MyCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyCalculator)
{
    // 通过样式表给窗口设置背景图
    // "MyCalculator" 为类名
    // "../test/test.jpg": 为图片路径，相对于可执行程序的相对路径
    this->setStyleSheet("MyCalculator{background-image: url(../MyCalculator/background1.png);} ");

    ui->setupUi(this);
    connect(ui->Button_0,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号0与槽函数
    connect(ui->Button_1,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号1与槽函数
    connect(ui->Button_2,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号2与槽函数
    connect(ui->Button_3,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号3与槽函数
    connect(ui->Button_4,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号4与槽函数
    connect(ui->Button_5,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号5与槽函数
    connect(ui->Button_6,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号6与槽函数
    connect(ui->Button_7,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号7与槽函数
    connect(ui->Button_8,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号8与槽函数
    connect(ui->Button_9,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号9与槽函数
    connect(ui->Button_add,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号+与槽函数
    connect(ui->Button_sub,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号-与槽函数
    connect(ui->Button_mul,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号*与槽函数
    connect(ui->Button_div,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号/与槽函数
    connect(ui->Button_backward,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号1/X与槽函数
    connect(ui->Button_C,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号C与槽函数
    connect(ui->Button_CE,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号CE与槽函数
    connect(ui->Button_XY,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号X^Y与槽函数
    connect(ui->Button_equal,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号=与槽函数
    connect(ui->Button_right,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号)与槽函数
    connect(ui->Button_remain,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号%与槽函数
    connect(ui->Button_time,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号Time与槽函数
    connect(ui->Button_left,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号(与槽函数
    connect(ui->Button_point,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号.与槽函数

    QPalette palette;
    palette.setColor(QPalette::Text,Qt::red);//设置字体颜色
    ui->lineEdit->setFont(QFont("Timers",20,QFont::Bold));//设置字体大小
    ui->lineEdit->setPalette(palette);

    input = "0";
}

//析构函数
MyCalculator::~MyCalculator()
{
    delete ui;
}

// 重写paintEvent()
void MyCalculator::paintEvent(QPaintEvent *)
{
    QStyleOption opt; // 需要头文件#include <QStyleOption>
    opt.init(this);
    QPainter p(this); // 需要头文件#include <QPainter>
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MyCalculator::buttonClicked()//按钮触动槽函数
{
    lineEdit = ui->lineEdit;

    input = lineEdit->text();//输入框
    QPushButton *tb = qobject_cast<QPushButton *>(sender());//把信号的发送者转换成pushbutton类型
    QString text = tb->text();//text:获取或设置文本框的文本内容。


     if(text == QString("CE"))
    {
        text = input.left(input.length()-1); //减去一字符
        lineEdit->setText(text);
    }
     else if(text == QString("C"))//清空所有
    {
        input="";
        lineEdit->setText(input);
    }
     else if(text == QString("±"))
    {
         if(input=="")
            text='-';
         else
         {
             QString::iterator p=text.end();
             p--;
             if('-'==*p)
                 text=text.left(text.length()-1);
             else
                 text=text+'-';
         }
         lineEdit->setText(text);
      }
      else if(text == QString("1/X"))
     {
         if(input != "")
             lineEdit->setText("1/"+input);
         else
         {
             lineEdit->setText("divisor can't be 0");
         }
     }
     else if(text == QString("X^Y"))
    {
        if(input != "")
            lineEdit->setText(input+"^");
    }
     else if(text == QString("Time"))
     {
         text=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"); //格式化输出当前时间
         lineEdit->setText(text);
     }
     else if(text == QString("="))
    {
            std::string str=input.toStdString();//QString转化为String
            const char *S=str.c_str();//整个输入框的字符串
            char OPS[50];//中缀表达式
            int len;//去掉括号之后中缀表达式的长度
            double result;//计算结果
            QString change;
            bool flag1 = true;//判断出书是否为0的标志
            Change(S,OPS,len);
            EXchange(OPS,len,result,flag1);
            if(flag1 == false)
            {
                lineEdit->clear();
                lineEdit->setText("divisor can't be 0");
            }
            else
            {
                change=QString::number(result,10,6);//将计算结果转换为字符串
                lineEdit->setText(change);
            }
    }
      else//+ - * / % 0-9
     {
          lineEdit->setText(input+=text);
     }
   }


void Change(const char *S,char OPS[],int &len)//将中缀表达式转变为后缀表达式
{
    QStack<char> OPE;//符号栈
    unsigned int i,j=0;
    unsigned int tmp = strlen(S);
    for (i = 0; i < tmp; i++)
    {
        switch (S[i])
        {
        case'+':
            if(OPE.isEmpty())//栈为空
             OPE.push(S[i]);
            else if (OPE.top() == '*' || OPE.top() == '/' || OPE.top() == '%' || OPE.top()=='^')
            {
                OPS[j++] = OPE.pop();//弹出比'+'运算符优先级高和相等的运算符，依次加入后缀表达式
                i--;
            }
            else
                OPE.push(S[i]);
            break;
        case'-':
            if(i!=0 && '('!=S[i-1])//正数
            {
             if(OPE.isEmpty())//栈为空
                  OPE.push(S[i]);
              else if (OPE.top() == '*' || OPE.top() == '/'|| OPE.top() == '%' || OPE.top()=='^')//弹出比'-'运算符优先级高和相等的运算符，依次加入后缀表达式
             {
               OPS[j++] = OPE.pop();
               i--;
             }
              else
                OPE.push(S[i]);
            }
            else//负数
            {
                while ((S[i] >= '0'&&S[i] <= '9' ) || S[i] == '.' || ('-'==S[i]&&(S[i-1]<'0'||S[i-1]>'9')))
                {
                    OPS[j++] = S[i];
                    if('-'==S[i])
                      OPS[j++]='@';
                    i++;
                }
                i--;
                OPS[j++] = '#';  //数字中的间隔符
            }
            break;
        case '^':
                OPE.push(S[i]);
            break;
        case'*':
            if(OPE.isEmpty())//栈为空
               OPE.push(S[i]);
            else if (OPE.top() == '^')
            {
                OPS[j++] = OPE.pop();//弹出比'/'运算符优先级高和相等的运算符，依次加入后缀表达式
                i--;
            }
            else
                OPE.push(S[i]);
            break;
        case'/':
            if(OPE.isEmpty())//栈为空
               OPE.push(S[i]);
            else if (OPE.top() == '^')
            {
                OPS[j++] = OPE.pop();//弹出比'/'运算符优先级高和相等的运算符，依次加入后缀表达式
                i--;
            }
            else
                OPE.push(S[i]);
            break;
        case '%':
            if(OPE.isEmpty())//栈为空
               OPE.push(S[i]);
            else if (OPE.top() == '^'|| OPE.top()=='*' || OPE.top()=='/')
            {
                OPS[j++] = OPE.pop();//弹出比'%'运算符优先级高和相等的运算符，依次加入后缀表达式
                i--;
            }
            else
                OPE.push(S[i]);
            break;
        case'(':
            OPE.push(S[i]);
            break;
        case')':
            while (OPE.top() != '(')//依次把栈中的运算符加入后缀表达式并将其出栈
            {
                OPS[j++] = OPE.pop();
            }
            OPE.pop();//从栈中弹出'('
            break;
        default:
            while ((S[i] >= '0'&&S[i] <= '9') || S[i] == '.' || ('-'==S[i]&&S[i-1]<'0'&&S[i-1]>'9'))
            {

                OPS[j++] = S[i];

                i++;
            }
            i--;
            OPS[j++] = '#';  //数字中的间隔符
            break;
        }
    }
    while (!OPE.isEmpty())
    {
        OPS[j++] = OPE.pop();
    }
    len = j;
}

void EXchange(char B[], int len, double &result,bool &flag)//用后缀表达式计算结果
{
    int i;
    double a;
    double b;
    double c;
    QStack<double>SZ;
    for (i = 0; i < len; i++)
    {
        switch (B[i])
        {
           case'^':
          {
            a = SZ.pop();
            b = SZ.pop();
            c = pow(b,a);
            SZ.push(c);
          }
            break;
           case'+':
           {
            a = SZ.pop();
            b = SZ.pop();
            c = b + a;
            SZ.push(c);
            }
               break;
           case'-':
           {
            if('@'!=B[i+1])
            {
            a = SZ.pop();
            b = SZ.pop();
            c = b - a;
            SZ.push(c);
            }
            else
            {
                int jx = 0;
                double dx;
                char *stx = new char[10];
                while (B[i] != '#')
                {
                   if('@'!=B[i])
                    stx[jx++] = B[i];
                    i++;

                }
                dx = atof(stx);//把字符串转换成浮点数
                SZ.push(dx);
                delete stx;
            }
           }
               break;
           case'*':
           {
            a = SZ.pop();
            b = SZ.pop();
            c = b*a;
            SZ.push(c);
           }
               break;
           case'/':
           {
              a = SZ.pop();
              b = SZ.pop();
              if (a == 0)
              {
                  flag = false;
                  return;
              }
              c = b / a;
              SZ.push(c);
           }
               break;
           case'%':
          {
           a = SZ.pop();
           b = SZ.pop();
           if (a == 0)
           {
               flag = false;
               return;
           }
           c = (int)b % (int)a;
           SZ.push(c);
          }
            break;
           default:
               int j = 0;
               double d;
               char *st = new char[10];
               while (B[i] != '#')
               {
                   st[j++] = B[i];
                   i++;
               }
               d = atof(st);//把字符串转换成浮点数
               SZ.push(d);
               delete st;
               break;
        }
    }
    result=SZ.top();
}
