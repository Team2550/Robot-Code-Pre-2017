#ifndef LAUNCwH_H_INCLUDED
#define LAUNCH_H_INCLUDED

class Launch
{
private:
    VictorSP left;
    VictorSP right;
    Relay(0); // set 0 to be the correct  channel for rotating launcher.
public:
    Launch();
    rotateTheLauncherUP();
    rotateTheLauncherDown();
    stopRotate();
    ~Launch();
};

#endif
