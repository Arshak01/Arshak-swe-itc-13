def find_names(arr, N = 3):
    names = []
    counts= []
    is_already_added = []
    for i in arr:
        words = i.split()
        for j in range(len(words)):
            if words[j][0].isupper():
                if words[j].upper() not in names and j != 0:
                    names.append(words[j].upper())
                    counts.append(1)
                    is_already_added.append(True)
                if words[j].upper() in names:
                    index = names.index(words[j].upper())
                    if is_already_added[index] == True:
                        continue
                    counts[index] += 1
                    is_already_added[index] = True

        for k in range(len(is_already_added)):
            is_already_added[k] = False
    result = []
    for m in range(len(names)):
        result.append({names[m]: counts[m]})
    result = sorted(result, key = lambda e: list(e.values())[0], reverse=True)
    if len(result) <= N:
        return result
    else:
        return result[0:N]

