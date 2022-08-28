#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<iostream>
#include<math.h>

void drawline(unsigned short ax,unsigned short ay,unsigned short bx,unsigned short by,bool times)//最后为判断是否在画箭头
{
	unsigned short x, y;
	//	unsigned short startx,starty,endx,endy;
	unsigned short to = 0;
	if (ay < by)
	{
		y = by - ay;
		if (ax < bx)
		{
			x = bx - ax;
			to = 0;
		}
		else
		{
			x = ax - bx;
			to = 1;
		}
	}
	else
	{
		y = ay - by;
		if (ax > bx)
		{
			x = ax - bx;
			to = 2;
		}
		else
		{
			x = bx - ax;
			to = 3;
		}
	}
	if (y == 0)//横线
	{
		if (to == 2)
		{
			for (unsigned short i = ax; i >= bx; i--)
				putpixel(i, ay, RGB(255, 255, 255));
		}
		else
			for (unsigned short i = ax; i <= bx; i++)
				putpixel(i, ay, RGB(255, 255, 255));
			
		if (times)//画箭头
		{
			unsigned short m =to==2?bx+3:bx - 3<0?0:bx-3;

			drawline(m, ay + 3, bx, by, false);
			drawline(m, ay - 3 < 0 ? 0 : ay - 3, bx, by, false);
		}
		return ;
	}
	if (x == 0)//竖线
	{
		if (to == 3)
			for (unsigned short i = ay; i >= by; i--)
				putpixel(ax, i, RGB(255, 255, 255));
		else
			for (unsigned short i = ay; i <= by; i++)
				putpixel(ax, i, RGB(255, 255, 255));
		if (times)
		{
			unsigned short n = 0;
			n = to == 3 ? by + 10 : (by - 10<0?0:by-10);
			drawline(ax + 3,n,  bx, by, false);
			drawline(ax - 3 < 0 ? 0 : ax - 3,n,  bx, by, false);
		}
		return ;
	}
	unsigned short tempy = 0;
	if (to == 0)//0,1,2,3为方向右上，左上，左下，右上
	{

		for (unsigned short i = ax; i <= bx; i++)
		{
			unsigned short c = i * y / x + ay - ax * y / x;
			putpixel(i, c, RGB(255, 255, 255));
			if (bx - i == 5)
				tempy = c;
		}
		if (times)//画箭头
		{
			drawline(bx - 7, tempy + (bx - 5) * x / y - (bx - 7) * x / y, bx, by, false);
			drawline(bx - 3, tempy + (bx - 5) * x / y - (bx - 3) * x / y, bx, by, false);
		}
	}
	else if (to == 1)
	{
		for (unsigned short i = ax; i >= bx; i--)
		{
			putpixel(i, ay + ax * y / x - i * y / x, RGB(255, 255, 255));
			if (i - bx == 5)
				tempy = ay + ax * y / x - i * y / x;
		}
		if (times)
		{
			drawline(bx + 7, (bx + 7) * x / y + tempy - (bx + 5) * x / y, bx, by, false);
			drawline(bx + 3, (bx + 3) * x / y + tempy - (bx + 5) * x / y, bx, by, false);
		}
	}
	else if (to == 2)
	{
		for (unsigned short i = ax; i >= bx; i--)
		{
			putpixel(i, i * y / x + ay - ax * y / x, RGB(255, 255, 255));
			if (i - bx == 5)
				tempy = i * y / x + ay - ax * y / x;
		}
		if (times)
		{
			drawline(bx + 7, tempy - (bx + 7) * x / y + (bx + 5) * x / y, bx, by, false);
			drawline(bx + 3, tempy - (bx + 3) * x / y + (bx + 5) * x / y, bx, by, false);
			std::cout << tempy + (bx + 7) * x / y - (bx + 5) * x / y << tempy + (bx + 3) * x / y - (bx + 5) * x / y << std::endl;
		}
	}
	else
	{
		for (unsigned short i = ax; i <= bx; i++)
		{
			putpixel(i, ay + ax * y / x - i * y / x, RGB(255, 255, 255));
			if (bx-i == 5)
				tempy = ay + ax * y / x - i * y / x;
		}
		if (times)
		{
			drawline(bx - 7, (bx - 7) * x / y + tempy - (bx - 5) * x / y, bx, by, false);
			drawline(bx - 3, (bx - 3) * x / y + tempy - (bx - 5) * x / y, bx, by, false);
		}
	}
}

int main()
{

	unsigned short ax, ay, bx,by;
	ax = 50;
	ay = 50;
	bx = 200;
	by = 200;
	initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
//	std::cin >> ax >> ay >> bx >> by;

	drawline(ax, ay, bx, by,true);
	std::cout<<_getch();				// 按任意键继续

//	closegraph();			// 关闭绘图窗口

	return 0;
}