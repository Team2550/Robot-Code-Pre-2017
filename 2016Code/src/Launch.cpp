#include "Launch.h"

Launch::Launch()
{

}
Launch::rotateTheLauncherUp(){ // note to self: rotating might be backwards.
    relay.set(relay::value::kReverse);
}
Launch::rotateTheLauncherDown(){
    relay.set(relay::value::kForward);
}
Launch::stopRotate(){
    relay.set(relay::value::kOff);
}
Launch::~Launch()
{

}
