#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"stdbool.h"//bool类型
#include"graphics.h"//easyx图形库
//空地 0	墙 1	目的地 2	箱子 3	玩家 4	箱子+目的地 5		玩家+目的地 6
#define SPACE	0
#define WALL	1
#define DEST	2
#define BOX		3
#define PLAYER	4
#define ROW 10  //定义行
#define COL 10  //定义列
int i, k;
//当前所在关卡
int level = 0;
//准备地图数据，用二维数组来存储(一个地图)
//int map[10][10] =
//{
//	{0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,1,1,1,0,0,0,0},
//	{0,0,0,1,2,1,0,0,0,0},
//	{0,0,0,1,3,1,1,1,1,0},
//	{0,1,1,1,0,3,0,2,1,0},
//	{0,1,2,3,4,1,1,1,1,0},
//	{0,1,1,1,3,1,0,0,0,0},
//	{0,0,0,1,2,1,0,0,0,0},
//	{0,0,0,1,1,1,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0}
//};

//多个地图
int map[3][ROW][COL] =
{
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,0,0,0,0},
		{0,0,0,1,2,1,0,0,0,0},
		{0,0,0,1,3,1,1,1,1,0},
		{0,1,1,1,0,3,0,2,1,0},
		{0,1,2,3,4,1,1,1,1,0},
		{0,1,1,1,3,1,0,0,0,0},
		{0,0,0,1,2,1,0,0,0,0},
		{0,0,0,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	},
		{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,1,1,0,0},
		{0,1,0,2,1,1,2,0,1,0},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,3,0,3,0,0,0,1},
		{1,0,0,0,4,0,0,0,0,1},
		{0,1,0,3,0,3,0,0,1,0},
		{0,0,1,2,0,0,2,1,0,0},
		{0,0,0,1,0,0,1,0,0,0},
		{0,0,0,0,1,1,0,0,0,0}
	},
		{
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,1,2,0,0,0,0,2,1,0},
		{0,1,0,0,0,0,0,0,1,0},
		{0,1,0,3,0,3,0,0,1,0},
		{0,1,0,0,4,0,0,0,1,0},
		{0,1,0,3,0,3,0,0,1,0},
		{0,1,2,0,0,0,0,2,1,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0}
	},
};
//定义图片数组 int IMAGE
IMAGE img_all[6];

void loadImg()
{
	//IMAGE img_all[6];//保存图片
	for (i = 0; i < 6; i++)
	{
		//wchar是宽字符类型
		wchar_t file[20] = {};//定义字符数组
		wsprintf(file,L"./%d.jpg", i);//sprintf()函数能够将printf()函数得到的 string 保存下来.#define _CRT_SECURE_NO_WARNINGS
		//加载图片
		loadimage(img_all+i,file, 64, 64);
		putimage(i * 64, 0, img_all+i);//输出图片
	}
	
}

void show()
{
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 10; k++)
		{
			int x = k * 64;
			int y = i * 64;
			switch (map[level][i][k])
			{
			case SPACE:
				//printf("  ");//输出带空格
				putimage(x, y, img_all);
				break;
			case WALL:
				//printf("▓ ");//输出带墙
				putimage(x, y, img_all + 1);
				break;
			case DEST:
				//printf("□");
				putimage(x, y, img_all + 2);
				break;
			case BOX:
				//printf("■");
				putimage(x, y, img_all + 3);
				break;
			case PLAYER:
				//printf("♂");
				putimage(x, y, img_all + 4);
				break;
			case BOX+DEST:
				//printf("◇");
				putimage(x, y, img_all + 5);
				break;
			case PLAYER+DEST:
				//printf("♀");
				putimage(x, y, img_all);
				break;
			default:
				printf("%d ", map[level][i][k]);
				break;

			}
			//if (map[level][i][k] == 0)
			//{
			//	printf("  ");//把数字0替换空格
			//}
			//else
			//{
			//	printf("%d ", map[level][i][k]);
			//}
		}
		//printf("\n");
	}
}

