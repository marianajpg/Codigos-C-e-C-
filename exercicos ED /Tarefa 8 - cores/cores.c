/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void black() {
  printf("\033[0;30m");
}

void green() {
  printf("\033[0;32m");
}

void blue() {
  printf("\033[0;34m");
}

void purple() {
  printf("\033[0;35m");
}

void cyan() {
  printf("\033[0;36m");
}
void white() {
  printf("\033[0;37m");
}

void red() {
  printf("\033[1;31m");
}

void yellow(){
  printf("\033[1;33m");
}

void reset() {
  printf("\033[0m");
}

int main () {
  red();
  printf("█"); 
  yellow();
  printf("█");
  reset();
  return 0;
}


