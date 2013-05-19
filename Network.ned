package treno2;

import treno2.Treno.Treno;
import treno2.TopologyManager.TopologyManager;
//import treno.MobilityManager.MobilityManager;
//import treno.MobileStation.MobileStation;
import treno2.BSC.Bsc;
import treno2.SRB.Srb;
import treno2.Channels.Channels;


network Network
{
    parameters:
        int numSrb;
        @display("bgi=background/terrain;bgb=50,30;bgs=16,km");
    submodules:
        treno: Treno {
            @display("p=2.3125,14.6875");
        }
        srb[numSrb]: Srb {
            @display("p=18,5.9375");
        }
        bsc: Bsc {
            @display("p=25.3125,1.6875");
        }
        ch: Channels {
            @display("p=24.1875,9.3125");
        }
        tm: TopologyManager {
            @display("p=48.25,1.75");
        }
    connections:
        for i=0..numSrb-1 {
            srb[i].in <-- bsc.out[i];
            srb[i].out --> bsc.in[i];
        }
}

