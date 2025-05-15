#ifndef HOMEPAGE_ADDBOOK_H
#define HOMEPAGE_ADDBOOK_H

#include "libhaven/res/homepage/addbook/draw.h"
#include "libhaven/res/homepage/addbook/inputs.h"
#include "libhaven/res/homepage/addbook/submit.h"

void addbook()
{
  char bookID[7]={0}, title[37]={0}, ISBN[11]={0}, author[30]={0};
  if(setjmp(Jaddbook)==0){setAddbook=1;};
  memset(bookID, 0, sizeof(bookID));
  memset(title, 0, sizeof(title));
  memset(ISBN, 0, sizeof(ISBN));
  memset(author, 0, sizeof(author));
  hidemouse();
  draw_addbook();
  showmouse();
  
  while(1)
  {
    updatemouse();
    //SIDE BAR
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
          if(mouseButton == 1){if(setDisplaybooks!=0){longjmp(Jdisplaybooks,1);};displaybooks(0);}
          updatemouse();
        }
        hidemouse();setcolor(BLACK);
        outtextxy(42, 183, "DISPLAY BOOKS");settextstyle(0,0,0);
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
          if(mouseButton == 1){seeprofile();}
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
    
    //TEXTFIELD
    if(mouseX > 220 && mouseX < 538)
    {
        if(mouseY > 220 && mouseY < 238)
        {
            if(mouseButton==1){addbook_getBookID(bookID);};
        }
        if(mouseY > 260 && mouseY < 278)
        {
            if(mouseButton==1){addbook_getBookTitle(title);};
        }
        if(mouseY > 300 && mouseY < 318)
        {
            if(mouseButton==1){addbook_getBookISBN(ISBN);};
        }
        if(mouseY > 340 && mouseY < 358)
        {
            if(mouseButton==1){addbook_getBookAuthor(author);};
        }
    }   
    
    //REGISTER BUTTON
    if((mouseX > 345 && mouseX < 420)&&(mouseY > 380 && mouseY < 395))
    {
        hidemouse();setfillstyle(1,WHITE);
        bar(346, 381, 419, 394);
        outtextxy(351,  385, "REGISTER");showmouse();
        while((mouseX > 345 && mouseX < 420)&&(mouseY > 380 && mouseY < 395))
        {
            if(mouseButton == 1){addbook_submit(bookID, title, ISBN, author);};
            updatemouse(); 
        }
        hidemouse();setfillstyle(1,LIGHTGRAY);
        bar(346, 381, 419, 394);
        outtextxy(351,  385, "REGISTER");showmouse();
    }
  }      
}


#endif