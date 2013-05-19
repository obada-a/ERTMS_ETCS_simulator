#include <omnetpp.h>


class DataManagerMs : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        int idMS;
};

Define_Module(DataManagerMs);

void  DataManagerMs::initialize()
{
    idMS    =   par("idMS");
}

void  DataManagerMs::handleMessage(cMessage *msg)
{
    EV<<"MS.DataManager: E' arrivato un messaggio non previsto"<<endl;
    delete msg;
}
