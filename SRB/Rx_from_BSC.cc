#include <omnetpp.h>


class Rx_from_BSC : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Rx_from_BSC);


void Rx_from_BSC::initialize()
{

}

void Rx_from_BSC::handleMessage(cMessage *msg)
{
    EV<<" SRB.Rx_from_BSC :  E' arrivato un messaggio di tipo "<<msg->getKind()<<endl;
    send(msg,"gateChannelOut");
}
