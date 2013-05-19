/*
 * SrbPower.cc
 *
 *  Created on: Aug 9, 2012
 *      Author: alex
 */

#include "SrbPower.h"
SrbPower::SrbPower()
{
    idSrb   =   0;
    potenzaRicevuta =   0;

}

SrbPower::SrbPower(int id, double potenza) {
    idSrb   =   id;
    potenzaRicevuta =   potenza;

}
SrbPower::SrbPower(const SrbPower &srbSource)
{
    idSrb   =   srbSource.idSrb;
    potenzaRicevuta =   srbSource.potenzaRicevuta;
}

SrbPower& SrbPower::operator= (const SrbPower &srbSource)
{
    idSrb   =   srbSource.idSrb;
    potenzaRicevuta =srbSource.potenzaRicevuta;

    return *this;
}

SrbPower::~SrbPower()
{

}

int SrbPower::getIdSrb()
{
    return idSrb;
}

double SrbPower::getPotenzaRicevuta()
{
    return potenzaRicevuta;
}

