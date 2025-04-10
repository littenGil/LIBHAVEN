#ifndef LOGIN_DRAW_H
#define LOGIN_DRAW_H

void draw_login_form()
{
//draw input text fields
  rectangle(159, 190, 479, 210);setfillstyle(1, LIGHTGRAY);bar(160, 191, 478, 209);
  rectangle(159, 250, 479, 270);setfillstyle(1, LIGHTGRAY);bar(160, 251, 478, 269);
    
//draw login button
  setfillstyle(1, DARKGRAY);bar(277,322,361,337);
  setfillstyle(1, LIGHTGRAY);bar(279,320,359,335);rectangle(279,320,359,335);
    
//draw quit button
  setcolor(RED);setlinestyle(0,0,3);line(619, 20, 599, 40 );
  line(599, 20, 619, 40 );setlinestyle(0,0,2);   
    
//print labels
  settextstyle(0,0,0);setcolor(BLACK);
  outtextxy(159,175, "Username:");outtextxy(159,235, "Password:");outtextxy(297,325,"Log in");

//draw eye icon for showing password
  setlinestyle(0,0,2);fillellipse(495, 260,10,5);circle(495,260,3);setlinestyle(0,0,2);
}
#endif