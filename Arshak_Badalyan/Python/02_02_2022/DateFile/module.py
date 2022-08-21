
from datetime import date
from datetime import timedelta

def convertDateObj(fileName):
    lists = []
    dateData = open(fileName, "r")
    for i in dateData:
        stripped = i.strip()
        lists.append(stripped)

    for i in  range(len(lists)-1):
        start = lists[i].split("-")
        end = lists[i+1].split("-")
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
            lists.append(day.strftime("%Y-%m-%d"))

    dateData.close()
    set_list = set()
    for i in lists:
        set_list.add(i)

    dates_list = []
    for i in set_list:
        dates_list.append(i)

    dates_list.sort()
    dateData = open(fileName,"w")
    for i in dates_list:
        dateData.write(i)
        dateData.write("\n")
    dateData.close()