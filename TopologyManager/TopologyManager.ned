package treno2.TopologyManager;

package scenario_1.TopologyManager;


simple TopologyManager
{
    parameters:
        double initialX @unit(km);
        double initialY @unit(km);
        int numSrb;
        double distanceTimeOut @unit(s);
    @display("i=misc/globe");
    gates:
        input in @directIn;
}
