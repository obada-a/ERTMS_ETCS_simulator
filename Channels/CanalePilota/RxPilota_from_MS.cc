#include <omnetpp.h>


class RxPilota_from_MS : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(RxPilota_from_MS);

void RxPilota_from_MS::initialize()
{

}

void RxPilota_from_MS::handleMessage(cMessage *msg)
{

}
