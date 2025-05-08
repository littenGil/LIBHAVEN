#ifndef DISPLAY_DRAW_H
#define DISPLAY_DRAW_H


void draw_display_tab()
{
    /*
      Draws UI for the Display Book Tab
    */
    
    //Setup
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
    
    //Catalog
    setfillstyle(1,LIGHTGRAY);
    bar(155, 220 ,604, 414);
    rectangle(155, 220 ,604, 414);
    
    //Search Bar
    setlinestyle(0,0,1);
    bar(155, 165, 604, 185);
    rectangle(155, 165, 604, 185);
    setcolor(DARKGRAY);
    circle(165, 175, 3);
    line(162,178, 160,180);
    settextstyle(0,0,1);
    
    //labels & Separator
    outtextxy(170, 172, "SEARCH: "); 
    outtextxy(241, 172, bookSearch);    
    setcolor(BLACK);
    outtextxy(270,210,"TITLE");
    outtextxy(500, 210,"STATUS");
    line(450, 220, 450,414);
    line(155, 236, 604,236);
    line(155, 252, 604,252);
    line(155, 268, 604,268);
    line(155, 284, 604,284);
    line(155, 300, 604,300);
    line(155, 316, 604,316);
    line(155, 332, 604,332);
    line(155, 348, 604,348);
    line(155, 364, 604,364);
    line(155, 380, 604,380);
    line(155, 396, 604,396);
}

void display_catalog(int numBooks,char bookCatalog[12][7])
{
    /*
      Display the books that are in the catalog
    */
    //Variables
    int i, status;FILE *book;char bookpath[35], title[35];
    
    //Loop through the catalog then print title and the status of the books
    for(i=0;i<numBooks;i++)
    {
       sprintf(bookpath,"c:/libhaven/books/%s.txt", bookCatalog[i]);
       book = fopen(bookpath,"r");
       fscanf(book," %35[^\n]s", title);
       outtextxy(165, 225+(i*16), title);
       fclose(book);
       
       //display status //check if book exist in lost or borrowed
       sprintf(bookpath,"c:/libhaven/borrowed/%s.txt", bookCatalog[i]);book=fopen(bookpath, "r");
       if(book!=NULL){fclose(book);setcolor(BLUE);outtextxy(490, 225+(i*16), "Borrowed");setcolor(BLACK);continue;}
       fclose(book);
       setcolor(GREEN);outtextxy(490, 225+(i*16), "Available");setcolor(BLACK);
    }
}

#endif