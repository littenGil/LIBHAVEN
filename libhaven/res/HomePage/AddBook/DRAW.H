#ifndef ADDBOOK_DRAW_H
#define ADDBOOK_DRAW_H

void draw_addbook()
{
    setcolor(BLACK);setfillstyle(1,LIGHTRED);
    bar(35,180,150,256);line(148,180,148,256); line(150,180,150,256);
    setfillstyle(1, LIGHTGRAY);
    settextstyle(2,0,4);
    //Side Bar
    bar(35, 180, 145, 196);
    rectangle(35, 180, 145, 196);
    outtextxy(42, 183, "DISPLAY BOOKS");
 
    bar(35, 220, 145, 236);
    rectangle(35, 220, 145, 236);
    outtextxy(42, 223, "SEE PROFILE");
    
    settextstyle(2,0,4);setfillstyle(1,CYAN);
    bar(151, 151, 608, 448);
    rectangle(152, 152, 607, 447);
    rectangle(35, 200, 152, 216);
    bar(36, 201, 153, 215);
    outtextxy(42, 203, "ADD BOOK");
    settextstyle(1,0,3);
    outtextxy(300, 170, "BOOK REGISTRY");
    setfillstyle(1, LIGHTGRAY);
    //draw text fields
    bar(220, 220, 538, 238);  
    rectangle(220, 220, 538, 238);
    bar(220, 260, 538, 278); 
    rectangle(220, 260, 538, 278);
    bar(220, 300, 538, 318); 
    rectangle(220, 300, 538, 318);
    bar(220, 340, 538, 358); 
    rectangle(220, 340, 538, 358);
    //print labels
    settextstyle(0,0,0);
    outtextxy(220,210,"Book ID number:");
    outtextxy(220,250,"Book Title: ");
    outtextxy(220,290,"Book ISBN:");
    outtextxy(220,330,"Book Author:");
    //register button
    setfillstyle(9,CYAN);
    bar(343, 382, 422, 397);
    setfillstyle(1,LIGHTGRAY);
    bar(345, 380, 420, 395);
    rectangle(345, 380, 420, 395);
    outtextxy(351,  385, "REGISTER");
}

#endif