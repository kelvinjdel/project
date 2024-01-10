from lcapy import Circuit

c = Circuit("""
V1  _1 0 ; down, l={$20\,V$}
R1  _1 _2 ; right, l={$10k\,\Omega$}
D1  _2 _3 ; right, l={$D$}
R2  _3 _0 ; down, l={$10k\,\Omega$}
W   _0 _4 ; left
W   _4 _1 ; up
""")

# Calculate the DC operating point
dc = c.dc()

print(f"DC operating point: {dc}")