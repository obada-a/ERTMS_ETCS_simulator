#include <omnetpp.h>


class TxDati_to_MS : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(TxDati_to_MS);

void TxDati_to_MS::initialize()
{

}

void TxDati_to_MS::handleMessage(cMessage *msg)
{

}
