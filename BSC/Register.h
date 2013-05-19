/*
 * Register.h
 *
 *  Created on: Aug 10, 2012
 *      Author: alex
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include <Component.h>
#include <vector>

class Register {
public:
    Register();
    void addComponent(int idMs, int idSrb);
    void delComponent(int idMs);
    void changeCompontent(int idMs, int idDriftSrb);
    int getSrb(int idMs);
    void deleteElement(int k , int dim);
    int searchElement(int idMs);
    void presenceControl();
    void presenceRevealed(int idMs);
    virtual ~Register();
    std::vector<Component*> reg;
};

#endif /* REGISTER_H_ */
