#include <omnetpp.h>
#include <DistanceMessage_m.h>
#include <HelloMessage_m.h>
#include <math.h>


class FiltroMessaggiPilota : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        void extractDistances(DistanceMessage *msg);
        double calcoloPotenza(cMessage *msg);
        double frequenza;
        double *distances;
        int numSrb;
        double potenzaSRB;
        double potenzaMS;
        double sensibilitaMS;
        double sensibilitaSRB;
        double lambda;
};

Define_Module(FiltroMessaggiPilota);

void FiltroMessaggiPilota::initialize()
{
    sensibilitaMS   =   par("sensibilitaMS");
    sensibilitaSRB  =   par("sensibilitaSRB");
    potenzaSRB =   par("potenzaSRB");
    potenzaMS   =   par("potenzaMS");
    numSrb  =   par("numSrb");
    frequenza =   par("frequenzaPilota");
    distances   =   new double[numSrb];
    lambda  =   3*pow(10,8)/(frequenza*pow(10,6));
}

void FiltroMessaggiPilota::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        case 0:
        {
            HelloMessage *inMsg = check_and_cast<HelloMessage *>(msg);
            int id  =   inMsg->getIdSRB();


            double potenzaRicevuta  =   calcoloPotenza(msg);
            EV<<"Potenza ricevuta della SRB: "<<id<<" ==== "<<potenzaRicevuta<<endl;
            if(potenzaRicevuta<sensibilitaMS)
            {
                delete msg;
                EV<<" Il messaggio della SRB: "<<id<<" e stato cancelato"<<endl;
            }
            else
            {
                EV<<"Il messaggio della SRB: "<<id<<" è stato inoltrato verso il TRENO"<<endl;
                send(msg,"msOut");
            }
        }
        break;
        case 1:
        {
            DistanceMessage *inMsg = check_and_cast<DistanceMessage *>(msg);
            extractDistances(inMsg);
            delete msg;
        }
        break;

        default:
        {
            delete msg;
            EV<<"Messaggio non previsto";
        }
        break;
    }
}

void FiltroMessaggiPilota::extractDistances(DistanceMessage *msg)
{
    for(int i=0;i<numSrb;i++)
    {
        distances[i]=msg->getDistances(i);
    }
}

double FiltroMessaggiPilota::calcoloPotenza(cMessage *msg)
{
    HelloMessage *inMsg = check_and_cast<HelloMessage *>(msg);
    int id  =   inMsg->getIdSRB();
    double potenzaRicevuta  =   potenzaSRB/pow(4*3.14*distances[id]*1000/lambda,2);
    return potenzaRicevuta;
}

