#include <omnetpp.h>


class Tx_to_Channel : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        cModule *canale;
};

Define_Module(Tx_to_Channel);


void Tx_to_Channel::initialize()
{
    canale=getParentModule();
    canale=canale->getParentModule();
    canale=canale->getSubmodule("ch");
}
// Trasmettitore invia il messaggio direttamente verso il canale
void Tx_to_Channel::handleMessage(cMessage *msg)
{
    EV<<"SRB.Tx_to_Channel: E' arrivato ed è stato inoltrato un messaggio di tipo: "<<msg->getKind()<<endl;
    sendDirect(msg,canale,"inSRB");
}
