#include <omnetpp.h>


class RxDati_from_MS : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(RxDati_from_MS);

void RxDati_from_MS::initialize()
{

}

void RxDati_from_MS::handleMessage(cMessage *msg)
{

}
