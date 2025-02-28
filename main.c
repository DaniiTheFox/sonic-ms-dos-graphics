#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include"SPRITES.h"
#include"BONIIGL.h"
#include"mmap.h"
struct xy{int x,y;
	  int alx,aly;
	  }player;
int bck = 79; int dir = 0;
int main(){
 asm{mov ax,0x13
     int 0x10}
 char far *screen = (char far *)MK_FP(0xa000,0);
 player.x = 160; player.y = 100;
 char key;
 do{
  cls(screen,bck);
  player.alx = player.x-8;
  player.aly = player.y-8;
  // all map goes here
   drawMap(map,0,100,50,screen);
  // all map goes here
  switch(dir){
   case 1:drawImage(r_bon,player.alx,player.aly,50,screen);break;
   case 0:drawImage(l_bon,player.alx,player.aly,50,screen);break;
  }
  if(kbhit()){
  key = getch();
  switch(key){
   case 'a':player.x-=3;dir = 0;break;
   case 'd':player.x+=3;dir = 1;break;
   case 'o':while(!kbhit());break;
   case ' ':player.y-=64;break;
   case 'p':exit(1);break;
  }
  }
   if(screen[(player.y+16)*320+(player.x-5)] == bck && screen[(player.y+16)*320+(player.x+5)] == bck){
    player.y++;
   }
   if(screen[(player.y+16)*320+(player.x-5)] != bck || screen[(player.y+16)*320+(player.x+5)] != bck){
   player.y--;
   }
  }while(1);
 asm{mov ax,0x03
     int 0x10}
 return 0;
}
