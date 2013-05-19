package treno2.BSC;


simple Tx_Bsc
{
    parameters:
        int numSrb;
    gates:
        output out[numSrb];
        input dataIn;
        input handoverIn;
        input accessIn;
}

simple Rx_Bsc
{
    parameters:
        int numSrb;
    gates:
        input in[numSrb];
        output accessOut;
        output dataOut;
        output handoverOut;
}

simple DecisoreHandover
{
    parameters:
        int numSrb;
    gates:
        input in;
        output out;
        output regOut;
}

simple AccessManager
{
    parameters:
        int numSrb;
    gates:
        input in;
        output out;
        output regOut;
}

simple AddressRegister
{
    parameters:
        double presenceTimeOut @unit(s);
    gates:
        input newAccess;
        input updatePosition;
        input dataIn;
        output dataOut;
}

simple DataManagerBsc
{
    parameters:
    gates:

        input regIn;
        output regOut;
        input dataIn;
        output dataOut;
}
module Bsc
{
    parameters:
        int numSrb;
        @display("i=old/pctower2;bgb=382,231");
    gates:
        input in[numSrb];
        output out[numSrb];
    submodules:
        tx: Tx_Bsc {
            @display("p=47,178;i=device/transmitter");
        }
        dataManager: DataManagerBsc {
            @display("p=335,42");
        }
        accessManager: AccessManager {
            @display("p=171,71");
        }
        register: AddressRegister {
            @display("p=47,42;i=block/table2");
        }
        rx: Rx_Bsc {
            @display("p=335,178;i=device/receiver");
        }
        decisoreHandover: DecisoreHandover {
            @display("p=47,110");
        }
    connections:
        tx.handoverIn <-- decisoreHandover.out;
        rx.handoverOut --> decisoreHandover.in;
        tx.dataIn <-- dataManager.dataOut;
        rx.dataOut --> dataManager.dataIn;
        rx.accessOut --> accessManager.in;
        tx.accessIn <-- accessManager.out;
        decisoreHandover.regOut --> register.updatePosition;
        accessManager.regOut --> register.newAccess;
        dataManager.regOut --> register.dataIn;
        dataManager.regIn <-- register.dataOut;

        for i=0..numSrb-1 {
            tx.out[i] --> out[i];
            rx.in[i] <-- in[i];
        }
}


