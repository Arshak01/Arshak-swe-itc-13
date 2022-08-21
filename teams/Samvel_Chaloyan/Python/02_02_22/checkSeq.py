<<<<<<< HEAD
=======
from asyncio import wrap_future
from calendar import month
from curses import start_color
from datetime import date
from datetime import timedelta
import datetime

#try:
#    f = open('dates.txt', 'r+')
#except:
#    print("The file doesn't exist!")

f = open('dates.txt', 'r+')
list = f.readlines()
# Delete the existing file content for replacing
#f.truncate()
f.close()

size = len(list)
dateStart = list[0]
dateEnd = list[size - 1]

startList = dateStart.split('-')

year = int(startList[0])

months = startList[1]
if months[0] == '0':
    months_int = int(months[1])
else:
    months_int = int(months)

days = startList[2]
if days[0] == '0':
    day_int = int(days[1])
else:
    day_int = int(days)

dateStart = datetime.date(year, months_int, day_int)

endList = dateEnd.split('-')

year = int(endList[0])

months = endList[1]
if months[0] == '0':
    months_int = int(months[1])
else:
    months_int = int(months)

days = endList[2]
if days[0] == '0':
    day_int = int(days[1])
else:
    day_int = int(days)

dateEnd = datetime.date(year, months_int, day_int)

delta = datetime.timedelta(days=1)

#For not lossing the main file I use a new on below
while dateStart <= dateEnd:
    new = open('dates_new.txt', 'a')
    line = str(dateStart)
    new.write(line)
    new.write('\n')
    dateStart += delta

# Print the new complited file
#f = open('dates_new.txt', 'r+')
#print(f)


>>>>>>> 9fc0e8c5c33bf92a7c4756168f79486e17b9eda4
