def counter(lists,dict_list):
    if len(lists) == 0:
        lists[str(lists)] = 1
        return 0

    for key in dict_list:
        if key.upper() == lists.upper():
            dict_list[key] += 1
            return 0
    dict_list[str(lists)] = 1

def sorting(dict_list):
    List=list(dict_list.items())
    l=len(List)
    for i in range(l-1):
        for j in range(i+1,l):
            if List[i][1] < List[j][1]:
                temp = List[i]
                List[i] = List[j]
                List[j] = temp
        sortdict_list = dict(List)
        return sortdict_list

def print_dict(dict1,n):
    if n > len(dict1) or n < 0:
        print("Entry number is great then list length or small of 0")
        return 0

    for f, v in dict1.items():
        if n == 0:
            break
        print(f, v)
        n -= 1