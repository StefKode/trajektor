/*#######################################################################################
 #
 # Copyright by Stefan Koch <StefanKoch@gmx.org>, 2015
 #
 # This file is part of spacepath
 #
 #    spacepath is free software: you can redistribute it and/or modify
 #    it under the terms of the GNU General Public License as published by
 #    the Free Software Foundation, either version 3 of the License, or
 #    (at your option) any later version.
 #
 #    spacepath is distributed in the hope that it will be useful,
 #    but WITHOUT ANY WARRANTY; without even the implied warranty of
 #    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #    GNU General Public License for more details.
 #
 #    You should have received a copy of the GNU General Public License
 #    along with spacepath.  If not, see <http://www.gnu.org/licenses/>.
 #
 ######################################################################################*/

#include<Movement.h>
#include<Position.h>
#include<math.h>
#include<stdio.h>

Position::Position(double x, double y)
{
	m_x = x;
	m_y = y;
}

double Position::get_x()
{
	return m_x;
}

double Position::get_y()
{
	return m_y;
}

double Position::distance_to(Position *other)
{
	double ax, ay, d;

	ax = pow(m_x - other->get_x(), 2.0);
	ay = pow(m_y - other->get_y(), 2.0);
	d  = sqrt(ax + ay);
	return d;
}

void Position::advance(Movement *move, double deltaT)
{
	double s, an, dx, dy;

	s    = move->get_speed();
	an   = move->get_direction_rad();
	dx   = s * deltaT * cos(an);
	dy   = s * deltaT * sin(an);
	m_x += dx;
	m_y += dy;
}

void Position::dbg_report()
{
	printf("x = %10.2f, y = %10.2f", m_x, m_y);
}
