#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#define KANAN 0
#define KIRI 1
#define ATAS 2
#define BAWAH 3


struct letak{
	int x1;
	int x2;
	int y1;
	int y2;
	
	int x[2];
	int y[2];
};

struct semua{
	letak posisi;
	int key;	
}; 

void map();		   //1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0
int map1[30][30] ={	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},//1
                    {3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},//2
				  	{3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},//3
					{3,2,2,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,2,2,3},//4
					{3,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,3},//5
					{3,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,3},//6
					{3,2,2,2,2,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,3},//7
					{3,2,2,2,2,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,3},//8
					{3,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//9
					{3,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//10
					{3,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//11
					{3,0,0,0,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//12
					{3,0,0,0,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,0,0,2,2,2,2,2,2,3},//13
					{3,0,0,0,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,0,0,2,2,2,2,2,2,3},//14
					{3,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//15
					{3,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//16
					{3,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,0,0,3},//17
					{3,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,0,0,3},//18
				  	{3,2,2,2,2,0,0,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//19
					{3,2,2,2,2,0,0,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//20
					{3,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},//21
					{3,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},//22
					{3,2,2,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,0,2,2,2,2,2,2,2,2,3},//23
					{3,2,2,2,2,0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,3},//24
					{3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,3},//25
					{3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,0,0,3},//26
					{3,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,3},//27
					{3,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,3},//28
					{3,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,3},//29
					{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},//30

																						};
void RODA(int key, int L, int T, int B, int R, int warna1, int warna2);
//void RODA(int key, int L, int T, int B, int R);
void TANK(int key, int L, int T, int B, int R, int Rad);

void RODA(int key, int L, int T, int B, int R, int warna1, int warna2)
//void RODA(int key, int L, int T, int B, int R)
{
	if(key==72 or key==80)		//Vertical
	{
		setfillstyle(SOLID_FILL,warna1);
		bar(L, T, L+10, T+5);
		setfillstyle(SOLID_FILL,warna2);
		bar(L, T+5, L+10, T+10);
		setfillstyle(SOLID_FILL,warna1);
		bar(L, T+10, L+10, T+15);
		setfillstyle(SOLID_FILL,warna2);
		bar(L, T+15, L+10, T+20);
		setfillstyle(SOLID_FILL,warna1);
		bar(L, T+20, L+10, T+25);
		setfillstyle(SOLID_FILL,warna2);
		bar(L, T+25, L+10, T+30);
		setfillstyle(SOLID_FILL,warna1);
		bar(L, T+30, L+10, T+35);
		setfillstyle(SOLID_FILL,warna2);
		bar(L, T+35, L+10, T+40);
		
		setfillstyle(SOLID_FILL,warna1);
		bar(L+30, T, R+1, T+5);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+30, T+5, R+1, T+10);
		setfillstyle(SOLID_FILL,warna1);
		bar(L+30, T+10, R+1, T+15);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+30, T+15, R+1, T+20);
		setfillstyle(SOLID_FILL,warna1);
		bar(L+30, T+20, R+1, T+25);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+30, T+25, R+1, T+30);
		setfillstyle(SOLID_FILL,warna1);
		bar(L+30, T+30, R+1, T+35);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+30, T+35, R+1, T+40);
		
		}
	if(key==75 or key==77)			//Horizontal
	{
		setfillstyle(SOLID_FILL,warna1);
		bar(L, T, L+5, T+10);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+5, T, L+10, T+10);
		setfillstyle(SOLID_FILL,warna1);
		bar(L+10, T, L+15, T+10);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+15, T, L+20, T+10);
		setfillstyle(SOLID_FILL,warna1);
		bar(L+20, T, L+25, T+10);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+25, T, L+30, T+10);
		setfillstyle(SOLID_FILL,warna1);
		bar(L+30, T, L+35, T+10);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+35, T, L+40, T+10);
		
		setfillstyle(SOLID_FILL,warna1);
		bar(L, T+30, L+5, B+1);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+5, T+30, L+10, B+1);
		setfillstyle(SOLID_FILL,warna1);
		bar(L+10, T+30, L+15, B+1);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+15, T+30, L+20, B+1);
		setfillstyle(SOLID_FILL,warna1);
		bar(L+20, T+30, L+25, B+1);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+25, T+30, L+30, B+1);
		setfillstyle(SOLID_FILL,warna1);
		bar(L+30, T+30, L+35, B+1);
		setfillstyle(SOLID_FILL,warna2);
		bar(L+35, T+30, L+40, B+1);

	}
}
void TANK(int key, int L, int T, int B, int R, int Rad, int warna1, int warna2)
//void TANK(int key, bebas juga, int Rad)     
{
	setfillstyle(1,GREEN);
	bar(L+9, T+9, R-9, B-9);

//	rectangle(L, T, R, B); 
	circle (L+20,T+20,6);
		setfillstyle(SOLID_FILL, RED);
		floodfill(L+20, T+20, WHITE);
	if(key==72 or key==80)			//Vertical]
	{
		RODA(key, L, T, B, R, warna1, warna2);
		//RODA(key, L, T, B, R);
		setfillstyle(SOLID_FILL, RED);

		if(key==72)
		{
			setfillstyle(1,WHITE);
			bar(L+18, T+5, L+22, T+16);


		}
		if(key==80)
		{
			setfillstyle(1,WHITE);
			bar(L+18, T+24, L+22, T+35);


		}
	}
	if(key==75 or key==77)			//Horizontal
	{
		RODA(key, L, T, B, R, warna1, warna2);
	//	RODA(key, L, T, B, R);
		setfillstyle(SOLID_FILL, RED);
		if(key==75)
		{
			setfillstyle(1,WHITE);
			bar(L+5, T+18, L+16, T+22);
			//(juga.posisi.x1+5,)
	
		}
		if(key==77)
		{
			setfillstyle(1,WHITE);
			bar(L+24, T+18, L+35, T+22);
	
		}
	}
}


