# OMNeT++ Layered Communication Simulation

## **Project Description**

This project implements communication between devices in a **layered environment** using the **Protocol Data Unit (PDU) concept** in OMNeT++. The simulation models a **two-node network** where each node contains a **network layer** and a **data link layer**, demonstrating encapsulation, decapsulation, and acknowledgment mechanisms.

## **Objective**

To simulate communication between network devices in a layered architecture using **PDUs** while demonstrating key OMNeT++ simulation concepts.

## **Network Design**

1. A network named **layerNetwork** is created with two nodes.
2. Each node consists of two layers:
   - **Network Layer**
   - **Data Link Layer**
3. Both nodes are connected with a **100ms delay channel**.
4. The communication is implemented using PDUs:
   - **N\_PDU** (Network Layer PDU)
   - **DL\_PDU** (Data Link Layer PDU)
5. The network layer passes packets to the data link layer, which then sends **DL\_PDUs** to the destination node.

## **Protocol Design and Simulation**

1. **Parameter Configuration in **``
   - Define **source address, destination address**, and **number of packets**.
   - Enable **event logging** and **packet tracing**.
2. **Network Layer Communication**
   - The **Source Node (SN)** sends **10 N\_PDUs** to the **Destination Node (DN)**.
   - Each packet is delayed based on **Round-Trip Time (RTT)**.
   - The **DN receives and deletes each packet** after successful transmission.
3. **Data Link Layer Communication**
   - SN encapsulates each **N\_PDU** into a **DL\_PDU**.
   - IDs are assigned in a **modulo-2** fashion (0 or 1 alternately).
   - DN receives, decapsulates, and **sends an acknowledgment (ACK)** back to SN.
   - DN forwards the decapsulated PDU to the upper layer.

## **Project Goals**

- Understand **packet creation**, **node movement**, and **design vs. source code mode**.
- Learn about **.h and .cc files**, `omnetpp.h`, `_m.h`, and namespaces.
- Implement key **OMNeT++ functions** such as:
  - `par()`, `gate()`, `cMessage`, `scheduleAt()`, `isSelfMessage()`, `send()`
  - `setPID()`, `getPID()`, `setPType()`, `getPType()`, `setSrc()`, `setDest()`
- Gain experience in **event-driven simulation and protocol design**.




