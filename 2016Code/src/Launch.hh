#ifndef LAUNCH_H_INCLUDED
#define LAUNCH_H_INCLUDED
#include "WPILib.h"

class Launch
{
private:
    VictorSP left;
    VictorSP right;
    DigitalInput topSwitch;
    DigitalInput bottomSwitch;
    Relay relay(0); // set 0 to be the correct  channel for rotating launcher.
public:
    Launch(int leftPort, int rightPort, int topPort, int bottomPort);
    ~Launch();
    void feedIntake();
    void feedStop();
    void feedLaunch();
    void remoteLaunch(bool launch, bool intake, bool stop, bool upButton, bool downButton);
    void rotateTheLauncherUp();
    void rotateTheLauncherDown();
    void stopRotate();
};

#endif
