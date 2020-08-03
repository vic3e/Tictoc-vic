//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Txc.h"

namespace helloworld_1 {

// your module
//Define_Module(Txc);

/*
void Txc::initialize()
{
    if (par("sendInitialMessage").boolValue())
    {
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

void Txc::handleMessage(cMessage *msg)
{
    // just send back the message we received
    send(msg, "out");
}*/

// The module class needs to be registered with OMNeT++/
Define_Module(Txc);
void Txc::initialize()
    {
     // Initialize is called at the beginning of the simulation. // To bootstrap the tic-toc-tic-toc process, one of the modules needs
     // to send the first message. Let this be `tic'.
     // Am I Tic or Toc?
     if (strcmp("tic", getName()) == 0) {
     // create and send first message on gate "out". "tictocMsg" is an
     // arbitrary string which will be the name of the message object.
     cMessage *msg = new cMessage("tictocMsg");
     // We draw a random number between 0 and the size of gate `out[]'.
     int n = gateSize("out");
     int k = intuniform(0, n-1);

     EV << "Sending message " << msg << " on port out[" << k << "]\n";
     send(msg, "out", k);
     }
    }
 /*   void Txc::handleMessage(cMessage *msg)
    {
     // The handleMessage() method is called whenever a message arrives
     // at the module. Here, we just send it to the other module, through
     // gate `out'. Because both `tic' and `toc' does the same, the message
     // will bounce between the two.
     send(msg, "out", 1); // send out the message
    }*/

    void Txc::handleMessage(cMessage *msg)
    {
        // In this example, we just pick a random gate to send it on.
        // We draw a random number between 0 and the size of gate `out[]'.
        int n = gateSize("out");
        int k = intuniform(0, n-1);

        EV << "Forwarding message " << msg << " on port out[" << k << "]\n";
        send(msg, "out", k);
    }





}; // namespace
