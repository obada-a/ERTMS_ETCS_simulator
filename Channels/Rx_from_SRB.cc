#include <omnetpp.h>


class Rx_from_SRB : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Rx_from_SRB);

void  Rx_from_SRB::initialize()
{

}

//I messaggi in arrivo vengo inoltrati sugli appositi canali i base al loro tipo
void  Rx_from_SRB::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        case 0:
        {
            send(msg,"pilotaOut");
            EV<<"Channels.Rx_from_SRB:  è arrivato un HelloMessage"<<endl;
        }
            break;

        //HandoverMessage
        case 3:
        {
            send(msg,"segnalazioneOut");
            EV<<"Channels.Rx_from_SRB:  è arrivato un HandoverMessage"<<endl;
        }
                    break;

        case 6:
        {
            EV<<"Channels.Rx_from_SRB:   è arrivato un NetworkAccessConfirmationMessage"<<endl;
            send(msg,"segnalazioneOut");
        }
            break;

        default:
        {
            delete msg;
            EV<<"Channels.Rx_from_SRB:  Messaggio non previsto"<<endl;
            std::cout<<"Channels.Rx_from_SRB:  Messaggio non previsto"<<endl;
        }
        break;
    }
}
