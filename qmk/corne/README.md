# ADAM'S CORNE KEYMAP

![keymap image](adamf24.drawio.png)

This keymap was designed for a 3x6 corne split ergonomic keyboard.  It is intended to be used along with a ploopy nano trackball positioned near the right thumb.  I write only in english and am a novice programmer so features for other languages and advanced usage beyond basic bash, python, html, and javascript were not considered in the design.  I tried and don't like fiddling with home row mods, autoshift, or toggling layers so you won't find any of those here.

# DESIGN PRINCIPLES

* Includes mouse buttons and scroll macro for use with a ploopy nano trackball running maddie
* Objective is speed and simplicity, not maximum features or peak ergonomics
* Prioritizes easy to remember key locations over peak ergonomics to reduce cognative load 
* Minimizes number of layers, again to reduce cognative load 
* Uses combos on strong fingers over pinky stretches

# FLASHING INSTRUCTIONS

* make sure to disconect usb first and allow time to discharge before disconnecting trrs

## compile new firmware

5. run command to compile `qmk compile -kb crkbd -km adamf`

## flash left

6. connect left keyboard
7. push reset button
8. `qmk flash -kb crkbd -km adamf -bl dfu`
9. disconnect

## flash right

10. connect right keyboard
11. push reset button
12. `qmk flash -kb crkbd -km adamf -bl dfu`
13. disconnect
