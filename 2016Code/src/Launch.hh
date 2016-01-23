#ifndef LAUNCH_H_INCLUDED
#define LAUNCH_H_INCLUDED
#include "WPILib.h"

class Launch
{
private:
    VictorSP left;
    VictorSP right;
public:
    Launch(int leftPort, int rightPort);
    ~Launch();
    void feedIntake();
    void feedStop();
    void feedLaunch();
    void remoteLaunch(bool launch, bool intake, bool stop);
};

#endif
