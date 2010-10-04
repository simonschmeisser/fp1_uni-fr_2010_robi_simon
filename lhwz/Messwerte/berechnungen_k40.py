# -*- coding: utf-8 -*-

from math import *

a = 10.5648
Sa =1.908
b = 1.64596
Sb = 0.596

cor = -0.947

f = 1.29
NA = 6.02214179e23
hrel = 0.000118
mrel = 74.5513

T = log(2) / 1.13 * f * NA * hrel / (2*a*b*mrel)/ 60 / 60 / 24 / 365

ST = T * sqrt((Sa/a)**2+(Sb/b)**2+2*cor*Sa/a*Sb/b)

print "T12 = ", T 

print "T12 = ", T /1e9, " e^9 a"

print "ST12 = ", ST /1e9, " e^9 a"


