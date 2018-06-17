from decimal import Decimal as D
from decimal import getcontext 
getcontext().prec=100
e=D('2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599')

f=D(1)-D(1)/e
for i in range(1,151):
	f=D(1)-f*i
for i in range(151,201):
	print i,f
while 1:
	a=1
