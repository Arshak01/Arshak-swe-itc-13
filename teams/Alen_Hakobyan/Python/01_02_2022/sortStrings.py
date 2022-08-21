def sortChar(strlist):
    str_list = strlist.copy()

    for i in range(len(str_list) - 1, -1, -1):
        for j in range(0, i):
            current_str = str_list[j].split()
            next_str = str_list[j + 1].split()
            cur_keys_ch = ""
            cur_keys_num = ""
            next_keys_ch = ""
            next_keys_num = ""
            for ch in current_str[0]:
                if 65 <= ord(ch) <= 122:
                    cur_keys_ch += ch
                else:
                    cur_keys_num += ch
            for ch in next_str[0]:
                if 65 <= ord(ch) <= 122:
                    next_keys_ch += ch
                else:
                    next_keys_num += ch
            if current_str[1].isdigit() and current_str[2].isdigit():
                is_cur_num = True
            else:
                is_cur_num = False
            if next_str[1].isdigit() and next_str[2].isdigit():
                is_next_num = True
            else:
                is_next_num = False
            if is_cur_num is False and is_next_num is False:
                loop_must_break = False
                if len(cur_keys_ch) == len(next_keys_ch):
                    if current_str[0] == next_str[0]:
                        if current_str[1][0].isalpha() is False and next_str[1][0].isalpha():
                            str_list[j], str_list[j + 1] = str_list[j + 1], str_list[j]
                            break
                    for k in range(len(cur_keys_ch)):
                        if cur_keys_ch[k] > next_keys_ch[k]:
                            str_list[j], str_list[j + 1] = str_list[j + 1], str_list[j]
                            loop_must_break = True
                            break
                    if loop_must_break:
                        break
                elif len(cur_keys_ch) < len(next_keys_ch):
                    for m in range(len(cur_keys_ch)):
                        if ord(cur_keys_ch[m]) > ord(next_keys_ch[m]):
                            str_list[j], str_list[j + 1] = str_list[j + 1], str_list[j]
                            loop_must_break = True
                            break
                    if loop_must_break:
                        break
                else:
                    for n in range(len(next_keys_ch)):
                        if ord(cur_keys_ch[n]) > ord(next_keys_ch[n]):
                            str_list[j], str_list[j + 1] = str_list[j + 1], str_list[j]
                            loop_must_break = True
                            break
                    if loop_must_break:
                        break

    return str_list


def sortNum(strlist):
    str_list = strlist.copy()

    for i in range(len(str_list) - 1, -1, -1):
        for j in range(0, i):
            current_s__arr = str_list[j].split()
            next_s_arr = str_list[j + 1].split()
            curr_key_ch = ""
            cur_key_num = ""
            next_key_ch = ""
            next_key_num = ""

            for ch in current_s__arr[0]:
                if 65 <= ord(ch) <= 122:
                    curr_key_ch += ch
                else:
                    cur_key_num += ch

            for ch in next_s_arr[0]:
                if 65 <= ord(ch) <= 122:
                    next_key_ch += ch
                else:
                    next_key_num += ch

            if current_s__arr[1].isdigit() and current_s__arr[2].isdigit():
                is_cur_num = True
            else:
                is_cur_num = False

            if next_s_arr[1].isdigit() and next_s_arr[2].isdigit():
                is_next_num = True
            else:
                is_next_num = False

            if is_cur_num and is_next_num is False:
                str_list[j], str_list[j + 1] = str_list[j + 1], str_list[j]
            if is_cur_num and is_next_num:
                if int(cur_key_num) < int(next_key_num):
                    str_list[j], str_list[j + 1] = str_list[j + 1], str_list[j]
                if int(cur_key_num) == int(next_key_num):
                    if len(curr_key_ch) > len(curr_key_ch):
                        str_list[j], str_list[j + 1] = str_list[j + 1], str_list[j]
                if int(cur_key_num) == int(next_key_num) \
                        and len(curr_key_ch) == len(curr_key_ch):
                    for k in range(len(curr_key_ch)):
                        if ord(curr_key_ch[k]) > ord(next_key_ch[k]):
                            str_list[j], str_list[j + 1] = str_list[j + 1], str_list[j]
    return str_list

def last_sort(strlist):
    str_list = strlist.copy()
    str_list = sortNum(str_list)
    str_list = sortChar(str_list)
    return str_list