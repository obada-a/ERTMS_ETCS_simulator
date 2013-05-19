#include <omnetpp.h>
#include <DistanceMessage_m.h>
#include <math.h>

class FiltroMessaggiDati : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        void extractDistances(DistanceMessage *msg);
        double *distances;
        double frequenza;
        int numSrb;
        double potenzaSRB;
        double potenzaMS;
        double sensibilitaMS;
        double sensibilitaSRB;
        double lambda;
};

Define_Module(FiltroMessaggiDati);

void FiltroMessaggiDati::initialize()
{
    potenzaMS   =   par("potenzaMS");
    potenzaSRB =   par("potenzaSRB");
    numSrb  =   par("numSrb");
    frequenza   =   par("frequenzaDati");
    distances   =   new double[numSrb];
    sensibilitaMS   =   par("sensibilitaMS");
    sensibilitaSRB  =   par("sensibilitaSRB");
    lambda  =   3*pow(10,8)/(frequenza*pow(10,6));
}

void FiltroMessaggiDati::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
        {
            case 0:
            {
                delete msg;
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


void FiltroMessaggiDati::extractDistances(DistanceMessage *msg)
{
    for(int i=0;i<numSrb;i++)
    {
        distances[i]=msg->getDistances(i);
    }
}
