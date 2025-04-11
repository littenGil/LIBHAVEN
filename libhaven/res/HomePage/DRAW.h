#ifndef HOMEPAGE_DRAW_H
#define HOMEPAGE_DRAW_H


void draw_user_main()
{
//search bar
  setfillstyle(1, LIGHTGRAY);setcolor(BLACK);setlinestyle(0,0,2);rectangle(129,150,510,180);
  bar(130,151,509,179);setcolor(DARKGRAY);circle(145,160,5);line(140,170,143,165);
  line(150,173,480,173);setcolor(BLACK);

//menu Button
  setlinestyle(0,0,2);rectangle(80,150,110 ,180);bar(81,151,109,179);setfillstyle(1,DARKGRAY);
  bar(85, 155, 105, 175);setcolor(LIGHTGRAY);setlinestyle(0,0,3);line(85, 161, 105, 161);
  line(85, 169,105,169);setlinestyle(0,0,2);setcolor(BLACK);
    
//catalog
  setfillstyle(1,LIGHTGRAY);setlinestyle(0,0,3);bar(81,201,558,459);rectangle(80,200,559,460);
  setlinestyle(0,0,2);
  bar(520,150,560,180);rectangle(520,150,560,180);
  outtextxy(525,162,"TAGS");outtextxy(133,210,"ISBN");outtextxy(300,210,"TITLE");outtextxy(464,210,"STATUS");
  line(220,200,220,460);line(420,200,420,460);
  line(80,225,560,225);
  
}

#endif
