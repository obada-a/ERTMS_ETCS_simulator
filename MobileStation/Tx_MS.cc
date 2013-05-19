#include <omnetpp.h>
#include <ConnectionConfiguration_m.h>
#include <PowerMessage_m.h>
#include <DriftSrbConfiguration_m.h>

class Tx_MS : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        int idServingSRB;
        bool connected;
        cModule *canale;
        int idMS;
};

Define_Module(Tx_MS);

void  Tx_MS::initialize()
{
    idMS    =   par("idMS");
    idServingSRB    =   par("idServingSRB");
    connected   =   par("connected");
    canale=getParentModule()->getParentModule()->getParentModule()->getSubmodule("ch");
}

void  Tx_MS::handleMessage(cMessage *msg)
{
        switch(msg->getKind())
        {
            //NetworkAccessRequest
            case 5:
            {
                EV<<"Tx_MS:  E arrivato un NetworkAccessMessage"<<endl;
                sendDirect(msg,canale,"inMS");
            }
            break;

            //PowerMessage
            case 7:
            {
                if(connected)
                {
                    EV<<"Tx_MS:   Arrivato e inoltrato PowerMessage"<<endl;
                    PowerMessage *inMsg = check_and_cast<PowerMessage *>(msg);
                    inMsg->setIdServingSrb(idServingSRB);
                    sendDirect(msg,canale,"inMS");
                }
                else
                {
                    delete msg;
                    EV<<"Tx_MS:   Connessione assente , PowerMessage non può essere inoltrato"<<endl;
                }
            }
            break;


            //ConnectionConfiguration Message
            case 20:
            {
                EV<<"Tx_MS:   La connessione è stata configurata "<<endl;
                ConnectionConfiguration *inMsg = check_and_cast<ConnectionConfiguration *>(msg);
                idServingSRB    =   inMsg->getIdServingSrb();
                connected   =   true;
                delete msg;
            }
            break;

            //DriftSrbConfiguration Message
            case 23:
            {
                EV<<"Tx_MS:   E' arrivato un DriftSrbConfiguration Message "<<endl;
                DriftSrbConfiguration *inMsg = check_and_cast<DriftSrbConfiguration *>(msg);
                idServingSRB    =   inMsg->getIdDriftSrb();
                delete msg;
            }
            break;

            //LostConnectionMessage
            case 25:
            {
                connected   =   false;
                delete msg;
            }
            break;

            default:
            {
                delete msg;
                EV<<"TX_MS: Messaggio non previsto"<<endl;
            }
            break;
        }

}
