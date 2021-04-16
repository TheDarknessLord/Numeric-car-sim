#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class CAR
{ 
 public:
 	float Vel,Acc,drag;
    bool Strt;
 public:
 
 	 void carStrt();
	 void carAcc();
	 void carBre();
	 void carVelUpg();
	 void carStop();
	 void display();
};
void CAR::carStrt()
{
	Strt=1;
}
void CAR::carAcc()
{  
    if(Acc<100)  
	Acc=Acc+1;
	else
	Acc=100.0;
}
void CAR::carBre()
{ 
 if(Acc>-10)
 Acc=Acc-1;
 else
 Acc=-10.0;
}
void CAR::carVelUpg()
{ if((Vel>-50)&&(Vel<300))
  Vel=Vel+Acc-drag;
 
}
void CAR::carStop()
{
  Strt=0;
  Acc=0;	
}
void CAR::display()
{
	cout<<"Car Status "<<Strt<<" 1 for on 0 for off "<<endl;
	cout<<"Car Velocity "<<Vel<<endl;
	cout<<"Car Acceleration "<<Acc<<endl;
	}
int main()
{
	CAR key;
	char inp;
	key.Acc=0;
	key.Strt=0;
	key.Vel=0;
	key.drag=10;
	cout<<"Press I to turn car on/off, The Up arrow to accerate,the down arrow to brake.";
	//main loop
	inp=getch();
	if(inp='i')
	while(1)
	{   system("cls");
	    inp=getch();
	    key.display();
	    Sleep(100);
	   	key.carVelUpg();
		if(kbhit())
		{  
			if(key.Strt==0&&inp=='i')
			{
			Sleep(50);
			key.carStrt();
			 key.display();}
			if(key.Strt==1&&inp=='i')
			{Sleep(50);
			key.carStop();key.display();}
			if(inp==72)
			{key.carAcc();key.display();}
			if(inp==80)
			{key.carBre();key.display();}
		}
		Sleep(100);
	}
	return 0;
}
