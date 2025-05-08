#ifndef SIGNUP_DRAW_H
#define SIGNUP_DRAW_H

void draw_signup_form()
{
  // draw input text fields
  hidemouse();
  draw_logo();
  setcolor(BLACK);
  rectangle(159, 190, 479, 210);
  setfillstyle(1, LIGHTGRAY);
  bar(160, 191, 478, 209); // fullname
  rectangle(159, 230, 479, 250);
  setfillstyle(1, LIGHTGRAY);
  bar(160, 231, 478, 249); // id number
  rectangle(159, 270, 479, 290);
  setfillstyle(1, LIGHTGRAY);
  bar(160, 271, 478, 289); // email
  rectangle(159, 310, 479, 330);
  setfillstyle(1, LIGHTGRAY);
  bar(160, 311, 478, 329); // contact
  rectangle(159, 350, 479, 370);
  setfillstyle(1, LIGHTGRAY);
  bar(160, 351, 478, 369); // password

  // Form Title
  setcolor(BLACK);
  settextstyle(0, 0, 2);
  outtextxy(270, 150, "SIGN UP");

  // draw signup button
  setfillstyle(9, LIGHTBLUE);
  bar(277, 390, 361, 417);
  setfillstyle(1, LIGHTGRAY);
  bar(279, 390, 359, 415);
  rectangle(279, 390, 359, 415);

  // draw quit button
  setcolor(RED);
  setlinestyle(0, 0, 3);
  line(619, 20, 599, 40);
  line(599, 20, 619, 40);
  setlinestyle(0, 0, 2);

  // print labels
  settextstyle(0, 0, 0);
  setcolor(BLACK);
  outtextxy(159, 180, "Fullname:");
  outtextxy(159, 220, "ID Number:");
  outtextxy(159, 260, "Email address:");
  outtextxy(159, 300, "Contact number:");
  outtextxy(159, 340, "Password:");
  outtextxy(293, 400, "SIGN UP");
  // draw eye icon for showing password

  setlinestyle(0, 0, 2);
  fillellipse(495, 360, 10, 5);
  circle(495, 360, 3);

  outtextxy(230, 425, "Already have an account");
}

#endif