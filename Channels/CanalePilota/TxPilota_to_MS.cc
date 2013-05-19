#include <omnetpp.h>


class TxPilota_to_MS : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        cModule *MS;
};

Define_Module(TxPilota_to_MS);

void TxPilota_to_MS::initialize()
{
    MS=getParentModule()->getParentModule()->getParentModule()->getSubmodule("treno")->getSubmodule("ms");
}

void TxPilota_to_MS::handleMessage(cMessage *msg)
{
    sendDirect(msg,MS,"in");
}
