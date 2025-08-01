
# The Cyber Kill Chain

> Vidath Dissanayake | Sri Lanka  
> Links: [principles and standards of infosec](principles%20and%20standards%20of%20infosec.md)
> Sources: [Lockheed Martin Cyber Kill Chain](https://www.lockheedmartin.com/en-us/capabilities/cyber/cyber-kill-chain.html) [# Getting Started in ICS/OT Cyber Security part 4](https://www.youtube.com/watch?v=kbiMb_Kgqjs&list=PLOSJSv0hbPZAlINIh1HcB0L8AZcSPc80g&index=4)

---

Created by Lockheed Martin in 2011, the Cyber Kill Chain framework identifies what the adversaries must complete in order to achieve their objective.

![cyber kill chain](assets/images/cyber%20kill%20chain.png)

---
## Reconnaissance

First, an adversary must perform reconnaissance on the target to gather information. This can include everything from OSINT to network scanning.

## Weaponization

In this phase the payload is created and a method of delivery is decided. They are then linked to work together.

## Delivery

This is the phase where the payload is delivered to the target. This can be though email, web, USB or the network.

## Exploitation

In this phase, the payload exploits a vulnerability in the target and gains access to it. 

## Installation

After successful exploitation, malware is installed on the system.

## Command and Control (C2)

The malware calls out to a C2 server and provides a command channel for remote manipulation of the victim.

## Actions on Objectives

With “Hands on Keyboard” access to the systems, the attackers can now achieve their original goals.