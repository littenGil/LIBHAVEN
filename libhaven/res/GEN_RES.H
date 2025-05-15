#ifndef GEN_RES_H
#define GEN_RES_H

// BASIC INCLUDES
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dos.h>
#include <time.h>
#include <dir.h>
#include <setjmp.h>

//Global Variables and Constants
char currentUser[7]={0},bookSearch[35]={0};
char TITLE[] = "LIBHAVEN", SUBTITLE[] = "Learn in Comfort";
char userlistfile[] = "c:/libhaven/users/list.txt";
char booklistfile[] = "c:/libhaven/books/list.txt";
char catalog[170][6];
char currDate [20];
int numCatalogBooks=0;

//Input Util
#include "libhaven/res/mouse.h"
#include "libhaven/res/inputs.h"

//Functions for pages
int login();
int signup();
int home();
void addbook();
void displaybooks(int offset);  
void seeprofile();

//Jump setters to prevent
jmp_buf Jaddbook,Jdisplaybooks,Jseeprofile;

//Checker for jumps
int setLogin = 0;
int setSignup = 0;
int setHome = 0;
int setDisplaybooks = 0;
int setAddbook = 0;
int setSeeprofile = 0;
 
//link to pages
#include "libhaven\res\draw.h"
#include "libhaven\res\homepage\homepage.h"
#include "libhaven\res\login\login.h"
#include "libhaven\res\bootup\bootup.h"

#endif
