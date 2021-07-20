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
    friend class readFile;
private:
    int pointnum, facenum;
    point p[100];
    face f[100];
public:
    off() {};
    off(std::string strpath);
    void getpoint(int n) {
        cout << p[n].x << p[n].y << p[n].z << endl;
    }
    void getface(int n) {
        for (int i = 0; i < f[n].n; i++)
            getpoint(f[n].p[i]);
    }
    void show()
    {
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
    }
};

off::off(std::string strpath) {
    ifstream readFile;                             //2.get file instance
    readFile.open(strpath, ios::in);        //3.open the file in mode xxx & judge the open result
    if (!readFile.is_open()) {
        cout << "open error" << endl;
    }
    string strBuffer;
    int flag = 0;
    while (readFile >> strBuffer) {
        flag++;
        if (flag == 2)
            pointnum = atoi(strBuffer.c_str());
        if (flag == 3)
        {
            facenum = atoi(strBuffer.c_str());
            readFile >> strBuffer;
            flag = 0;
            while (flag < 3 * pointnum)
            {
                readFile >> strBuffer;
                if (flag % 3 == 0)
                    p[(flag) / 3].x = atof(strBuffer.c_str());
                else if (flag % 3 == 1)
                    p[(flag) / 3].y = atof(strBuffer.c_str());
                else if (flag % 3 == 2)
                    p[(flag) / 3].z = atof(strBuffer.c_str());
                flag++;
            }
            int i = 0;
            while (readFile >> strBuffer)
            {
                f[i].n = atoi(strBuffer.c_str());
                for (int j = 0; j < f[i].n; j++)
                {
                    readFile >> strBuffer;
                    f[i].p[j] = atoi(strBuffer.c_str());
                }
                i++;
            }
        }

    }
    readFile.close();
};

/*void readFileData(ifstream& file) {
    string strBuffer;
    int flag=0;
    while (file >> strBuffer) {
        flag++;
        if(flag==2)
            pointnum= atoi(strBuffer.c_str());
        if (flag == 3)
        {
            facenum = atoi(strBuffer.c_str());
            file >> strBuffer;
            flag = 0;
            while (flag<3*pointnum)
            {
                file >> strBuffer;
                if ( flag%3==0)
                    p[(flag) / 3].x = atof(strBuffer.c_str());
                else if(flag % 3 == 1)
                    p[(flag) / 3].y = atof(strBuffer.c_str());
                else if (flag % 3 == 2)
                    p[(flag) / 3].z = atof(strBuffer.c_str());
                flag++;
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
}*/


int main()
{                           //5.close the file
    off of("m784.off");
    cout << "输出点8" << endl;
    of.getpoint(8);
    cout << "输出面8" << endl;
    of.getface(8);
    cout << "全输出" << endl;
    of.show();
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
