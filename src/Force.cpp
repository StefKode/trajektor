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

#include<Force.h>
#include<math.h>

Force::Force()
{
	m_force     = 0.0;
	m_direction = 0.0;
}

void Force::add_forceVector(double force, double direction)
{
	double fx1, fy1, fx2, fy2, fx, fy, heading;
	
	fx1 = m_force * cos(m_direction);
	fy1 = m_force * sin(m_direction);

	fx2 = force * cos(direction);
	fy2 = force * sin(direction);

	fx = fx1 + fx2;
	fy = fy1 + fy2;

	m_force = sqrt((fx * fx) + (fy * fy));
	
	heading = atan2(fx, fy);

        if (heading < 0) {
                heading = heading + (2 * M_PI);
	}
	
	m_direction = heading;
}

double Force::get_currentForce()
{
	return m_force;
}

double Force::get_currentDirection()
{
	return m_direction;
}

double Force::get_gravity(double r, double m1, double m2)
{
	const double G = 6.67384e-11;
	double Fg;

	Fg = G * m1 * m2 / (r * r);
	return Fg;
}
