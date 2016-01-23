/*
    Copyright (C) 2016 "jadon belezos" "lance booth" "kira corbet" "caleb reister"

    This program is free software: you can redistribute it and/or modify
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
#ifndef XBOX_H
#define XBOX_H

namespace xbox
{
	namespace axis
	{
		const uint32_t leftY = 1;
		const uint32_t rightY = 5;
		
		const uint32_t leftX = 0;
		const uint32_t rightX = 4;
		
		const uint32_t LT = 2;
		const uint32_t RT = 3;
		const uint32_t dpadX = 6;
	}
	namespace btn
	{
		const uint32_t a = 1;
		const uint32_t b = 2;
		const uint32_t x = 3;
		const uint32_t y = 4;
		
		const uint32_t lb = 5;
		const uint32_t rb = 6;
		
		const uint32_t back = 7;
		const uint32_t start = 8;
		
		const uint32_t leftPush = 9;
		const uint32_t rightPush = 10;
	}
}

#endif