int main()
{
	int gd = DETECT, gm, warna, key, x=5 , y=4 , maxh = 768, maxw = 1200;
	int i = 0, L = 80, T = 80, R = 119, B = 119;
	int X = 30, Y = 30, Rad = 5;
	int warna1 = 4;
	int warna2 = 15;
	int temp;
	int page=0;
			int kolom1 =5, baris1 = 4;
			int kolom2 =5, baris2 = 5;
			int cepat;
			int ulang;
		int paruhx=100, paruhy=100;
//	bebas juga, juga2;
//	juga.posisi.x1= 80;
	initwindow(maxw, maxh);
	map();
	TANK(key, L, T, B, R, Rad, warna1, warna2);
	while(true){
	if(kbhit())
	{
		key = getch();
		switch(key)
		{
			case 77: //kanan
			if(map1[y][x+1]==2 && map1[y+1][x+1]==2)
                {
               x=x+1;
               i=20;
               L+=i;
               R+=i;
                                map();
				TANK(key, L, T, B, R, Rad, warna1, warna2);
               
        	temp = warna2;
            warna2 = warna1;
            warna1 = temp;
            
                }
			break;
		case 75: //kiri
			if(map1[y][x-2]==2 && map1[y+1][x-2]==2)
               {x=x-1;
                i=20;
                L-=i;
                R-=i;
                                 map();
				TANK(key, L, T, B, R, Rad, warna1, warna2);
			temp = warna2;
            warna2 = warna1;
            warna1 = temp;
               }
			break;
		case 80: //bawah
			if(map1[y+2][x-1]==2 && map1[y+2][x]==2)
                {y=y+1;
                 i=20;
                 T+=i;
                 B+=i;
                 map();
				TANK(key, L, T, B, R, Rad, warna1, warna2);
			temp = warna2;
            warna2 = warna1;
            warna1 = temp;
				
				
                }
			break;
		case 72: //atas
			if(map1[y-1][x-1]==2 && map1[y-1][x]==2 )
            {
             y=y-1;
             i=20;
             T-=i;
             B-=i;
                              map();
				TANK(key, L, T, B, R, Rad, warna1, warna2);
			temp = warna2;
            warna2 = warna1;
            warna1 = temp;
            }
			break;
		case 13:	
	//	circle (paruhx+cepat,paruhy,9);		
			if (key==13)
			{ulang =0;
			kolom1=x;
			for (cepat=0; (map1[baris1][kolom1]==2 && map1[baris2][kolom2]==2); cepat +=5)
			{
			//	setactivepage(page);
              //  setvisualpage(1-page);
               cleardevice();
                
               circle (L+20,T+20,2);
                if (ulang==4)
                {
                	kolom1+=1;
                	kolom2+=1;
                	ulang=0;
				}
				ulang+=1;
				map();
				TANK(key, L, T, B, R, Rad, warna1, warna2);
				
				page=1-page;
			}
	}
	break;
}
}
}
}


void map()
{
	int x,y;
	map1[30][30];
	for(x=0;x<=29;x++)
	{
		for(y=0;y<=29;y++)
	
		{
			if(map1[y][x]==0)

			{
				setfillstyle(9, RED);
				bar(0+(x*20),0+(y*20),40+(x*20),40+(y*20));
				//rectangle(35+(x*40),35+(y*40),70+(x*40),70+(y*40));//t2
			}else if(map1[y][x]==1)
				{
						setfillstyle(1, RED);
				bar(40+(x*20),40+(y*20),75+(x*20),75+(y*20));
				rectangle(35,35,70,70);
				}else if(map1[y][x]==2) 
				{
					setfillstyle(9,BROWN);

				//	readimagefile("tembok.bmp",0+(x*20),0+(y*20),40+(x*20),40+(y*20));
				bar(0+(x*20),0+(y*20),40+(x*20),40+(y*20));
				}else if(map1[y][x]==3)
				{
					setfillstyle(9,DARKGRAY);
					bar(0+(x*20),0+(y*20),40+(x*20),40+(y*20));
				}
		}
	}

}

