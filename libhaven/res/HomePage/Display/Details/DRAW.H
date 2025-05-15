#ifndef BOOKDETAILS_DRAW_H#define BOOKDETAILS_DRAW_H

void draw_bookdetails(int status)
{
  setcolor(BLACK);setfillstyle(1,LIGHTRED);
  bar(35,180,150,256);line(148,180,148,256); line(150,180,150,256);
  setfillstyle(1, LIGHTGRAY);
  settextstyle(2,0,4);
    
  //Sidebar
  bar(35, 180, 145, 196);
  rectangle(35, 180, 145, 196);
  outtextxy(42, 183, "DISPLAY BOOKS");
  bar(35, 200, 145, 216);
  rectangle(35, 200, 145, 216);
  outtextxy(42, 203, "ADD BOOK");
  bar(35, 220, 145, 236);
  rectangle(35, 220, 145, 236);
  outtextxy(42, 223, "SEE PROFILE");
    
  //Container
  setfillstyle(1,CYAN);
  setcolor(BLACK);
  bar(151, 151, 608, 448);
  rectangle(152, 152, 607, 447);
  rectangle(35, 180, 152, 196);
  bar(36, 181, 153, 195);
  outtextxy(42, 183, "DISPLAY BOOKS");
  settextstyle(1,0,3);
  outtextxy(300, 170, "BOOK DETAILS");
  settextstyle(0,0,1);
  
  //Print Buttons
  setfillstyle(1, LIGHTRED);
  bar(446, 400, 512, 426);rectangle(446, 400, 512, 426);rectangle(448, 402, 510, 424);outtextxy(455, 410,"DELETE");
  setfillstyle(1,LIGHTBLUE);
  bar(532, 400, 598, 426);rectangle(532, 400, 598, 426);rectangle(534, 402, 596, 424);outtextxy(545, 410,"ISSUE");
  
  //Display Corresponding buttons
  switch(status)
  {
      case 0: outtextxy(200, 353, "Issue to: "); setfillstyle(1,LIGHTGRAY);bar(275,345,598,365);rectangle(275,345,598,365);break;
      case 1: setfillstyle(1,LIGHTGREEN);
              bar(532, 400, 598, 426);rectangle(532, 400, 598, 426);rectangle(534, 402, 596, 424);outtextxy(543, 410,"RETURN");break;  
  }
  //Exit Button
  setcolor(RED);settextstyle(0,0,2); outtextxy(580,156,">");outtextxy(590,156,"<");
  setcolor(BLACK);settextstyle(0,0,1);

}


#endif