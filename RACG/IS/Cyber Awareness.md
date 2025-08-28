# Cybersecurity Awareness Project

Okay, so here's the plan. Since we are going to do this as a joint project, I think there should be at least one presenter from either side. If we do this with Manipal, it should be easy enough for them to find a cybersec professor to do this. We can also find a professor or someone qualified. If not, I can do it myself if I get some time to prepare.

The aim of this project is to raise cybersecurity awareness. However, there is no use raising awareness about attacks on power plants or nuclear programs or anything that doesn't affect the day-to-day life of average person or things that they can't influence. The subject of the talks should be limited to things that the people encounter on their day-to-day life.

Here are some examples off the top of my mind.
- Authentication practices (If I have to do this from our side, I want this)
    - Password security
    - MFA
- Digital hygiene and privacy
    - Data we share
    - What people can do with it
- OSINT
    - Similar to digital hygiene but show how much you can learn about people with just openly available resources. Can just put them under one topic as well.
    - How these can lead to identity theft and even physical or monetary harm
- Data stealers, phishing and other common attacks and scams (This might also be a fun one to do for me.)
    - How to identify phishing attacks (not talking about bad spelling and stuff. Attackers are more sophisticated. Talk about the mental state they try to put you in as well.)
    - Common ways attacker hide exploits
    - What an attacker can do after they have successfully done the exploitation. Show C2 capabilities.
    - BTW, digital natives (us) are the most likely to fall for exploits. Not grandparents. Kind of Dunning-Kruger effectish.
- There's so much more. Open to suggestions.
- Here's another one. Backups and ransomeware resistance. (Onedrive is not a backup. Well unless you do it properly. What they give by default in Windows is not.)


All of these should have audience interaction as well as practical components. For example, 
- For password security, show a password being successfully cracked. Show how to use a password manager. Show how to create a strong password. Ask audience about their passwords. Can even try to guess the password format of audience. Maybe even use a CTF platform to let the audience get hands-on experience.
- Similarly for OSINT, do actual OSINT on a person. There are pre-made realistic OSINT challenges. If not make one. 
- For last one, exploit a VM. Show C2 capabilities. Show how attackers hide malware in plain sight. Let the audience hack into something and see. Maybe something easy to exploit like eternal blue. Can use something like TryHackMe ig.

Also talk about recent attacks. These are not hypotheticals. For each of these, you should be able to find an attack within the past month. Watch Dr. Gerald Auger's Daily Cyber Threat Brief or something. 

Here are some off the top.
- 23andme attack. Credential stuffing iirc.
- There are thousands of data breaches.
- Identity theft, doxing by geolocation via OSINT. There's a lot of stuff people can do when they have information on you. Spear phishing? Iirc there was a recent high profile case.
- Data stealers. Show redline and other ones. So many for this. Phishing attacks? Basically everything starts with phishing. There's even that case where they use deepfake to fool a financial guy in the company to transfer a lot of money. Don't remember details but yeah find it. Also, there's this cool new exploit with unpached winrar...