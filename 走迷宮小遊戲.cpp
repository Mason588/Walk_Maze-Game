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
//�u�ƹ��з|�{				
void Hide()
{
	HANDLE         hOut;
	CONSOLE_CURSOR_INFO curInfo;
	
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	curInfo.dwSize=1;
	curInfo.bVisible=0;
	SetConsoleCursorInfo(hOut, &curInfo); 
}				
//�]�m�}�l�T��
void Welcome()
{
	printf("\n\n       �� �g �c �p �C ��");
	printf("\n\n       �Ы����N��}�l");
	getch();
	//�M���e�� 
	system("cls");
	
}				
				
//�u�Ƶe���|�{�����D
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
	//�s�x�ϥΪ̿�J 
	char ch;
	x=1;y=1;
	for(int i=0;i<=7;i++)
	puts(a[i]);
	while(1)
	{
		//�i���ϥΪ̿�J���r�� 
		ch = getch();
		if(ch=='s')
		{
			//�p�G�U�@��O�šA��}�C�]���� 
			if(a[x+1][y]==' ')
			{
				a[x][y] = ' ';
				x++;
				//�Ⲿ�ʪ�����]�����a 
				a[x][y]='O';
			} 
		}
		
		else if(ch=='a')
		{
			//�p�G�U�@��O�šA��}�C�]���� 
			if(a[x][y-1]==' ')
			{
				a[x][y] = ' ';
				y--;
				//�Ⲿ�ʪ�����]�����a 
				a[x][y]= 'O';
			} 
		}
		
		else if(ch=='d')
		{
			//�p�G�U�@��O�šA��}�C�]���� 
			if(a[x][y+1]==' ')
			{
				a[x][y] = ' ';
				y++;
				//�Ⲿ�ʪ�����]�����a 
				a[x][y]= 'O';
			} 
		}
		
		else if(ch=='w')
		{
			//�p�G�U�@��O�šA��}�C�]���� 
			if(a[x-1][y]==' ')
			{
				a[x][y] = ' ';
				x--;
				//�Ⲿ�ʪ�����]�����a 
				a[x][y]= 'O';
			} 
		}
		//�M���e�� 
		Set();
		for(int i=0;i<=7 ;i++)
		puts(a[i]);
		//����I�y�Э��|�NĹ�F
		if(x==5 && y==14) 
		break;
	}
	printf("�AĹ�F! ");
	Sleep(10000);
	return 0;
			
}

