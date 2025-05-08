#ifndef SIGN_UP_H
#define SIGN_UP_H

#include "libhaven\res\signup\draw.h"
#include "libhaven\res\signup\input.h"
#include "libhaven\res\signup\submit.h"

int signup()
{
    char key, fullname[35] = {0}, idnum[6] = {0}, email[35] = {0}, contactnum[11] = {0};
    char password[35] = {0};
    int selected,isHidden=1;
    draw_signup_form();
    delay(500);
    // event handling
    while (1)
    {
        showmouse();
        updatemouse();
        setcolor(BLACK);
        
        //Keyboard Shortcut
        if (kbhit())
        {
            key = getch();
            switch (key)
            {
              case 27: //Esc key
                exit(0);
              case '\r': //Enter key
                signup_submit(fullname, idnum, email, contactnum, password);
                break;
            }
        }
        // exit
        if (mouseX > 599 && mouseX < 619)
        {
            if (mouseY > 20 && mouseY < 40)
            {
                if (mouseButton == 1){exit(0);};
            }
        }
        // text fields
        if (mouseX > 159 && mouseX < 479)
        {
            if (mouseY > 190 && mouseY < 210)
            {
                if (mouseButton == 1){signup_getfullname(fullname);};
            }; // fullname
            if (mouseY > 230 && mouseY < 250)
            {
                if (mouseButton == 1){signup_getidnum(idnum);};
            }; // Idnum
            if (mouseY > 270 && mouseY < 290)
            {
                if (mouseButton == 1){signup_getemail(email);
                }
            }; // email
            if (mouseY > 310 && mouseY < 330)
            {
                if (mouseButton == 1){signup_getcontactnum(contactnum);};
            }; // contact
            if (mouseY > 350 && mouseY < 370)
            {
                if (mouseButton == 1){signup_getpassword(password, isHidden);};
            }; // password
        }

        // signup button
        if (mouseX > 279 && mouseX < 359)
        { 
            if (mouseY > 390 && mouseY < 415)
            {
                setfillstyle(1,WHITE);
                hidemouse();
                bar(279, 390, 359, 415);
                rectangle(279, 390, 359, 415);
                outtextxy(293, 400, "SIGN UP");
                showmouse();
                while((mouseX > 279 && mouseX < 359) && (mouseY > 390 && mouseY < 415))
                {
                  if (mouseButton == 1)
                  {
                    if(!signup_submit(fullname, idnum, email, contactnum, password)){return 1;};
                  }
                  updatemouse();
                }
                setfillstyle(1,LIGHTGRAY);
                hidemouse();
                bar(279, 390, 359, 415);
                rectangle(279, 390, 359, 415);
                outtextxy(293, 400, "SIGN UP");
                showmouse();
            }
        }


        // back to login
        if (mouseX > 230 && mouseX < 412 && mouseY > 425 && mouseY < 431)
        {
            hidemouse();
            setcolor(WHITE);
            outtextxy(230, 425, "Already have an account");
            showmouse();
            while (mouseX > 230 && mouseX < 412 && mouseY > 425 && mouseY < 431)
            {
                if (mouseButton == 1){login();};
                updatemouse();
            }
            hidemouse();
            setcolor(BLACK);
            outtextxy(230, 425, "Already have an account");
            showmouse();
        }
        //Hide Password
        if ((mouseX > 485 && mouseX < 505) && (mouseY > 355 && mouseY < 365))
        {
          if (mouseButton == 1)
          {
            if(isHidden)
            {
              isHidden = 0;
              setfillstyle(1, LIGHTGRAY);
              bar(160, 351, 478, 369);
                      outtextxy(180, 359, password);
                      delay(500);
            }
            else
            {
              isHidden = 1;
              setfillstyle(1, LIGHTGRAY);
              bar(160, 351, 478, 369);
              moveto(180, 359);
              for (int i = 0; i < strlen(password); i++){outtext("*");}
              delay(500);
            }
           };
        }
    }
};
#endif
