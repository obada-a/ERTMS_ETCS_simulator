#include <omnetpp.h>


class DataManagerBsc : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(DataManagerBsc);

void  DataManagerBsc::initialize()
{

}

void  DataManagerBsc::handleMessage(cMessage *msg)
{

}
