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
parser.add_argument("-f", "--file", dest = "filename")
parser.add_argument("-d", "--directory", dest="directory")
parser.add_argument("-s", "--search", dest="regex", action="store_true", default=False)
parser.add_argument("--path", dest="path", default="/home")
parser.add_argument("--include", dest="included_files", nargs="?", default=False)
parser.add_argument("--exclude", dest="excluded_files", nargs="?", default=False)
args = vars(parser.parse_args())
fl = args.get("filename")
pth = args.get("path")
dir = args.get("directory")
if fl:
    for i in r_glob(pth,fl):
        print(i)
else:
    for i in r_glob(pth,dir):
        print(i)