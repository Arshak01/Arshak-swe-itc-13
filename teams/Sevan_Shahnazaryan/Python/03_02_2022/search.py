from argparse import ArgumentParser
import os

path = ''

def findFile(file, path):
    for dirpath, dir, filenames in os.walk(f"{path}"):
        for filename in filenames:
            if filename.endswith(f"{file}"):
                print('FILE: ', os.path.join(dirpath, filename))

def findDir(dir, path):
    for dirpath, dirnames, filenames in os.walk(f"{path}"):
        for d in dirnames:
            if d.endswith(f"{dir}"):
                print('Dirname: ', os.path.join(dirpath, dir))

parser = ArgumentParser()
parser.add_argument('--file', '-f', required = False)
parser.add_argument('--directory', '-d', required = False)
parser.add_argument('--path', '-p', default = os.getcwd(), required = False)
args = vars(parser.parse_args())
if args['file']:
    findFile(args['file'], args['path'])
if args['directory']:
    findDir(args['directory'], args['path'])
