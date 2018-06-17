from decimal import Decimal as D
from decimal import getcontext 
getcontext().prec=10000
e=D(0)
t=D(1)
for i in range (1,10000):
	print i
	e=e+t
	t=t/i

print "E CL\n"
f=open('ee.txt','w')
print >>f, e
e=D(1)/e
print "E-1 CL\n";
f=open('e.txt','w')
print >>f, e
