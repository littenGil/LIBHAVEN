#ifndef GEN_INPUT_H
#define GEN_INPUT_H

// Scan Text
int inputtext(char *string, int limit)
{
  delay(150);
  int i = strlen(string);
  char key, feedback[1];
  if (i != 0){hidemouse();outtext(string);showmouse();};
  while (1)
  {
    if (kbhit())
    {
      key = getch();
      if (key == '|'){key = ':';};
      if (key == '\r' || key == '\t'){return 0;}
      if (key == '\b')
      {
         if (i == 0){continue;};
         string[--i] = '\0';
         hidemouse();
         bar(getx(), gety(), getx() - textwidth("H"), gety() + textheight("H"));
         showmouse();
         moveto(getx() - textwidth("H"), gety());
      }
      else if (i < limit)
      {                    
        string[i++] = key;       
        string[i] = '\0';
        sprintf(feedback, "%c", key); 
        hidemouse();
        outtext(feedback);
        showmouse();
      };
    }
    updatemouse();  
    if(mouseButton==1){return 0;}
  }
};

// scan Password
int inputpassword(char *string, int limit)
{
  delay(150);
  int j, i = strlen(string);hidemouse();
  for (j = 0; j < i; j++){outtext("*");}
  showmouse();
  char key;
  while (1)
  {
    if (kbhit())
    {
      key = getch();
      if (key == '|'){key = ':';}
      if (key == '\r' || key == '\t'){return 0;}
      if (key == '\b')
      {
	    if (i == 0){continue;};
        string[--i] = '\0';
        hidemouse();
        bar(getx(), gety(), getx() - textwidth("H"), gety() + textheight("H"));
        showmouse();
        moveto(getx() - textwidth("H"), gety());
      }
      else if (i < limit)
      {
        string[i++] = key;
        string[i] = '\0';
        hidemouse();
        outtext("*");
        showmouse();
      };
    }
    updatemouse();  
    if(mouseButton==1){return 0;}
  }
};

// scan text but number inputs only
int inputnumtext(char *string, int limit) 
{
  delay(150);
  int i = strlen(string);
  char key, feedback[1];
  if (i != 0){hidemouse();outtext(string);showmouse();};
  while (1)
  {
    if (kbhit())
    {
      key = getch();
      if (key == '\r' || key == '\t'){return 0;};
      if (key == '\b')
      {
        if (i == 0){continue;};
        string[--i] = '\0';
        hidemouse();
        bar(getx(), gety(), getx() - textwidth("H"), gety() + textheight("H"));
        showmouse();
        showmouse();
        moveto(getx() - textwidth("H"), gety());
      }
      if (key >= '0' && key <= '9')
      {
        if (i>=limit){continue;};
          string[i++] = key;
          string[i] = '\0';
          sprintf(feedback, "%c", key);
          hidemouse();
          outtext(feedback);
          showmouse();
          continue;
      }
    }
    updatemouse();  
    if(mouseButton==1){return 0;}
  }
};

//Check if string 2 is a substring of string 1
int checksubstring(char string1[], char string2[])
{
    int i, j, found;
    for (i = 0; string1[i] != '\0'; i++)
    {
     found = 1;
     for (j = 0; string2[j] != '\0'; j++) 
     {
       if (tolower(string1[i + j]) != tolower(string2[j])){found = 0;break;}
     }
     if (found && string2[j] == '\0') {return 1;}
    }
    return 0;
}

//Update the date
void updateDate()
{
    struct date datetoday;
    struct time timenow;
    char time[]="AM";
    char months[12][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE","JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    getdate(&datetoday);
    gettime(&timenow);
    if(timenow.ti_hour>12){strcpy(time,"PM");}
    sprintf(currDate, "%s %d, %d | (%d:%2d %s)", months[datetoday.da_mon - 1], datetoday.da_day, datetoday.da_year, timenow.ti_hour%12, timenow.ti_min,time);
}

#endif