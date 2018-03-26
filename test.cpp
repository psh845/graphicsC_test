#include <stdio.h>
#include <conio.h>
#include <graphics\graphics.h>
#include <math.h>
#include <stdlib.h>
/*
ALGORITHM:

1.      Start

2.      Initialize the graphics mode.

3.      Construct a 2D object  (use Drawpoly()) e.g. (x,y)

4.      A) Translation

a.       Get the translation value tx, ty

b.      Move the 2d object with tx, ty (x¡¯=x+tx,y¡¯=y+ty)

c.       Plot (x¡¯,y¡¯)

5.      B)  Scaling

a.       Get the scaling value Sx,Sy

b.       Resize the object with Sx,Sy  (x¡¯=x*Sx,y¡¯=y*Sy)

c.       Plot (x¡¯,y¡¯)

6.      C) Rotation

a.       Get the Rotation angle

b.      Rotate the object by the angle ¬æ 

                    x¡¯=x cos ¬æ -  y sin ¬æ 

                    y¡¯=x sin ¬æ  + y cos¬æ   

c.       Plot (x¡¯,y¡¯)
*/


int main()
{	
	int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
	int x1,x2,x3,y1,y2,y3,nx1,nx2,nx3,ny1,ny2,ny3,c;
	int sx,sy,xt,yt,r,cx,cy;
	float t;

	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
  /* rectangle(left, top, right, bottom);
   circle(x, y, radius);
   bar(left + 300, top, right + 300, bottom);
   line(left - 10, top + 150, left + 410, top + 150);
   ellipse(x, y + 200, 0, 360, 100, 50);
   outtextxy(left + 100, top + 325, "My First C Graphics Program");
   
   getch();
   closegraph();*/
	printf("\t Program for basic transactions");

	printf("\n\t Enter the points of triangle");

    setcolor(1);

    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);

    line(x1,y1,x2,y2);

    line(x2,y2,x3,y3);

    line(x3,y3,x1,y1);

    getch();

    printf("\n 1.Transaction\n 2.Rotation\n 3.Scalling\n 4.exit");

    printf("Enter your choice:");

    scanf("%d",&c);

    switch(c)
    {

        case 1:

            printf("\n Enter the translation factor");

            scanf("%d%d",&xt,&yt);

            nx1=x1+xt;

            ny1=y1+yt;

            nx2=x2+xt;

            ny2=y2+yt;

            nx3=x3+xt;

            ny3=y3+yt;

            line(nx1,ny1,nx2,ny2);

            line(nx2,ny2,nx3,ny3);

            line(nx3,ny3,nx1,ny1);

            getch();

			break;


        case 2:

            printf("\n Enter the angle of rotation");

            //scanf("%d",&r);
			scanf("%d%d%d",&r,&cx,&cy);

			x1 -= cx; //pivotx
			y1 -= cy; //pivoty
			x2 -= cx; //pivotx
			y2 -= cy; //pivoty
			x3 -= cx; //pivotx
			y3 -= cy; //pivoty

            t=3.14*r/180; //radian  digree: rad* 180/pi

            nx1=x1*cos(t)-y1*sin(t);

            ny1=x1*sin(t)+y1*cos(t);

            //nx2=abs(x2*cos(t)-y2*sin(t));
			nx2 = x2*cos(t)-y2*sin(t);

            //ny2=abs(x2*sin(t)+y2*cos(t));
			ny2=x2*sin(t)+y2*cos(t);

            //nx3=abs(x3*cos(t)-y3*sin(t));
		    nx3=x3*cos(t)-y3*sin(t);

            //ny3=abs(x3*sin(t)+y3*cos(t))
			ny3=x3*sin(t)+y3*cos(t);

			nx1 += cx; 
			ny1 += cy;
			nx2 += cx; 
			ny2 += cy; 
			nx3 += cx;
			ny3 += cy; 
            line(nx1,ny1,nx2,ny2);

            line(nx2,ny2,nx3,ny3);

            line(nx3,ny3,nx1,ny1);

            getch();

			break;


        case 3:
            printf("\n Enter the scalling factor");

            //scanf("%d%d",&sx,&sy);
			scanf("%d%d%d%d",&sx,&sy,&cx,&cy);
			x1 -= cx; //pivotx
			y1 -= cy; //pivoty
			x2 -= cx; //pivotx
			y2 -= cy; //pivoty
			x3 -= cx; //pivotx
			y3 -= cy; //pivoty

            nx1=x1*sx;

            ny1=y2*sy;

            nx2=x2*sx;

            ny2=y2*sy;

            nx3=x3*sx;

            ny3=y3*sy;

			nx1 += cx; 
			ny1 += cy;
			nx2 += cx;  
			ny2 += cy; 
			nx3 += cx; 
			ny3 += cy; 

            line(nx1,ny1,nx2,ny2);

            line(nx2,ny2,nx3,ny3);

            line(nx3,ny3,nx1,ny1);

            getch();
			break;

        case 4:
			break;

        default:
            printf("Enter the correct choice");

    }

   closegraph();


   return 0;


}