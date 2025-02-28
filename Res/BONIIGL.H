//main drawing functions
void cls(char far *s,int c){ // c is the background color to use
 for(int y = 0 ; y < 200 ; y++){
  for(int x = 0 ; x < 320 ; x++){
   s[y*320+x]=c;
  }
 }
}

void linedraw(int x1,int y1,int x2,int y2,int color,char far *scn){
 int ux,uy;
 int pixpos = y1*320+x1;
 int ydif = y2-y1;
 if(ydif < 0){
  ydif = ydif*-1;
  uy = -320;
 }else{uy = 320;}
 int xdif = x2-x1;
 if(xdif < 0){
  xdif = xdif * -1;
  ux = -1;
 }else{ux = 1;}
 int onerror=0;int len;
 if(xdif>ydif){
  len=xdif+1;
  for(int i = 0 ; i < len ; i++){
   scn[pixpos]=color;
   pixpos+=ux;
   onerror+=ydif;
   if(onerror>xdif){
    onerror-=xdif;
    pixpos+=uy;
   }
  }
 }else{
  len=ydif+1;
  for(int i=0;i<len;i++){
   scn[pixpos]=color;
   pixpos+=uy;
   onerror+=xdif;
   if(onerror>0){
    onerror-=ydif;
    pixpos+=ux;
   }
  }
 }
}


void drawImage(int imagen[][21],int y,int x,int t,char far *scrn){
  for(int i = 0; i < 21; i++){
   for(int j = 0; j < 24; j++){
    if(imagen[j][i] != t){
    scrn[(j+x)*320+(i+y)] = imagen[j][i];
    }
   }
  }
}
void drawMap(int imagen[][188],int x,int y,int t,char far *scrn){
  for(int i = 0; i < 188/*same as y*/; i++){
   for(int j = 0; j < 100; j++){
    if(imagen[j][i] != t){
    scrn[(y+j)*320+(i+x)] = imagen[j][i];
    }
   }
  }
}
