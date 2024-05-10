
#include "main.h"

#define LEFT_LINE_SENSOR 21
#define RIGHT_LINE_SENSOR 16
#define IR_SENSOR 20

    
void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Motor Stop\r\n");
    Motor_Stop(MOTOR_FL);
    Motor_Stop(MOTOR_FR);
    Motor_Stop(MOTOR_BL);
    Motor_Stop(MOTOR_BR);
    DEV_ModuleExit();

    exit(0);
}

void goStraight(){
    printf("Going forward at 100 speed\n");
    Motor_Run(FORWARD, 100);
}

void turnLeft(){
    int pwm = 100;
    while(gpioRead(IR_SENSOR)){
        pwm = pwm - 10;
        //DECREASE LEFT MOTOR
    }
    //assertion: car is centered
    //motor foward 100%
}

void turnRight(){
    int pwm = 100;
    while(gpioRead(IR_SENSOR)){
        pwm = pwm - 10;
        //DECREASE RIGHT MOTOR
    }
    //assertion: car is centered
    //motor foward 100%
}


void crab(){
    /*
    left front and back right motor set to

    */
}
int main(void)
{
    //1.System Initialization
    if(DEV_ModuleInit())
        exit(0);
    
    //setup GPIO
	if (gpioInitialise() == PI_INIT_FAILED){
		printf("Failed to initialize\n");
		return 0;
	}
    gpioSetMode(LEFT_LINE_SENSOR, PI_INPUT);
    gpioSetMode(RIGHT_LINE_SENSOR, PI_INPUT);
    gpioSetMode(IR_SENSOR, PI_INPUT);

    //start motor
    void goStraight();


    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
    while(1) {
    }
    
    //3.System Exit
    DEV_ModuleExit();
    return 0;
}



