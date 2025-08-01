# Firewall

> Vidath Dissanayake | Sri Lanka  
> Links: [cyber defences](cyber%20defences.md)
> Sources: [Getting Started in ICS/OT Cyber Security part 4](https://www.youtube.com/watch?v=WReeJDw-AV4&list=PLOSJSv0hbPZAlINIh1HcB0L8AZcSPc80g&index=4) 

---

A firewall is used to filter traffic between two or more network segments. Typically, firewalls should be configured to block **all** traffic. Then exceptions can be made to allow traffic required for a specific purpose. **These exceptions must be as specific as possible.**

## Main Types of Firewalls

### Packet Filtering

These are the most basic type of firewalls. They filter traffic based on five tuples.
- Source IP
- Destination IP
- Source Port
- Destination Port
- Protocol

### Stateful Inspection

These firewalls perform packet filtering and tracks the state of each connection passing through the firewall. This prevents bypassing the firewall by spoofing the source IP and acting as return traffic. 

### Deep Packet Inspection

These can perform packet filtering and stateful inspection. They further examine the data within the packet to identify the application transmitting data and look for malicious activity. 