#ifndef HOMEPAGE_DRAW_H
#define HOMEPAGE_DRAW_H

void draw_user_main()
{
   setcolor(BLACK);
   setfillstyle(9,LIGHTBLUE);
   bar(30, 150, 609, 449);
   rectangle(30, 150, 609, 449);
   setfillstyle(1, LIGHTRED);
   bar(31, 151, 150, 448);
   
   rectangle(32, 152, 148, 447);
   rectangle(30, 150, 150, 449);
   setfillstyle(1, LIGHTGRAY);
   settextstyle(2,0,4);
   
   bar(35, 180, 145, 196);
   rectangle(35, 180, 145, 196);
   outtextxy(42, 183, "DISPLAY BOOKS");
  
   bar(35, 200, 145, 216);
   rectangle(35, 200, 145, 216);
   outtextxy(42, 203, "ADD BOOK");
   
   bar(35, 220, 145, 236);
   rectangle(35, 220, 145, 236);
   outtextxy(42, 223, "SEE PROFILE");
   
   bar(35, 420, 145, 436);
   rectangle(35, 420, 145, 436);
   outtextxy(65, 423, "LOGOUT");
}





#endif
