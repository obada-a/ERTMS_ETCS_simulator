#include <omnetpp.h>
#include <Register.h>
#include <RegistrationMessage_m.h>
#include <HandoverUpdate_m.h>
#include <PresenceMessage_m.h>

class AddressRegister : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        double presenceTimeOut;
        Register    reg;
};

Define_Module(AddressRegister);

void AddressRegister::initialize()
{
    presenceTimeOut =   par("presenceTimeOut");
    cMessage *presenceControlMessage    =   new cMessage("PresenceControlMessage",40);
    scheduleAt(simTime()+presenceTimeOut,presenceControlMessage);
}

void AddressRegister::handleMessage(cMessage *msg)
{
    switch( msg->getKind())
    {
        //RegistrationMessage
        case 20:
        {
            EV<<"BSC.AddressReg :   E' arrivato un RegistrationMessage"<<endl;
            RegistrationMessage *inMsg = check_and_cast<RegistrationMessage *>(msg);
            int idMs    =   inMsg->getIdMS();
            int idSrb   =   inMsg->getIdSRB();
            delete msg;
            reg.addComponent(idMs , idSrb);
        }
        break;

        //HandoverUpdate
        case 21:
        {
            EV<<"BSC.AddressReg :   E' arrivato un HandoverUpdateMessage"<<endl;
            HandoverUpdate *inMsg = check_and_cast<HandoverUpdate *>(msg);
            int idMs    =   inMsg->getIdMs();
            int idDriftSrb   =   inMsg->getIdDriftSrb();
            delete msg;
            reg.changeCompontent(idMs , idDriftSrb);
        }
        break;

        //PresenceMessage
        case 22:
        {
            EV<<"BSC.AddressReg :   E' arrivato un PresenceMessage"<<endl;
            PresenceMessage *inMsg = check_and_cast<PresenceMessage *>(msg);
            int idMs    =   inMsg->getIdMs();
            delete msg;
            reg.presenceRevealed(idMs);
        }
        break;

        //PresenceControlTimeOut
        case 40:
        {
            delete msg;
            EV<<"BSC.AddressReg :   Presence Control TimeOut"<<endl;
            reg.presenceControl();
            cMessage *presenceControlMessage    =   new cMessage("PresenceControlMessage",40);
            scheduleAt(simTime()+presenceTimeOut,presenceControlMessage);
        }
        break;

        default:
        {
            EV<<"BSC.AddressReg :   Ho ricevuto un messaggio non previsto"<<endl;
            delete msg;
        }
        break;
    }
}
