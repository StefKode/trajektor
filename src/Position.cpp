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

Position::Position(Vector3d init)
{
	m_vect  = new Vector3d(1,2,3);
	*m_vect = init;
}

Vector3d Position::get_vect()
{
	return *m_vect;
}

double Position::distance_to(Position *other)
{
	Vector3d tmp;
	tmp = other->get_vect() - *m_vect;
	return tmp.norm();
}

void Position::advance(Movement *move, double deltaT)
{
	*m_vect += move->get_vect() * deltaT;
}

void Position::dbg_report()
{
	printf("x = %10.2e, y = %10.2e, z = %10.2e", (*m_vect)(1), (*m_vect)(2),(*m_vect)(3));
}
