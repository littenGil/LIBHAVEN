#ifndef BOOT_UP_H
#define BOOT_UP_H

#include "libhaven/res/bootup/draw.h"

void bootup()
{
  int i, j;
  FILE *userlist, *booklist, *borrowerlist;
  draw_bootup();
  // create database folder
  mkdir("c:/libhaven");
  mkdir("c:/libhaven/users");
  mkdir("c:/libhaven/books");
  mkdir("c:/libhaven/borrowed");
  
  //Draw loading circles  
  settextstyle(1, 0, 1);
  outtextxy(285, 328, "LOADING...");
  for (i = 0; i <= 4; i++)
  {
    if (i % 2 == 1){setcolor(WHITE);};
    if (i % 2 == 0){setcolor(BLACK);};j = 0;while (j < 360)
    {
      arc(330, 300, 0, j += 10, 25);
    }
  };
  
  //Check if creating database was successful
  userlist = fopen(userlistfile, "r");
  booklist = fopen(booklistfile, "r");
  settextstyle(0, 0, 1);
  if (userlist == NULL)
  {
    fclose(userlist);
    userlist = fopen(userlistfile, "w");
    setcolor(RED);
    outtext("Launching Users Database...");
    setcolor(BLACK);
    moveto(0, gety() + 20);
  };
  if (booklist == NULL)
  {
    fclose(booklist);
    booklist = fopen(booklistfile, "w");
    setcolor(RED);
    outtext("Launching Books Database...");
    setcolor(BLACK);
    moveto(0, gety() + 20);
  };

  fclose(userlist);
  fclose(booklist);

  // print prompt text
  setcolor(GREEN);
  settextstyle(7, 0, 1);
  setfillstyle(1, BLACK);
  bar(285, 328, 500, 400);
  outtextxy(180, 328, "(PRESS ANY KEY TO CONTINUE)");
  showmouse();
  updatemouse();
  switch (mouseButton)
  {
  case 1:
    while (1)
    {
      if (mouseButton == 0){break;}
      if (kbhit()){getch();break;}
      updatemouse();
    }
    break;
  case 0:
    while (1)
    {
      if (mouseButton == 1){break;}
      if (kbhit())
      {getch();break;}
      updatemouse();
    }
    break;
  }
  i = 0;
  while (i < 400)
  {
    sound(i);
    delay(50);
    i += 50;
  }
  delay(100);
  nosound();
  setfillstyle(SOLID_FILL, WHITE);
  settextstyle(0, 0, 0);
  hidemouse();

  login();
};

#endif