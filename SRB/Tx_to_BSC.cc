#include <omnetpp.h>


class Tx_to_BSC : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Tx_to_BSC);


void Tx_to_BSC::initialize()
{

}

void Tx_to_BSC::handleMessage(cMessage *msg)
{
    EV<<"SRB.Tx_to_BSC:   Ho ricevuto e inoltrato un messaggio di tipo: "<<msg->getKind()<<endl;
    send(msg,"out");
}
