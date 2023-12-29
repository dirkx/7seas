import light_character.light_character
import fileinput
import sys
import math

atts = []
lines = []
for line in fileinput.input(sys.argv[1:]):
    lines.append(line.strip())

MAX = 0
MAX_STEPS = 0
lights = 0
for line in lines:
    # L	N	Actual	approx	counterclock	LGRID	LSEG
    (l,n,lc,label,cl,lgrid,lseg) = line.split("\t")
    lights = lights + 1
    if label == "na":
       continue
    pattern = light_character.light_character.characteristic_to_light_states(lc)
    pattern = light_character.light_character.collapse_states(pattern)

    if pattern[0][0] == 'Off':
        f = pattern[0]
        pattern = pattern[1:]
        pattern.append(f)

    tts = []
    T = 0
    if len(pattern) > MAX_STEPS:
       MAX_STEPS = len(pattern) 

    for l in pattern:
       if len(pattern) > 1:
          tts.append(l[1])
          atts.append(l[1])
          if l[1] > MAX:
            MAX=l[1]
       T = T + l[1]
    if len(pattern) > 1:
      stl = math.gcd(*tts)

tock = math.gcd(*atts)

print("const unsigned char patterns[] = {{ \n\t0, /* Null pattern - no light/led */".format());
N = 1;
starts = []
idx = {}
for line in lines:
    (l,n,lc,label,cl,lgrid,lseg) = line.split("\t")
    if label == "na":
        if N == 0:
           trow 
        starts.append(0)
        continue
    print("/* {} */".format(line))

    pattern = light_character.light_character.characteristic_to_light_states(lc)
    pattern = light_character.light_character.collapse_states(pattern)

    if pattern[0][0] == 'Off':
        z = pattern
        f = pattern[0]
        pattern = pattern[1:]
        pattern.append(f)

    out = []
    for l in pattern:
       if len(pattern) > 1:
          out.append(l[1]/tock)
       else:
          out.append(MAX/tock)

   
    os = ''.join('x'+str(int(l)) for l in out)
    if os in idx:
        starts.append(idx[ os ])
        print("\t/* repeated pattern; reusing sequence at idx {} */".format(idx[ os ]))
        print("\t\t/* {},{} {} {} */".format(','.join(str(int(l)) for l in out),lgrid,lseg,label,lc));
        print("\t\t/* {} */".format(pattern))
        continue
    else:
        starts.append(N)

    print("/*\tindex {} - {} */".format(N,pattern))
    print("\t{},0,\n\t/*\t\t{},{} {} {} */".format(','.join(str(int(l)) for l in out),lgrid,lseg,label,lc));
        
    idx[ os ] = N
    N = N + len(out) + 1

print("};");
print("const unsigned char idx[{}] = {{".format(lights))
print("\t\t/* Grid,Seg\tLocation and pattern */")
for line in lines:
    (l,n,lc,label,cl,lgrid,lseg) = line.split("\t")
    i = starts[0]
    starts = starts[1:]
    print("	{},	/* {},{}\t\t{} {} */".format(i,lgrid,lseg,label,lc))
print("};")

print("const int tock={}; /* milliSeconds */".format(tock))
print("const int lights={}; /* number of lights/entries */".format(lights))

