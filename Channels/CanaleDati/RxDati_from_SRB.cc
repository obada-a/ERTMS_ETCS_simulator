#include <omnetpp.h>


class RxDati_from_SRB : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(RxDati_from_SRB);

void RxDati_from_SRB::initialize()
{

}

void RxDati_from_SRB::handleMessage(cMessage *msg)
{

}
