#include <cstdio>
#include <conio.h>
#include <windows.h>

char a[20][20]={"***************",
	            "*O* ******  ***",
	            "*    ** *** ***",
	            "****    *******",
	            "******  ***   *",
				"*******     *  ",
				};
//優化鼠標會閃				
void Hide()
{
	HANDLE         hOut;
	CONSOLE_CURSOR_INFO curInfo;
	
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	curInfo.dwSize=1;
	curInfo.bVisible=0;
	SetConsoleCursorInfo(hOut, &curInfo); 
}				
//設置開始訊息
void Welcome()
{
	printf("\n\n       走 迷 宮 小 遊 戲");
	printf("\n\n       請按任意鍵開始");
	getch();
	//清除畫面 
	system("cls");
	
}				
				
//優化畫面會閃的問題
void Set()
{
	HANDLE hOut;
	COORD pos = {0,0};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}				
				

int main()
{
	Hide();
	Welcome(); 
	int x,y;
	//存儲使用者輸入 
	char ch;
	x=1;y=1;
	for(int i=0;i<=7;i++)
	puts(a[i]);
	while(1)
	{
		//可抓到使用者輸入的字元 
		ch = getch();
		if(ch=='s')
		{
			//如果下一格是空，把陣列設為空 
			if(a[x+1][y]==' ')
			{
				a[x][y] = ' ';
				x++;
				//把移動的那格設為玩家 
				a[x][y]='O';
			} 
		}
		
		else if(ch=='a')
		{
			//如果下一格是空，把陣列設為空 
			if(a[x][y-1]==' ')
			{
				a[x][y] = ' ';
				y--;
				//把移動的那格設為玩家 
				a[x][y]= 'O';
			} 
		}
		
		else if(ch=='d')
		{
			//如果下一格是空，把陣列設為空 
			if(a[x][y+1]==' ')
			{
				a[x][y] = ' ';
				y++;
				//把移動的那格設為玩家 
				a[x][y]= 'O';
			} 
		}
		
		else if(ch=='w')
		{
			//如果下一格是空，把陣列設為空 
			if(a[x-1][y]==' ')
			{
				a[x][y] = ' ';
				x--;
				//把移動的那格設為玩家 
				a[x][y]= 'O';
			} 
		}
		//清除畫面 
		Set();
		for(int i=0;i<=7 ;i++)
		puts(a[i]);
		//跟終點座標重疊就贏了
		if(x==5 && y==14) 
		break;
	}
	printf("你贏了! ");
	Sleep(10000);
	return 0;
			
}

