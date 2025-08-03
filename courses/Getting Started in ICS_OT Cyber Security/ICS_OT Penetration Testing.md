# ICS/OT Penetration Testing

> Vidath Dissanayake | Sri Lanka  
> Links: [Getting Started in ICS_OT Cybersecurity](Getting%20Started%20in%20ICS_OT%20Cybersecurity.md)
> Sources: [Getting Started in ICS/OT Cyber Security part 10](https://www.youtube.com/watch?v=A-gTRMQpy5w&list=PLOSJSv0hbPZAlINIh1HcB0L8AZcSPc80g&index=11) [ICSRank](https://icsrank.com) [Shodan](https://shodan.io)

---

![SANS ICS kill chain](assets/images/SANS%20ICS%20kill%20chain.png)

![MITRE ATT&CK for ICS](assets/images/MITRE%20ATT&CK%20for%20ICS.png)

![ICS pentesting methodology](assets/images/ICS%20pentesting%20methodology.png)


## Reconnaissance

![ICS pentesting recon 1](assets/images/ICS%20pentesting%20recon%201.png)
![ICS pentesting recon 2](assets/images/ICS%20pentesting%20recon%202.png)
![ICS pentesting recon 3](assets/images/ICS%20pentesting%20recon%203.png)

[ICSRank](https://icsrank.com) provides a GUI where you can select a device you want to search for, and it will create a [Shodan](https://shodan.io) query and search it.

[SNMP](../../network/communication%20protocol/TCP%20IP%20layer%204/OSI%20layer%207/SNMP.md) is often useful, as most ICS systems will just disclose information when queried with SNMP. [snmpwalk](../../tools/hacking/network/protocol%20specific/SNMP/snmpwalk.md) can be used for this. 

---

## Initial Access

![ICS pentesting initial access 1](assets/images/ICS%20pentesting%20initial%20access%201.png)
![ICS pentesting initial access 2](assets/images/ICS%20pentesting%20initial%20access%202.png)
![ICS pentesting initial access 3](assets/images/ICS%20pentesting%20initial%20access%203.png)

### Initial Access Techniques

#### Rogue Master

![rogue master initial access](assets/images/rogue%20master%20initial%20access.png)

#### Wi-Fi Network Access

![wifi initial access 1](assets/images/wifi%20initial%20access%201.png)
![wifi initial access 2](assets/images/wifi%20initial%20access%202.png)

#### Other Wireless Attacks

![flipperzero1](assets/images/flipperzero1.png)
![flipperzero2](assets/images/flipperzero2.png)
![flipperzero3](assets/images/flipperzero3.png)![flipperzero4](assets/images/flipperzero4.png)
![flipperzero5](assets/images/flipperzero5.png)

---

## Discovery

![ICS pentesting discovery 1](assets/images/ICS%20pentesting%20discovery%201.png)
![ICS pentesting discovery 2](assets/images/ICS%20pentesting%20discovery%202.png)

### Network Connection Enumeration

On Windows, to list network connections,
```
netstat -nao
```
Can use to find other local devices.

Look at network connection tables available in some PLCs.

Perform a [Nmap](../../tools/hacking/network/scanning/Nmap.md) scan. Use scripts to gain more information.

---

## Collection

![ICS pentesting collection](assets/images/ICS%20pentesting%20collection.png)
![detect operating mode](assets/images/detect%20operating%20mode.png)

Most PLCs have an app or software that allows discovery of PLCs. These usually provide a lot of information.

---

## Execution

![ICS pentesting execution 1](assets/images/ICS%20pentesting%20execution%201.png)
![ICS pentesting execution 2](assets/images/ICS%20pentesting%20execution%202.png)

---

## Lateral Movement

![ICS pentesting lateral movement 1](assets/images/ICS%20pentesting%20lateral%20movement%201.png)
![ICS pentesting lateral movement 2](assets/images/ICS%20pentesting%20lateral%20movement%202.png)

---

## Persistence

![ICS pentesting persistence 1](assets/images/ICS%20pentesting%20persistence%201.png)
![ICS pentesting persistence 2](assets/images/ICS%20pentesting%20persistence%202.png)

---

## Evasion

![ICS pentesting evasion 1](assets/images/ICS%20pentesting%20evasion%201.png)
![ICS pentesting evasion 2](assets/images/ICS%20pentesting%20evasion%202.png)

---

## Inhibit Response Functions

This means,
- loss of control
- loss of visibility
- loss of both

![ICS pentesting inhibit response 1](assets/images/ICS%20pentesting%20inhibit%20response%201.png)

---

## Command and Control

![ICS pentesting C2 1](assets/images/ICS%20pentesting%20C2%201.png)