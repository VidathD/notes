# Secure Network Architecture

> Vidath Dissanayake | Sri Lanka  
> Links: [Getting Started in ICS_OT Cybersecurity](Getting%20Started%20in%20ICS_OT%20Cybersecurity.md)
> Sources: [Getting Started in ICS/OT Cyber Security part 4](https://www.youtube.com/watch?v=kbiMb_Kgqjs&list=PLOSJSv0hbPZAlINIh1HcB0L8AZcSPc80g&index=4) [Industry 4.0](https://en.wikipedia.org/wiki/Fourth_Industrial_Revolution)

---

Without Secure Network Architecture, a malware infection in the IT systems can easily move into the OT systems.

## The IT Cyber Kill Chain

See [Cyber Kill Chain](../../Cybersecurity/hacking/principles%20and%20standards%20of%20infosec/Cyber%20Kill%20Chain.md) for more information.

---

## The Expanded Purdue Model

The Expanded Purdue Model defines different levels of logically segmenting both the IT and OT networks. It promotes security between IT and OT while providing additional security inside the OT environment.

![Purdue model](assets/images/Purdue%20model.png)

This model divides the environment into layers that have different security considerations and functionality.

Levels 0, 1, 2, 3 belong to the OT environment while levels 4 and 5 belong to the IT environment. Level 3.5 is a DMZ that is between these two environments. In the perspective of OT, IT is an untrusted network. Therefore, there should be protections between these two. With a DMZ, these are separated by two firewalls. 

Ideally, IT should not be able to talk to OT. Only OT should be providing information to IT. Anything that come into the OT network should come because of a request from OT. 

Generally, systems in a layer should only be able to communicate with devices that are one layer above or below them. 

### Functionality of the OT/IT DMZ

The DMZ houses those systems that should be directly reachable from the IT network. It ensures that network filtering is in place to prevent direct compromise of the OT network from IT. In case the DMZ is compromised, the second firewall filters traffic to OT network to prevent infection. In a perfect world, no connections originate from IT. Only OT pushes data to the IT network to enable the business to function.

### Functionality of the OT Environment

#### Level 3: Site Operations

This level is responsible for the monitoring and control over the assets at the site level. This layer consists of traditional IT resources such as Windows servers and workstations. An additional layer of firewall exists between this layer and the rest of OT network.

#### Level 2: Supervisory Control

Responsible for monitoring and control of specific areas or groups of assets. This layer can also include systems similar to previous layers, such as Windows machines, but includes industrial control assets such as HMIs and PLCs.

#### Level 1: Basic Control

Devices in this level interface directly with field devices. This layer includes [Safety Instrumented System (SIS)](Control%20Systems%20and%20Protocols.md#Safety%20Instrumented%20System%20(SIS)) in a physically separate network for an added layer of security. It should not be possible to connect to the SIS remotely and manage it in any way. Windows is almost never seen and all machines run custom OSes that are usually Linux based.

#### Level 0: Process

Field devices interact directly with the physical world.
- Sensors measure physical parameters or states.
- Actuators include motors, valves, and relays which are controlled by PLCs and make things move in the real world.


### Controls for Purdue Model

#### Firewalls

This can be achieved with a [firewall](../../Cybersecurity/cyber%20defenses/firewall.md). The firewall should be configured to block all traffic by default and exceptions are made to allow required traffic with rules being as specific as possible. OT specific firewalls exist that understand ICS/OT protocols and can perform deep packet inspection on them.

Following is an implementation of firewall rules that is too permissive. RDP and HTTP(S) should not be available for anyone to access. This is allowing IT to talk to OT too much.

![permissive firewall](assets/images/permissive%20firewall.png)

There should be two firewalls on either side of the DMZ in the Dual-Homed structure. Ideally, they are from different vendors, which will prevent an attacker with an exploit against one from taking over the whole network.

![dual-homed firewall](assets/images/dual-homed%20firewall.png)

Sometimes to save money, Triple-Homed structure is used. However, this is not necessarily a good idea as if the attacker can take over the firewall, usually form the IT side, they can directly gain access to the OT systems.

![triple homed firewall](assets/images/triple%20homed%20firewall.png)

Network switches with Layer 3 IP routing capabilities can be used to implement network Access Control Lists (ACLs). While these mimic firewalls, they do not provide the same level of security. If security is a concern, they shouldn't be used to replace actual firewalls. Several attacks such as VLAN hopping and double tagging exist that can be used to bypass ACLs on a network switch.

#### Data Diodes and Unidirectional Gateways

Data diodes are network appliances which use physics to ensure that data can only flow in one direction. 
- Allows OT to push data to IT without any chance of return connections.
- Prevents all inbound connections from IT to OT.

Unidirectional gateways use hardware and software to emulate the functionality of a data diode, usually at a lower cost.

Unlike firewalls and unidirectional gateways, data diodes are physical systems and therefore cannot be hacked (unless physically tampered with).

---

## The ICS Cyber Kill Chain

Michael J. Assante and Rob M. Lee along with SANS created the ICS Cyber Kill Chain. 

![ICS cyber kill chain](assets/images/ICS%20cyber%20kill%20chain.png)

Stage 1 is essentially the same as the usual IT [Cyber Kill Chain](../../Cybersecurity/hacking/principles%20and%20standards%20of%20infosec/Cyber%20Kill%20Chain.md). However, to exploit ICS systems, a second stage is needed as shown.

![SANS ICS kill chain](assets/images/SANS%20ICS%20kill%20chain.png)

---

## ISA 62443: Zones and Conduits

Zones are logical groups of like assets that serve a similar purpose.

Conduits are the communication paths between zones.

More about this in [Industry Standards and Regulations](Industry%20Standards%20and%20Regulations.md).

---

## IIoT (Industrial Internet of Things)

In IIoT, the ICS/OT environment is purposefully connected to the internet. This requires additional security measures to ensure that the OT network is safe. This usually doesn't require return traffic. Data diodes and unidirectional gateways can be used for this.

The main requirement is for the OT systems to send process data to powerful analytics platforms that cannot be housed locally on-site. Predictive analytics and identifying opportunities for streamlining processes can require internet connection. This is often discussed under [Industry 4.0](https://en.wikipedia.org/wiki/Fourth_Industrial_Revolution). 

---

## Secure Remote Access

- Many ICS/OT environments allows vendors, integrators and other parties to remotely access the ICS/OT network from over the Internet. 
- Primary incentives for doing so include reduced costs of outside parties having to travel to the site and physical safety/security considerations.
- This introduces additional attack surface that attackers can use to gain access to the OT systems.
