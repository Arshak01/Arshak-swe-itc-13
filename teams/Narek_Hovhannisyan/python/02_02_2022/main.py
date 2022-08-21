import gapsbetweendates
import most_often_names

def main():
    # gapsbetweendates.fill_spaces_between_dates("dates.txt")
    # uncomment the line above to fill missing dates in the "dates.txt" file

    names_list = [
        "Tux is a penguin character LiNuX and the official brand character of the LINUX kernel",
        "Originally created as an entry to a Linux logo competition, TUX is the most commonly used icon for Linux", 
        "although LINUX different Linux distributions Linux depict Tux in various styles Linux", 
        "The character is used Tux in many other Linux programs and as a general"
    ]
    res = most_often_names.find_names(names_list, 1)
    print(res)
    res2 = most_often_names.find_names(names_list, 5)
    print(res2)
    res3 = most_often_names.find_names(names_list)
    print(res3)


if __name__ == "__main__":
    main()