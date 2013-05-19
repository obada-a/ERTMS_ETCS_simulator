package treno2.Channels.CanaleDati;



simple TxDati_to_SRB
{
    gates:
        input in;
}

simple RxDati_from_SRB
{
    gates:
        output out;
        input in @directIn;
}

simple TxDati_to_MS
{
    gates:
        input in;
}

simple RxDati_from_MS
{
    gates:
        input in;
        output out;
}


simple FiltroMessaggiDati
{
    parameters:
        double sensibilitaMS;
        double sensibilitaSRB;
        double potenzaSRB;
        double potenzaMS;
        double frequenzaDati;
        int numSrb;
    gates:
        input distancesIn @directIn;
        input srbIn;
        input msIn;
        output srbOut;
        output msOut;
}


module CanaleDati
{
    parameters:
        @display("bgl=2;bgb=438,225;i=misc/sun");
    gates:
        input inSRB;
        input inMS;
    submodules:
        tx_to_srb: TxDati_to_SRB {
            @display("p=364,32");
        }
        tx_to_ms: TxDati_to_MS {
            @display("p=97,32");
        }
        rx_from_srb: RxDati_from_SRB {
            @display("p=364,156");
        }
        rx_from_ms: RxDati_from_MS {
            @display("p=97,156");
        }
        fm: FiltroMessaggiDati {
            @display("p=229,92");
        }
    connections:
        tx_to_srb.in <-- fm.srbOut;
        tx_to_ms.in <-- fm.msOut;
        fm.srbIn <-- rx_from_srb.out;
        fm.msIn <-- rx_from_ms.out;
        rx_from_ms.in <-- inMS;
        rx_from_srb.in <-- inSRB;
}