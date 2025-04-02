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

#include "nl_node.h"

Define_Module(Nl_node);

void Nl_node::initialize()
{
    remaining_packets=par("remaining_packets");
    id=par("nl_id");
    in=gate("nl_in");
    out=gate("nl_out");
    source=par("source");
    if(id==source)
    {
        cMessage *event =new cMessage();
        scheduleAt(0,event);
    }

}

void Nl_node::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        Nl_pkt* data=new Nl_pkt();
        if(remaining_packets==0)
        {
            return;
        }

        data->setNl_pkt_id(remaining_packets--);
        data->setNl_pkt_type(1);   //1 for data and 0 for acknowledgment;
        send(data,out);
        cMessage *event=new cMessage;
        scheduleAt(simTime()+200,event); //200ms is RTT so after that much time a new packet will be created

   }
    else
    {
        delete(msg);  //when the packet reaches destination it will be deleted;
    }
}
