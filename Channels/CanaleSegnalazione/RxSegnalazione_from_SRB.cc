#include <omnetpp.h>


class RxSegnalazione_from_SRB : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(RxSegnalazione_from_SRB);

void RxSegnalazione_from_SRB::initialize()
{

}

void RxSegnalazione_from_SRB::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //HandoverMessage
        case 3:
        {
            EV<<"Channel.RxSegnalazione_from_SRB :   E' arrivato un HandoverMessage"<<endl;
            send(msg,"out");
        }
        break;

        //NetworkAccessConfirmationMessage
        case 6:
        {
            EV<<"Channel.RxSegnalazione_from_SRB :   E' arrivato un NetworkAccessConfirmationMessage"<<endl;
            send(msg,"out");
        }
        break;


        default:
        {
            EV<<"Channel.RxSegnalazione_from_SRB :   E' arrivato un Messaggio non previsto"<<endl;
            delete msg;
        }
        break;
    }
}
