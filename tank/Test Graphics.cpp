#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

struct kond{
	int posisi[4];
	int kondisi;
};

struct tank1{
	int key=77;
	int x1=20;
	int y1=20;
	int x2=59;
	int y2=59;
}tank;

struct array1{
	int x=2;
	int y=1;
}array;

struct swap1{
	int warna1=4;
	int warna2=15;
	int temp;
}swap;

struct tembak1{
	int X;
	int Y;
	int l;
	int t;
}tembak;
	
	int i;
	int page=0;
	int current;
	int IndScore;
	int score =0;
	char scored[6];
	int ss = 100;
	int sss = 200;

	void rumput();
	void air();
	void baja();
	void bata();
	void road();
	void modulSkor();
	void showskor();
	void prosess();

	
  				   //1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0
int map1[30][30] ={	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},//1
                    {3,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,3},//2
				  	{3,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,3},//3
					{3,1,1,3,3,3,3,2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,3,3,3,3,1,1,3},//4
					{3,1,1,3,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,3,1,1,3},//5
					{3,1,1,3,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,3,1,1,3},//6
					{3,2,2,2,2,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,3},//7
					{3,2,2,2,2,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,3},//8
					{3,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//9
					{3,1,1,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,1,1,3},//10
					{3,1,1,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,1,1,3},//11
					{3,1,1,5,5,5,5,0,0,5,5,1,1,0,0,1,1,5,5,0,0,5,0,0,5,5,5,1,1,3},//12
					{3,1,1,5,5,5,5,0,0,5,5,1,1,0,0,1,1,5,5,0,0,0,0,5,5,5,5,1,1,3},//13
					{3,1,1,5,5,5,5,0,0,5,5,1,1,0,0,1,1,5,5,0,0,0,0,5,5,5,5,1,1,3},//14
					{3,1,1,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,0,0,2,2,2,1,1,3},//15
					{3,1,1,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,0,0,2,2,1,1,3},//16
					{3,2,2,2,2,2,2,0,0,2,2,2,2,5,5,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//17
					{3,2,2,2,2,2,2,0,0,2,2,2,2,5,5,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//18
				  	{3,2,2,2,2,0,0,0,2,2,2,2,2,1,1,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//19
					{3,2,2,2,2,0,0,2,2,2,2,2,2,1,1,2,2,2,2,0,0,2,2,0,0,2,2,2,2,3},//20
					{3,2,2,3,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,3,2,2,3},//21
					{3,2,2,3,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,3,2,2,3},//22
					{3,2,2,3,3,3,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,3,3,3,3,2,2,3},//23
					{3,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,3},//24
					{3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},//25
					{3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},//26
					{3,5,5,5,1,1,2,2,2,2,2,2,0,0,0,0,0,0,2,2,2,2,2,2,1,1,5,5,5,3},//27
					{3,1,1,1,1,1,2,2,2,2,2,2,0,0,2,2,0,0,2,2,2,2,2,2,1,1,1,1,1,3},//28
					{3,1,1,1,1,1,2,2,2,2,2,2,0,0,2,2,0,0,2,2,2,2,2,2,1,1,1,1,1,3},//29
					{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},//30
																						};
void shoot(int current,tembak1 tembak,tank1 tank, swap1 swap);

void menu()
{
	int x=200 ,i , gdriver=DETECT,gmode, key;
	
	while (kbhit() != 49 || kbhit()!= 50)
	{
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy(225,75,"BeTa Ver. 0.4");
		outtextxy(265,100,"[1]PLAY");
		outtextxy(265,125,"[2]EXIT");
		if (kbhit())
	{
		key=getch();
		switch(key)
		{
			case 49:
				cleardevice();
				settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 				outtextxy(200,250,"LOADING,PLEASE WAIT");
  				for(i=0;i<300;++i)
 				{
  					delay(15);
  					line(x,270,x,290);
  					x++;
				}
				prosess();
				break;
			case 50:
				exit(1);
				break;
			}	
	}

	}

}

void RODA(tank1 tank, swap1 swap)
{
	if(tank.key==72 or tank.key==80)		//Vertical
	{
		setfillstyle(SOLID_FILL,swap.warna1);
		bar(tank.x1, tank.y1, tank.x1+10, tank.y1+5);
		setfillstyle(SOLID_FILL,swap.warna2);
		bar(tank.x1, tank.y1+5, tank.x1+10, tank.y1+10);
		setfillstyle(SOLID_FILL,swap.warna1);
		bar(tank.x1, tank.y1+10, tank.x1+10, tank.y1+15);
		setfillstyle(SOLID_FILL,swap.warna2);
		bar(tank.x1, tank.y1+15, tank.x1+10, tank.y1+20);
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1, tank.y1+20, tank.x1+10, tank.y1+25);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1, tank.y1+25, tank.x1+10, tank.y1+30);
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1, tank.y1+30, tank.x1+10, tank.y1+35);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1, tank.y1+35, tank.x1+10, tank.y1+40);

		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1+30, tank.y1, tank.x2+1, tank.y1+5);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+30, tank.y1+5, tank.x2+1, tank.y1+10);
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1+30, tank.y1+10, tank.x2+1, tank.y1+15);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+30, tank.y1+15, tank.x2+1, tank.y1+20);
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1+30, tank.y1+20, tank.x2+1, tank.y1+25);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+30, tank.y1+25, tank.x2+1, tank.y1+30);
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1+30, tank.y1+30, tank.x2+1, tank.y1+35);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+30, tank.y1+35, tank.x2+1, tank.y1+40);

		}
	if(tank.key==75 or tank.key==77)			//Horizontal
	{
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1, tank.y1, tank.x1+5, tank.y1+10);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+5, tank.y1, tank.x1+10, tank.y1+10);
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1+10, tank.y1, tank.x1+15, tank.y1+10);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+15, tank.y1, tank.x1+20, tank.y1+10);
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1+20, tank.y1, tank.x1+25, tank.y1+10);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+25, tank.y1, tank.x1+30, tank.y1+10);
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1+30, tank.y1, tank.x1+35, tank.y1+10);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+35, tank.y1, tank.x1+40, tank.y1+10);

		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1, tank.y1+30, tank.x1+5, tank.y2+1);
		setfillstyle(SOLID_FILL,swap.warna2);
		bar(tank.x1+5, tank.y1+30, tank.x1+10, tank.y2+1);
		setfillstyle(SOLID_FILL,swap.warna1);
		bar(tank.x1+10, tank.y1+30, tank.x1+15, tank.y2+1);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+15, tank.y1+30, tank.x1+20, tank.y2+1);
		setfillstyle(SOLID_FILL, swap.warna1);
		bar(tank.x1+20, tank.y1+30, tank.x1+25, tank.y2+1);
		setfillstyle(SOLID_FILL, swap.warna2);
		bar(tank.x1+25, tank.y1+30, tank.x1+30, tank.y2+1);
		setfillstyle(SOLID_FILL,swap.warna1);
		bar(tank.x1+30, tank.y1+30, tank.x1+35, tank.y2+1);
		setfillstyle(SOLID_FILL,swap.warna2);
		bar(tank.x1+35, tank.y1+30, tank.x1+40, tank.y2+1);

	}
}
void TANK(tank1 tank, swap1 swap)
{
	setfillstyle(1,GREEN);
	bar(tank.x1+9, tank.y1+9, tank.x2-9, tank.y2-9);

		circle (tank.x1+20,tank.y1+20,6);
		setfillstyle(SOLID_FILL, RED);
		floodfill(tank.x1+20, tank.y1+20, WHITE);
		switch(tank.key){
		case 72: //atas
			RODA(tank, swap);
			setfillstyle(SOLID_FILL, RED);
			setfillstyle(1,WHITE);
			bar(tank.x1+18, tank.y1+5, tank.x1+22, tank.y1+16);
			break;
		case 80: //bawah
			RODA(tank, swap);
			setfillstyle(SOLID_FILL, RED);
			setfillstyle(1,WHITE);
			bar(tank.x1+18, tank.y1+24, tank.x1+22, tank.y1+35);
		break;
		case 75:
			RODA(tank, swap);
			setfillstyle(SOLID_FILL, RED);
			setfillstyle(1,WHITE);
			bar(tank.x1+5, tank.y1+18, tank.x1+16, tank.y1+22);
		break;
		case 77:
			RODA(tank, swap);
			setfillstyle(SOLID_FILL, RED);
			setfillstyle(1,WHITE);
			bar(tank.x1+24, tank.y1+18, tank.x1+35, tank.y1+22);
			break;
		}
}
void prosess()
{
	int i;
	int temp;
	baja();
	bata();
	road();
	air();
	int current=80;
	TANK(tank, swap);
	rumput();
	while(true){
		showskor();
	if(kbhit())
	{
		tank.key = getch();
		switch(tank.key)
		{
		case 77: //kanan
            	if(tank.key!=current){
            		air();
                	TANK(tank, swap);
                	rumput();
         			    setactivepage(page);
            			setvisualpage(1-page);
            			cleardevice();
                    baja();
            		bata();
            		road();
            			page=1-page;
            		current=tank.key;
            		showskor();
					}
					else {
						if(map1[array.y][array.x+1]==2 && map1[array.y+1][array.x+1]==2 || map1[array.y][array.x+1]==1 && map1[array.y+1][array.x+1]==1 ){
				    		array.x=array.x+1;
				    		i=20;
               				tank.x1+=i;
              				tank.x2+=i;
              		temp = swap.warna2;
            		swap.warna2 = swap.warna1;
            		swap.warna1 = temp;
            		air();
					TANK(tank, swap);
					rumput();
               			setactivepage(page);
            			setvisualpage(1-page);
            			cleardevice();
                    baja();
            		bata();
            		road();

            			page=1-page;
            		current=tank.key;
            		showskor();
					}
				}
			break;
		case 75: //kiri
				if(tank.key!=current){
					air();
					TANK(tank, swap);
					rumput();
            			setactivepage(page);
            			setvisualpage(1-page);
            			cleardevice();
                    baja();
            		bata();
            		road();
            			page=1-page;
            		current=tank.key;
            		showskor();
			   }
			   else{
			   		if(map1[array.y][array.x-2]==2 && map1[array.y+1][array.x-2]==2 || map1[array.y][array.x-2]==1 && map1[array.y+1][array.x-2]==1){
						array.x=array.x-1;
               			i=20;
               			tank.x1-=i;
               			tank.x2-=i;
            		temp = swap.warna2;
            		swap.warna2 = swap.warna1;
            		swap.warna1 = temp;
            		air();
                	TANK(tank, swap);
                	rumput();
            			setactivepage(page);
            			setvisualpage(1-page);
            			cleardevice();
                    baja();
            		bata();
            		road();
            			page=1-page;
            		current=tank.key;
					showskor();
						}
               		}
			break;
		case 80: //bawah
        	    if(tank.key!=current){
        	    	air();
            		TANK(tank, swap);
            		rumput();
            			setactivepage(page);
            			setvisualpage(1-page);
            			cleardevice();
                    baja();
            		bata();
            		road();
						page=1-page;
					current=tank.key;
					showskor();
					}
					else{
						if(map1[array.y+2][array.x-1]==2 && map1[array.y+2][array.x]==2 || map1[array.y+2][array.x-1]==1 && map1[array.y+2][array.x]==1){
           				array.y=array.y+1;
            			i=20;
              			tank.y1+=i;
            			tank.y2+=i;
					temp = swap.warna2;
            		swap.warna2 = swap.warna1;
            		swap.warna1 = temp;
					air();
                	TANK(tank, swap);
                    rumput();
            			setactivepage(page);
            			setvisualpage(1-page);
            			cleardevice();
                    baja();
            		bata();
            		road();
						page=1-page;
					current=tank.key;
					showskor();
            		    }
					}
			break;
		case 72: //atas
        	if(tank.key!=current){
        			air();
            		TANK(tank,swap);
            		rumput();
            			setactivepage(page);
            			setvisualpage(1-page);
            			cleardevice();
                    baja();
            		bata();
            		road();
            			page=1-page;
					current=tank.key;
					showskor();
					}
					else{
						if(map1[array.y-1][array.x-1]==2 && map1[array.y-1][array.x]==2 || map1[array.y-1][array.x-1]==1 && map1[array.y-1][array.x]==1){
           				array.y=array.y-1;
            			i=20;
            			tank.y1-=i;
             			tank.y2-=i;
            		temp = swap.warna2;
            		swap.warna2 = swap.warna1;
            		swap.warna1 = temp;
            		air();
             		TANK(tank, swap);
             		rumput();
            			setactivepage(page);
            			setvisualpage(1-page);
            			cleardevice();
                    baja();
            		bata();
            		road();
            			page=1-page;
            		current=tank.key;
            		showskor();
           		 	}
				}
        	break;
        case 32: //enter (tembak)
        	tembak.l=tank.x1;
        	tembak.t=tank.y1;
        	tembak.X=array.x;
        	tembak.Y=array.y;
        	tank.key=current;
        	shoot(current, tembak, tank, swap);
        	air();
            		TANK(tank, swap);
            		rumput();
            			setactivepage(page);
            			setvisualpage(1-page);
            			cleardevice();
            			showskor();
                    baja();
            		bata();
            		road();
            			page=1-page;
        	break;
			}
        }
	}
}


