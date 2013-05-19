#include <omnetpp.h>


class RxPilota_from_SRB : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(RxPilota_from_SRB);

void RxPilota_from_SRB::initialize()
{

}

void RxPilota_from_SRB::handleMessage(cMessage *msg)
{
    //il messaggio viene inoltrato verso il FiltroMessaggiPilota
    send(msg,"out");
}
