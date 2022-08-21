import datetime
from os import TMP_MAX
try:
    def fill_dates(date_file):
        f = open(date_file, "rt")
        date_list = f.readlines()

        for i in range(len(date_list)) :
            date_list[i] = date_list[i].strip()

        for i in range(len(date_list) - 1) :
            curr_arr = date_list[i].split("-")
            next_arr = date_list[i + 1].split("-")
            curr_date = datetime.date(int(curr_arr[0]), int(curr_arr[1]), int(curr_arr[2]))
            next_date = datetime.date(int(next_arr[0]), int(next_arr[1]), int(next_arr[2]))
            diff = (next_date - curr_date).days
            tmp_date = curr_date
            for j in range(diff - 1):
                tmp_date += datetime.timedelta(days=1)
                date_list.append(tmp_date.strftime("%Y-%m-%d"))

        date_list.sort()
        f.close()
        f = open(date_file, "wt")
        for n in range(len(date_list)):
            f.write(date_list[n])
            if n != len(date_list) - 1:
                f.write("\n")
        f.close()
except FileNotFoundError:
    print("There isn't such file")