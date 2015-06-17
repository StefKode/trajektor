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

#include<stdio.h>
#include<Movement.h>
#include<math.h>

Movement::Movement(Vector3d init)
{
	m_vect  = new Vector3d(1,2,3);
	*m_vect = init;
}

void Movement::add_moveVector(Vector3d add)
{
	*m_vect += add;
}

Vector3d Movement::get_vect()
{
	return *m_vect;
}

void Movement::report()
{
	printf("Vx=%10.2e_m/s ", (*m_vect)(0));
	printf("Vy=%10.2e_m/s ", (*m_vect)(1));
	printf("(%e) | ", m_vect->norm());
}
