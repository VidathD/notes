# Control Systems and Protocols

> Vidath Dissanayake | Sri Lanka  
> Links: [Getting Started in ICS_OT Cybersecurity](Getting%20Started%20in%20ICS_OT%20Cybersecurity.md)
> Sources: [Getting Started in ICS/OT Cyber Security part 3](https://www.youtube.com/watch?v=WReeJDw-AV4&list=PLOSJSv0hbPZAlINIh1HcB0L8AZcSPc80g&index=3) [ICS Security Tools](https://github.com/ITI/ICS-Security-Tools) [GRFICSv2](https://github.com/Fortiphyd/GRFICSv2)

---

## Control Systems

There are several types of control systems.

### Field Devices

Field devices are responsible for taking measurements from the physical world as well as taking action in the physical world. These are the low level devices that actually do the work.

- Sensors
    - Temperature
    - Humidity
    - Motion
- Actuators
    - Valves
    - Pumps
    - Compressors
- Motors

Usually, but not always, physical access is needed to influence the functionality of these. Therefore, they are the most overlooked part in a cybersecurity perspective.

### Programmable Logic Controller (PLC)

This is the most common type of control system. Similar to a standard computer system, PLCs, have their own processor, memory, and storage. This is often not large amounts of data. There are ruggedized to be able to function within extreme environments.

They are programmed using specialized software and languages. 
- Ladder Logic is the most common PLC programming language.
- Try Ladder Logic at [PLC Simulator](https://app.plcsimulator.online/).
    ![PLC simulator](assets/images/PLC%20simulator.png)

To interact with the physical world, PLCs talk to [Field Devices](#Field%20Devices) as inputs and outputs (I/Os).

Each I/O is physically wired into other systems.
- Setpoints
    - Determines a baseline value for the system.
    - Any value over or under the baseline value should be acted on.
- Inputs allow PLC to receive information from other systems.
    - Receive current temperature
    - Receive current humidity
- Outputs allow PLC to send signals to the system.
    - Turn on the heater
    - Turn on the dehumidifier

Here is a simple illustration of PLC and I/O in a power plant.

![PLC in power plant](assets/images/PLC%20in%20power%20plant.png)

When a threat actor gets access to an environment, they may gain access to a PLC but not know what it is controlling. They need to reverse-engineer the process data to understand what is connected.

PLCs have two modes that are controlled by physical switches. Some models may have more modes.
- Program mode allows the PLC to have its code updated.
    - This mode should only be turned on during an update. Leaving it on otherwise leaves the PLC in an unsecure state.
- Run mode places the PLC into a “read only” mode.
    - In this mode, the system runs and performs its function but cannot be updated.
    - This prevents remote attackers from influencing the PLC.

### Distributed Communication System (DCS)

Think of this as Active Directory for OT systems. These provide monitoring and control capabilities of multiple **local** systems. 

![DCS in power generation](assets/images/DCS%20in%20power%20generation.png)

This is different from SCADA which provides monitoring and control capabilities over **remote** systems. These are often used to automate tasks rather than dispatch worker.

### Human Management Interface (HMI)

HMI provides a GUI for a human to interact with a control system such as a PLC. 

![HMI example](assets/images/HMI%20example.jpeg)

HMIs are top targets for attackers because it provides greater visibility and control over the system allowing attackers to more easily understand the system. These 

HMIs typically run as web interfaces and can be accidentally exposed to the internet, which can be dangerous. They are sometimes exposed in a read-only mode, which is less dangerous but provides visibility to attackers.

There are cyber risks with HMIs and other graphical interfaces due to cyberattacks.
- Loss of Visibility
    - The operator is not able to determine the exact status of a particular process.
        - Could look abnormal, such as created by a system failure.
        - Could appear normal due to an attacker's interference.
- Loss of Control
    - The operator is unable to interact with the system remotely.
        - Created by a system failure
        - Introduced by an attacker
- Loss of Visibility and Control

### Safety Instrumented System (SIS)

This is the most important system in the environment. It acts as a failsafe for an ICS/OT facility. It is designed explicitly to protect human life and the facility.

It monitors the facility and allows the site to be shutdown safely in the event an unsafe, or potentially unsafe condition is alerted on.

Safety functions are designed as Safety Instrumented Functions (SIF). This system is designed separately from the rest of the network. 

This was highlighted during the [Triton/Trisis](https://en.wikipedia.org/wiki/Triton_(malware) incident in 2017. This is the only known ICS/IT attack to specifically target human life.

### Engineering Workstation (EWS)

This is a “normal” computer, typically running Windows, that is used to run software for programming assets, such as PLCs.

It should be protected as any traditional IT workstation. Special consideration is taken for the physical and cyber protection of the asset, along with the protection of the data on it. 

If it is a laptop, more care should be taken as it can be taken offsite.

If an attacker gains access to a EWS, they will have access to the programming data and will be able to reverse engineer the processes.

### Data Historian

This is typically a traditional database server running a commodity operating system and database management system. 
- E.g: Windows Server running MS SQL Server

It stores process data. This is data collected from OT operations on the site. This includes data generated by field devices and sent to centralized control systems such as DCS or SCADA. This data is presented to operators and engineers in GUIs such as HMIs. They are continually monitored to ensure the operation of the facility can identify future failures.
- How many resources were consumed.
- How much product was made
This storage in Data Historians allows for real-time analysis or time-series format for later analysis.

![control room of a power plant](assets/images/control%20room%20of%20a%20power%20plant.jpg)

Most environments will have multiple data historians for secure architecture purposes between ICS and IT networks.

This is a very popular target for attackers due to its IT based attack surface as well as availability in both IT and OT networks.

### Other Types of Control Systems

There are many other types of control systems. While less common, they can be very important to their systems.

- Remote Terminal Units (RTU)
- Intelligent Electronic Devices (IED)
- Variable Frequency Drives (VFD)
- Phasor Management Unit (PMU)
- Process Control System (PCS)
- Very Small Aperture Terminal (VSAT)
- Data Acquisition System (DAS)
- Distribution Management System (DMS)
- Energy Management System (EMS)
- Manufacturing Execution System (MES)

---

## Industrial Control Protocols

In this course we will be using the packet captures at [ICS Security Tools](https://github.com/ITI/ICS-Security-Tools) for analysis. We can also use [GRFICSv2](https://github.com/Fortiphyd/GRFICSv2) to emulate an ICS environment.

### Modbus

See [Modbus](../../IoT/ICS_SCADA/ICS%20protocols/Modbus.md) for information about this protocol.

### S7comm

See [S7comm](../../IoT/ICS_SCADA/ICS%20protocols/S7comm.md) for more information about this protocol.

### OPC UA

Open-source standard created by the OPC Foundation to enable sensor to cloud communication. It has a platform independent and service oriented architecture.

It supports publish-subscribe and client-server models and multiple transport protocols.
- TCP
- UDP
- MQTT
- AMQP
- WebSockets

It also includes several security features.
- Authetication
- Autherization
- Encryption
- Key management

### Other Industrial Control Protocols

- BACnet
- Ethernet/IP
- DNP3
- Tridium Fox
- HART
- PCWorx
- Omron
- CODESYS

---

## Wireless

Many plants and facilities use wireless protocols without considering the security risk. Some commonly used wireless OT protocols are,
- 802.11 Wi-Fi
- ZigBee
- WirelessHART