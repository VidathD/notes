# Input Output

There are various communication protocols. In some cases we need to retain all the data provided by I/O device (e.g. network card) but sometimes we can drop some intermediate values without issue (e.g. mouse pointer).

Convey errors properly (e.g. printer out of paper).

What happens when there are multiple interrupts at the same time. We have to prioritize depending on importance and time taken to complete. We have to do a context switch.

What happens if you get an interrupt while you are executing the ISR? If the frequency is low or priority is high, we can attend to it. But 