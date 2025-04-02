

#include "dll_node.h"

Define_Module(Dll_node);

void Dll_node::initialize()
{
    id=par("dll_id");
    in_n=gate("dlln_in");
    out_n=gate("dlln_out");
    in_p=gate("dllp_in");
    out_p=gate("dllp_out");
}

void Dll_node::handleMessage(cMessage *msg)
{
    if(msg->getArrivalGate()==in_n)
    {
        Dll_pkt* data=new Dll_pkt();
        Nl_pkt* data_to_encapsulate=check_and_cast<Nl_pkt*>(msg);
        data->encapsulate(data_to_encapsulate);
        data->setDll_pkt_type(1);
        send(data,out_p);
    }
    else if(msg->getArrivalGate()==in_p)
    {
        Dll_pkt* message=check_and_cast<Dll_pkt*>(msg);
        if(message->getDll_pkt_type()==1)
        {
            message->decapsulate();
            send(message,out_n);
            Dll_pkt* ack=new Dll_pkt();
            ack->setDll_pkt_type(0);
            send(ack,out_p);
        }
        else{
            delete(msg);
        }

    }
}
