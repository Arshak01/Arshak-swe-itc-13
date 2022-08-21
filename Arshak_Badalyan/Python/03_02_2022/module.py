import argparse
import glob
import os

def _getDirs(base):
    return [x for x in glob.iglob(os.path.join( base, '*')) if os.path.isdir(x) ]

def searchElement(base, pattern):
    list = []
    list.extend(glob.glob(os.path.join(base,pattern)))
    dirs = _getDirs(base)
    if len(dirs):
        for d in dirs:
            list.extend(searchElement(os.path.join(base,d), pattern))
    return list

parser = argparse.ArgumentParser()
parser.add_argument("-f", "--file", dest = "filename", default=False)
parser.add_argument("-d", "--directory", dest="directory", default=False)
parser.add_argument("-s", "--search", dest="regex", default=False)
parser.add_argument("--path", dest="path", default="./")
parser.add_argument("--include", dest="included_files", nargs="?", default=False)
parser.add_argument("--exclude", dest="excluded_files", nargs="?", default=False)
args = parser.parse_args()
args = vars(parser.parse_args())

dir_name=args.get("directory")
file_name=args.get("filename")
path_name=args.get("path")

if dir_name:
    for i in searchElement(path_name,dir_name):
        print(i)
else:
    for i in searchElement(path_name,file_name):
        print(i)