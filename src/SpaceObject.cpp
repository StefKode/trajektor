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

#include<SpaceObject.h>
#include<stdio.h>
#include<string.h>

SpaceObject::SpaceObject(const char *name, 
			 double px, double py, double pz,
			 double vx, double vy, double vz,
		 	 double mass, double radius)
{
	Vector3d p(1,2,3);
	Vector3d v(1,2,3);
	p << px, py, pz;
	v << vx, vy, vz;

	m_pos   = new Position(p);
	m_move  = new Movement(v);
	m_body  = new Body(mass, radius);
	m_force = new Force();
	mref_name = name;
}

SpaceObject::~SpaceObject()
{
	delete(m_pos);
	delete(m_move);
	delete(m_body);
	delete(m_force);
}

double SpaceObject::get_mass() {
	return m_body->get_mass();
}

void SpaceObject::add_forceInteraction(SpaceObject *other)
{
	double d, Fg;

	d  = m_pos->distance_to(other->get_posRef());
	Fg = Force::get_gravity(d, m_body->get_mass(), other->get_mass());

	Vector3d direction;
	direction = other->get_posRef()->get_vect() - m_pos->get_vect();
	direction.normalize();

	m_force->add_forceVector(Fg * direction);
}

void SpaceObject::advance(double deltaT)
{
	Vector3d mAddVect;

	//F=m*a
	//a=F/m
	//move_change=a * deltaT
	//move_new = move_old + move_change

	mAddVect = deltaT * m_force->get_vect() / m_body->get_mass();

	m_move->add_moveVector(mAddVect);
	m_pos->advance(m_move, deltaT);
}

void SpaceObject::report()
{
	printf("%-10s | ", mref_name);
	m_pos->report();
	m_move->report();
	m_force->report();
	printf("\n");
}

void SpaceObject::posLog()
{
	printf("%s ", mref_name);
	printf("%f, %f, %f\n", get_pos(0), get_pos(1), get_pos(2));
}

Position* SpaceObject::get_posRef()
{
	return m_pos;
}

void SpaceObject::clearForce()
{
	m_force->clear();
}

double SpaceObject::get_pos(unsigned int idx)
{
	if (idx > 3) {
		throw "Pos-Index out of bounds";
	}
	return (m_pos->get_vect())(idx);
}

bool SpaceObject::nameMatch(const char *name)
{
	if (strcmp(name, mref_name) == 0) {
		return true;
	}
	return false;
}

const char *SpaceObject::getName()
{
	return mref_name;
}
