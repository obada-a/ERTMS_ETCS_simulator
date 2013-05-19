#include <omnetpp.h>


class RxSegnalazione_from_MS : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(RxSegnalazione_from_MS);

void RxSegnalazione_from_MS::initialize()
{

}

void RxSegnalazione_from_MS::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //NetworkAccessRequestMessage
        case 5:
        {
            EV<<"Channel.CS.RxSegnalazione:    E' arrivato NetworkAccessRequestMessage"<<endl;
            send(msg,"out");
        }
        break;

        //PowerMessage
        case 7:
        {
            EV<<"Channel.CS.RxSegnalazione:    E' arrivato PowerMessage"<<endl;
            send(msg,"out");
        }
        break;

        default:
        {
            delete msg;
            EV<<"Channel.CS.RxSegnalazione:    E' arrivato un messaggio non previsto"<<endl;
        }
        break;
    }
}
