
network Layerednetwork
{
    parameters:
        int source;
        int dest;

        @display("bgb=345,281");
    submodules:
        N1: Comp {
            p_id = 1;
            @display("p=67,74");
        }

        N2: Comp {
            p_id = 2;
            @display("p=242,74;is=l");
        }

    connections:
        N1.p_out --> {  delay = 100ms; } --> N2.p_in;
        N2.p_out --> {  delay = 100ms; } --> N1.p_in;
}
