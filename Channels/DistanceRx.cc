#include <omnetpp.h>
#include <DistanceMessage_m.h>


class DistanceRx : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        void forwardMessage(DistanceMessage *msg);
        void extractDistances(DistanceMessage *msg);
        void setDistances(DistanceMessage *msg,int dim);
        double *distances;
        int numSrb;
        cModule *filtroPilota;
        cModule *filtroDati;
        cModule *filtroSegnalazione;
};

Define_Module(DistanceRx);

void  DistanceRx::initialize()
{
    filtroPilota=getParentModule()->getSubmodule("cp")->getSubmodule("fm");
    filtroDati=getParentModule()->getSubmodule("cd")->getSubmodule("fm");
    filtroSegnalazione=getParentModule()->getSubmodule("cs")->getSubmodule("fm");

    numSrb=par("numSrb");
    distances=new double[numSrb];
}

void  DistanceRx::handleMessage(cMessage *msg)
{
    DistanceMessage *inMsg = check_and_cast<DistanceMessage *>(msg);
    forwardMessage(inMsg);
    delete msg;
}

void DistanceRx::forwardMessage(DistanceMessage *msg)
{
    extractDistances(msg);
    DistanceMessage *msgPilota=new DistanceMessage("Messaggio Distanze verso il canale Pilota",1);
    DistanceMessage *msgDati=new DistanceMessage("Messaggio Distanze verso il canale Dati",1);
    DistanceMessage *msgSegnalazione=new DistanceMessage("Messaggio Distanze verso il canale Segnalazione",1);
    setDistances(msgPilota,numSrb);
    setDistances(msgDati,numSrb);
    setDistances(msgSegnalazione,numSrb);
    sendDirect(msgPilota,filtroPilota,"distancesIn");
    sendDirect(msgDati,filtroDati,"distancesIn");
    sendDirect(msgSegnalazione,filtroSegnalazione,"distancesIn");
}

void DistanceRx::extractDistances(DistanceMessage *msg)
{
    for(int i=0;i<numSrb;i++)
    {
        distances[i]=msg->getDistances(i);
    }
}

void DistanceRx::setDistances(DistanceMessage *msg, int dim)
{
    msg->setDistancesArraySize(dim);
    for(int i=0 ; i<dim ; i++)
    {
        msg->setDistances(i,distances[i]);
    }
}

