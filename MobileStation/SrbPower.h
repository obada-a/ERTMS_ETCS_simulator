/*
 * SrbPower.h
 *
 *  Created on: Aug 9, 2012
 *      Author: alex
 */

#ifndef SRBPOWER_H_
#define SRBPOWER_H_

class SrbPower {
public:
    SrbPower();
    SrbPower(int idSrb,double potenzaRicevuta);
    SrbPower(const SrbPower &srbSource);
    SrbPower& operator= (const SrbPower &srbSource);
    int getIdSrb();
    double getPotenzaRicevuta();
    virtual ~SrbPower();
    int idSrb;
    double potenzaRicevuta;
};

#endif /* SRBPOWER_H_ */
