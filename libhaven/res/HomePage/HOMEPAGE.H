#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "libhaven/res/homepage/draw.h"

int home(){
 cleardevice();
 hidemouse();
 draw_logo();
 draw_user_main();

 getch();
 closegraph();
 return 0;
}
#endif
