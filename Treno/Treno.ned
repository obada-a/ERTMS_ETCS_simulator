package treno2.Treno;
import treno2.MobileStation.MobileStation;
import treno2.MobilityManager.MobilityManager;

module Treno
{
    parameters:
        double initialX @unit(km);
        double initialY @unit(km);
        @display("i=device/train");
    gates:
        
    submodules:
        ms: MobileStation {
            @display("p=90,78");
        }
        mm: MobilityManager {
            @display("p=243,79");
        }
    connections:
        
}
