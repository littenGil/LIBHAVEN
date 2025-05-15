#ifndef SIGNUP_INPUTS_H
#define SIGNUP_INPUTS_H
//Fill Up Sign up Fullname Field
void signup_getfullname(char fullname[35])
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(160, 191, 478, 209);
  showmouse();
  moveto(180, 198);
  inputtext(fullname, 35);
  setfillstyle(1, LIGHTGRAY);
  hidemouse();
  bar(160, 191, 478, 209);
  outtextxy(180, 198, fullname);
  showmouse();
}
//Fill Up Sign up idnum Field
void signup_getidnum(char idnum[6])
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(160, 231, 478, 249);
  showmouse();
  moveto(180, 238);
  inputnumtext(idnum, 6);
  setfillstyle(1, LIGHTGRAY);
  hidemouse();
  bar(160, 231, 478, 249);
  outtextxy(180, 238, idnum);
  showmouse();
}

//Fill Up Sign up Email Field
void signup_getemail(char email[35])
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(160, 271, 478, 289);
  showmouse();
  moveto(180, 279);
  inputtext(email, 35);
  setfillstyle(1, LIGHTGRAY);
  hidemouse();
  bar(160, 271, 478, 289);
  outtextxy(180, 279, email);
  showmouse();
}

//Fill Up Sign UP Contact num field
void signup_getcontactnum(char contactnum[11])
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(160,311,478,329);
  showmouse();
  moveto(180, 319);
  inputnumtext(contactnum, 11);
  setfillstyle(1, LIGHTGRAY);
  hidemouse();
  bar(160, 311, 478, 329);
  outtextxy(180, 319, contactnum);
  showmouse();
}

//Fill Up Sign Up Password Field
void signup_getpassword(char password[35], int isHidden)
{
  setfillstyle(1, WHITE);
  hidemouse();
  bar(160, 351, 478, 369);
  showmouse();
  moveto(180, 359);
  if(isHidden)
  {
      inputpassword(password, 35);
      setfillstyle(1, LIGHTGRAY);
      moveto(180, 359);
      hidemouse();
      bar(160, 351, 478, 369);
      for (int i = 0; i < strlen(password); i++){outtext("*");}
      showmouse();
  }
  else
  {
      inputtext(password, 35);
      setfillstyle(1, LIGHTGRAY);
      hidemouse();
      bar(160, 351, 478, 369);
      outtextxy(180, 359,password);
      showmouse();
  }
}

#endif

/*





*/