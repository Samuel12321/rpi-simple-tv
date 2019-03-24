import string

import sys 
import os
from evdev import InputDevice
from select import select

device = InputDevice('/dev/input/event0')  # Change to potentiometer values
keys = {
    '2': '1',
    '3': '2',
    '4': '3',
    '5': '4',
    '6': '5',
    '7': '6',
    '8': '7',
    '9': '8',
    '10': '9',
    '11': '0',
    '71': '7',
    '72': '8',
    '73': '9',
    '75': '4',
    '76': '5',
    '77': '6',
    '79': '1',
    '80': '2',
    '81': '3',
};

def get_key(event):
    code = str(event.code)
    if event.type == 1 and event.value == 1 and code in keys:
        return keys[str(event.code)]
    return None

while True:
    r, w, x = select([device], [], [])
    for event in device.read():
        if event.type == 1 and event.value == 1:
            sys.stderr.write('Key code: ' + str(event.code) + '\n')
        key = get_key(event)
        if (key != None):
            sys.stdout.write(key + '\n')
            sys.stdout.flush()
