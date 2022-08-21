def isName(word):
    if word[0].isupper() and not word[1:].isupper():
        return True
    elif  word.isupper():
        return True
    else:
        return False

def exists(dict, name):
    if dict.get(name):
        return True
    else:
        return False

def main():
    text = []

    tmp = input("text: ").split('.')
    N = int(input("N: "))
    for i in range(len(tmp) - 1):
        tmp[i] = tmp[i]
        text.append(tmp[i].split())
    tmp[-1] = tmp[-1][:-1]
    table = {}

    punct = ".,:;"

    for i in text:
        isBeginning = True
        for j in i:
            if isBeginning and isName(j) and j not in table:
                continue
            elif isName(j):
                if j[-1] in punct:
                    j = j[:-1]
                if exists(table, j):
                    table.update({j:table.get(j) + 1})
                else:
                    table[j] = 1
            isBeginning = False

    print(list(dict(sorted(table.items(), key=lambda item: item[1], reverse = True)).items())[:N])

if __name__ == "__main__":
    main()