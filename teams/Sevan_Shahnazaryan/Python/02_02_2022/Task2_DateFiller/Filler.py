from datetime import date, datetime, timedelta

def filler():
    with open("dates.txt") as date_list:
        date_list = date_list.readlines()
        new_list = []
        first_date = datetime.strptime(date_list[0][:-1], '%Y-%m-%d').date()
        second_date = datetime.strptime(date_list[-1], '%Y-%m-%d').date()
        delta = (second_date - first_date)
        new_list.append(first_date)
        while(delta.days > 0):
            first_date += timedelta(days=1)
            new_list.append(first_date)
            delta -= timedelta(days = 1)

    with open("dates.txt", 'w') as date_list:
        for i in new_list:
            date_list.write(str(i) + '\n')