#include <omnetpp.h>


class TxPilota_to_SRB : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(TxPilota_to_SRB);

void TxPilota_to_SRB::initialize()
{

}

void TxPilota_to_SRB::handleMessage(cMessage *msg)
{
    delete msg;
}
