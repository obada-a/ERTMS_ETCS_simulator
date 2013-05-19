package treno2.SRB;

simple Tx_to_BSC
{
    gates:
        output out;
        input gateChannelIn;
}

simple Rx_from_BSC
{
    gates:
        input in;
        output gateChannelOut;
}

simple Tx_to_Channel
{
    gates:
        input gateBscIn;
        input gateHelloM;
}

simple Rx_from_Channel
{
    gates:
        output gateBscOut;
        input in;
}

simple HelloManager
{
    parameters:
        double frequenzaDati;
        double frequenzaSegnalazione;
        double frequenzaPilota;
        double helloTimeOut @unit(s);
    gates:
        output out;
}

module Srb
{
    @display("i=device/antennatower");
    gates:
        output out;
        input in;
        input in_from_channel @directIn;
    submodules:
        tx_to_bsc: Tx_to_BSC {
            @display("p=227,58");
        }
        rx_from_bsc: Rx_from_BSC {
            @display("p=68,58");
        }
        tx_to_channel: Tx_to_Channel {
            @display("p=68,137");
        }
        rx_from_channel: Rx_from_Channel {
            @display("p=227,137");
        }
        hm: HelloManager {
            @display("p=150,97");
        }
    connections:
        tx_to_bsc.gateChannelIn <-- rx_from_channel.gateBscOut;
        tx_to_bsc.out --> out;
        rx_from_bsc.gateChannelOut --> tx_to_channel.gateBscIn;
        rx_from_bsc.in <-- in;
        hm.out --> tx_to_channel.gateHelloM;
        in_from_channel --> rx_from_channel.in;
}