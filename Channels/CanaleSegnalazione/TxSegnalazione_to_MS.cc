#include <omnetpp.h>


class TxSegnalazione_to_MS : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        cModule *ms;
};

Define_Module(TxSegnalazione_to_MS);

void TxSegnalazione_to_MS::initialize()
{
    ms = getParentModule()->getParentModule()->getParentModule()->getSubmodule("treno")->getSubmodule("ms");
}

void TxSegnalazione_to_MS::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //HandoverMessage
        case 3:
        {
            EV<<"TxSegnalazione_to_MS:   E' arrivato un HandoverMessage"<<endl;
            sendDirect(msg,ms,"in");
        }
        break;


        //NetworkAccessConfirmationMessage
        case 6:
        {
            EV<<"TxSegnalazione_to_MS:   E' arrivato un NetworkAccessConfirmationMessage"<<endl;
            sendDirect(msg,ms,"in");
        }
        break;

        default :
        {
            EV<<"TxSegnalazione_to_MS:   Messaggio non  previsto"<<endl;
            delete msg;
        }
        break;
    }
}
