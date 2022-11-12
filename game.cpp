#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"stdbool.h"//bool����
#include"graphics.h"//easyxͼ�ο�
//�յ� 0	ǽ 1	Ŀ�ĵ� 2	���� 3	��� 4	����+Ŀ�ĵ� 5		���+Ŀ�ĵ� 6
#define SPACE	0
#define WALL	1
#define DEST	2
#define BOX		3
#define PLAYER	4
#define ROW 10  //������
#define COL 10  //������
int i, k;
//��ǰ���ڹؿ�
int level = 0;
//׼����ͼ���ݣ��ö�ά�������洢(һ����ͼ)
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

//�����ͼ
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
//����ͼƬ���� int IMAGE
IMAGE img_all[6];

void loadImg()
{
	//IMAGE img_all[6];//����ͼƬ
	for (i = 0; i < 6; i++)
	{
		//wchar�ǿ��ַ�����
		wchar_t file[20] = {};//�����ַ�����
		wsprintf(file,L"./%d.jpg", i);//sprintf()�����ܹ���printf()�����õ��� string ��������.#define _CRT_SECURE_NO_WARNINGS
		//����ͼƬ
		loadimage(img_all+i,file, 64, 64);
		putimage(i * 64, 0, img_all+i);//���ͼƬ
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
				//printf("  ");//������ո�
				putimage(x, y, img_all);
				break;
			case WALL:
				//printf("�� ");//�����ǽ
				putimage(x, y, img_all + 1);
				break;
			case DEST:
				//printf("��");
				putimage(x, y, img_all + 2);
				break;
			case BOX:
				//printf("��");
				putimage(x, y, img_all + 3);
				break;
			case PLAYER:
				//printf("��");
				putimage(x, y, img_all + 4);
				break;
			case BOX+DEST:
				//printf("��");
				putimage(x, y, img_all + 5);
				break;
			case PLAYER+DEST:
				//printf("��");
				putimage(x, y, img_all);
				break;
			default:
				printf("%d ", map[level][i][k]);
				break;

			}
			//if (map[level][i][k] == 0)
			//{
			//	printf("  ");//������0�滻�ո�
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
	//��ͼ������Щ�����п�������ң� PLAYER  PLAYER+DEST
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[level][i][k] == PLAYER)
			{
				goto end;//��������ѭ��
				break;
			}
		}
	}
end:;

	//��ȡ���̰��� _getch();һ������������Ҫ���س�	getchar();����֮����Ҫ���س�
	char key = _getch();
	//printf("%d_%c\n", key, key);
	switch (key)
	{
	case 'w':
	case 'W':
	case 72://�����ƶ�
		//ʲô�������Ҳ����ƶ��������ӣ�1.���ǰ���ǿյأ���ҵ�ǰ������ӣ����ӵ�ǰ���ǿյأ�
		if (map[level][i - 1][k] == SPACE || map[level][i - 1][k] == DEST)
		{
			map[level][i - 1][k] += PLAYER;//���ƹ�ȥ
			map[level][i][k] -= PLAYER;//ɾ��ԭ��
		}
		else if (map[level][i - 1][k] == BOX)//��ҵ�ǰ��������
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
	case 80://�����ƶ�
		if (map[level][i + 1][k] == SPACE || map[level][i + 1][k] == DEST)
		{
			map[level][i + 1][k] += PLAYER;//���ƹ�ȥ
			map[level][i][k] -= PLAYER;//ɾ��ԭ��
		}
		else if (map[level][i + 1][k] == BOX)//��ҵ�ǰ��������
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
	case 75://�����ƶ�
		if (map[level][i ][k-1] == SPACE || map[level][i ][k-1] == DEST)
		{
			map[level][i ][k-1] += PLAYER;//���ƹ�ȥ
			map[level][i][k] -= PLAYER;//ɾ��ԭ��
		}
		else if (map[level][i ][k-1] == BOX)//��ҵ�ǰ��������
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
	case 77://�����ƶ�
		if (map[level][i ][k+1] == SPACE || map[level][i ][k+1] == DEST)
		{
			map[level][i ][k+1] += PLAYER;//���ƹ�ȥ
			map[level][i][k] -= PLAYER;//ɾ��ԭ��
		}
		else if (map[level][i ][k+1] == BOX)//��ҵ�ǰ��������
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

//ʲô����²Ź���	û������
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
	//���úڴ��ڵĴ�С
	//system("mode con cols=30 lines=20");
	//����ͼ�ν��洰��	���ߣ�SHOWCONSOLE��ʾͬʱ��ʾ����̨
	initgraph(ROW*64,COL*64);
	loadImg();
	while (1)
	{
		//system("cls");//����
		show();
		if (Judge())
		{
			level++;//�������
			if (level > 2)
			{
				outtextxy(250,250,L"������");
				_getch();
			}
		}
		pushBox();
	}
	
	getchar();
	return 0;
}