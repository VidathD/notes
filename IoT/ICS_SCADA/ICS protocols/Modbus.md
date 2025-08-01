# Modbus

> Vidath Dissanayake | Sri Lanka  
> Links: [ICS Protocols](ICS%20Protocols.md)
> Sources: [modbus.org](https://modbus.org) [Getting Started in ICS/OT Cyber Security part 3](https://www.youtube.com/watch?v=WReeJDw-AV4&list=PLOSJSv0hbPZAlINIh1HcB0L8AZcSPc80g&index=3) [Modbus Wikipedia](https://en.wikipedia.org/wiki/Modbus)

---

Modbus is the most common ICS/OT protocol in use today. It is a royalty-free protocol available at [modbus.org](https://modbus.org). Modbus works over TCP/IP and the default port is TCP 502. 

It works similar to [SNMP](../../../network/communication%20protocol/TCP%20IP%20layer%204/OSI%20layer%207/SNMP.md) in the sense that it allows remote reading and writing of system variables in a client-server configuration.
- Allows an engineer to make PLC programming changes.
- Allows a maintenance technician to upgrade the PLCs firmware.
- Allows an attacker to remotely manipulate the PLC process.

Data can be stored in fields called coils and registers. Each of these can be read or written. 
- Coils store binary values to indicate only two states. (True/False, On/Off)
- Registers store larger data (16/32-bit integers, floating point numbers)

The registers and coils are numbered with base 0 (first register is 0).

## Function Codes

Modbus uses function codes as commands.

![Modbus function codes](assets/images/Modbus%20function%20codes.png)

### Data Access

- 1 Read Coils
- 2 Read Discrete Inputs
- 3 Read Multiple Holding Registers
- 4 Read Input Registers
- 5 Write Single Coil
- 6 Write Single Holding Register
- 15 Write Multiple Coils
- 16 Write Multiple Holding Registers
- 20 Read File Record
- 21 Write File Record
- 22 Mask Write Register
- 23 Read/Write Multiple Registers
- 24 Read FIFO Queue

### Diagnostics

- 7 Read Exception Status
- 8 Diagnostic
- 11 Get Com Event Counter
- 12 Get Com Event Log
- 17 Report Server ID
- 43 Read Device Identification

### Other

- 43 Encapsulated Interface Transport

