 #include<stdio.h>                                          fuck                
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

int x=5,y=3,t=3,k=5;                                          //����ȫ�ֱ���
char area[20][200];

void gotoxy(int x,int y)                                      //�������꺯��                         
{
COORD pos;
pos.X=x;
pos.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


DWORD WINAPI ThreadProc1( LPVOID lpParam )                     //�����߳�
{
	    
	    void gotoxy(int x,int y);
		int *px,*py,i,j,z=0; 
		px=&x; py=&y; 
		
		while(1)                          //��ѭ������ʹ��ͼ
	{
		*py=*py+1;  *px=*px+1;              //�ı䡰�񡱵�����λ��               
	    
	    system("cls");   
		
        t=3; //����tֵ���ı�

		gotoxy(k,t);//�ص���ǰλ��

        for(i=0;i<20;i++)//�����������ͼ
		 {
			 for(j=0+z;j<39+z;j++)
				 printf("%c",area[i][j]);
			  t++;  gotoxy(k,t); //�����һ�к󣬻������ ����ֱ����'\n'����'\n'�᷵�ص���0�����		 
		}

		     z++; //����ʹ��ͼ�ƶ�
			 
		gotoxy(7,*py);  putchar('B');//���������������

		 if(area[*py-3][*px-6]=='*')//����*�����Ϸ
		{
			 x=10; y=26;
			gotoxy(x,y);
			printf("�ⶼ�����ˣ�ɵ��"); break;
		}

		if(x>162)//�ж�ʤ������
		{
			x=10; y=26;
			gotoxy(x,y);
			printf("������ҵĺú���"); break;
		} 
		
		Sleep(300); //300��������������ͼ����     
	}   
return 0; 		
}

int main()
{
	void move(int *px,int *py);   //���������Ͷ�����ֱ���
	void inter(char c[20][200]);
	 int i,j,*px,*py;	
	 char c;
	 gotoxy(x,y);
	 px=&x;  py=&y;

	 for(i=0;i<20;i++)//���Ȱѵ�ͼȫ������Ϊ�ո�
	   for(j=0;j<200;j++)
		   area[i][j]=' ';

	     inter(area);
		 
		 
		 for(i=0;i<20;i++)//�����ʼ��ͼ
		 {
			 for(j=0;j<39;j++)
	          printf("%c",area[i][j]);
			 gotoxy(k,++t);
		 }

		   x=7;   y=8;//�����ĳ�ʼλ��
		 gotoxy(x,y);
	   putchar('B');
	   gotoxy(x,y);

	   CreateThread( NULL, 0, ThreadProc1, NULL, 0, NULL);                      //�����߳�

	 while(1)
	{
        c=getch();   //�����ַ�
		 
		if(c==32)                                    //�ж�������ǿո�ʱ������������                                           
		 {
			 gotoxy(7,*py);                          //��ԭλ������ո񣬸��ǵ�ԭ�����ַ�                  
			 putchar(' ');
			 gotoxy(7,*py);

			 *py=*py-1;                             //����λ�����B
			 gotoxy(7,*py);
			 putchar('B');
			 gotoxy(7,*py);

		} 
		

		 if(area[*py-3][*px-6]=='*')               //��������*���˳�ѭ��
		{
			 x=10; y=26;
			gotoxy(x,y);
			printf("�ⶼ�����ˣ�ɵ��"); break;
		}
		
		 if(x>162)                               //ʤ������������������ͼ
		{
			x=10; y=26;
			gotoxy(x,y);
			printf("������ҵĺú���"); break;
		}  
		
	 } 
	 
	 getch();     

return 0;
}


void inter(char c[20][200])                              //���ɵ�ͼ
{
	int i,j,k;
	for(i=0;i<160;i++)

	{
		c[0][i]='*';
		c[19][i]='*';
	}
	
	  for(i=0;i<4;i++)
		 for(k=0;k<=11;k++)
		   for(j=9;j<=10;j++)
				c[k][j+i*40]='*';
			
		
		for(i=0;i<4;i++)
	      for(k=15;k<=18;k++)
	         for(j=13;j<=14;j++)
				c[k][j+i*40]='*';
	
		for(i=0;i<4;i++)
		 for(k=0;k<=15;k++)
			for(j=18;j<=24;j++)
				c[k][j+i*40]='*';
			
		for(i=0;i<4;i++)
		  for(k=13;k<=18;k++)
		    for(j=32;j<=33;j++)
				c[k][j+i*40]='*';
			


		for(i=0;i<4;i++)
		  for(k=9;k<=18;k++)
			for(j=38;j<=39;j++)
				c[k][j+i*40]='*';

		for(i=0;i<4;i++)
		  for(k=0;k<=6;k++)
			for(j=38;j<=39;j++)
				c[k][j+i*40]='*';


         
}

