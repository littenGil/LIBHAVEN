#ifndef HOMEPAGE_SEEPROFILE_H
#define HOMEPAGE_SEEPROFILE_H

void seeprofile()
{
  char userdatafilepath[35], Text[37];
  FILE *userdatafile;
  hidemouse();
  setcolor(BLACK);setfillstyle(1,LIGHTRED);
  bar(35,180,150,256);line(148,180,148,256); line(150,180,150,256);
  setfillstyle(1, LIGHTGRAY);
  settextstyle(2,0,4);
  //Side Bar
  bar(35, 180, 145, 196);
  rectangle(35, 180, 145, 196);
  outtextxy(42, 183, "DISPLAY BOOKS");
  bar(35, 200, 145, 216);
  rectangle(35, 200, 145, 216);
  outtextxy(42, 203, "ADD BOOK");
    
  //COntainer
  settextstyle(2,0,4);setfillstyle(1,CYAN);
  bar(151, 151, 608, 448);
  rectangle(152, 152, 607, 447);
  rectangle(35, 220, 152, 236);
  bar(36, 221, 153, 235);
  outtextxy(42, 223, "SEE PROFILE");
  settextstyle(1,0,3);
  outtextxy(275, 170, "LIBRARIAN PROFILE");

    
  //print labels
  settextstyle(0,0,0);
  outtextxy(220,240,"     ID #:");
  outtextxy(220,261,"     Name: ");
  outtextxy(220,282,"    Email:");
  outtextxy(220,303,"Contact #:");
    
  //Fetch Information
  sprintf(userdatafilepath,"c:/libhaven/users/%s.txt", currentUser);
  userdatafile=fopen(userdatafilepath, "r");
    
  //Id number
  outtextxy(320,240, currentUser);
  //Fullname
  fscanf(userdatafile," %[^\n]s", Text);
  outtextxy(320,261,Text);
  //Email
  fscanf(userdatafile," %[^\n]s", Text);
  outtextxy(320,282,Text);
  //Contact #
  fscanf(userdatafile," %[^\n]s", Text);
  outtextxy(320,303,Text);
  
  fclose(userdatafile);
  showmouse();
  
  while(1)
  {
    updatemouse();
    //SIDE BAR
      if(mouseX>35&&mouseX<145)
      {
        //DISPLAY BOOKS
        if(mouseY>180 && mouseY<196)
        {
          hidemouse();setcolor(WHITE);settextstyle(2,0,4);  
          outtextxy(42, 183, "DISPLAY BOOKS");
          showmouse();
          while((mouseX>35&&mouseX<145)&&(mouseY>180 && mouseY<196))
          {
	    if(mouseButton == 1){if(setDisplaybooks!=0){longjmp(Jdisplaybooks,1);};displaybooks(0);}
            updatemouse();
          }
          hidemouse();setcolor(BLACK);
          outtextxy(42, 183, "DISPLAY BOOKS");settextstyle(0,0,0);
          showmouse();
        }
      
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
    }
}


#endif