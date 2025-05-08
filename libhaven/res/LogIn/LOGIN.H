#ifndef LOGIN_H
#define LOGIN_H

#include "libhaven\res\signup\signup.h"
#include "libhaven\res\login\inputs.h"
#include "libhaven\res\login\draw.h"
#include "libhaven\res\login\submit.h"

int login()
{
  char idnum[6] = {0}, password[35] = {0}, key; int isHidden=1;
  draw_login_form();
  delay(500);
//Await keyboard press
  while (1)
  {
    if (kbhit())
    {
        key = getch();
        switch (key)
        {
          case 27:   //Esc key for exit
            exit(0);
          case '\r': //Enter for submit
	    if(login_submit(idnum, password)){login();return 0;};
        }
    }
    
    showmouse();
    updatemouse();

    if (mouseX > 159 && mouseX < 479)
    {
        if (mouseY > 190 && mouseY < 210)
        {
           if (mouseButton == 1){login_getidnum(idnum);};
           continue;
        }
        if (mouseY > 250 && mouseY < 270)
        {
           if (mouseButton == 1){login_getpassword(password, isHidden);};
           continue;
        }
    }

    if (mouseX > 485 && mouseX < 505)
    {
      if (mouseY > 255 && mouseY < 265)
      {
          if (mouseButton == 1)
        {
          if(isHidden)
          {
            isHidden = 0;
            setfillstyle(1, LIGHTGRAY);
            bar(160, 251, 478, 269);
            outtextxy(180, 259, password);
            delay(500);
          }
          else
          {
            isHidden = 1;
            setfillstyle(1, LIGHTGRAY);
            bar(160, 251, 478, 269);
            moveto(180, 259);
            for (int i = 0; i < strlen(password); i++){outtext("*");}
            delay(500);
           }
        };
       }
    }
    
    // Submit
    if (mouseX > 279 && mouseX < 359)
    {
      if (mouseY > 320 && mouseY < 335)
      {
        setfillstyle(1, WHITE);
        hidemouse();
        bar(279, 320, 359, 335);
        rectangle(279, 320, 359, 335);
        outtextxy(297, 325, "LOG IN"); 
        showmouse();
        while((mouseX > 279 && mouseX < 359)&&(mouseY > 320 && mouseY < 335))
        {
          if (mouseButton == 1){if(login_submit(idnum, password)){login();return 0;};};
          updatemouse();
        }
        setfillstyle(1, LIGHTGRAY);
        hidemouse();
        bar(279, 320, 359, 335);
        rectangle(279, 320, 359, 335);
        outtextxy(297, 325, "LOG IN"); 
        showmouse();
      }
    }
    // Exit
    if (mouseX > 599 && mouseX < 619)
    {
      if (mouseY > 20 && mouseY < 40)
      {
        if (mouseButton == 1){exit(0);};
      }
    }
    // Sign Up Button
    if (mouseX > 279 && mouseX < 375 && mouseY > 345 && mouseY < 351)
    {
      hidemouse();
      setcolor(WHITE);
      outtextxy(265, 345, "Create account");
      showmouse();
      while (mouseX > 279 && mouseX < 375 && mouseY > 345 && mouseY < 351)
      {
        if (mouseButton == 1){signup();}
        updatemouse();
      }
      hidemouse();
      setcolor(BLACK);
      outtextxy(265, 345, "Create account");
      showmouse();
    }
  }
};

#endif
