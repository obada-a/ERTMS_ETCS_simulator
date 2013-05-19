#include <omnetpp.h>


class TxDati_to_SRB : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(TxDati_to_SRB);

void TxDati_to_SRB::initialize()
{

}

void TxDati_to_SRB::handleMessage(cMessage *msg)
{

}
