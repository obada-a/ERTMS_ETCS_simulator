#include <omnetpp.h>


class Rx_from_Channel : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Rx_from_Channel);


void Rx_from_Channel::initialize()
{

}

void Rx_from_Channel::handleMessage(cMessage *msg)
{
    EV<<"SRB.Rx_from_channel:   Ho ricevuto e inoltrato un messaggio di tipo: "<<msg->getKind()<<endl;
    send(msg,"gateBscOut");
}
