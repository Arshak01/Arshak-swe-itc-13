def s_sort_alphabetics(p_list):
    l = p_list.copy()

    for i in range(len(l) - 1, -1, -1):
        for j in range(0, i):
            current_s__arr = l[j].split()
            next_s_arr = l[j + 1].split()
            current_keys_alphabetic_part = ""
            current_keys_numeric_part = ""
            next_keys_alphabetic_part = ""
            next_keys_numeric_part = ""

            for ch in current_s__arr[0]:
                if 65 <= ord(ch) <= 122:
                    current_keys_alphabetic_part += ch
                else:
                    current_keys_numeric_part += ch

            for ch in next_s_arr[0]:
                if 65 <= ord(ch) <= 122:
                    next_keys_alphabetic_part += ch
                else:
                    next_keys_numeric_part += ch

            if current_s__arr[1].isdigit() and current_s__arr[2].isdigit():
                is_current_numeric = True
            else:
                is_current_numeric = False

            if next_s_arr[1].isdigit() and next_s_arr[2].isdigit():
                is_next_numeric = True
            else:
                is_next_numeric = False

            if is_current_numeric is False and is_next_numeric is False:
                loop_must_break = False
                if len(current_keys_alphabetic_part) == len(next_keys_alphabetic_part):
                    if current_s__arr[0] == next_s_arr[0]:
                        if current_s__arr[1][0].isalpha() is False and next_s_arr[1][0].isalpha():
                            l[j], l[j + 1] = l[j + 1], l[j]
                            break
                    for k in range(len(current_keys_alphabetic_part)):
                        if current_keys_alphabetic_part[k] > next_keys_alphabetic_part[k]:
                            l[j], l[j + 1] = l[j + 1], l[j]
                            loop_must_break = True
                            break
                    if loop_must_break:
                        break
                elif len(current_keys_alphabetic_part) < len(next_keys_alphabetic_part):
                    for m in range(len(current_keys_alphabetic_part)):
                        if ord(current_keys_alphabetic_part[m]) > ord(next_keys_alphabetic_part[m]):
                            l[j], l[j + 1] = l[j + 1], l[j]
                            loop_must_break = True
                            break
                    if loop_must_break:
                        break
                else:
                    for n in range(len(next_keys_alphabetic_part)):
                        if ord(current_keys_alphabetic_part[n]) > ord(next_keys_alphabetic_part[n]):
                            l[j], l[j + 1] = l[j + 1], l[j]
                            loop_must_break = True
                            break
                    if loop_must_break:
                        break

    return l


def s_sort_numerics(p_list):
    l = p_list.copy()

    for i in range(len(l) - 1, -1, -1):
        for j in range(0, i):
            current_s__arr = l[j].split()
            next_s_arr = l[j + 1].split()
            current_keys_alphabetic_part = ""
            current_keys_numeric_part = ""
            next_keys_alphabetic_part = ""
            next_keys_numeric_part = ""

            for ch in current_s__arr[0]:
                if 65 <= ord(ch) <= 122:
                    current_keys_alphabetic_part += ch
                else:
                    current_keys_numeric_part += ch

            for ch in next_s_arr[0]:
                if 65 <= ord(ch) <= 122:
                    next_keys_alphabetic_part += ch
                else:
                    next_keys_numeric_part += ch

            if current_s__arr[1].isdigit() and current_s__arr[2].isdigit():
                is_current_numeric = True
            else:
                is_current_numeric = False

            if next_s_arr[1].isdigit() and next_s_arr[2].isdigit():
                is_next_numeric = True
            else:
                is_next_numeric = False

            # first is numeric and second isn't numeric
            if is_current_numeric and is_next_numeric is False:
                l[j], l[j + 1] = l[j + 1], l[j]
            # both are numeric
            if is_current_numeric and is_next_numeric:
                if int(current_keys_numeric_part) < int(next_keys_numeric_part):
                    l[j], l[j + 1] = l[j + 1], l[j]
                if int(current_keys_numeric_part) == int(next_keys_numeric_part):
                    if len(current_keys_alphabetic_part) > len(current_keys_alphabetic_part):
                        l[j], l[j + 1] = l[j + 1], l[j]
                if int(current_keys_numeric_part) == int(next_keys_numeric_part) \
                        and len(current_keys_alphabetic_part) == len(current_keys_alphabetic_part):
                    for k in range(len(current_keys_alphabetic_part)):
                        if ord(current_keys_alphabetic_part[k]) > ord(next_keys_alphabetic_part[k]):
                            l[j], l[j + 1] = l[j + 1], l[j]
    return l


def final_sort(p_list):
    l = p_list.copy()
    l = s_sort_numerics(l)
    l = s_sort_alphabetics(l)
    return l

