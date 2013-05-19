#include <omnetpp.h>


class Rx_from_MS : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Rx_from_MS);

void  Rx_from_MS::initialize()
{

}

void  Rx_from_MS::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //NetworkAccessRequestMessage
        case 5:
        {
            EV<<"Channels.Rx_from_MS:    E' arrivato un NetworkAccessRequestMessage"<<endl;
            send(msg,"segnalazioneOut");
        }
        break;

        //PowerMessage
        case 7:
        {
            EV<<"Channels.Rx_from_MS:    E' arrivato un PowerMessage"<<endl;
            send(msg,"segnalazioneOut");
        }
        break;

        default:
        {
            delete msg;
            EV<<"Channels.Rx_from_MS:    E' arrivato un messaggio non previsto"<<endl;
        }
        break;
    }
}
