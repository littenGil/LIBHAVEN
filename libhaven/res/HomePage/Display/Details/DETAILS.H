#ifndef BOOKDETAILS_H
#define BOOKDETAILS_H

#include "libhaven/res/homepage/display/details/draw.h"
void bookdetails(const char bookID[7])
{
  //variables
  int status=0;
  char text[50],textbuff[37],bookpath[35], recordpath[35], fbookID[7], borrower[35]={0};
  FILE *book, *record, *booklist, *temp;
  
  //bookfile
  sprintf(bookpath, "c:/libhaven/books/%s.txt", bookID);
  book=fopen(bookpath, "r");
  
  //status checker
  sprintf(recordpath, "c:/libhaven/borrowed/%s.txt", bookID);
  record=fopen(recordpath, "r");
  if(record != NULL){ status = 1;}
  
  //common display
  hidemouse();
  draw_bookdetails(status);
  sprintf(text, "Book ID     : %s", bookID);
  outtextxy(200,220, text);
  fscanf(book, " %[^\n]", textbuff);
  sprintf(text, "Title       : %s",textbuff);
  outtextxy(200,240, text);
  fscanf(book, " %[^\n]", textbuff);
  sprintf(text, "ISBN        : %s",textbuff);
  outtextxy(200,260, text);
  fscanf(book, " %[^\n]", textbuff);
  sprintf(text, "Author      : %s",textbuff);
  outtextxy(200,280, text);
  fclose(book);
  //Print Borrow Information
  if(status == 1)
  {
    fscanf(record, " %35[^\n]", textbuff);
    sprintf(text,"Issued to   : %s",textbuff);
    outtextxy(200,320, text);
    
    fscanf(record, " %35[^\n]", textbuff);
    sprintf(text,"Date Issued : %s",textbuff);
    outtextxy(200,340, text);
    fclose(record);
  }
  showmouse();
  
  //User inputs
  while(1)
  {
     updatemouse();
     //Exit 
     if(((mouseX < 151 || mouseX > 608) || (mouseY <151 || mouseY > 448))&&mouseButton==1){longjmp(Jdisplaybooks,1);};
     if(((mouseX > 580 && mouseX < 601) && (mouseY > 154 && mouseY < 171))&&mouseButton==1){longjmp(Jdisplaybooks,1);};
     
     //DELETE
     if(((mouseX > 446 && mouseX < 512) && (mouseY > 400 && mouseY < 426))&&mouseButton==1)
     {
       //Remove files
       remove(bookpath);
       remove(recordpath);
       //Remove from list
       booklist = fopen(booklistfile, "r");
       temp = fopen("c:/libhaven/books/temp.txt", "w");
       while(fscanf(booklist, " %6s", fbookID)==1)
        {
           if(!strcmp(bookID, fbookID))
           {
            continue;
           }
           fprintf(temp, "%s\n", fbookID);
       }       
       delay(150);
       fclose(booklist);
       fclose(temp);
       remove(booklistfile);
       rename("c:/libhaven/books/temp.txt", booklistfile);
       longjmp(Jdisplaybooks,1);
     };
     
     //IF available
     if(status == 0)
     {
       //Borrowers text field
       if(((mouseX > 275 && mouseX < 598) && (mouseY > 345 && mouseY < 365))&&mouseButton==1)
       {
  
         hidemouse();
         setfillstyle(1,WHITE);
         bar(276,346,597,364);
         moveto(280,352);
         showmouse();
         inputtext(borrower, 35);
         hidemouse();
         setfillstyle(1,LIGHTGRAY); 
         bar(276,346,597,364);
         outtextxy(280,352,borrower);     
         showmouse();         
       }
       //Issue Button
       if(((mouseX > 532 && mouseX < 598) && (mouseY > 400 && mouseY < 426))&&mouseButton==1)
       {
         if(strlen(borrower))
         {
           sprintf(bookpath, "c:/libhaven/borrowed/%s.txt", bookID);
           book=fopen(bookpath,"w");
           updateDate();
           fprintf(book,"%s\n%s",borrower,currDate);
           fclose(book);
           longjmp(Jdisplaybooks,1);
         }
       }
     }
     
     //Return Button
     if(status == 1)
     {
       if(((mouseX > 532 && mouseX < 598) && (mouseY > 400 && mouseY < 426))&&mouseButton==1)
       {
           sprintf(bookpath, "c:/libhaven/borrowed/%s.txt", bookID);
           remove(bookpath);
           longjmp(Jdisplaybooks,1);
       }
     }  
  }
}


#endif