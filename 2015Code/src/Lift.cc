#include "Lift.hh"

Lift::Lift() : liftMotor(1) {
	liftMotor.SetPercentMode();
	liftMotor.ConfigEncoderCodesPerRev(1);
}

Lift::Lift(uint8_t jagID, uint16_t encoderTicks) : liftMotor(jagID) {
	liftMotor.ConfigEncoderCodesPerRev(encoderTicks);
}

const LiftTask Lift::stop() {
	liftMotor.Set(0);
	task.mode = READY;
}

const LiftTask Lift::bottom() {
	if(liftMotor.GetForwardLimitOK())
	{
		task.mode = BOTTOM;
		liftMotor.Set(.35);
	}
	else
		stop();
	return task;
}

const LiftTask Lift::top() {
	if(liftMotor.GetReverseLimitOK())
	{
		task.mode = TOP;
		liftMotor.Set(-.65);
	}
	else
		stop();
	return task;
}

const LiftTask moveDist(uint32_t dist) {

}
const LiftTask setPosition(uint32_t position) {

}
const LiftTask setBox(uint8_t boxLevel) {

}

const LiftTask Lift::remoteLift(float stick, bool upButton, bool downButton, bool stopButton) {
	if(stick < -.2 && liftMotor.GetReverseLimitOK())
	{
		liftMotor.Set(stick);
	}
	else if(stick > .2 && liftMotor.GetForwardLimitOK())
	{
			liftMotor.Set(stick);
	}
	else if(downButton)
	{
		bottom();
	}
	else if(upButton)
	{
		top();
	}
	else if(stopButton  && !liftMotor.GetReverseLimitOK())
	{
		liftMotor.Set(-.2);
	}
	else
	{
		stop();
	}
}
