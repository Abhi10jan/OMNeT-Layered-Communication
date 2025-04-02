
#ifndef __LAB_7_NL_NODE_H_
#define __LAB_7_NL_NODE_H_

#include <omnetpp.h>
#include<NL_PDU_m.h>
using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Nl_node : public cSimpleModule
{
  protected:
    int id;
    cGate *in;
    cGate *out;
    int remaining_packets;
    int source;
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
