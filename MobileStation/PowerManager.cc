#include <omnetpp.h>
#include <HelloMessage_m.h>
#include <DistanceMessage_m.h>
#include <math.h>
#include <PowerMessage_m.h>
#include <BestSrbRespons_m.h>
#include <vector>
#include <SrbPower.h>

class PowerManager : public cSimpleModule
{
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        void extractDistances(DistanceMessage *msg);
        void calcoloPotenze(HelloMessage *msg);
        void setPowers(PowerMessage *msg);
        int bestSrb();
        int numSrb;
        double *distances;
        double potenzaSRB;
        double timeOutPowerMsg;
        int idMS;
        int idBestSrb;
        std::vector<SrbPower> powers;
};

Define_Module(PowerManager);

void  PowerManager::initialize()
{
    idMS    =   par("idMS");
    timeOutPowerMsg =   par("timeOutPowerMessage");
    potenzaSRB  =   par("potenzaSRB");
    numSrb  =   par("numSrb");
    distances   =   new double[numSrb];
    cMessage *timeOutPowerMessage   =   new cMessage("PowerManager:  Best SRB Respons",40);
    scheduleAt(simTime()+timeOutPowerMsg,timeOutPowerMessage);
    idBestSrb   =   -1;
}

void  PowerManager::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
        //HelloMessage
        /**
         *HelloMessage viene inviato dalle SRB, contengono l'idSrb e le frequenze
         * del canale pilota , canale Segnalazione e del canale Dati
         */
        case 0:
        {
            EV<<"MS.PowerManager :   Ho ricevuto un HelloMessage"<<endl;
            HelloMessage *inMsg = check_and_cast<HelloMessage *>(msg);
            calcoloPotenze(inMsg);
            delete msg;
        }
        break;

        //DistanceMessage
        /**
         * DistanceMessage è un messaggio che viene inviato dal TopologyManager
         * esso contiene le distanze del treno da tutte le SRB
         */
        case 1:
        {
            DistanceMessage *inMsg = check_and_cast<DistanceMessage *>(msg);
            extractDistances(inMsg);
            delete msg;
        }
        break;

        //BestSrbRequest
        /**
         * Questo tipo di messaggio arriva dal NetworkAccessManager ed equivale ad una
         * richiesta dell'id della SRB con maggiore potenza rilevata
         */
        case 21:
        {
            delete msg;
            BestSrbRespons *bestSRB =   new BestSrbRespons("PowerManager:  Best SRB Respons",22);
            bestSRB->setIdBestSrb(idBestSrb);
            EV<<"PowerManager:  Rispondo alla BestSrbRequest con  idBestSrb == "<<idBestSrb<<endl;
            send(bestSRB,"out_to_NAM");
        }
        break;

        //PowerMessageTimeOut
        /**
         * Quando scatta il PowerMessageTimeOut
         * viene inviato un PowerMessage,
         * viene salvato l'id della SRB con maggiore potenza rilevata per poter rispondere ai BestSrbRequest
         * dopo di che viene svuotato il vettore contenente le potenze rilevate
         */
        case 40:
        {
            EV<<"MS.PowerManager :  Invio PowerMessage"<<endl;
            delete msg;
            PowerMessage *powerMsg  =   new PowerMessage("PowerMessage verso BSC",7);
            powerMsg->setIdMS(idMS);
            setPowers(powerMsg);
            send(powerMsg,"out");
            cMessage *timeOutPowerMessage   =   new cMessage("TimeOutPowerMessage",40);
            scheduleAt(simTime()+timeOutPowerMsg,timeOutPowerMessage);
            idBestSrb   =   bestSrb();
            powers.clear();

        }
        break;

        default:
        {
            delete msg;
            EV<<"PM: Messaggio non previsto"<<endl;
        }
        break;
    }
}

//Questa funzione estrae e salva le distanze da un DistanceMessage prende in ingresso
// il DistanceMessage contenente le distanze
void PowerManager::extractDistances(DistanceMessage *msg)
{
    int dim =   msg->getDistancesArraySize();
    for(int i=0;i<dim;i++)
    {
        distances[i]=msg->getDistances(i);
    }
}

//Calcola Le potenze rilevate dalle stazioni radio base
//Prende la frequenza  dall'HelloMessage
//Prende le distanze dall'array distances

void PowerManager::calcoloPotenze(HelloMessage *msg)
{
    double frequenza    =   msg->getFrequenzaCanalePilota();
    double lambda   =   3*pow(10,8)/(frequenza*pow(10,6));
    int id  =   msg->getIdSRB();
    double potenzaRicevuta  =   potenzaSRB/pow(4*3.14*distances[id]*1000/lambda,2);
    SrbPower srbPower   =   SrbPower(id,potenzaRicevuta);
    powers.push_back(srbPower);
}

//Inserisce le potenze rilevate nel PowerMessage
void PowerManager::setPowers(PowerMessage *msg)
{
    int dim =   powers.size();
    msg->setPotenzeArraySize(dim);
    msg->setIdSrbArraySize(dim);
    for(int i=0;i<dim;i++)
    {
        int idSrb   =   powers[i].getIdSrb();
        double potenza  =   powers[i].getPotenzaRicevuta();
        msg->setPotenze(i,potenza);
        msg->setIdSrb(i,idSrb);
    }
}

// bestSrb() scorre il vettore powers e restituisce l'indice della SRB con maggiore potenza
// restituisce -1 quando il vettore è vuoto, cioè non ci sono SRB in visibilità
int PowerManager::bestSrb()
{
    int k   =   0;
    int dim =   powers.size();
    if(dim == 0)
    {
        return -1;
    }
    else
    {
        double max  =   powers[0].getPotenzaRicevuta();
        for(    int i = 0;    i < dim;  i++)
        {
            if(powers[i].getPotenzaRicevuta() >= max)
            {
                max =   powers[i].getPotenzaRicevuta();
                k   =   i;
            }
        }
        return k;
    }
}
