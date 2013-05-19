#include <omnetpp.h>
#include <HandoverMessage_m.h>
#include <DriftSrbConfiguration_m.h>

class HandoverManager : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        int idMS;
};

Define_Module(HandoverManager);

void  HandoverManager::initialize()
{
    idMS    =   par("idMS");
}

void  HandoverManager::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //HandoverMessage
        case 3:
        {
            EV<<"MS.HandoverManager :  E' stato ricevuto un HandoverMessage"<<endl;
            HandoverMessage *inMsg = check_and_cast<HandoverMessage *>(msg);
            int idDriftSrb  =   inMsg->getIdDriftSrb();
            delete msg;
            DriftSrbConfiguration *driftSrbConfigMsgTx    =  new DriftSrbConfiguration("DriftSrbConfiguration",23);
            DriftSrbConfiguration *driftSrbConfigMsgRx    =  new DriftSrbConfiguration("DriftSrbConfiguration",23);
            driftSrbConfigMsgRx->setIdDriftSrb(idDriftSrb);
            driftSrbConfigMsgTx->setIdDriftSrb(idDriftSrb);
            send(driftSrbConfigMsgRx,"outRx");
            send(driftSrbConfigMsgTx,"out");
            EV<<"MS.HandoverManager :  Sono stati inviati i DriftSrbConfiguration msg verso Tx e Rx"<<endl;
        }
        break;

        default:
        {
            EV<<"MS.HandoverManager :  E' stato ricevuto un messaggio non previsto, tipo messaggio : "<<msg->getKind()<<endl;
            delete msg;
        }
        break;
    }
}
