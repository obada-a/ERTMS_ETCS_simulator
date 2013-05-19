/*
 * Component.h
 *
 *  Created on: Aug 10, 2012
 *      Author: alex
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

class Component {
public:
    Component();
    Component(int idMS ,    int idSrb );
    Component( const Component &cSource);
    Component& operator=  (const Component &cSource);
    int getIdMs();
    int getIdSrb();
    void setIdMs(int id);
    void setIdSrb(int id);
    void resetCounter();
    void incrementCounter();
    int getCounter();
    int idMs;
    int idSrb;
    int presenceCounter;
    virtual ~Component();
};

#endif /* COMPONENT_H_ */
