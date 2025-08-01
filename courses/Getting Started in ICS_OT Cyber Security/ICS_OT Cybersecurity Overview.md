# ICS/OT Cybersecurity Overview

> Vidath Dissanayake | Sri Lanka  
> Links: [Getting Started in ICS_OT Cybersecurity](Getting%20Started%20in%20ICS_OT%20Cybersecurity.md)
> Sources: [course video 2](https://www.youtube.com/watch?v=Ue8JjQigv-4&list=PLOSJSv0hbPZAlINIh1HcB0L8AZcSPc80g&index=2) [Stuxnet](https://en.wikipedia.org/wiki/Stuxnet) [ISA 62443](https://www.isa.org/standards-and-publications/isa-standards/isa-iec-62443-series-of-standards)

---

## Differences Between IT and ICS/OT

Information Technology (IT) refers to the systems (e.g. laptops, workstations, servers) used to store and process data.

Operational Technology (OT) refers to technology that manages any process that manipulates some type of action in the real world.

Industrial Control Systems (ICS) are larger scale deployments as a subset of OT in industrial environments.

**For the purpose of this course, the terms ICS and OT are used interchangeably.**

In IT usually large amounts of data is stored and processed. In OT, usually only small amounts of data is processed and stored. 

In OT, safety is the primary consideration. Safety primarily includes safety of personnel and public. ICS/OT security is concerned with,
- physical safety
- environmental safety
- availability

In IT, the primary consideration is the [CIA triad](../../Cybersecurity/hacking/principles%20and%20standards%20of%20infosec/CIA%20triad/CIA%20triad.md). Here the concern is about digital danger. More focus is given to confidentiality and integrity over availability. In OT, availability gets more focus.

Most OT networks these days have a connected IT network. This introduces digital dangers to the system. An attacker that gets into the IT network can gain access to the OT environment and use that as a foothold to do further damage.

Usually, the OT system sends information to the IT systems. Such as the amount of product created. However, there is typically no need for network communication to originate from IT and influence OT systems. Sometimes this is not possible. However, it is important to keep in mind that allowing IT to influence OT can be dangerous if compromised. It is recommended to use a firewall to block this access.

An [IoT](../../IoT/IoT.md) device is typically different from an OT device. IoT is a term used to refer to consumer devices that require [Internet](../../network/the%20Internet/the%20Internet.md) connectivity for functionality. Such devices have limited computing capability and requires significant computing resources made available by the cloud. 

---

## Common Ways Attackers Enter ICS/OT Networks

1. From the IT back office/enterprise network
    - As previously discussed, if the IT network is compromised, attackers can take over the entire IT network and then find the path into the OT systems if they are exposed. 
2. Physically brought in by “transitory cyber assets”
    - These are equipment such as laptops, USB drives, and mobile phones that can be brought into the environment. If that asset is infected, and is then connected to the system, the OT system may get infected as well. This can damage air gaped systems as well. A famous example of this kind of attack is [Stuxnet](https://en.wikipedia.org/wiki/Stuxnet).
3. Control systems directly exposed to the internet
    - This is common, specially in smaller systems. If a vulnerability exists in that exposed system, it can be exploited and used as a foothold for further attacks.
4. Via remote access capabilities
    - Remote access is used to cut down on transport costs and when there is no other option, such as during a pandemic. Remote access is also used to ensure safety by allowing to perform maintenance in usually unsafe areas. Therefore, sometimes remote access is necessary and should be used securely as possible.
5. Malicious insiders
    - Insider threat is one of the largest concerns in IT, and it also applies to OT. Employees who already have access to the OT systems can act maliciously and allow attacks in or act as an attacker themselves.

---

## A Simple OT Example

A thermostat is a simple OT example. 
- It is set to a certain temperature.
- It uses sensors to continuously check the temperature. 
- If the temperature rises above or falls below a certain threshold, it sends a signal to the air conditioning system to turn on.
- Once the temperature is within the desired range, it sends a signal for the A/C to turn off.
- This is called the control loop.
![thermostat as a simple OT example](assets/images/thermostat%20as%20a%20simple%20OT%20example.png)

The concern is when this thermostat is given an [IP address](../../network/communication%20protocol/TCP%20IP%20layer%202/OSI%20layer%203/IP/IP%20address.md). Then, while it may only be able to talk to the other devices on the [LAN](../../network/lan/LAN.md), if any of them are compromised, attackers can talk to the thermostat and make it behave as they want. For example, in this case, they can increase the temperature, decrease the temperature or change the reported temperature. In a more complicated OT system, this can easily lead to a physical safety issue. 

---

## Types of Industrial Control Environments

### ICS vs SCADA

ICS refers to all control systems in a single location.
- Think of this as similar to a LAN.

Supervisory Control and Data Acquisition (SCADA) often refers to control systems that communicate over multiple locations over wide area links. These links can be 4G/5G, satellite, or fibre optic.
- Think of this as similar to a WAN.

A single power plant is considered ICS. Communication with substations that are along the power transmission lines is SCADA. 

SCADA can be a collection of ICS.

![ICS vs SCADA](assets/images/ICS%20vs%20SCADA.png)

### Critical Infrastructure Sectors

There are several sectors that are considered as critical infrastructure and OT is operating in almost all of them. Space may be added as a sector in the future as well.

![critical infrastructure](assets/images/critical%20infrastructure.png)

---

## What is ICS/OT Cybersecurity?

Focus is on securing ICS/OT systems from cyber threats. These threats can come over the network or from a cyber asset.
- E.g: PLCs, data historians, engineering workstations, maintenance laptops or tablets, USB drives.

Cyber attacks can have severe real world consequences. For example, a power plant going offline for 3 months would be disastrous. 

Physical attacks should be taken into consideration. If an attacker can walk in and physically touch a system, they can almost always take full control of it or steal it. They can also leave an asset such as a Kali Dropbox to use as a foothold for attack.

---

## Annotated History of ICS/OT Cybersecurity

The type of attackers that target ICS/OT systems have changed significantly since about 2021. Before 2021, it was mostly nation state threat actors and APTs that were attacking these kinds of systems (for example, Stuxnet).

As of 2021, 
- nation state threat actors
- criminal organizations
- ransomware groups
- hacktivists
- cyber mercenaries
- lone wolves
- script kiddies
that is to say, everyone is targeting these systems. A prime example is the [Colonial Pipeline ransomware attack](https://en.wikipedia.org/wiki/Colonial_Pipeline_ransomware_attack).

These are some notable attacks in the history on ICS/OT.

![a history of major ICS/OT cyber incidents](assets/images/a%20history%20of%20major%20ICS_OT%20cyber%20incidents.png)
![notable malware for OT](assets/images/notable%20malware%20for%20OT.png)

---

## Hybrid Approach to ICS/OT Cybersecurity

[ISA 62443](https://www.isa.org/standards-and-publications/isa-standards/isa-iec-62443-series-of-standards) is currently the gold standard for ICS/OT cybersecurity. It is a collection of standards to address different aspects of cybersecurity in ICS/OT systems created by ISA 99 Standards Committee. It establishes a common set of rules that asset owners and operators can use to secure their facilities. 

Similar to IT systems, there are some critical security controls that mitigate most of the risk.

![OT critical security controls](assets/images/OT%20critical%20security%20controls.png)

---

## The Sliding Scale of Cybersecurity

In this scale, it is better to do the things at the left first for the best return on investment.

![sliding scale for OT security](assets/images/sliding%20scale%20for%20OT%20security.png)
![cost of controls in OT](assets/images/cost%20of%20controls%20in%20OT.png)

---

## Terminology

### Inside Battery Limits (ISBL)

ISBL refers to the systems and processes that make up the facility. These directly contribute to production. These can include,
- turbines
- generators
- condensers
- cooling systems
- electrical systems
- industrial control and instrumentation systems
- reactors
- distillation columns.

### Outside Battery Limits (OSBL)

OSBL refers to on-site supporting locations and systems that are required for the safe operation of the facility. These can include,
- administrative buildings (control room, data centre, staff offices)
- storage facilities
- wastewater treatment
- cooling tower
- water intake.

![ISBL vs OSBL](assets/images/ISBL%20vs%20OSBL.png)

### Greenfield Projects

This is a brand-new facility. It is much easier to implement cybersecurity in a Greenfield facility as it can be a focus from the start.

### Brownfield Projects

This is a redesign or addition to an existing facility. Small changes can have significant and unforeseen effects as these systems are old and complicated or not well implemented. Care should be taken when implementing cybersecurity in such a facility.


## Common Ports in ICT/OT

Here are some common ports used in ICS/OT environments.

![common ports in ICS](assets/images/common%20ports%20in%20ICS.png)