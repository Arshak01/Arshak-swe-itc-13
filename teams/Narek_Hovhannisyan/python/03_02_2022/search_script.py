import argparse
import os
import re


def matcher(res, targets_list):
    for i in targets_list:
        if re.search(i, res, re.IGNORECASE):
            return True
    return False


def find_target():
    parser = argparse.ArgumentParser(description="find file or directory")
    parser.add_argument("-f", "--file", dest="file")
    parser.add_argument("-d", "--directory", dest="directory")
    parser.add_argument("-s", "--search", dest="is_allowed_regex", action="store_true", default=False)
    parser.add_argument("--path", dest="path", default="./")
    parser.add_argument("--include", dest="included_files", nargs="+")
    parser.add_argument("--exclude", dest="excluded_files", nargs="+")
    args = parser.parse_args()

    if args.file is None and args.directory is not None:
        target = args.directory
    elif args.file is None and args.directory is None:
        target = "."
        args.file = "."
    else:
        target = args.file

    path = args.path
    is_allowed_regex = args.is_allowed_regex
    included_files = args.included_files
    excluded_files = args.excluded_files

    result = []
    if args.file is not None:
        if is_allowed_regex:
            for root, dirs, files in os.walk(path):
                for name in files:
                    if re.search(target, name, re.IGNORECASE):
                        result.append((os.path.join(root, name)))
        else:
            for root, dirs, files in os.walk(path):
                if target in files:
                    result.append(os.path.join(root, target))
    else:
        if is_allowed_regex:
            for root, dirs, files in os.walk(path):
                for name in dirs:
                    if re.search(target, name, re.IGNORECASE):
                        result.append((os.path.join(root, name)))
        else:
            for root, dirs, files in os.walk(path):
                if target in dirs:
                    result.append(os.path.join(root, target))

    if included_files is not None:
        result = list(filter(lambda r: matcher(r, included_files), result))

    if excluded_files is not None:
        result = list(filter(lambda r: not matcher(r, excluded_files), result))

    for i in result:
        print(i)
    print("matches count = ", len(result))


find_target()
