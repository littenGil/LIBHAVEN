#ifndef LOGIN_SUBMIT_H
#define LOGIN_SUBMIT_H

int login_submit(char username[36], char password[36])
{
//utility variables
  int i = 150;char f_username[36];char f_password[36];
  
//reset error field
  setfillstyle(1,LIGHTBLUE);bar(239,175,600,185);bar(239,235,600,243);
  
//open userlist file
  FILE *userlist = fopen(userlistfile, "r");if (userlist == NULL){return 1;};

//check if user exist
  while (fscanf(userlist, " %35[^|]|%35s", f_username, f_password) == 2){
  if (strcmp(username, f_username) == 0){
//check if password matched username1
  if (strcmp(password, f_password) == 0){while (i < 400){sound(i);delay(50);i += 50;}
  delay(150);nosound();fclose(userlist);home();return 0;}

//error message for wrong password
  else{setcolor(RED);outtextxy((639 / 2) - (639 / 8), (380 / 2) + 45, "WRONG PASSWORD");
  setcolor(BLACK);fclose(userlist);return 1; }}}

//error message for unregistered user
  setcolor(RED);outtextxy((639 / 2) - (639 / 8), (380 / 2) - 15, "NO RECORDS FOUND");
  setcolor(BLACK);fclose(userlist);return 1;  
}

#endif