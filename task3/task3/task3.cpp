// task3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

struct point {
    double x, y, z;
};

struct face {
    int n;
    int p[4];
};
class off
{
private:
    int pointnum, facenum;
    point p[1000];
    face f[1000];
public:
    off() {};
};

void readFileData(ifstream& file,int& pointnum,int &facenum,point* p,face* f) {
    string strBuffer;
    int flag=0;
    while (file >> strBuffer) {
        flag++;
        if(flag==2)
            pointnum= atoi(strBuffer.c_str());
        if (flag == 3)
        {
            flag -= 3;
            facenum = atoi(strBuffer.c_str());
            file >> strBuffer;
            file >> strBuffer;
            while (flag<3*pointnum)
            {
                flag++;
                file >> strBuffer;
                if (0 < flag <= 3 * pointnum && flag%3==0)
                    p[(flag) / 3].x = atof(strBuffer.c_str());
                else if(0 < flag <= 3 * pointnum && flag % 3 == 1)
                    p[(flag) / 3].y = atof(strBuffer.c_str());
                else if (0 < flag <= 3 * pointnum && flag % 3 == 2)
                    p[(flag) / 3].z = atof(strBuffer.c_str());
            }
            int i = 0;
            while (file >> strBuffer)
            {
                f[i].n = atoi(strBuffer.c_str());
                for (int j = 0; j < f[i].n; j++)
                {
                    file >> strBuffer;
                    f[i].p[j] = atoi(strBuffer.c_str());
                }
                i++;
            }
        }

    }
}


int main()
{
    ifstream readFile;                             //2.get file instance
    readFile.open("m784.off", ios::in);        //3.open the file in mode xxx & judge the open result
    if (!readFile.is_open()) {
        cout << "open error" << endl;
        return 0;
    }
    int pointnum, facenum;
    point p[1000];
    face f[1000];
    readFileData(readFile,pointnum,facenum,p,f);
    cout << pointnum << " " << facenum << endl;
    for (int i = 0; i < pointnum; i++)
        cout << p[i].x << " " << p[i].y << " " << p[i].z << endl;
    for (int i = 0; i < facenum; i++)
    {
        cout << f[i].n << " ";
        for (int j = 0; j < f[i].n; j++)
            cout << f[i].p[j] << " ";
        cout << endl;
    }
    readFile.close();                              //5.close the file
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
