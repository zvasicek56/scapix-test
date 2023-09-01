import os, sys

for pth in ['../build/vs2022-python/Debug', '../build/vs2022-python/Release']:
    sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), pth)))

try:
    print("Importing demolib")
    import demolib
except Exception as e:
    print(f"Can't import demolib {e}")
    print("Please install Microsoft VS redistributables from https://aka.ms/vs/17/release/vc_redist.x64.exe")


def load_data():
    return [1,2,3]

d = demolib.Device()
d.initialize(load_data)