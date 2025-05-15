#ifndef ADDBOOK_SUBMIT_H
#define ADDBOOK_SUBMIT_H

void addbook_submit(char bookID[7], char title[37], char ISBN[11], char author[30])
{
   //Variables
   int error=0, IDexist=0,inserted=0,i=150;
   char fbookID[8], filepath[30], tempbookTitle[37];
   char booklistfile[] = "c:/libhaven/books/list.txt";
   FILE *booklist,*tempbooklist, *book;
   
   //Check if id is already used
   delay(500);
   booklist = fopen(booklistfile, "r");
   while(fscanf(booklist, " %6s", fbookID)==1)
   {
    if(strcmpi(fbookID, bookID)==0){IDexist=1;break;}
   }
   fclose(booklist);
   
   //Check if inputs are valid
   setfillstyle(1,CYAN);setcolor(RED);
   if(IDexist){outtextxy(372,210,"ID number unavailable");error++;}
     else{bar(372,210,538,218);}
   if(strlen(bookID) != 6){outtextxy(400,210,"Invalid ID number");error++;};
   if(!strlen(title)){outtextxy(345,250,"This field cant be empty");error++;}
     else{bar(345,250,538,258);}
   if(!strlen(ISBN)){outtextxy(440,290,"Invalid ISBN");error++;}
     else{bar(440,290,538,298);}
   if(!strlen(author)){outtextxy(
   345,330,"This field cant be empty");error++;}
     else{bar(345,330,538,338);}
   if(error){setcolor(BLACK);return;}
   
   //Append new book at a sorted list
   booklist = fopen(booklistfile, "r");
   tempbooklist = fopen("c:/libhaven/books/temp.txt", "w");
   while(fscanf(booklist, " %6s", fbookID)==1)
   {
    sprintf(filepath, "c:/libhaven/books/%s.txt", fbookID);
    book = fopen(filepath,"r");if(book==NULL){continue;}
    fscanf(book, " %35[^\n]s", tempbookTitle);
    
     //sort book by title then save it to temp file
    if(strcmpi(tempbookTitle, title)>0&& !inserted)
    {
        fprintf(tempbooklist, "%s\n", bookID);
        inserted = 1;
    }
    fprintf(tempbooklist, "%s\n", fbookID);
    fclose(book);continue;
   }
   if(!inserted){fprintf(tempbooklist, "%s\n", bookID);}
  
   //save temp file  
   fclose(booklist);
   fclose(tempbooklist);
   remove(booklistfile);
   rename("c:/libhaven/books/temp.txt", booklistfile);
   
   sprintf(filepath, "c:/libhaven/books/%s.txt", bookID);
   book = fopen(filepath, "w");
   fprintf(book,"%s\n%s\n%s", title, ISBN,author);
   fclose(book);
   
   //Show confirmation message
   while (i < 400){sound(i);delay(50);i += 50;};
   delay(150);nosound();
   hidemouse();
   setcolor(BLACK);
   settextstyle(2,0,4);
   setfillstyle(1,LIGHTGRAY);
   bar(151, 151, 608, 448);
   rectangle(152, 152, 607, 447);
   bar(151, 151, 608, 448);
   rectangle(152, 152, 607, 447);
   rectangle(35, 200, 152, 216);
   bar(36, 201, 153, 215);
   outtextxy(42, 203, "ADD BOOK");
   setfillstyle(1,GREEN);setlinestyle(0,0,3);
   fillellipse(380, 220, 25,25);
   line(363,220,375,235);line(365,220,377,237);
   line(395,210,375,235);line(398,210,377,236);
   setlinestyle(0,0,1);
   setcolor(BLACK);
   settextstyle(0,0,2);
   outtextxy(160, 270, "BOOK SUCESSFULLY REGISTERED");
   outtextxy(363,320,"OK");
   rectangle(350, 317, 410, 336);
   showmouse();
   //await confirmation
   while(1)
   {
     updatemouse();
     if((mouseX > 350 && mouseX < 410)&&(mouseY > 317 && mouseY < 336))
     {
         hidemouse();setcolor(WHITE);
         outtextxy(363,320,"OK");showmouse();
         while((mouseX > 350 && mouseX < 410)&&(mouseY > 317 && mouseY < 336))
         {
             if(mouseButton == 1){longjmp(Jaddbook,0);};
             updatemouse();
         }
         hidemouse();setcolor(BLACK);
         outtextxy(363,320,"OK");showmouse();
     }
     if((mouseX < 151 || mouseX > 608)||(mouseY < 151 || mouseY > 448))
     {
         if(mouseButton == 1){addbook();};
     }
   }
}
#endif