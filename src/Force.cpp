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
#include<Force.h>
#include<math.h>
#include<stdio.h>

Force::Force()
{
	m_vect = new Eigen::Vector3d(1,2,3);
	*m_vect << 0, 0, 0;
}

void Force::add_forceVector(Vector3d addForce)
{
	*m_vect += addForce;
}

Vector3d Force::get_vect()
{
	return *m_vect;
}

double Force::get_gravity(double r, double m1, double m2)
{
	const double G = 6.67384e-11;
	double Fg;

	Fg = G * m1 * m2 / (r * r);
	return Fg;
}

void Force::clear()
{
	*m_vect << 0, 0, 0;
}

void Force::report()
{
	printf("Fx=%10.2e_N ", (*m_vect)(0));
	printf("Fy=%10.2e_N ", (*m_vect)(1));
	printf("(%e) | ", m_vect->norm());
}
