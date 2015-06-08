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

SpaceObject::SpaceObject(	const char *name,
				double x,	double y,
				double speed,	double direction,
				double mass,	double radius)
{
	m_pos   = new Position(x,y);
	m_move  = new Movement(speed, direction);
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

double SpaceObject::get_x()
{
	return m_pos->get_x();
}

double SpaceObject::get_y()
{
	return m_pos->get_y();
}

double SpaceObject::get_mass() {
	return m_body->get_mass();
}

void SpaceObject::add_forceInteraction(SpaceObject *other)
{
	double d, b, Fg;

	d  = m_pos->distance_to(other->get_posRef());

	b  = m_pos->get_bearing(other->get_posRef());

	Fg = Force::get_gravity(d, m_body->get_mass(), other->get_mass());

	m_force->add_forceVector(Fg, b);
}

void SpaceObject::advance(double deltaT)
{
	m_pos->advance(m_move, deltaT);
}

void SpaceObject::dbg_report()
{
	printf("[ %-10s ] ", mref_name);
	m_pos->dbg_report();
	printf("\n");
}

Position* SpaceObject::get_posRef()
{
	return m_pos;
}
