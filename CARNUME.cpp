#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class CAR//Define all the Members of required data
{ 
 public:
 	float Vel,Acc,drag;//Define Velocity(1-d), Acceleration and Drag(Constant here)
    bool Strt;
 public:
 
 	 void carStrt();
	 void carAcc();
	 void carBre();
	 void carVelUpg();
	 void carStop();
	 void display();
};
void CAR::carStrt()//iF THE CAR is Turned on:- still in development
{
	Strt=1;
}
void CAR::carAcc()//If accelerator is pressed Do the changes in cars acceleration
{   if(Vel==300){Acc=Acc;}//300 is max speed of car
    if(Vel==-50){Acc=Acc;}//-50 is max reverse speed of car
	
    if(Acc<100)  //100 is max acceleration
	Acc=Acc+10;
	else
	Acc=100.0;
}
void CAR::carBre()
{ 
if(Vel==300){Acc=Acc;}//max speed is 300
    if(Vel==-50){Acc=Acc;}//max reverse speed is -50
 if(Acc>-100)//-100 is max retardation
 Acc=Acc-10;
 else
 Acc=-100.0;
}
void CAR::carVelUpg()//Upgrade Velocity per cycle per call acc to the current acceration
{ if(Vel>=0&&Vel<=300&&Acc!=0)//will work only if ACC IS ZERO
 Vel=Vel+0.6*Acc-0.2*Vel*drag;//I modified the formula for drag 
 if(Vel==300||Vel>300)
 Vel=300;
 if(Vel<=0&&Vel>=-50&&Acc!=0)
 Vel=Vel+0.6*Acc+0.2*Vel*drag;
 if(Vel==-50||Vel<-50)
 Vel=-50;
 if(Acc==0&&Vel>0)
 Vel=Vel-10;
 if(Acc==0&&Vel<0)
 Vel=Vel+10;
}
void CAR::carStop()//Stopping the car
{
  Strt=0;
  Acc=0;	
}
void CAR::display()//DISPLAY THE CARS STATUS
{
	cout<<"Car Status "<<Strt<<" 1 for on 0 for off "<<endl;
	cout<<"Car Velocity "<<Vel<<endl;
	cout<<"Car Acceleration "<<Acc<<endl;
	if(Vel>0)
	cout<<"Car is going in the forward direction";
	if(Vel<0)
	cout<<"Car is going in the backward direction";
	}
int main()
 {
	CAR key;
	char inp;
	key.Acc=0;
	key.Strt=0;
	key.Vel=0;
	key.drag=0.5;
	cout<<"Press I to turn car on/off, The Up arrow to accerate,the down arrow to brake/Reverse.";
	//main loop
	inp=getch();
	if(inp='i')
	while(1)//infinite loop
	{   system("cls");//Clears screen
	    key.display();//Display Updated Data
	    key.carVelUpg();//Upgrade Val Call
	    inp=getch();//get the input character
	   
	    Sleep(100);//Delay by 100ms
	   	
	 
		if(key.Strt==0&&inp=='i')
		{
		Sleep(50);
		key.carStrt();
	    key.display();}
		if(key.Strt==1&&inp=='i')//Ignition 
		{Sleep(50);//Delay
		key.carStop();system("cls");key.display();}
		if(inp==72)
		{key.carAcc();system("cls");key.display();}
		if(inp==80)
		{key.carBre();system("cls");key.display();}
		if(!kbhit())//if any key is not pressed
		{ if(key.Acc>0)
		key.Acc=key.Acc-5;
		if(key.Acc<0)
		key.Acc=key.Acc+5;
		if(key.Acc==0)
		key.Acc=0;
		system("cls");
		key.display();}
		
		Sleep(200);//Delay 200ms
	}
	return 0;
}
