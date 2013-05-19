#include <omnetpp.h>
#include <HelloMessage_m.h>


class HelloManager : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        int id;
        double frequenzaPilota;
        double frequenzaDati;
        double frequenzaSegnalazione;
        double helloTimeOut;
};

Define_Module(HelloManager);


void HelloManager::initialize()
{
    helloTimeOut=par("helloTimeOut");
    id=getParentModule()->getIndex();
    EV<<"SRB :"<<id<<endl;
    frequenzaPilota=par("frequenzaPilota");
    frequenzaDati=par("frequenzaDati");
    frequenzaSegnalazione=par("frequenzaSegnalazione");

    cMessage *timeOutMsg=new cMessage("TimeOut HelloMessage",40);
    scheduleAt(simTime()+helloTimeOut,timeOutMsg);
}

//L'HelloManager periodicamente inizializza e invia HelloMessage verso Tx_to_Channel
void HelloManager::handleMessage(cMessage *msg)
{
    delete msg;
    HelloMessage *helloMsg=new HelloMessage("Hello from SRB: "+id,0);
    helloMsg->setIdSRB(id);
    helloMsg->setFrequenzaCanaleDati(frequenzaDati);
    helloMsg->setFrequenzaCanalePilota(frequenzaPilota);
    helloMsg->setFrequenzaCanaleSegnalazione(frequenzaSegnalazione);
    EV<<"HelloManager manda messaggio di hello"<<endl;
    send(helloMsg,"out");
    cMessage *timeOutMsg=new cMessage("TimeOut HelloMessage",40);
    scheduleAt(simTime()+helloTimeOut,timeOutMsg);
}
