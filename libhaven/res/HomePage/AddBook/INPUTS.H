#ifndef ADDBOOK_INPUTS_H
#define ADDBOOK_INPUTS_H

//Input for bookID
void addbook_getBookID(char bookID[7])
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(221, 221, 537, 237); 
  showmouse();
  moveto(241, 225);
  inputnumtext(bookID, 6);
  setfillstyle(1, LIGHTGRAY);
  hidemouse();
  bar(221, 221, 537, 237); 
  outtextxy(241, 225, bookID);
  showmouse();
}

//Input for Title
void addbook_getBookTitle(char title[37])
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(221, 261, 537, 277); 
  showmouse();
  moveto(241, 265);
  inputtext(title, 35);
  setfillstyle(1, LIGHTGRAY);
  hidemouse();
  bar(221, 261, 537, 277);
  outtextxy(241, 265, title);
  showmouse();
}

//Input for International Serial Book Number
void addbook_getBookISBN(char ISBN[11])
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(221, 301, 537, 317); 
  showmouse();
  moveto(241, 305);
  inputnumtext(ISBN, 11);
  setfillstyle(1, LIGHTGRAY);
  hidemouse();
  bar(221, 301, 537, 317); 
  outtextxy(241, 305, ISBN);
  showmouse();
}

//Input for Author
void addbook_getBookAuthor(char author[35])
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(221, 341, 537, 357);  
  showmouse();
  moveto(241, 345);
  inputtext(author, 35);
  setfillstyle(1, LIGHTGRAY);
  hidemouse();
  bar(221, 341, 537, 357);
  outtextxy(241, 345, author);
  showmouse();
}

#endif