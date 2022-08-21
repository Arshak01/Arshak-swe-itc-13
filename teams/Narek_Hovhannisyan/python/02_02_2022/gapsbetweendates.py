import datetime

def fill_spaces_between_dates(filename):
    f = open(filename, "rt")
    l_dates = f.readlines()
    l_dates.sort()
    for i in range(len(l_dates) - 1):
        l_dates[i] = l_dates[i].strip()
        c_arr = l_dates[i].split("-")
        n_arr = l_dates[i + 1].split("-")
        c_date = datetime.date(int(c_arr[0]), int(c_arr[1]), int(c_arr[2]))
        n_date = datetime.date(int(n_arr[0]), int(n_arr[1]), int(n_arr[2]))
        diff_in_days = (n_date - c_date).days
        tmp_date = c_date
        for j in range(diff_in_days - 1):
            tmp_date += datetime.timedelta(days=1)
            l_dates.append(tmp_date.strftime("%Y-%m-%d"))
    l_dates.sort()
    f.close()
    f = open(filename, "w").close()
    f = open(filename, "wt")
    for k in range(len(l_dates)):
        f.write(l_dates[k])
        if k != len(l_dates) - 1:
            f.write("\n")
    f.close()

