#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "libhaven/res/homepage/draw.h"
#include "libhaven/res/homepage/display/display.h"
#include "libhaven/res/homepage/addbook/addbook.h"
#include "libhaven/res/homepage/profile/profile.h"

int home()
{
    delay(150);
    hidemouse();
    draw_logo(); 
    draw_user_main();
    showmouse();
    showmouse();
    while(1)
    {
      updatemouse();
     
      if(mouseX>35&&mouseX<145)
      {
        //DISPLAY BOOKS
        if(mouseY>180 && mouseY<196)
        {
          hidemouse();setcolor(WHITE);settextstyle(2,0,4);  
          outtextxy(42, 183, "DISPLAY BOOKS");
          showmouse();
          while((mouseX>35&&mouseX<145)&&(mouseY>180 && mouseY<196))
          {
            if(mouseButton == 1){displaybooks(0);}
            updatemouse();
          }
          hidemouse();setcolor(BLACK);
          outtextxy(42, 183, "DISPLAY BOOKS");settextstyle(0,0,0);
          showmouse();
        }
      
      
        //ADD BOOK
        if(mouseY>200 && mouseY<216)
        {
          hidemouse();setcolor(WHITE);settextstyle(2,0,4);  
          outtextxy(42, 203, "ADD BOOK");
          showmouse();
          while((mouseX>35&&mouseX<145)&&(mouseY>200 && mouseY<216))
          {
            if(mouseButton == 1){seeprofile();}
            updatemouse();
          }
          hidemouse();setcolor(BLACK);
          outtextxy(42, 203, "ADD BOOK");settextstyle(0,0,0);
          showmouse();
        }
        
        //SEE PROFILE
        if(mouseY>220 && mouseY<236)
        {
          hidemouse();setcolor(WHITE);settextstyle(2,0,4);  
          outtextxy(42, 223, "SEE PROFILE");
          showmouse();
          while((mouseX>35&&mouseX<145)&&(mouseY>220 && mouseY<236))
          {
            if(mouseButton == 1){addbook();}
            updatemouse();
          }
          hidemouse();setcolor(BLACK);
          outtextxy(42, 223, "SEE PROFILE");settextstyle(0,0,0);
          showmouse();
        }
        
        
      
        //LOG OUT
        if(mouseY>420 && mouseY<436)
        {
          hidemouse();setcolor(WHITE);settextstyle(2,0,4);  
          outtextxy(65, 423, "LOGOUT");
          showmouse();
          while((mouseX>35&&mouseX<145)&&(mouseY>420 && mouseY<436))
          {
            if(mouseButton == 1){strcpy(currentUser,"");login();}
            updatemouse();
          }
          hidemouse();setcolor(BLACK);
          outtextxy(65, 423, "LOGOUT");settextstyle(0,0,0);
          showmouse();
        }
      }
    }
}
#endif
