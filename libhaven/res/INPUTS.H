#ifndef GEN_INPUT_H
#define GEN_INPUT_H
//Scan Text
int inputtext(char *string, int limit)   //use in place of scanf and gets for string input
{
   int i = strlen(string);char key, feedback[1];
   if(i != 0){outtext(string);} 
   while(1){
     if(kbhit()){
       key = getch();
       if(key == '|'){key = ':';};
       if(key == 0 || key == (char)255){
           key=getch(); if(key == 72 || key == 80){string[i] = '\0';return 0;}}
       else if(key == '\r' || key == '\t'){string[i] = '\0';return 0;}
       else if(key == '\b'){if(i!=0){
           string[--i] = '\0';
           bar(getx(), gety(), getx()-textwidth("H"),gety()+textheight("H"));
           moveto(getx()-textwidth("H"), gety());}}
       else  if(i<=limit){
           string[i++] = key;sprintf(feedback, "%c", key);outtext(feedback);};}
   }
};

//scan Password
int inputpassword(char *string, int limit)   //like inputtext() but with privacy protection
{
 int i = strlen(string);
 for(int j = 0; j < i; j++){outtext("*");}
 char key;  
   while(1){
     if(kbhit()){
       key = getch();
       if(key == '|'){key = ':';};
       if(key == 0 || key == (char)255){
         key=getch(); if(key == 72 || key == 80){string[i] = '\0';return 0;}}
       else if(key == '\r' || key == '\t'){string[i] = '\0';return 0;}
       else if(key == '\b'){if(i!=0){
           string[--i] = '\0';
           bar(getx(), gety(), getx()-textwidth("H"),gety()+textheight("H"));
           moveto(getx()-textwidth("H"), gety());}}
       else  if(i<=limit){string[i++] = key;outtext("*");};}
   }
};





//scan text but number inputs only
int inputnumtext(char *string, int limit)   //use in place of scanf and gets for string input
{
   int i = strlen(string), dot = 0;char key, feedback[1];
   if(i != 0){outtext(string);} 
   while(1){
     if(kbhit()){
       key = getch();
       if(key == 0 || key == (char)255){
           key=getch(); if(key == 72 || key == 80){string[i] = '\0';return 0;}}
       else if(key == '\r' || key == '\t'){string[i] = '\0';return 0;}
       else if(key == '\b'){if(i!=0){
           if(string[i-1] == '.'){ dot = 0;}
           string[--i] = '\0';
           bar(getx(), gety(), getx()-textwidth("H"),gety()+textheight("H"));
           moveto(getx()-textwidth("H"), gety());}}
       else if(key >= '0' && key <= '9'){
         if(i<=limit){string[i++] = key;sprintf(feedback, "%c", key);outtext(feedback);};}
       else if(key == '.' && dot == 0){
         if(i<=limit){dot=1;string[i++] = key;sprintf(feedback, "%c", key);outtext(feedback);};};}    
   }
};

//scan integers numbers 
int inputinteger(int limit)
{
    char inttext[16];
    inputnumtext(inttext, limit);
    return atoi(inttext); 
}

//scan float numbers
float inputfloat(int limit)
{
    char floattext[16];
    inputnumtext(floattext, limit);
    return atof(floattext); 
}

#endif