#ifndef MOUSE_H
#define MOUSE_H
union REGS in, out; // registers
int mouseX = 0, mouseY = 0, mouseButton = 0; //Global Mouse Variables


int showmouse() // set up and show mouse pointer
{
    in.x.ax = 1;
    int86(51, &in, &out);
    return 0;
};

int hidemouse() // hide mouse   (! use before drawing anything to prevent black spots)
{
    in.x.ax = 2;
    int86(51, &in, &out);
    return 0;
};

int updatemouse() // update mouse variables by sending request to bios 
{
    in.x.ax = 3;
    int86(51, &in, &out);
    mouseButton = out.x.bx;
    mouseX = out.x.cx;
    mouseY = out.x.dx;
    return 0;
};
#endif