package treno2.MobileStation;

simple Tx_MS
{
    parameters:
        bool connected;
        int idServingSRB;
        int idMS;
    gates:
        input inNAM;
        input inPM;
        input inHM;
        input inDM;
}

simple Rx_MS
{
     bool connected;
     int idServingSRB;
     int idMS;
    gates:
        input in @directIn;
        output outNAM;
        output outPM;
        output outHM;
        output outDM;
        input in_from_NAM;
        input in_from_HM;
}

simple NetworkAccessManager

{
    parameters:
        int idMS;
        bool connected;
     	int idServingSRB;
     	double connectionTimeOut @unit(s);
    gates:
        input in;
        output out;
        output out_to_Rx;
        output out_to_PM;
        input in_from_PM;
}

simple PowerManager
{
    parameters:
        int numSrb;
        double potenzaSRB;
        double timeOutPowerMessage @unit(s);
        int idMS;
    gates:
        input in;
        output out;
        input in_from_NAM;
        output out_to_NAM;
}


simple HandoverManager
{
    parameters:
        int idMS;
    gates:
        input in;
        output out;
        output outRx;
}

simple DataManagerMs
{
    parameters:
        int idMS;
    gates:
        input in;
        output out;
}


module MobileStation
{
    parameters:
        @display("bgb=478,209;i=old/handset1");
    gates:
        input in @directIn;
    submodules:
        rx: Rx_MS {
            @display("p=42,170;i=device/receiver");
        }
        tx: Tx_MS {
            @display("p=35,31;i=device/transmitter");
        }
        nam: NetworkAccessManager {
            @display("p=444,31;i=block/network");
        }
        dm: DataManagerMs {
            @display("p=396,102;i=msg/mail");
        }
        pm: PowerManager {
            @display("p=444,170;i=block/control");
        }
        hm: HandoverManager {
            @display("p=127,102");
        }
    connections:
        rx.in <-- in;
        rx.outDM --> dm.in;
        rx.outHM --> hm.in;
        rx.outNAM --> nam.in;
        rx.outPM --> pm.in;
        tx.inDM <-- dm.out;
        tx.inHM <-- hm.out;
        tx.inNAM <-- nam.out;
        tx.inPM <-- pm.out;
        nam.out_to_PM --> pm.in_from_NAM;
        pm.out_to_NAM --> nam.in_from_PM;
        nam.out_to_Rx --> rx.in_from_NAM;
        hm.outRx --> rx.in_from_HM;
}


