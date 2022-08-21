# Searching Script in Python

## Description 

To run the script you should run following command from "search_script.py" directory

```bash
python3 search_script.py
```

The script takes several flags, the most important flags are "-f", "--file" or "-d", "--directory".

### -f --file or -d --directory [arg]

* If none of them is used, as a default will be set "--file" with "." value. "." means any symbol
* If passed -d or --directory flag with argument, script will find directories matching the argument
* If passed -f or --file flag with argument, script will find files matching the argument

### --path <arg>

* If used this flag with argument, script will find files or directories(see above) starting from this directory. Argument is required.
* If "--path" flag is not passed, the current directory will be set as a starting directory

### -s --search

* If this flag is used, script will consider "-d"'s or "-f"'s argument as regex, default value is "False". To use this flag, just use "-s" or "--search" without any argument, the argument will be set as "True" automatically

### --include <args...>

* If this flag is used, the script will filter results according to the arguments. The flag takes multiple arguments separated by spaces. At least one argument is required for this flag. If you say differently, each result must match at least one argument.

suppose we have results

```bash
python3 search_script.py -d dir --path ~/
dir/b/c
dir/e/f
dir/h/i
```

and used the script with flag "--include" as below

```bash
python3 search_script.py -d dir --path ~/ --include e i
dir/e/f
dir/h/i

```

### --exclude <args...>

* If this flag is used, result will be filtered so as not to include any match from arguments list. At least one argument is required for this flag

```bash
python3 search_script.py -d dir --path ~/
dir/b/c
dir/e/f
dir/h/i

python3 search_script.py -d dir --path ~/ --exclude b f
dir/h/i
```

### Thanks