void baja()
{
	int x,y;
	map1[30][30];
	for(x=0;x<=29;x++)
	{
			for(y=0;y<=29;y++)

		{
				if(map1[y][x]==3)
				{
					setfillstyle(1,DARKGRAY);
					bar(x*20,y*20,20+(x*20),20+(y*20));
			// readimagefile("air.bmp",0+(x*20),0+(y*20),40+(x*20),40+(y*20));
				}
	}
}
}

void road()
{
	int x,y;
	map1[30][30];
	for(x=0;x<=29;x++)
	{
			for(y=0;y<=29;y++)

		{
				if(map1[y][x]==2)
				{
				setfillstyle(1,BLACK);
			//	readimagefile("aspal.bmp",0+(x*20),0+(y*20),40+(x*20),40+(y*20));
				bar(x*20,y*20,20+(x*20),20+(y*20));
				}
	}
}
}

void bata()
{
	int x,y;
	map1[30][30];
	for(x=0;x<=29;x++)
	{
			for(y=0;y<=29;y++)

		{
			if(map1[y][x]==0)
			{
				setfillstyle(1, RED);
				//readimagefile("rumput.bmp",0+(x*20),0+(y*20),40+(x*20),40+(y*20));
				bar(x*20,y*20,20+(x*20),20+(y*20));
				//rectangle(35+(x*40),35+(y*40),70+(x*40),70+(y*40))
			}
	}
}
}

