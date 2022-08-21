from datetime import date, timedelta

def convertDateObj(file_name):
    date_file = open(file_name,"r")
    list_s = []
    for i in date_file:
        stripped = i.strip()
        list_s.append(stripped)
    for i in range(len(list_s)-1):
        start = list_s[i].split("-")
        end = list_s[i+1].split("-")
        start_year = int(start[0])
        start_month = int(start[1])
        start_day = int(start[2])
        finish_year = int(end[0])
        finish_month = int(end[1])
        finish_day = int(end[2])
        start_date = date(start_year,start_month,start_day)
        finish_date = date(finish_year,finish_month,finish_day)
        delta = finish_date - start_date
        for i in range(delta.days):
            day = start_date + timedelta(days = i)
            list_s.append(day.strftime("%Y-%m-%d"))
    date_file.close()
    set_list = set()
    for i in list_s:
        set_list.add(i)
    dates_list = []
    for i in set_list:
        dates_list.append(i)
    dates_list.sort()
    date_file = open(file_name,"w")
    for i in dates_list:
        date_file.write(i)
        date_file.write("\n")
    date_file.close()