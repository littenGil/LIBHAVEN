#ifndef HOMEPAGE_DISPLAY_H
#define HOMEPAGE_DISPLAY_H
#include "libhaven/res/homepage/display/draw.h"
#include "libhaven/res/homepage/display/catalog.h"
#include "libhaven/res/homepage/display/details/details.h"
void displaybooks(int offset)
{
  //variables
  int selected,prevSelected, numBooks=0, more;
  char bookCatalog[12][7];char bookpath[35];char newSearch[37];
  FILE *book;
  
  //set jump point
  if(setjmp(Jdisplaybooks)==0){setDisplaybooks=1;};
  
  //reset variables
  numBooks=0;
  memset(bookCatalog, 0, sizeof(bookCatalog));
  memset(bookpath, 0, sizeof(bookpath));
  book=NULL;
  strcpy(newSearch, bookSearch);
  //Draw interface
  hidemouse();
  draw_display_tab();
  showmouse();
  //fill up and display catalog 
  more = updatecatalog(offset, &numBooks, bookCatalog, bookSearch);
  display_catalog(numBooks,bookCatalog);
  hidemouse();
  if(more){outtextxy(550, 420, "NEXT>>");}
  if(offset>0){outtextxy(500, 420, "<<PREV");}
  showmouse();
  
  //Handle events
  while(1)
  {
    updatemouse();
    //Side Bar
    if(mouseX>35&&mouseX<145)
    {   
      //ADD BOOK
      if(mouseY>200 && mouseY<216)
      {
        hidemouse();setcolor(WHITE);settextstyle(2,0,4);  
        outtextxy(42, 203, "ADD BOOK");
        showmouse();
        while((mouseX>35&&mouseX<145)&&(mouseY>200 && mouseY<216))
        {
          if(mouseButton == 1){if(setLogin!=0){longjmp(Jaddbook,1);};addbook();}
          updatemouse();
        }
        hidemouse();setcolor(BLACK);
        outtextxy(42, 203, "ADD BOOK");settextstyle(0,0,0);
        showmouse();
      }
      
        
      //SEE PROFILE
      if(mouseY>220 && mouseY<236)
      { 
        hidemouse();setcolor(WHITE);settextstyle(2,0,4);  
        outtextxy(42, 223, "SEE PROFILE");
        showmouse();
        while((mouseX>35&&mouseX<145)&&(mouseY>220 && mouseY<236))
        {
          if(mouseButton == 1){seeprofile();}
          updatemouse();
        }
        hidemouse();setcolor(BLACK);
        outtextxy(42, 223, "SEE PROFILE");settextstyle(0,0,0);
        showmouse();
      }
      
      //LOG OUT
      if(mouseY>420 && mouseY<436)
      {
        hidemouse();setcolor(WHITE);settextstyle(2,0,4);  
        outtextxy(65, 423, "LOGOUT");
        showmouse();
        while((mouseX>35&&mouseX<145)&&(mouseY>420 && mouseY<436))
        {
          if(mouseButton == 1){strcpy(currentUser,"");login();}
          updatemouse();
        }
        hidemouse();setcolor(BLACK);
        outtextxy(65, 423, "LOGOUT");settextstyle(0,0,0);
        showmouse();
      }
      
    }
    //SearchBar bar(155, 165, 604, 185);
    if((mouseX > 155 && mouseX < 604 )&&(mouseY > 165 && mouseY < 185))
    {
       hidemouse();
       setcolor(BLACK);circle(165, 175, 3);line(162,178, 160,180);
       outtextxy(170, 172, "SEARCH: ");  
       showmouse();
       while((mouseX > 155 && mouseX <604 )&&(mouseY > 165 && mouseY < 185))
       {
          updatemouse();
          if(mouseButton == 1)
          {
                setfillstyle(1, WHITE);setcolor(BLACK);
                hidemouse();
                bar(156, 166, 603, 184);
                circle(165, 175, 3);line(162,178, 160,180);
                outtextxy(170, 172, "SEARCH: ");  
                showmouse();
                moveto(241, 172);
                inputtext(newSearch, 35);
                if(strcmp(newSearch, bookSearch) != 0)
                {
                  strcpy(bookSearch, newSearch);
                  longjmp(Jdisplaybooks,1);
                }
          }
       }
       hidemouse();
       setcolor(DARKGRAY);circle(165, 175, 3);line(162,178, 160,180);
       outtextxy(170, 172, "SEARCH: ");  
       showmouse();
    }

    //Catalog
    if((mouseX > 155 && mouseX < 604)&&(mouseY>220 &&mouseY<413))
    {
        updatemouse();
        selected = ((mouseY - 221) * 12)/(413 - 221);
        prevSelected = selected;
        if(selected >= numBooks){continue;};
        setcolor(WHITE);
        hidemouse();
        sprintf(bookpath,"c:/libhaven/books/%s.txt", bookCatalog[selected]);
        book = fopen(bookpath,"r");
        fscanf(book," %35[^\n]s", bookpath);
        outtextxy(165, 225+(selected*16), bookpath);
        fclose(book);
        setcolor(BLACK);
        showmouse();
        while((selected == prevSelected) && ((mouseX > 155 && mouseX < 604)&&(mouseY>221 &&mouseY<413)))
        {
            updatemouse();
            selected = ((mouseY - 221) * 12)/(413 - 221);
            if(mouseButton == 1){bookdetails(bookCatalog[selected]);longjmp(Jdisplaybooks,1);};
        }
        hidemouse();
        display_catalog(numBooks,bookCatalog);
        showmouse();
    }
    //Next page
      if(((mouseX > 550 && mouseX < 600)&&(mouseY>420 && mouseY<426))&&more)
      {
        setcolor(WHITE);hidemouse();outtextxy(550, 420, "NEXT>>");showmouse();
        while((mouseX > 550 && mouseX < 600)&&(mouseY>420 && mouseY<426))
        {
           updatemouse();
           if(mouseButton==1){displaybooks(offset+12);}
         }
         setcolor(BLACK);hidemouse();outtextxy(550, 420, "NEXT>>");showmouse();
      }
    //Previous
      if(((mouseX > 500 && mouseX < 545)&&(mouseY>420 && mouseY<426))&&offset)
      {
        setcolor(WHITE);hidemouse();outtextxy(500, 420, "<<PREV");showmouse();
        while((mouseX > 500 && mouseX < 545)&&(mouseY>420 && mouseY<426))
        {
           updatemouse();
           if(mouseButton==1){displaybooks(offset-12);}
         }
         setcolor(BLACK);hidemouse();outtextxy(500, 420, "<<PREV");showmouse();
      }
  }
}
 
#endif