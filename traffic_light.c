#include <regx51.h>

//-------------------------//
//     IR Sensor Inputs    //
//-------------------------//

sbit IR1 = P1^0;      // Near Sensor
sbit IR2 = P1^1;      // Far Sensor

//-------------------------//
//    Traffic Light LEDs   //
//-------------------------//

sbit GREEN  = P2^0;
sbit YELLOW = P2^1;
sbit RED    = P2^2;

//-------------------------//
//     Global Variables    //
//-------------------------//

unsigned char density = 0;

// density = 0 --> No Vehicle
// density = 1 --> Low Traffic
// density = 2 --> High Traffic

//-------------------------//
//      Delay Function     //
//-------------------------//

void delay(unsigned int t)
{
    unsigned int i,j;

    for(i=0;i<t;i++)
    {
        for(j=0;j<1275;j++);
    }
}

//-------------------------//
//    Read IR Sensors      //
//-------------------------//

void ReadDensity()
{
    // No Vehicle

    if(IR1==0 && IR2==0)
    {
        density=0;
    }

    // Low Traffic

    else if(IR1==1 && IR2==0)
    {
        density=1;
    }

    // High Traffic

    else if(IR1==1 && IR2==1)
    {
        density=2;
    }

    // Invalid Condition (Safety)

    else
    {
        density=2;
    }
}

//-------------------------//
//      Green Signal       //
//-------------------------//

void GreenLight(unsigned int time)
{
    GREEN=1;
    YELLOW=0;
    RED=0;

    delay(time);
}

//-------------------------//
//      Yellow Signal      //
//-------------------------//

void YellowLight()
{
    GREEN=0;
    YELLOW=1;
    RED=0;

    delay(1000);
}

//-------------------------//
//       Red Signal        //
//-------------------------//

void RedLight(unsigned int time)
{
    GREEN=0;
    YELLOW=0;
    RED=1;

    delay(time);
}

void main()
{
    // Initialize Ports

    P1 = 0xFF;      // Configure Port 1 as Input
    P2 = 0x00;      // Clear Port 2

    // Initial Traffic Signal State

    GREEN  = 0;
    YELLOW = 0;
    RED    = 1;     // Red ON initially

    // Infinite Loop

    while(1)
    {
	
	        // Read Traffic Density

        ReadDensity();

        //-------------------------------
        // No Vehicle Detected
        //-------------------------------

        if(density==0)
        {
            GreenLight(1000);      
            YellowLight();         
            RedLight(1000);        
        }

        //-------------------------------
        // Low Traffic
        //-------------------------------

        else if(density==1)
        {
            GreenLight(2000);     
            YellowLight();         
            RedLight(1000);      
        }

        //-------------------------------
        // High Traffic
        //-------------------------------

        else
        {
            GreenLight(4000);     
            YellowLight();        
            RedLight(1000);        

    }   // End while

}       // End main