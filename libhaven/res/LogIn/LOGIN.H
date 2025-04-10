#ifndef LOGIN_H
#define LOGIN_H

#include "libhaven\res\login\inputs.h"
#include "libhaven\res\login\draw.h"
#include "libhaven\res\login\submit.h"

int login()
{
//variables
 int tab=0;char username[36]={0};char password[36]={0};
//draw interface   
 draw_logo();draw_login_form();
 while(1){
//keyboard navigation
        if(kbhit()){
            switch(getch()){
                case '\t': case 72: case 80:
                    if(tab == 0){login_getusername(username); tab = 1;}
                    else{login_getpassword(password); tab = 0;}
                    break;
                case '\r':
                    if(!login_submit(username, password)){return 0;}
                    break;
                case 27:
                    return 0;
            };
        };
//mouse navigation
    showmouse();updatemouse();
    if(mouseX > 159 && mouseX < 479){
        if(mouseY > 190 && mouseY < 210){
            if(mouseButton==1){login_getusername(username);tab = 1;}
            continue;
        }
        if(mouseY > 250 && mouseY < 270){
            if(mouseButton==1){login_getpassword(password);tab = 0;}
            continue;
        }
    }
    if(mouseX > 485 && mouseX<505){
        if(mouseY > 255 && mouseY < 265){
            if(mouseButton == 1){
               setfillstyle(1, LIGHTGRAY);bar(160, 251, 478, 269);
               while(mouseButton == 1){
               if(strlen(password) == 0){break;};
               outtextxy(180,259, password); updatemouse();}
               setfillstyle(1, LIGHTGRAY);bar(160, 251, 478, 269);
               moveto(180, 259);
               for(int i = 0; i < strlen(password); i++){outtext("*");}};
        }
    }
    if(mouseX > 279 && mouseX < 359){
        if(mouseY > 320 && mouseY < 335){
            if(mouseButton == 1){if(!login_submit(username, password)){return 0;};}
        }
    }
    if(mouseX > 599 && mouseX < 619){
        if(mouseY > 20 && mouseY < 40){
            if(mouseButton == 1){return 0;}}
        }
    }
};


#endif

