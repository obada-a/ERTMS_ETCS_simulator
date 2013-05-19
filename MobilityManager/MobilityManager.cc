#include <omnetpp.h>
#include <PositionUpdateMessage_m.h>

class MobilityManager : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        double timeOutSpostamento;
        double initialSpeedX;
        double initialSpeedY;
        cModule *topologyManager;
};

Define_Module(MobilityManager);

void  MobilityManager::initialize()
{
    timeOutSpostamento  =   par("timeOutSpostamento");
    initialSpeedX    =   par("initialSpeedX");
    initialSpeedY    =   par("initialSpeedY");
    cMessage *spostamentoMsg    =   new cMessage("SpostamentoTimeOut",40);
    topologyManager =   getParentModule()->getParentModule()->getSubmodule("tm");
    scheduleAt(simTime(),spostamentoMsg);
}

void  MobilityManager::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //SpostamentoTimeOut
        case 40:
        {
            delete msg;
            EV<<"MobilityManager : E' scattato lo SpostamentoTimeOut"<<endl;


        }
        break;

        default:
        {
            delete msg;
            EV<<"MobilityManager : E' arrivato un messaggio non previsto"<<endl;
        }
        break;
    }
}
