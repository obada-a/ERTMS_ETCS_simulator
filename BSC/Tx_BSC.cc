#include <omnetpp.h>
#include <NetworkAccessConfirmationMessage_m.h>
#include <HandoverMessage_m.h>

class Tx_Bsc : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Tx_Bsc);

void Tx_Bsc::initialize()
{

}

void Tx_Bsc::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //HandoverMessage
        case 3:
        {
            HandoverMessage *inMsg = check_and_cast<HandoverMessage *>(msg);
            EV<<"BSC.Tx_Bsc :   E' arrivato ed è stato inoltrato un HandoverMessage"<<endl;
            send(msg, inMsg->getIdServingSrb());
        }
        break;


        //NetworkAccessConfirmation
        case 6:
        {
            NetworkAccessConfirmationMessage *inMsg = check_and_cast<NetworkAccessConfirmationMessage *>(msg);
            EV<<"BSC.Tx_Bsc :   E' arrivato ed è stato inoltrato un NetworkAccessConfirmationMessage"<<endl;
            send(msg,"out",inMsg->getIdSrb());
        }
        break;

        default:
        {
            delete msg;
        }
        break;
    }
}
