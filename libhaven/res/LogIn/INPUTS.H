#ifndef LOGIN_INPUTS_H
#define LOGIN_INPUTS_H

void login_getusername(char username[36])
{
//get user input
  hidemouse();setfillstyle(1, WHITE);bar(160, 191, 478, 209);
  moveto(180,198);inputtext(username, 35);
//close user input
  setfillstyle(1, LIGHTGRAY);bar(160, 191, 478, 209);
  outtextxy(180,198, username);
};

void login_getpassword(char password[36])
{
//get user input
  hidemouse();setfillstyle(1, WHITE);bar(160, 251, 478, 269);;
  moveto(180,259);inputpassword(password, 35);
//close user input
  setfillstyle(1, LIGHTGRAY);bar(160, 251, 478, 269);
  moveto(180, 259);
  for(int i = 0; i < strlen(password); i++){
      outtext("*");}
};


#endif