#ifndef BOOTUP_DRAW.H
#define BOOTUP_DRAW .H

void draw_bootup()
{
  // set variables
  int i = 190;
  int book1[] = {170, 240, 80, 215, 170, 190, 170, 240};
  int book2[] = {170, 220, 90, 200, 170, 170, 170, 220};
  int book3[] = {170, 204, 96, 186, 170, 150, 170, 204};

  // draw blue bar
  cleardevice();
  setfillstyle(1, BLUE);
  setcolor(BLUE);
  bar(175, 125, 180, 255);

  // draw blue book
  fillpoly(4, book1);
  setfillstyle(1, BLACK);
  bar(80, 210, 100, 220);
  setcolor(WHITE);
  setlinestyle(0, 0, 3);
  line(105, 213, 170, 229);
  line(105, 217, 170, 233);

  // draw darkgray book
  setfillstyle(1, DARKGRAY);
  setcolor(DARKGRAY);
  setlinestyle(0, 0, 1);
  fillpoly(4, book2);
  setfillstyle(1, BLACK);
  bar(85, 195, 105, 205);
  setcolor(WHITE);
  setlinestyle(0, 0, 3);
  line(110, 198, 170, 213);
  line(110, 202, 170, 217);

  // draw brown book
  setfillstyle(1, BROWN);
  setcolor(BROWN);
  setlinestyle(0, 0, 1);
  fillpoly(4, book3);
  setfillstyle(1, BLACK);
  bar(92, 180, 111, 189);
  setcolor(WHITE);
  setlinestyle(0, 0, 3);
  line(116, 183, 170, 197);
  line(116, 187, 170, 201);

  // play tone
  while (i < 400)
  {
    sound(i);
    delay(50);
    i += 50;
  }
  nosound();

  // print title
  settextstyle(0, 0, 5);
  outtextxy(190, 165, TITLE);
  settextstyle(0, 0, 2);
  outtextxy(220, 220, SUBTITLE);
}

#endif