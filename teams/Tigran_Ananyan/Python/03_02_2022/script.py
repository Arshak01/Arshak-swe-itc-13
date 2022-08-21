import os
import argparse
import re

def compare(res, targets_list):
     for i in targets_list:
         if re.search(i, res, re.IGNORECASE):
             return True
     return False

def search():

    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--file', help = 'Search file with file_name')

    parser.add_argument( '-d', '--directory', help = 'Search directory with directory_name')

    parser.add_argument('-s', '--search', default = False, action = 'store_true', help = 'Searching text')

    parser.add_argument('--path', default = '~/', help = 'The searching root file')

    parser.add_argument('--include', help = 'Do the searching including this files', nargs = '+')

    parser.add_argument('--exclude', help = 'Do the searching excluding this files', nargs = '+')

    results = parser.parse_args()
    file_name = results.file
    dir_name = results.directory
    path = results.path
    regex_on = results.search
    included_files = results.include
    excluded_files = results.exclude

    found = []
    if file_name is None and dir_name is not None:
        target = dir_name
    elif file_name is not None and dir_name is None:
        target = file_name
    else:
        target = "."
        file_name = "."

    if file_name is not None:
            if regex_on:
                for root, dirs, files in os.walk(path):
                    for name in files:
                        if re.search(target, name, re.IGNORECASE):
                            found.append((os.path.join(root, name)))
            else:
                for root, dirs, files in os.walk(path):
                    if target in files:
                        found.append(os.path.join(root, target))
    else:
        if regex_on:
            for root, dirs, files in os.walk(path):
                for name in dirs:
                    if re.search(target, name, re.IGNORECASE):
                        found.append((os.path.join(root, name)))
        else:
            for root, dirs, files in os.walk(path):
                if target in dirs:
                    found.append(os.path.join(root, target))

    if included_files is not None:
            found = list(filter(lambda r: compare(r, included_files), found))

    if excluded_files is not None:
            found = list(filter(lambda r: not compare(r, excluded_files), found))

    for i in found:
        print(i)
    print("matches count = ", len(found))