/*
    Copyright (C) 2015, 2016 "Jadon Belezos" "Lance Booth" "Kira Corbett" "Caleb Reister" "Nathan Walker"

    This file is a part of the Team 2500 Robot Code.

    The Team 2500 Robot Code program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <Lift.hh>

Lift::Lift(int liftPort, float liftSpeed) :
           lift(liftPort)
{
	speed = liftSpeed;
}

Lift::~Lift()
{
}

void Lift::remoteLift(bool in, bool out)
{
	if (in)
		liftIn(speed);
	else if (out)
		liftOut(speed);
	else
		stopLift();
}

void Lift::liftOut(float speed)
{
	lift.Set(speed);
}

void Lift::liftIn(float speed)
{
	lift.Set(-speed);
}

void Lift::stopLift()
{
	lift.Set(0);
}
