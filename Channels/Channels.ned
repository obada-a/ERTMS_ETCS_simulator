package treno2.Channels;
import treno2.Channels.CanalePilota.CanalePilota;
import treno2.Channels.CanaleDati.CanaleDati;
import treno2.Channels.CanaleSegnalazione.CanaleSegnalazione;



simple Rx_from_SRB
{
    gates:
        input in;
        output pilotaOut;
        output segnalazioneOut;
        output datiOut;
}

simple Rx_from_MS
{
    gates:
        input in;
        output pilotaOut;
        output segnalazioneOut;
        output datiOut;
}

simple DistanceRx
{
    parameters:
        int numSrb;
    gates:
        input in;
}


module Channels
{
    parameters:
        @display("bgb=299,191;i=block/control");
    gates:
        input inSRB @directIn;
        input inMS @directIn;
        input inTM @directIn;
    submodules:
        cp: CanalePilota {
            @display("p=138,145");
        }
        cs: CanaleSegnalazione {
            @display("p=25,145");
        }
        cd: CanaleDati {
            @display("p=257,139");
        }
        rx_from_srb: Rx_from_SRB {
            @display("p=237,42");
        }
        rx_from_ms: Rx_from_MS {
            @display("p=61,42");
        }
        distanceRx: DistanceRx {
            @display("p=149,34");
        }
    connections:
        rx_from_srb.in <-- inSRB;
        rx_from_ms.in <-- inMS;
        rx_from_srb.pilotaOut --> cp.inSRB;
        rx_from_srb.segnalazioneOut --> cs.inSRB;
        rx_from_srb.datiOut --> cd.inSRB;
        rx_from_ms.pilotaOut --> cp.inMS;
        rx_from_ms.segnalazioneOut --> cs.inMS;
        rx_from_ms.datiOut --> cd.inMS;
        distanceRx.in <-- inTM;
}


