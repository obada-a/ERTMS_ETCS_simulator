#include <omnetpp.h>
#include <NetworkAccessRequestMessage_m.h>
#include <PowerMessage_m.h>


class TxSegnalazione_to_SRB : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(TxSegnalazione_to_SRB);

void TxSegnalazione_to_SRB::initialize()
{

}

void TxSegnalazione_to_SRB::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //NetworkAccessRequestMessage
        case 5:
        {
            NetworkAccessRequestMessage *inMsg = check_and_cast<NetworkAccessRequestMessage *>(msg);
            int idSrb   =   inMsg->getIdDesideredSRB();
            cModule *srb    =   getParentModule()->getParentModule()->getParentModule()->getSubmodule("srb",idSrb);
            sendDirect(msg,srb,"in_from_channel");
            EV<<"TxSegnalazione_to_SRB:   Ho ricevuto e inoltrato NetworkAccessRequestMessage"<<endl;
        }
        break;

        //PowerMessage
        case 7:
        {
            PowerMessage *inMsg = check_and_cast<PowerMessage *>(msg);
            int idSrb   =   inMsg->getIdServingSrb();
            cModule *srb    =   getParentModule()->getParentModule()->getParentModule()->getSubmodule("srb",idSrb);
            sendDirect(msg,srb,"in_from_channel");
            EV<<"TxSegnalazione_to_SRB:   Ho ricevuto e inoltrato un PowerMessage"<<endl;
        }
        break;


        default:
        {
            delete msg;
            EV<<"TxSegnalazione_to_SRB:   Messaggio non previsto"<<endl;
        }
        break;
    }
}
