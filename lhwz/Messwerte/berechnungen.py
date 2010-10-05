# -*- coding: utf-8 -*-

from math import *

n = 0.611

nuntergrund = 0.004

t = 4200

Sn = sqrt(n/t)

print "n = ", n
print "Sn = ", Sn


d = 29.125
Sd = 0.125

F = pi/4*d**2
SF = pi/2*d*Sd

print "F=", F
print "SF=", SF

T = 3.62e17*F / 100 /(0.611-nuntergrund) /60.0 /60.0 /24 /365

ST = T * sqrt( (Sn/n)**2 + (SF/F)**2 )

print "T1/2= ", T
print "ST = ", ST

Tlit = 1.06e11

print (T-Tlit)/ST
