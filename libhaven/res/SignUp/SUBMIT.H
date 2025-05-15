#ifndef SIGNUP_SUBMIT_H
#define SIGNUP_SUBMIT_H

int signup_submit(char fullname[35], char idnum[6], char email[35], char contactnum[11], char password[35])
{

  // utility variables
  int errors = 0, i=150;
  char f_idnum[7];
  char f_password[37];
  FILE *userlist, *userdata;
  char userdatafile[34];
  
  // reset error field
  setfillstyle(1, LIGHTBLUE);

  // test fields
  setcolor(RED);
  if (!strlen(fullname)){outtextxy(380, 180, "Invalid Name");errors++;}
    else{bar(300, 180, 600, 189);};
  if (strlen(idnum)<6){outtextxy(395, 220, "Invalid ID");errors++;}
    else{bar(300, 220, 600, 229);};
  if (!strlen(email)||!checksubstring(email,"@")){outtextxy(373, 260, "Invalid email");errors++;}
    else{bar(300, 260, 600, 269);};
  if (strlen(contactnum)<11){outtextxy(305, 300, "Invalid Contact Number");errors++;}
    else{bar(300, 300, 600, 309);};
  if (!strlen(password)){outtextxy(350, 340, "Invalid Password");errors++;}
    else{bar(300, 340, 600, 349);};
  if (errors)
  {
    setcolor(BLACK);
    return 1;
  };
  
  // test if id is available
  userlist = fopen(userlistfile, "r");
  if (userlist == NULL){return 1;};

  //Check whether Id is aleardy used by another account
  while (fscanf(userlist, " %6[^|]|%*s", f_idnum) == 1)
  {
    if (strcmp(f_idnum, idnum)){continue;};
    outtextxy(300, 220, "Id is not available");setcolor(BLACK);
    fclose(userlist);
    return 1;
  };
  
  //Open Data files then right the details of the new user
  sprintf(userdatafile, "c:/libhaven/users/%s.txt", idnum);
  userdata = fopen(userdatafile, "w");
  if(userdata == NULL){fclose(userlist);return 1;};
  fprintf(userdata, "%s\n%s\n%s",fullname, email, contactnum);
  userlist = fopen(userlistfile, "a");
  fprintf(userlist, "%s|%s\n", idnum, password);
  
  //Close the files
  fclose(userdata);
  fclose(userlist);
  strcpy(currentUser,idnum);
  
  //sHOW confirmation message
  
  while (i < 400){sound(i);delay(50);i += 50;};
  delay(150);nosound();
  hidemouse();
  setcolor(BLACK);
  settextstyle(2,0,4);
  setfillstyle(1,LIGHTGRAY);
  bar(10,10,629,469);
  rectangle(10,10,629,469);
   
  setfillstyle(1,GREEN);setlinestyle(0,0,3);
  fillellipse(319, 100, 50,50);
  settextstyle(0,0,8);
  outtextxy(305,80,"/");
  settextstyle(0,0,3);
  outtextxy(285,105,"\\");
  outtextxy(285,106,"\\");  
  outtextxy(285,109,"\\");
  outtextxy(285,112,"\\");
  outtextxy(285,115,"\\");
  setlinestyle(0,0,1);
  setcolor(BLACK);
  settextstyle(0,0,2);
  outtextxy(120, 200, "USER SUCESSFULLY REGISTERED");
  outtextxy(305,260,"OK");
  rectangle(280, 245, 359, 287);
  showmouse();
  //Await Confirmation
  while(1)
  {
    updatemouse();
    if((mouseX > 280 && mouseX < 359)&&(mouseY > 245 && mouseY < 287))
    {
      hidemouse();setcolor(WHITE);
      outtextxy(305,260,"OK");showmouse();
      while((mouseX > 280 && mouseX < 359)&&(mouseY > 245 && mouseY < 287))
      {
        if(mouseButton == 1){home();};
        updatemouse();
      }
      hidemouse();setcolor(BLACK);
      outtextxy(305,260,"OK");showmouse();
    }  
  }
}

#endif
