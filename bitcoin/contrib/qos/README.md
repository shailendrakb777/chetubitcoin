### QoS (Quality of service) ###

This is a Linux bash script that will set up tc to limit the outgoing bandwidth for connections to the H2hcoin network. It limits outbound TCP traffic with a source or destination port of 8333, but not if the destination IP is within a LAN.

This means one can have an always-on h2hcoind instance running, and another local h2hcoind/h2hcoin-qt instance which connects to this node and receives blocks from it.
