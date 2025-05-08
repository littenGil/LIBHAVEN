#ifndef LOGIN_SUBMIT_H
#define LOGIN_SUBMIT_H

int login_submit(const char *idnum, const char *password)
{
//utility variables
  int i = 150;char fidnum[7], fpassword[37];FILE *userlist;

//reset error field
  setfillstyle(1,LIGHTBLUE);bar(239,175,600,185);bar(239,235,600,243);
   
//open userlist file
  userlist = fopen(userlistfile, "r");if (userlist == NULL){return 1;};

//check if user exist
  while (fscanf(userlist, " %6[^|]|%35[^\n]s", fidnum, fpassword) == 2)
  {
    if (strcmp(idnum, fidnum) == 0)
    {
//check if password matched idnum
       if (strcmp(password, fpassword) == 0)
       {
          while (i < 400){sound(i);delay(50);i += 50;};
          delay(150);nosound();fclose(userlist);
          strcpy(currentUser,idnum);hidemouse();home();return 1;
       }
       else
       {
          setcolor(RED);outtextxy((639 / 2) - (639 / 8), (380 / 2) + 45, "WRONG PASSWORD");
          setcolor(BLACK);fclose(userlist);return 0; 
       }
    }
  }

//error message for unregistered user
  setcolor(RED);outtextxy((639 / 2) - (639 / 8), (380 / 2) - 15, "NO RECORDS FOUND");
  setcolor(BLACK);fclose(userlist);return 0;  
}

#endif