void rumput()
{
	int x,y;
	map1[30][30];
	for(x=0;x<=29;x++)
	{
			for(y=0;y<=29;y++)

		{
			if(map1[y][x]==1)
			{
				setfillstyle(1, GREEN);
			//	readimagefile("rumput.bmp",0+(x*20),0+(y*20),20+(x*20),20+(y*20));
				bar(x*20,y*20,20+(x*20),20+(y*20));
				//rectangle(35+(x*40),35+(y*40),70+(x*40),70+(y*40))
			}
	}
}
}

void air()
{
	int x,y;
	map1[30][30];
	for(x=0;x<=29;x++)
	{
			for(y=0;y<=29;y++)

		{
			if(map1[y][x]==5)
			{
				setfillstyle(1,BLUE);
			//	readimagefile("rumput.bmp",0+(x*20),0+(y*20),20+(x*20),20+(y*20));
				bar(x*20,y*20,20+(x*20),20+(y*20));
				//rectangle(35+(x*40),35+(y*40),70+(x*40),70+(y*40))
			}
	}
}
}

void modulSkor(){
	if(IndScore==1){
		score= score + ss;
	}
}

void showskor(){
	sprintf(scored,"Score");
		outtextxy(750,70,"Score");
		sprintf(scored,"%d", score);
		outtextxy (750, 85, scored );
}

