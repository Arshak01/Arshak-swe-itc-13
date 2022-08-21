import glob
import os
import argparse

def get_dirs(base):
    return [x for x in glob.iglob(os.path.join( base, '*')) if os.path.isdir(x) ]

def r_glob(base, pattern):
    lists = []
    lists.extend(glob.glob(os.path.join(base,pattern)))
    dirs = get_dirs(base)
    if len(dirs):
        for d in dirs:
            lists.extend(r_glob(os.path.join(base,d), pattern))
    return lists

parser = argparse.ArgumentParser()
parser.add_argument("-f", "--file", dest = "filename", nargs = '?')
args = parser.parse_args()
file_name = args.filename
path = "/home"

for i in r_glob(path,file_name):
    print(i)