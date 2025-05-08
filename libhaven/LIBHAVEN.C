#include"libhaven\res\GEN_RES.h"

int main()
{
  int gdriver=DETECT, gmode;
  initgraph(&gdriver, &gmode,"C:\\TURBOC3\\BGI");
  bootup();
  closegraph();
  return 0;
}
