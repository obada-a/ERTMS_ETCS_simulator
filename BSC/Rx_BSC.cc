#include <omnetpp.h>


class Rx_Bsc : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Rx_Bsc);
void Rx_Bsc::initialize()
{

}

void Rx_Bsc::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //NetworkAccessMessage
        case 5:
        {
            EV<<"BSC.RX_BSC:  E' arrivato un NetworkAccessRequestMessage"<<endl;
            send(msg,"accessOut");
        }
        break;

        //PowerMessage
        case 7:
        {
            EV<<"BSC.RX_BSC:  E' arrivato un PowerMessage"<<endl;
            send(msg,"handoverOut");
        }
        break;

        default:
        {
            EV<<"BSC.RX_BSC:  E' arrivato un messaggio non previsto"<<endl;
            delete msg;
        }
        break;
    }
}
