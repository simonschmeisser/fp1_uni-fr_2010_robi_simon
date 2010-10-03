# -*- coding: utf-8 -*-

from math import *

n = 0.611

Sn = 0.02 #AUSRECHNEN!!!


d = 29.125
Sd = 0.125

F = pi/4*d**2
SF = pi/2*d*Sd

print "F=", F
print "SF=", SF

T = 3.62e17*F / 100 /0.611 /60.0 /60.0 /24 /365

ST = T * sqrt( (Sn/n)**2 + (SF/F)**2 )

print "T1/2= ", T
print "ST = ", ST

