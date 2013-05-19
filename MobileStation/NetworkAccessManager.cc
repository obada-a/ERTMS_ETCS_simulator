#include <omnetpp.h>
#include <NetworkAccessRequestMessage_m.h>
#include <BestSrbRespons_m.h>
#include <ConnectionConfiguration_m.h>


class NetworkAccessManager : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        int idMS;
        bool connected;
        int idServingSRB;
        double connectionTimeOut;
        int idBestSrb;
        int contatoreMancatiHello;
};

Define_Module(NetworkAccessManager);

void  NetworkAccessManager::initialize()
{
    connected   =   par("connected");
    idServingSRB    =   par("idServingSRB");
    idMS    =   par("idMS");
    connectionTimeOut   =   par("connectionTimeOut");
    contatoreMancatiHello   =   0;
    cMessage *connectionTimeOutMessage  =   new cMessage("NAM : Connection TimeOut Message",40);
    scheduleAt(simTime(),connectionTimeOutMessage);
}

void  NetworkAccessManager::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //NetworkAccessConfirmtaionMessage
        case  6:
        {
            delete msg;
            idServingSRB    =   idBestSrb;
            connected   =   true;
            ConnectionConfiguration *connConfTxMsg    =   new ConnectionConfiguration("NAM: ConnectionConfiguration Message",20);
            connConfTxMsg->setIdServingSrb(idBestSrb);
            ConnectionConfiguration *connConfRxMsg    =   new ConnectionConfiguration("NAM: ConnectionConfiguration Message",20);
            connConfRxMsg->setIdServingSrb(idBestSrb);
            send(connConfTxMsg,"out");
            send(connConfRxMsg,"out_to_Rx");
        }
        break;

        //BestSrbRespons
        case 22:
        {
            BestSrbRespons *inMsg = check_and_cast<BestSrbRespons *>(msg);
            idBestSrb   =   inMsg->getIdBestSrb();
            if(idBestSrb <  0)
            {
                EV<<"NAM:  Non c'è nessuna SRB in visibilita'"<<endl;
            }
            else
            {
                EV<<"NAM: Ho ricevuto BestSrbRespons == "<<idBestSrb<<endl;
                NetworkAccessRequestMessage *narMsg =   new NetworkAccessRequestMessage("NAM: NetworkAccessRequestMessage",5);
                narMsg->setIdMS(idMS);
                narMsg->setIdDesideredSRB(idBestSrb);
                EV<<"NAM: Invio Messaggio NetworkAccessRequestMessage"<<endl;
                send(narMsg,"out");
            }
            delete msg;
        }
        break;

        //ServingSrbHelloConfirmation
        case 24:
        {
            delete msg;
            contatoreMancatiHello = 0;
            EV<<"NAM : E' arrivato ServingSrbHelloConfirmationMessage"<<endl;
        }
        break;


        //ConnectionTimeOut
        case 40:
        {
            delete msg;
            if(!connected)
            {
                cMessage *bestSrbRequest    =   new cMessage("NAM: BestSrbRequest",21);
                EV<<"NAM :  Invio BestSrbRequest Message"<<endl;
                send(bestSrbRequest,"out_to_PM");
                cMessage *connectionTimeOutMessage  =new cMessage("NAM: ConnectionTimeOut",40);
                scheduleAt(simTime()+connectionTimeOut,connectionTimeOutMessage);
            }
            else
            {
                if(contatoreMancatiHello > 3)
                {
                    connected    =   false;
                    cMessage *lostConnectionTx  =   new cMessage("LostConnectionMessage");
                    cMessage *lostConnectionRx  =   new cMessage("LostConnectionMessage");
                    cMessage *bestSrbRequest    =   new cMessage("BestSrbRequest",21);
                    EV<<"NAM :  Invio BestSrbRequest Message"<<endl;
                    send(bestSrbRequest,"out_to_PM");
                    send(lostConnectionRx,"out_to_Rx");
                    send(lostConnectionTx,"out");
                    cMessage *connectionTimeOutMessage  =new cMessage("NAM: ConnectionTimeOut",40);
                    scheduleAt(simTime()+connectionTimeOut,connectionTimeOutMessage);

                }
                else
                {
                    contatoreMancatiHello++;
                    cMessage *connectionTimeOutMessage  =new cMessage("NAM: ConnectionTimeOut",40);
                    scheduleAt(simTime()+connectionTimeOut,connectionTimeOutMessage);
                }
            }
        }
        break;

        default:
        {
            delete msg;
            EV<<"NAM: Messaggio non Previsto"<<endl;
        }
        break;


    }
}
