#!/usr/bin/python

import random
import time

while True:
    message = input()
    time.sleep(random.uniform(0.1, 1.0)) # simulates process time
    print(message[::-1])

