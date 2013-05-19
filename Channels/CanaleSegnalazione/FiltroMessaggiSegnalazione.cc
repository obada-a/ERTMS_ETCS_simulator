#include <omnetpp.h>
#include <DistanceMessage_m.h>
#include <math.h>
#include <NetworkAccessRequestMessage_m.h>
#include <NetworkAccessConfirmationMessage_m.h>
#include <PowerMessage_m.h>
#include <HandoverMessage_m.h>


class FiltroMessaggiSegnalazione : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        void extractDistances(DistanceMessage *msg);
        double calcoloPotenzaRicevutaSRB(cMessage *msg,int tipoMessaggio, int idSrb);
        double calcoloPotenzaRicevutaMS(cMessage *msg,int tipoMessaggio, int idSrb);
        double *distances;
        int numSrb;
        double frequenza;
        double potenzaSRB;
        double potenzaMS;
        double sensibilitaMS;
        double sensibilitaSRB;
        double lambda;
};

Define_Module(FiltroMessaggiSegnalazione);

void FiltroMessaggiSegnalazione::initialize()
{
    sensibilitaMS   =   par("sensibilitaMS");
    sensibilitaSRB  =   par("sensibilitaSRB");
    potenzaSRB =   par("potenzaSRB");
    potenzaMS   =   par("potenzaMS");
    numSrb  =   par("numSrb");
    distances   =   new double[numSrb];
    frequenza   =   par("frequenzaSegnalazione");
    lambda  =   3*pow(10,8)/(frequenza*pow(10,6));
}

void FiltroMessaggiSegnalazione::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
        {
            case 0:
            {
                delete msg;
            }
            break;

            //DistanceMessage
            case 1:
            {
                DistanceMessage *inMsg = check_and_cast<DistanceMessage *>(msg);
                extractDistances(inMsg);
                delete msg;
            }
            break;

            //HandoverMessage
            case 3:
            {
                HandoverMessage *inMsg = check_and_cast<HandoverMessage *>(msg);
                int idSRB   =   inMsg->getIdServingSrb();
                double potenzaRicevutaSrb  =   calcoloPotenzaRicevutaMS(msg , 3, idSRB);
                if(potenzaRicevutaSrb < sensibilitaMS)
                {
                    EV<<"CanaleSegnalazione.FiltroMesg:   HandoverMessage verso SRB: "<<idSRB<<" è stato cancelato"<<endl;
                    EV<<"CanaleSegnalazione.FiltroMesg:   PotenzaRicevuta dalla SRB: "<<idSRB<<" === "<<potenzaRicevutaSrb<<endl;
                    delete msg;
                }
                else
                {
                    EV<<"CanaleSegnalazione.FiltroMesg:   HandoverMessage verso SRB: "<<idSRB<<" è stato inoltrato"<<endl;
                    EV<<"CanaleSegnalazione.FiltroMesg:   PotenzaRicevuta dalla SRB: "<<idSRB<<" === "<<potenzaRicevutaSrb<<endl;
                    send(msg,"srbOut");
                }

            }
            break;

            //NetworkAccessRequestMessage
            case 5:
            {
                NetworkAccessRequestMessage *inMsg = check_and_cast<NetworkAccessRequestMessage *>(msg);
                int idSRB  =   inMsg->getIdDesideredSRB();
               // int idMS    =   inMsg->getIdMS();
                double potenzaRicevutaSrb  =   calcoloPotenzaRicevutaSRB(msg , 5, idSRB);
                if(potenzaRicevutaSrb < sensibilitaSRB)
                {
                    EV<<"CanaleSegnalazione.FiltroMesg:  Il NetAccReqMesg verso SRB: "<<idSRB<<" è stato cancelato"<<endl;
                    EV<<"CanaleSegnalazione.FiltroMesg:   PotenzaRicevuta dalla SRB: "<<idSRB<<" === "<<potenzaRicevutaSrb<<endl;
                    delete msg;
                }
                else
                {
                    EV<<"CanaleSegnalazione.FiltroMesg:  Il NetAccReqMesg verso SRB: "<<idSRB<<" è stato inoltrato"<<endl;
                    EV<<"CanaleSegnalazione.FiltroMesg:   PotenzaRicevuta dalla SRB: "<<idSRB<<" === "<<potenzaRicevutaSrb<<endl;
                    send(msg,"srbOut");
                }

            }
            break;

            //NetworkAccessConfirmationMessage
            case 6:
            {
                NetworkAccessConfirmationMessage *inMsg = check_and_cast<NetworkAccessConfirmationMessage *>(msg);
                int idSRB  =    inMsg->getIdSrb();
                double potenzaRicevutaMs  =   calcoloPotenzaRicevutaMS(msg , 6, idSRB);
                if(potenzaRicevutaMs < sensibilitaMS)
                {
                    EV<<"CanaleSegnalazione.FiltroMesg:  Il NetAccConfMesg verso MS è stato cancelato"<<endl;
                    EV<<"CanaleSegnalazione.FiltroMesg:   PotenzaRicevuta dal MS === "<<potenzaRicevutaMs<<endl;
                    delete msg;
                }
                else
                {
                    EV<<"CanaleSegnalazione.FiltroMesg:  Il NetAccConfMesg verso MS è stato inoltrato"<<endl;
                    EV<<"CanaleSegnalazione.FiltroMesg:   PotenzaRicevuta dal MS === "<<potenzaRicevutaMs<<endl;
                    send(msg,"msOut");
                }

            }
            break;

            //PowerMessage
            case 7:
            {
                PowerMessage *inMsg = check_and_cast<PowerMessage *>(msg);
                int idSRB   =   inMsg->getIdServingSrb();
                double potenzaRicevutaSrb  =   calcoloPotenzaRicevutaSRB(msg , 7, idSRB);
                if(potenzaRicevutaSrb < sensibilitaSRB)
                {
                    EV<<"CanaleSegnalazione.FiltroMesg:  Il PowerMessage verso SRB: "<<idSRB<<" è stato cancelato"<<endl;
                    EV<<"CanaleSegnalazione.FiltroMesg:   PotenzaRicevuta dalla SRB: "<<idSRB<<" === "<<potenzaRicevutaSrb<<endl;
                    delete msg;
                }
                else
                {
                    EV<<"CanaleSegnalazione.FiltroMesg:  Il PowerMessage verso SRB: "<<idSRB<<" è stato inoltrato"<<endl;
                    EV<<"CanaleSegnalazione.FiltroMesg:   PotenzaRicevuta dalla SRB: "<<idSRB<<" === "<<potenzaRicevutaSrb<<endl;
                    send(msg,"srbOut");
                }

            }
            break;

            default:
            {
                delete msg;
                EV<<"CanaleSegnalazione.FiltroMeg:   Messaggio non previsto"<<endl;
            }
            break;
        }
}

void FiltroMessaggiSegnalazione::extractDistances(DistanceMessage *msg)
{
    for(int i=0;i<numSrb;i++)
    {
        distances[i]=msg->getDistances(i);
    }
}

double FiltroMessaggiSegnalazione::calcoloPotenzaRicevutaSRB(cMessage *msg,int tipoMessaggio, int idSrb)
{
    double potenzaRicevuta  =   potenzaMS/pow(4*3.14*distances[idSrb]*1000/lambda,2);
    return potenzaRicevuta;
}


double FiltroMessaggiSegnalazione::calcoloPotenzaRicevutaMS(cMessage *msg, int tipoMessaggio, int idSrb)
{
    double potenzaRicevuta  =   potenzaSRB/pow(4*3.14*distances[idSrb]*1000/lambda,2);
    return potenzaRicevuta;
}
