#ifndef LAUNCH_H_INCLUDED
#define LAUNCH_H_INCLUDED

class Launch
{
private:
    VictorSP left;
    VictorSP right;
    Relay(0); // set 0 to be the correct  channel for rotating launcher.
public:
    Launch(int leftPort, int rightPort);
    ~Launch();
    void feedIntake();
    void feedStop();
    void feedLaunch();
    void remoteLaunch(bool launch, bool intake, bool stop);
    void rotateTheLauncherUP();
    void rotateTheLauncherDown();
    void stopRotate();
};

#endif
