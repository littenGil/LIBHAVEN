#ifndef BOOT_UP_H
#define BOOT_UP_H

#include "libhaven/res/bootup/draw.h"

void bootup()
{
    int i = 0;
    draw_bootup();
    //draw loading circle
    for(i=0; i<360 ; i+=8){
    setcolor(BLACK);circle(314, 350, 25);setcolor(WHITE);
    arc(314, 350, i, i+270, 25);delay(12);
    };
    checkfiles(); 
    setcolor(BLACK);circle(314,350, 25);

    //print prompt text
    setcolor(GREEN);settextstyle(7, 0, 1);
    outtextxy(200,328,"(LEFT CLICK TO CONTINUE)");showmouse();
    updatemouse();
    switch(mouseButton)
    {
        case 1:
           while(1){if(mouseButton==0){break;}if(kbhit()){getch();}updatemouse();}break;
        case 0:
           while(1){if(mouseButton==1){break;}if(kbhit()){getch();}updatemouse();}break;
    }
    i=0;
    while(i<400)
    {
     sound(i);
     delay(50);
     i+=50;
    }
    delay(100);
    nosound();
    setfillstyle(SOLID_FILL, WHITE);
    settextstyle(0,0,0);
    hidemouse();
    
    login();
    
};

#endif