void shoot(int current, tembak1 tembak, tank1 tank, swap1 swap)
{
	tank.key=current;
	switch(current){
	case 77: /* kanan */ {
        while(map1[tembak.Y][tembak.X]==2  && map1[tembak.Y+1][tembak.X]==2 || map1[tembak.Y][tembak.X]==1 && map1[tembak.Y+1][tembak.X]==1 || map1[tembak.Y][tembak.X]==5 && map1[tembak.Y+1][tembak.X]==5 ||
			  map1[tembak.Y][tembak.X]==2  && map1[tembak.Y+1][tembak.X]==1 || map1[tembak.Y][tembak.X]==2 && map1[tembak.Y+1][tembak.X]==5 || map1[tembak.Y][tembak.X]==1 && map1[tembak.Y+1][tembak.X]==5 ||
			  map1[tembak.Y][tembak.X]==1  && map1[tembak.Y+1][tembak.X]==2 || map1[tembak.Y][tembak.X]==5 && map1[tembak.Y+1][tembak.X]==2 || map1[tembak.Y][tembak.X]==5 && map1[tembak.Y+1][tembak.X]==1){
            air();
			setfillstyle(SOLID_FILL, WHITE);
			circle (tembak.l+34,tembak.t+20,6);
			floodfill(tembak.l+34, tembak.t+20, WHITE);
			tembak.X=tembak.X+1;
			i=20;
            tembak.l+=i;

			TANK(tank, swap);
			rumput();
            baja();
            bata();
           	setactivepage(page);
           	setvisualpage(1-page);
           	cleardevice();
           	showskor();
                baja();
            	bata();
            	road();
           	page=1-page;
		}
		if(map1[tembak.Y][tembak.X]==0 && map1[tembak.Y+1][tembak.X]==0){
			map1[tembak.Y][tembak.X]=2;
			map1[tembak.Y+1][tembak.X]=2; IndScore=1;
			modulSkor();
		}
		else if(map1[tembak.Y][tembak.X]==0 && map1[tembak.Y+1][tembak.X]!=3){
			map1[tembak.Y][tembak.X]=2; IndScore=1;
			modulSkor();}
			else if(map1[tembak.Y][tembak.X]!=3 && map1[tembak.Y+1][tembak.X]==0){
				map1[tembak.Y+1][tembak.X]=2; IndScore=1;
			modulSkor();}
            	road();
	}break;
	case 75: /* kiri */ {
		while(map1[tembak.Y][tembak.X-1]==2  && map1[tembak.Y+1][tembak.X-1]==2 || map1[tembak.Y][tembak.X-1]==1 && map1[tembak.Y+1][tembak.X-1]==1 || map1[tembak.Y][tembak.X-1]==5 && map1[tembak.Y+1][tembak.X-1]==5 ||
			  map1[tembak.Y][tembak.X-1]==2  && map1[tembak.Y+1][tembak.X-1]==1 || map1[tembak.Y][tembak.X-1]==2 && map1[tembak.Y+1][tembak.X-1]==5 || map1[tembak.Y][tembak.X-1]==1 && map1[tembak.Y+1][tembak.X-1]==5 ||
			  map1[tembak.Y][tembak.X-1]==1  && map1[tembak.Y+1][tembak.X-1]==2 || map1[tembak.Y][tembak.X-1]==5 && map1[tembak.Y+1][tembak.X-1]==2 || map1[tembak.Y][tembak.X-1]==5 && map1[tembak.Y+1][tembak.X-1]==1){

			air();
			setfillstyle(SOLID_FILL, WHITE);
			circle (tembak.l+6,tembak.t+20,6);
			floodfill(tembak.l+6, tembak.t+20, WHITE);
			tembak.X=tembak.X-1;
			i=20;
            tembak.l-=i;

			TANK(tank, swap);
				rumput();
                baja();
            	bata();
           	setactivepage(page);
           	setvisualpage(1-page);
           	cleardevice();
           	showskor();
                baja();
            	bata();
            	road();
           	page=1-page;
		}
		if(map1[tembak.Y][tembak.X-1]==0 && map1[tembak.Y+1][tembak.X-1]==0){
			map1[tembak.Y][tembak.X-1]=2;
			map1[tembak.Y+1][tembak.X-1]=2; IndScore=1;
			modulSkor();
		}
		else if(map1[tembak.Y][tembak.X-1]==0 && map1[tembak.Y+1][tembak.X-1]!=3){
			map1[tembak.Y][tembak.X-1]=2; IndScore=1;
			modulSkor();}
			else if(map1[tembak.Y][tembak.X-1]!=3 && map1[tembak.Y+1][tembak.X-1]==0){
				map1[tembak.Y+1][tembak.X-1]=2; IndScore=1;
			modulSkor();}
            	road();
	}break;
	case 80: /* bawah */ {
		while(map1[tembak.Y+1][tembak.X]==2  && map1[tembak.Y+1][tembak.X-1]==2 || map1[tembak.Y+1][tembak.X]==1 && map1[tembak.Y+1][tembak.X-1]==1 || map1[tembak.Y+1][tembak.X]==5 && map1[tembak.Y+1][tembak.X-1]==5 ||
			  map1[tembak.Y+1][tembak.X]==2  && map1[tembak.Y+1][tembak.X-1]==1 || map1[tembak.Y+1][tembak.X]==2 && map1[tembak.Y+1][tembak.X-1]==5 || map1[tembak.Y+1][tembak.X]==1 && map1[tembak.Y+1][tembak.X-1]==5 ||
			  map1[tembak.Y+1][tembak.X]==1  && map1[tembak.Y+1][tembak.X-1]==2 || map1[tembak.Y+1][tembak.X]==5 && map1[tembak.Y+1][tembak.X-1]==2 || map1[tembak.Y+1][tembak.X]==5 && map1[tembak.Y+1][tembak.X-1]==1){
			air();
			setfillstyle(SOLID_FILL, WHITE);
			circle (tembak.l+20,tembak.t+34,6);
			floodfill(tembak.l+20, tembak.t+34, WHITE);
			tembak.Y=tembak.Y+1;
			i=20;
            tembak.t+=i;

			TANK(tank, swap);
				rumput();
                baja();
            	bata();
           	setactivepage(page);
           	setvisualpage(1-page);
           	cleardevice();
            showskor();
                    baja();
            		bata();
            		road();
           	page=1-page;
		}
		if(map1[tembak.Y+1][tembak.X]==0 && map1[tembak.Y+1][tembak.X-1]==0){
			map1[tembak.Y+1][tembak.X]=2;
			map1[tembak.Y+1][tembak.X-1]=2; IndScore=1;
			modulSkor();
		}
		else if(map1[tembak.Y+1][tembak.X-1]==0 && map1[tembak.Y+1][tembak.X]!=3){
			map1[tembak.Y+1][tembak.X-1]=2; IndScore=1;
			modulSkor();}
			else if(map1[tembak.Y+1][tembak.X-1]!=3 && map1[tembak.Y+1][tembak.X]==0){
				map1[tembak.Y+1][tembak.X]=2; IndScore=1;
			modulSkor();}
            	road();
	}break;
	case 72: /* atas */ {
		while(map1[tembak.Y][tembak.X]==2  && map1[tembak.Y][tembak.X-1]==2 || map1[tembak.Y][tembak.X]==1 && map1[tembak.Y][tembak.X-1]==1 || map1[tembak.Y][tembak.X]==5 && map1[tembak.Y][tembak.X-1]==5 ||
			  map1[tembak.Y][tembak.X]==2  && map1[tembak.Y][tembak.X-1]==1 || map1[tembak.Y][tembak.X]==2 && map1[tembak.Y][tembak.X-1]==5 || map1[tembak.Y][tembak.X]==1 && map1[tembak.Y][tembak.X-1]==5 ||
			  map1[tembak.Y][tembak.X]==1  && map1[tembak.Y][tembak.X-1]==2 || map1[tembak.Y][tembak.X]==5 && map1[tembak.Y][tembak.X-1]==2 || map1[tembak.Y][tembak.X]==5 && map1[tembak.Y][tembak.X-1]==1){
			air();
			setfillstyle(SOLID_FILL, WHITE);
			circle (tembak.l+20,tembak.t+6,6);
			floodfill(tembak.l+20, tembak.t+6, WHITE);
			tembak.Y=tembak.Y-1;
			i=20;
           tembak.t-=i;

			TANK(tank, swap);
				rumput();
                baja();
            	bata();
				
           	setactivepage(page);
           	setvisualpage(1-page);
           	cleardevice();
            showskor();
                    baja();
            		bata();
            		road();
           	page=1-page;
		}
		if(map1[tembak.Y][tembak.X]==0 && map1[tembak.Y][tembak.X-1]==0){
			map1[tembak.Y][tembak.X]=2;
			map1[tembak.Y][tembak.X-1]=2;
				IndScore=1;
				modulSkor();
		}
		else if(map1[tembak.Y][tembak.X-1]==0 && map1[tembak.Y][tembak.X]!=3){
			map1[tembak.Y][tembak.X-1]=2;	IndScore=1;
			modulSkor();}
			else if(map1[tembak.Y][tembak.X-1]!=3 && map1[tembak.Y][tembak.X]==0){
				map1[tembak.Y][tembak.X]=2; IndScore=1;
				modulSkor();}
            		road();
	}break;
}
}

int main (){
	initwindow(900, 600);
	int gd = DETECT, gm, warna ;
	menu();
	baja();
	bata();
	road();
	air();
}
