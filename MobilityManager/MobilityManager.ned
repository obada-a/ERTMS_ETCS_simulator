package treno2.MobilityManager;

simple MobilityManager
{
    parameters:
	double timeOutSpostamento @unit(s);
	double initialSpeedX;
	double initialSpeedY;
        @display("i=block/cogwheel");
    gates:
}