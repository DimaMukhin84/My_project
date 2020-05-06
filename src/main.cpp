#include <LedControl.h>

LedControl matrix = LedControl(12, 13, 10, 4);
int a,b=0,c=3,d,e,f,g;

uint8_t dan1[9]   = {1,3,7,15,31,63,127,255};
uint8_t dan2[9]   = {192,224,240,248,252,254,255};


void setup() {
    Serial.begin(9600);
  for (uint8_t i = 0; i < matrix.getDeviceCount(); i ++)
  {
    matrix.shutdown(i, false);                                                       //  включаем индикатор
    matrix.setIntensity(i, 2);                                                       //  задаём интенсивность свечения индикатора
    matrix.clearDisplay(i);                                                          //  очистка индикатора
  }

}

void zapolnenie(){
   for (a=0;a<8;a++){
  matrix.setLed(c,b,a,true);
  delay(937);
  }
  b++;
  if(b==8)
   {c--;
    a=0;
    b=0;
    };
    if(c<0){
       for (uint8_t i = 0; i < matrix.getDeviceCount(); i ++)
      {
      matrix.clearDisplay(i);                                                          //  очистка индикатора
      }
      a=0;
      b=0;
      c=3; 
      }
}

void strelka()
{ 
 matrix.clearDisplay(0); 
 for(a=0;a<8;a++)
  { 
    
    b=7;
    c=0;
    matrix.clearDisplay(0); 
    switch (a)
    {
      case 0:
      matrix.setLed(0,7,0,true);
      break;

      case 1:
      matrix.setLed(0,6,1,true);
      matrix.setRow(0,6,128);
      matrix.setColumn(0,1,3);
      break;
      case 2:
      for(int z=0;z<a;z++)
      {
        matrix.setLed(0,b,c,true);
        b--;
        c++;
      }
      matrix.setRow(0,5,192);
      matrix.setColumn(0,2,7);
      break;
      case 3:
      for(int z=0;z<a;z++)
      {
        matrix.setLed(0,b,c,true);
        b--;
        c++;
      }
      matrix.setRow(0,4,224);
      matrix.setColumn(0,3,15);
      break;
      
      case 4:
      for(int z=0;z<a;z++)
      {
        matrix.setLed(0,b,c,true);
        b--;
        c++;
      }
      matrix.setRow(0,3,240);
      matrix.setColumn(0,4,31);
      break;

      case 5:
      for(int z=0;z<a;z++)
      {
        matrix.setLed(0,b,c,true);
        b--;
        c++;
      }
      matrix.setRow(0,2,248);
      matrix.setColumn(0,5,63);
      break;

      case 6:
      for(int z=0;z<a;z++)
      {
        matrix.setLed(0,b,c,true);
        b--;
        c++;
      }
      matrix.setRow(0,1,252);
      matrix.setColumn(0,6,127);
      break;
      case 7:
      for(int z=0;z<a;z++)
      {
        matrix.setLed(0,b,c,true);
        b--;
        c++;
      }
      matrix.setRow(0,0,254);
      matrix.setColumn(0,7,255);
      break;
    default:
      break;

    }
       delay(50);
  }

}


void loop() {
  zapolnenie();
  // strelka();
}


