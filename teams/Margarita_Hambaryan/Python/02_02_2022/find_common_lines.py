def polish(word: str):
    if word[-1] == ',':
        return word[:-1]
    return word

dict_ = {}
while True:
    inp = input()
    if inp == "":
        break
    line = inp[:-1].split()
    line_l = []
    for word in line:
        word = polish(word)

        if word[0].isupper() and word.upper() not in line_l: 
            if word.upper() in dict_.keys():
                dict_[word.upper()] = dict_.get(word.upper()) + 1
                line_l.append(word.upper())
            else:

                if word.upper() != line[0].upper():
                    dict_[word.upper()] = 1
                    line_l.append(word.upper())

n = int(input('N: '))

def print_names(dict_):
    if n > len(dict_):
        for elem in dict_:
            print(f'{elem}: {dict_[elem]}')
    else:
        for elem in list(dict_.items())[:n]:
            print(f'{elem[0]}: {elem[1]}')

def main():
    print_names(dict_)

if __name__ == '__main__':
    main()