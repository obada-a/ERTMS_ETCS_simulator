#include <omnetpp.h>
#include <SrbPower.h>
#include <PowerMessage_m.h>
#include <HandoverMessage_m.h>
#include <HandoverUpdate_m.h>
#include <PresenceMessage_m.h>


class DecisoreHandover : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        SrbPower getMaxPowerSrb(PowerMessage *msg);
        double findServingSrbPower(PowerMessage *msg);
};

Define_Module(DecisoreHandover);

void DecisoreHandover::initialize()
{

}

void DecisoreHandover::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //PowerMessage
        case 7:
        {

            EV<<"BSC.DecisoreHandover :  E' arrivato un PowerMessage"<<endl;
            PowerMessage *inMsg = check_and_cast<PowerMessage *>(msg);
            int idServinSrb =   inMsg->getIdServingSrb();
            SrbPower maxSrbPower    =   getMaxPowerSrb(inMsg);
            int idDriftSrb  =   maxSrbPower.getIdSrb();
            int idMs    =   inMsg->getIdMS();
            if(maxSrbPower.getIdSrb() < 0)
            {
                    EV<<"BSC.DecisoreHandover :  Errore ServingSrb non è in visibilità"<<endl;
            }
            else if( idServinSrb != idDriftSrb)
            {
                EV<<"BSC.DecisoreHandover :  Inizio procedura di Handover   "<<endl;
                HandoverMessage *handoverMessage    =   new HandoverMessage("HandoverMessage", 3);
                handoverMessage->setIdServingSrb(idServinSrb);
                handoverMessage->setIdDriftSrb(idDriftSrb);
                handoverMessage->setIdMs(idMs);
                send(handoverMessage,"out");
                HandoverUpdate *handoverUpdate  =   new HandoverUpdate("HandoverUpdate",21);
                handoverUpdate->setIdMs(idMs);
                handoverUpdate->setIdDriftSrb(idDriftSrb);
                send(handoverUpdate,"regOut");
            }
            else
            {
                EV<<"BSC.DecisoreHandover :   Non c'è bisogno di Handover l'MS è connesso alla migliore SRB"<<endl;
            }
            delete msg;

            PresenceMessage *presenceMessage =  new PresenceMessage("PresenceMessage", 22);
            presenceMessage->setIdMs(idMs);
            send(presenceMessage,"regOut");
        }
        break;

        default:
        {

        }
        break;
    }
}


SrbPower DecisoreHandover::getMaxPowerSrb(PowerMessage *msg)
{
    int dim =   msg->getIdSrbArraySize();
    double  servingSrbPower =    findServingSrbPower(msg);
    if( servingSrbPower > 0 )
    {
        SrbPower    maxPowerSrb =   SrbPower(msg->getIdServingSrb(),servingSrbPower);
        for(int i=0 ; i < dim ; i++)
        {
            if(msg->getPotenze(i)   >  maxPowerSrb.getPotenzaRicevuta())
            {
                maxPowerSrb =   SrbPower(msg->getIdSrb(i) , msg->getPotenze(i));
            }
        }
        return maxPowerSrb;
    }

    return SrbPower( -1 , 0);

}

double DecisoreHandover::findServingSrbPower(PowerMessage *msg)
{
    int idSrb   =   msg->getIdServingSrb();
    int dim =   msg->getIdSrbArraySize();
    for(int i = 0 ; i < dim ; i++)
    {
        if(msg->getIdSrb(i) == idSrb)
            return msg->getPotenze(i);
    }
    return -1;
}
