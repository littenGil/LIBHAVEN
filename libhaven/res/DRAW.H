#ifndef DRAW_H
#define DRAW_H

void draw_logo()
{
  int book1[] = {217, 125, 155, 105, 217, 80, 217, 125};
  int book2[] = {217, 114, 160, 95, 217, 68, 217, 114};
  int book3[] = {217, 101, 165, 85, 217, 56, 217, 101};

  // draw blue bar
  setfillstyle(1, LIGHTBLUE);
  bar(0, 0, 639, 479);
  setlinestyle(0, 0, 1);
  setfillstyle(SOLID_FILL, BLUE);
  setcolor(BLUE);
  bar(220, 50, 225, 130);

  // draw blue book
  fillpoly(4, book1);
  setfillstyle(1, LIGHTBLUE);
  bar(155, 102, 160, 107);
  setcolor(WHITE);
  setlinestyle(0, 0, 1);
  line(163, 104, 217, 122);
  line(163, 106, 217, 124);

  // draw dark gray book
  setfillstyle(1, DARKGRAY);
  setcolor(DARKGRAY);
  setlinestyle(0, 0, 1);
  fillpoly(4, book2);
  setfillstyle(1, LIGHTBLUE);
  bar(160, 92, 165, 97);
  setcolor(WHITE);
  setlinestyle(0, 0, 1);
  line(168, 94, 217, 110);
  line(168, 96, 217, 112);

  // draw brown book
  setfillstyle(1, BROWN);
  setcolor(BROWN);
  setlinestyle(0, 0, 1);
  fillpoly(4, book3);
  setfillstyle(1, LIGHTBLUE);
  bar(165, 82, 170, 88);
  setcolor(WHITE);
  setlinestyle(0, 0, 1);
  line(173, 83, 217, 97);
  line(173, 85, 217, 99);
  settextstyle(0, 0, 3);

  // print title
  outtextxy(230, 70, TITLE);
  settextstyle(0, 0, 1);
  outtextxy(260, 100, SUBTITLE);
  setlinestyle(0, 0, 2);
  settextstyle(0, 0, 0);
  setcolor(BLACK);
  setlinestyle(0, 0, 2);
  rectangle(10, 10, 629, 469);
}

#endif
