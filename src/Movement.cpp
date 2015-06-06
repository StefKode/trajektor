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
#include<math.h>

Movement::Movement(double speed, double direction)
{
	m_speed     = speed;
	m_direction = direction;
}

double Movement::get_speed()
{
	return m_speed;
}

double Movement::get_direction()
{
	return m_direction;
}

double Movement::get_direction_rad()
{
	double dr;

	dr = m_direction * 2 * M_PI / 360;
	return dr;
}
