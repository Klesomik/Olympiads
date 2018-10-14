import os, sys

for i in range (1000):
    print ('Test:', i + 1)
    os.popen ('Gen.exe > test.txt')
    v1 = os.popen ('Smart.exe < test.txt').read ()
    v2 = os.popen ('Stupid.exe < test.txt').read ()
    if v1 != v2:
        print ('WA')
        break
    else:
        print ('OK')