void pushBox()
{
	//地图里有哪些数据有可能是玩家？ PLAYER  PLAYER+DEST
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[level][i][k] == PLAYER)
			{
				goto end;//跳出多重循环
				break;
			}
		}
	}
end:;

	//获取键盘按键 _getch();一触即发，不需要按回车	getchar();输入之后需要按回车
	char key = _getch();
	//printf("%d_%c\n", key, key);
	switch (key)
	{
	case 'w':
	case 'W':
	case 72://向上移动
		//什么情况下玩家才能移动，推箱子？1.玩家前面是空地，玩家的前面的箱子（箱子的前面是空地）
		if (map[level][i - 1][k] == SPACE || map[level][i - 1][k] == DEST)
		{
			map[level][i - 1][k] += PLAYER;//复制过去
			map[level][i][k] -= PLAYER;//删除原有
		}
		else if (map[level][i - 1][k] == BOX)//玩家的前面是箱子
		{
			if (map[level][i - 2][k] == SPACE || map[level][i-2][k] == DEST)
			{
				map[level][i - 2][k] += BOX;
				//map[level][i - 1][k] -= BOX;
				map[level][i - 1][k] += (PLAYER - BOX);
				map[level][i][k] -= PLAYER;
			}
		}
		break;
	case 's':
	case 'S':
	case 80://向下移动
		if (map[level][i + 1][k] == SPACE || map[level][i + 1][k] == DEST)
		{
			map[level][i + 1][k] += PLAYER;//复制过去
			map[level][i][k] -= PLAYER;//删除原有
		}
		else if (map[level][i + 1][k] == BOX)//玩家的前面是箱子
		{
			if (map[level][i + 2][k] == SPACE || map[level][i + 2][k] == DEST)
			{
				map[level][i + 2][k] += BOX;
				//map[level][i+1][k] -= BOX;
				map[level][i + 1][k] += (PLAYER - BOX);
				map[level][i][k] -= PLAYER;
			}
		}
		break;
	case 'a':
	case 'A':
	case 75://向左移动
		if (map[level][i ][k-1] == SPACE || map[level][i ][k-1] == DEST)
		{
			map[level][i ][k-1] += PLAYER;//复制过去
			map[level][i][k] -= PLAYER;//删除原有
		}
		else if (map[level][i ][k-1] == BOX)//玩家的前面是箱子
		{
			if (map[level][i ][k-2] == SPACE || map[level][i ][k-2] == DEST)
			{
				map[level][i ][k-2] += BOX;
				//map[level][i+1][k] -= BOX;
				map[level][i ][k-1] += (PLAYER - BOX);
				map[level][i][k] -= PLAYER;
			}
		}
		break;
	case 'd':
	case 'D':
	case 77://向右移动
		if (map[level][i ][k+1] == SPACE || map[level][i ][k+1] == DEST)
		{
			map[level][i ][k+1] += PLAYER;//复制过去
			map[level][i][k] -= PLAYER;//删除原有
		}
		else if (map[level][i ][k+1] == BOX)//玩家的前面是箱子
		{
			if (map[level][i ][k+2] == SPACE || map[level][i ][k+2] == DEST)
			{
				map[level][i ][k+2] += BOX;
				//map[level][i ][k+1] -= BOX;
				map[level][i ][k+1] += (PLAYER - BOX);
				map[level][i][k] -= PLAYER;
			}
		}
		break;

	}
}

//什么情况下才过关	没有箱子
bool Judge()
{
	for (i = 0; i < ROW; i++)
	{
		for (k = 0; k < COL; k++)
		{
			if (map[level][i][k] == BOX)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	//设置黑窗口的大小
	//system("mode con cols=30 lines=20");
	//创建图形界面窗口	宽，高，SHOWCONSOLE表示同时显示控制台
	initgraph(ROW*64,COL*64);
	loadImg();
	while (1)
	{
		//system("cls");//清屏
		show();
		if (Judge())
		{
			level++;//最大三关
			if (level > 2)
			{
				outtextxy(250,250,L"过关了");
				_getch();
			}
		}
		pushBox();
	}
	
	getchar();
	return 0;
}