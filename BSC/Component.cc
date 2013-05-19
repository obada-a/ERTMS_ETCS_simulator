/*
 * Component.cc
 *
 *  Created on: Aug 10, 2012
 *      Author: alex
 */

#include "Component.h"

Component::Component()
{

}

Component::Component(int idTerminale , int idBts)
{
    idMs    =   idTerminale;
    idSrb   =   idBts;
    presenceCounter =   0;
}

Component::Component(const Component &cSource)
{
    idMs    =   cSource.idMs;
    idSrb   =   cSource.idSrb;
    presenceCounter =   cSource.presenceCounter;
}

Component& Component::operator= (const Component &cSource)
{
    idMs    =   cSource.idMs;
    idSrb   =   cSource.idSrb;
    presenceCounter = cSource.presenceCounter;
    return *this;
}
Component::~Component() {
    // TODO Auto-generated destructor stub
}

int Component::getIdMs()
{
    return idMs;
}

int Component::getIdSrb()
{
    return idSrb;
}

void Component::setIdMs(int id)
{
    idMs    =   id;
}

void Component::setIdSrb(int id)
{
    idSrb   =   id;
}

void Component::resetCounter()
{
    presenceCounter =   0;
}

void Component::incrementCounter()
{
    presenceCounter++;
}

int Component::getCounter()
{
    return presenceCounter;
}
