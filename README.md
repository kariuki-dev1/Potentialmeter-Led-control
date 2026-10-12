# led-potentiometer-control
# LED Potentiometer Control

An Arduino Uno project in which a potentiometer controls the brightness of three LEDs using PWM.

![Circuit in Wokwi](images/circuit.png)

## What it does
- **Red LED** gets brighter as the knob turns up.
- **Blue LED** gets dimmer as the knob turns up.
- **Magenta LED** is brightest in the middle and dim at both ends.

## Parts
| Part | Pin |
|---|---|
| Potentiometer (signal) | A0 |
| Red LED | 9 (PWM) |
| Blue LED | 10 (PWM) |
| Magenta LED | 11 (PWM) |
| Resistors | 1 kΩ in series with each LED |

## How it works
`analogRead()` returns 0 to 1023. `map()` converts that range to 0 to 255 for `analogWrite()`.
For the magenta LED, `abs(value - 512)` measures the distance from the middle of the knob.

## Run it
1. Open the folder in VS Code with PlatformIO and the Wokwi extension.
2. Click Build (checkmark).
3. Press F1 and choose **Wokwi: Start Simulator**.

## What I learned
- `map()`, `constrain()` and `abs()`
- PWM pins on the Uno are 3, 5, 6, 9, 10 and 11