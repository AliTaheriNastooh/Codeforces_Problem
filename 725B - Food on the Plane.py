
q=raw_input()
col=q[len(q)-1]
n=0
if col=='a':
    n+=4
elif col=='b':
    n+=5
elif col=='c':
    n+=6
elif col=='d':
    n+=3
elif col=='e':
    n+=2
elif col=='f':
    n+=1
num=int(q[:len(q)-1])
tmp=num/4
tmp1=num%4
if tmp>=1 and tmp1==0:
    n+=((tmp-1)*12)+(tmp-1)+(tmp-1)*3
elif tmp>=1:
    n+=((tmp)*12)+(tmp)+(tmp)*3
    

if tmp1==0 or tmp1==2:
    n+=7
print n
    