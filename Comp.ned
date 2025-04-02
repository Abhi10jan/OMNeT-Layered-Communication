module Comp
{
    parameters:
        int p_id;
        @display("bgb=421,299");

    gates:
        input p_in;
        output p_out;

    submodules:
        Nl: Nl_node {
            @display("p=287,248");
        }
        Dll: Dll_node {

            @display("p=83,77;is=l");
        }
    connections:
        Nl.nl_out --> Dll.dlln_in;   //output of network layer to input 
        Dll.dlln_out --> Nl.nl_in;
        Dll.dllp_out --> p_out;      //packet from dll output goes directly to output of physical layer 
                                    //without going to input of physical layer
        p_in --> Dll.dllp_in;
}
