#include <omnetpp.h>
#include <RegistrationMessage_m.h>
#include <NetworkAccessRequestMessage_m.h>
#include <NetworkAccessConfirmationMessage_m.h>


class AccessManager : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

};

Define_Module(AccessManager);
void AccessManager::initialize()
{

}

void AccessManager::handleMessage(cMessage *msg)
{
    switch( msg->getKind())
    {
        //NetworkAccessRequesMessage
        case 5:
        {
            EV<<"  BSC.AccessManager : Ho ricevuto un NetworkAccessRequestMessage"<<endl;
            NetworkAccessRequestMessage *inMsg = check_and_cast<NetworkAccessRequestMessage *>(msg);
            int idSrb   =   inMsg->getIdDesideredSRB();
            int idMS    =   inMsg->getIdMS();
            delete msg;
            RegistrationMessage *regMessage =   new RegistrationMessage("RegistrationMessage",20);
            regMessage->setIdMS(idMS);
            regMessage->setIdSRB(idSrb);
            send(regMessage,"regOut");
            NetworkAccessConfirmationMessage *networkAccessConfirmation =   new NetworkAccessConfirmationMessage("NetworkAccessConfirmation",6);
            networkAccessConfirmation->setIdSrb(idSrb);
            networkAccessConfirmation->setIdMs(idMS);
            send(networkAccessConfirmation,"out");
            EV<<"  BSC.AccessManager : L'accesso è stato confermato"<<endl;

        }
        break;

        //NetworkAccessAcknowledgement
        case 8:
        {
            EV<<"BSC.AccessManager : Ho ricevuto L'Ack "<<endl;
            delete msg;
        }
        break;

        default:
        {
            EV<<"BSC.AccessManager : E' Arrivato un Messaggio non previsto"<<endl;
            delete msg;
        }
        break;
    }
}
