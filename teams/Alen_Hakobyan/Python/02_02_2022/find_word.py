from module_find_word import sorting,counter,print_dict

def readFile(file_name):
    try:
        file = open(file_name, "r")
        lists=file.read()
    except IOError:
        print ("Could not read file: {file_name} ")
    else:
        lists = lists.replace("\n","")
        lists=lists.split(" ")
        return lists
    finally:
        file.close()

def appendList(lists,found_list):
    for i in lists:
        if len(i) == 2 and i[len(i)-1] == ".":
            continue
        if i == " ":
            continue
        if i[0].isupper() or i.isupper():
            if i not in found_list:
                found_list.append(i)
    return found_list

def main():
    lists = readFile("text.txt")
    dict_list = {}
    foundList=[]
    appendList(lists,foundList)
    for i in foundList:
        counter(i,dict_list)
    dict_list = sorting(dict_list)
    n = 2
    print_dict(dict_list,n)

if __name__ == "__main__":
    main()