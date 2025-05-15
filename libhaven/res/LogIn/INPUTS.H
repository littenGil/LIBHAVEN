#ifndef LOGIN_INPUTS_H

#define LOGIN_INPUTS_H

//get ID
void login_getidnum(char idnum[6])
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(160, 191, 478, 209);
  showmouse();
  moveto(180, 198);
  inputnumtext(idnum, 6);
  setfillstyle(1, LIGHTGRAY);
  hidemouse();
  bar(160, 191, 478, 209);
  outtextxy(180, 198, idnum);
  showmouse();
}

//Get password
void login_getpassword(char password[35], int isHidden)
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(160, 251, 478, 269);
  showmouse();
  moveto(180, 259);
  //Show and Hide password
  if(isHidden)
  {
    inputpassword(password, 35);
    setfillstyle(1, LIGHTGRAY);
    moveto(180, 259);
    hidemouse();
    bar(160, 251, 478, 269);
    for (int i = 0; i < strlen(password); i++){outtext("*");}  
    showmouse();    
  }
  else
  {
    inputtext(password, 35);
    setfillstyle(1, LIGHTGRAY);
    hidemouse();
    bar(160, 251, 478, 269);
    outtextxy(180, 259, password); 
    showmouse();    
  }
}


#endif


