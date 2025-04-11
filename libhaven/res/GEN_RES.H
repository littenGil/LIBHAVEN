#ifndef GEN_RES_H
#define GEN_RES_H

//BASIC INCLUDES
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

char TITLE[] = "LIBHAVEN", SUBTITLE[] = "Learn in Comfort";
char userlistfile[] = "c:/libhaven/users/list.txt";
char booklistfile[] = "c:/libhaven/books/list.txt";


int checkfiles()
{
   FILE *userlist = fopen(userlistfile, "r");FILE *booklist = fopen(booklistfile, "r");
   settextstyle(0,0,1);
   if (userlist == NULL){setcolor(RED);outtext("record of users not found");setcolor(BLACK);moveto(0,gety()+20);}; 
   if (booklist == NULL){setcolor(RED);outtext("record of books not found");setcolor(BLACK);moveto(0,gety()+20);};
   return 0;
}
#include "libhaven\res\mouse.h"
#include "libhaven\res\inputs.h"


#include "libhaven\res\draw.h"
#include "libhaven\res\homepage\homepage.h"
#include "libhaven\res\login\login.h"
#include "libhaven\res\bootup\bootup.h"

#endif
