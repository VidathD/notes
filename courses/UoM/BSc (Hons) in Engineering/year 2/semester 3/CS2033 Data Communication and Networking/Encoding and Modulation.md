# Encoding and Modulation

![L02 - Encoding and Modulation](assets/documents/L02%20-%20Encoding%20and%20Modulation.pdf)

## Biphase

If bit period is too small, might miss data. If longer, can send less bits. If longer, can send more= bits. But chance of missing data is the tradeoff.

At the mid bit period, there is a mandatory transition. 

## Scrambling

Problem with constant voltage is, especially at 0, is that it is ambiguous if the data/connection was lost.


Linear predictive model
Pulse code modulation
Delta modulation

## PCM

Normalise to range
Take PAM value
Quantize
Find PCM code
Ts= Sampling interval
To improve accuracy, increase the number of quanta (number of bits used to represent), increase the number of samples.
Most used scheme in audio standards.