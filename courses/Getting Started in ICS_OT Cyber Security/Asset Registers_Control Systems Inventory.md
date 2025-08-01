# Asset Registers/Control Systems Inventory

> Vidath Dissanayake | Sri Lanka  
> Links: [Getting Started in ICS_OT Cybersecurity](Getting%20Started%20in%20ICS_OT%20Cybersecurity.md)
> Sources: [Getting Started in ICS/OT Cyber Security part 5](https://www.youtube.com/watch?v=madBOec2s74&list=PLOSJSv0hbPZAlINIh1HcB0L8AZcSPc80g&index=6)

---

## The Important Role of Asset Registers

This is an inventory of all hardware and software within an environment. It needs to include **all** assets, including hardware, software, and firmware assets. This also includes virtualized assets.

An asset register is never going to be perfect, as the assets can always change. 
- A maintenance technician can connect a new field device.
- A PLC programmer connects a new EWS to the network.
- Someone can plug in a USB drive.
- A bored team member in the control room can plug in an Xbox. 
- An attacker can plant a device.

We cannot protect what we don't know we have. So it is important to have an asset register that is as accurate as possible. This provides a strong foundation for threat and vulnerability management.

If an attacker gains access to an asset register, they will have a map of the environment and will be able to plan future attacks more easily. 

---

## Creating an Asset Register

The most common asset register tool is Excel. Other database software and COTS (Commercial Off-the-Shelf) solutions also exist. When using cloud based applications, risk of it falling onto attackers hands should be considered. 

![what to store in an asset register](assets/images/what%20to%20store%20in%20an%20asset%20register.png)
![sample asset register](assets/images/sample%20asset%20register.png)

### Obtaining Data for Asset Register

There are several methods of obtaining data to build an asset register.

- Walking the environment
    - Physically trace cables through the environment.
    - This can be unsafe depending on the environment.
- Review existing data
    - Network diagrams, programming data, project files, procurement info
- Review network packet captures
    - Use tools such as [Wireshark](../../tools/hacking/network/packet%20sniffers/wireshark/Wireshark.md) to analyse passively captured network data
- Actively scan the environment
    - Tools such as [Nmap](../../tools/hacking/network/scanning/Nmap.md) can be used to send network packets on the network to test for the presence of assets and additional information gathering techniques.
    - **WARNING** Active scanning can be considered harmful in ICS/OT.

#### Walking the Environment

This is considered the most physically dangerous option, as it requires team members to be exposed. It is also the most time-consuming and requires the most effort. It can also cause production issues if a mistake is made, such as a cable coming loose. 

During this, basic maintenance checks can also be done, such as ensuring that PLC key switch is in “Run” mode. However, some may not have a physical key switch.

#### Review Project File Data

Information about the assets in the environment can exist in multiple places.
- Project files
    - Network diagrams
    - System design specifications
    - PLC programming files
    - Asset specifications
    - Project plans and schedules
    - Change management records
    - Purchase records
- Network appliance configurations
    - [ARP](../../network/communication%20protocol/TCP%20IP%20layer%201/ARP.md) tables

![using network devices to find assets](assets/images/using%20network%20devices%20to%20find%20assets.png)
![ARP tables in Windows and Linux](assets/images/ARP%20tables%20in%20Windows%20and%20Linux.png)

#### Network Mapping of ICS/OT Networks

Different “scanning” techniques can be used to discover live hosts, open ports, services, applications, vendors, versions and more.

Not all assets run TCP/IP but use industrial control protocols for communication (e.g., Modbus, S7comm).

##### Active Scanning

Active scanning sends network packets to discover live hosts and associated services.

Usually not allowed for use in ICS/OT environments due to concerns that active scanning can cause certain OT assets, particularly older ones, to reset, crash or completely brick.

The most common network scanning tool is [Nmap](../../tools/hacking/network/scanning/Nmap.md) which was originally designed to discover live hosts and open ports in IT environments.

The goal of these scans is to find,
- Live hosts (Using a ping sweep with `nmap -sP`)
- Open ports (With a port scan) 
    - There are 65535 ports for [TCP](../../network/communication%20protocol/TCP%20IP%20layer%203/OSI%20layer%204/TCP.md) and same number for [UDP](../../network/communication%20protocol/TCP%20IP%20layer%203/OSI%20layer%204/UDP.md)
    - 1 to 1023: Well-known ports
    - 1024 to 49151: Registered ports
    - 49151 to 65535: Free ports
- Services/apps
- Versions
- Vulnerabilities




## Change Management

## Monitoring Control System State

## Securing the Asset Register