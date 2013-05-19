#include <omnetpp.h>
#include <HelloMessage_m.h>
#include <ConnectionConfiguration_m.h>
#include <DriftSrbConfiguration_m.h>


class Rx_MS : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        int idServingSRB;
        int idMS;
        bool connected;

};

Define_Module(Rx_MS);

void  Rx_MS::initialize()
{
    connected   =   par("connected");
    idMS    =   par("idMS");
    idServingSRB    =   par("idServingSRB");
}

void  Rx_MS::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //HelloMessage
        case 0:
        {
            if(connected)
            {
                HelloMessage *inMsg = check_and_cast<HelloMessage *>(msg);
                if(inMsg->getIdSRB() == idServingSRB)
                {
                    cMessage *helloServingSrbConfirm =   new cMessage("Rx_MS: Hello From Serving SRB",24);
                    send(helloServingSrbConfirm,"outNAM");
                }
            }
            send(msg,"outPM");
            EV<<"Rx_MS:  è arrivato un HelloMessage ed e stato inoltrato verso PowerManager"<<endl;
        }
        break;

        //DistanceMessage
        case 1:
        {
            send(msg,"outPM");
            EV<<"Rx_MS:  è arrivato un DistanceMessage ed e stato inoltrato verso PowerManager"<<endl;
        }
        break;

        //HandoverMessage
        case 3:
        {
            send(msg,"outHM");
            EV<<"Rx_MS:  è arrivato un HandoverMessage ed è stato inoltrato verso HandoverManager"<<endl;
        }
        break;




        //NetworkAccessConfirmationMessage
        case 6:
        {
            EV<<"Rx_MS:  è arrivato un NetAccConfMsg ed e stato inoltrato verso NAM"<<endl;
            send(msg,"outNAM");
        }
        break;

        //ConnectionConfiguration Message
        case 20:
        {
            EV<<"Rx_MS:  La connessione è stata configurata"<<endl;
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
            EV<<"Rx_MS:  Messaggio non previsto"<<endl;
            delete msg;
        }
        break;
    }
}
