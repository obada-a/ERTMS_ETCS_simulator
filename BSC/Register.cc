/*
 * Register.cc
 *
 *  Created on: Aug 10, 2012
 *      Author: alex
 */

#include "Register.h"
#include <vector>

Register::Register()
{


}

Register::~Register()
{
    reg.clear();
}

void Register::addComponent(int idMs , int idSrb)
{
    Component *newComponent     =   new Component(idMs , idSrb);
    reg.push_back(newComponent);
}

void Register::delComponent(int idMs)
{
    int dim =   reg.size();
    int index   =   searchElement(idMs);
    if(index >= 0)
        deleteElement(index , dim);
}

void Register::changeCompontent(int idMs , int idDriftSrb)
{
    int index = searchElement(idMs);
    if(index >= 0)
    {
        reg[index]->setIdSrb(idDriftSrb);
    }
}

int Register::getSrb(int idMs)
{
    int index   =   searchElement(idMs);
    if( index >= 0)
    {
        return reg[index]->getIdSrb();
    }
    else
        return -1;
}
void Register::deleteElement(int k, int dim)
{
    for(int i=k ; i < dim-1 ; i++)
    {
        reg[k]=reg[k+1];
    }
    reg.pop_back();
}

int Register::searchElement(int idMs)
{
       int index = -1;
       int  dim =reg.size();
       for(int i=0 ; i<dim ; i++ )
       {
           if( reg[i]->getIdMs() == idMs)
               index = i;
       }
       return index;
}

void Register::presenceControl()
{
    int dim =   reg.size();
    for(int i=0 ; i<dim ; i++)
    {
        if(reg[i]->getCounter() >= 3)
        {
            deleteElement(i,dim);
            dim--;
        }
        else
        {
            reg[i]->incrementCounter();
        }
    }
}

void Register::presenceRevealed(int idMs)
{
    int index   =   searchElement(idMs);
    reg[index]->resetCounter();
}
