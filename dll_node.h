

#ifndef __LAB_7_DLL_NODE_H_
#define __LAB_7_DLL_NODE_H_

#include <omnetpp.h>
#include<NL_PDU_m.h>
#include<DLL_PDU_m.h>
using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Dll_node : public cSimpleModule
{
  protected:
    int id;
    cGate *in_n;
    cGate *out_n;
    cGate *in_p;
    cGate *out_p;

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
