# -*- coding: utf-8 -*-


def number_to_latex(number, precission, base):
  return r'' + str(round(number/(10**base), precission)) + r'\e{' + str(base) + r'}'
  
def number_error_to_latex(number, error, precission, base):
  return r'(' + str(round(number/(10**base), precission)) + r' \pm ' + str(round(error/(10**base), precission)) + r')\e{' + str(base) + r'}'
  
#print number_to_latex(0.0001234567890, 3, -5)
#print number_error_to_latex(0.0001234567890, 1e-6, 3, -5)
