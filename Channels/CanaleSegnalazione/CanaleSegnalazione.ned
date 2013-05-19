package treno2.Channels.CanaleSegnalazione;



simple TxSegnalazione_to_SRB
{
    gates:
        input in;
}

simple RxSegnalazione_from_SRB
{
    gates:
        output out;
        input in @directIn;
}

simple TxSegnalazione_to_MS
{
    gates:
        input in;
}

simple RxSegnalazione_from_MS
{
    gates:
        input in;
        output out;
}


simple FiltroMessaggiSegnalazione
{
    parameters:
		double sensibilitaMS;
        double sensibilitaSRB;
        double frequenzaSegnalazione;
        int numSrb;
        double potenzaSRB;
        double potenzaMS;
    gates:
        input distancesIn @directIn;
        input srbIn;
        input msIn;
        output srbOut;
        output msOut;
}


module CanaleSegnalazione
{
    parameters:
        @display("bgl=2;bgb=438,225;i=misc/sun");
    gates:
        input inSRB;
        input inMS;
    submodules:
        tx_to_srb: TxSegnalazione_to_SRB {
            @display("p=364,32");
        }
        tx_to_ms: TxSegnalazione_to_MS {
            @display("p=97,32");
        }
        rx_from_srb: RxSegnalazione_from_SRB {
            @display("p=364,156");
        }
        rx_from_ms: RxSegnalazione_from_MS {
            @display("p=97,156");
        }
        fm: FiltroMessaggiSegnalazione {
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