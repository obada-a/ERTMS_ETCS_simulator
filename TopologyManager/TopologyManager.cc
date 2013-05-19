#include <omnetpp.h>
#include <DistanceMessage_m.h>
#include <Punto.h>

class TopologyManager : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        void disegnaEntita(cModule *entita,Punto position);
        void asignPositions(Punto positions[],int dim);
        void calcoloDistanze();
        void getSRB();
        void setDistances(DistanceMessage *msg,int dim);
        int numSrb;
        double distanceTimeOut;
        Punto  *positions;
        Punto positionTreno;
        double *distances;
        cModule **srb;
        cModule *treno;
        cModule *canale;
        cModule *ms;
};

Define_Module(TopologyManager);

void  TopologyManager::initialize()
{
    distanceTimeOut =   par("distanceTimeOut");
    numSrb  =   par("numSrb");
    double X    =   par("initialX");
    double Y    =   par("initialY");

    canale=getParentModule();
    canale=canale->getSubmodule("ch");

    srb =   new cModule*[numSrb];
    positionTreno   =   Punto(X,Y);
    treno   =   getParentModule()->getSubmodule("treno");;
    ms=treno->getSubmodule("ms");


    positions   =   new Punto[numSrb];
    distances   =   new double[numSrb];
    cMessage *distanceTimeOutMsg   =   new cMessage("DistanceTimeOut",40);
    scheduleAt(simTime(),distanceTimeOutMsg);
}

void  TopologyManager::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {

        case 40:
        {
            delete msg;
            asignPositions(positions,numSrb);
            getSRB();
            for(int i=0;i<numSrb;i++)
            {
                disegnaEntita(srb[i],positions[i]);
            }
            disegnaEntita(treno,positionTreno);
            calcoloDistanze();
            cMessage *distanceTimeOutMsg   =   new cMessage("DistanceTimeOut",41);
            scheduleAt(simTime(),distanceTimeOutMsg);
        }
        break;
        case 41:
        {
            delete msg;
            DistanceMessage *distMsgTreno=new DistanceMessage("Distance Message",1);
            setDistances(distMsgTreno,numSrb);
            DistanceMessage *distMsgCanale=new DistanceMessage("Distance Message",1);
            setDistances(distMsgCanale,numSrb);
            sendDirect(distMsgTreno,ms,"in");
            sendDirect(distMsgCanale,canale,"inTM");
            cMessage *distanceTimeOutMsg   =   new cMessage("DistanceTimeOut",41);
            scheduleAt(simTime()+distanceTimeOut,distanceTimeOutMsg);
        }
        break;

        default:
            std::cout<<"ERRORE: è arrivato un msg non consentito al modulo Treno.Rx"<<endl;
            EV<<"ERRORE: è arrivato un msg non consentito al modulo Treno.Rx"<<endl;
        break;
    }

}

void TopologyManager::asignPositions(Punto positions[],int dim)
{
    for(int i=0;i<dim;i++)
    {
        double h=uniform(0,5);
        double l=uniform(-5,5);
        if(i%2==0)
        {
            double X=i*5+5+l;
            double Y=positionTreno.getY()+h;
            positions[i]=Punto(X,Y);
        }
        else
        {
            double X=i*5+5+l;
            double Y=positionTreno.getY()-h;
            positions[i]=Punto(X,Y);
        }

    }
}

void TopologyManager::getSRB()
{
    for(int i=0;i<numSrb;i++)
    {
        srb[i]=getParentModule()->getSubmodule("srb",i);
    }
}

void TopologyManager::disegnaEntita(cModule *entita,Punto position)
{
    entita->getDisplayString().setTagArg("p", 0, position.getX());
    entita->getDisplayString().setTagArg("p", 1, position.getY());
}

void TopologyManager::calcoloDistanze()
{
    for(int i=0;i<numSrb;i++)
    {
        distances[i]=positionTreno.calcDist(positions[i]);
    }

}

void TopologyManager::setDistances(DistanceMessage *msg, int dim)
{
    msg->setDistancesArraySize(dim);
    for(int i=0 ; i<dim ; i++)
    {
        msg->setDistances(i,distances[i]);
    }
}


