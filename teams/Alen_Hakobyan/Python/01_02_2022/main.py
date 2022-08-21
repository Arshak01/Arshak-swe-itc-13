import sortStrings

def main():
    str_list = ["wz3 45 df8",
                "qe3 12 907",
                "wz3 f12 mn0",
                "wz3 f12 mn1",
                "asd45 df 77",
                "po12 567 9"]
    list_sorted = sortStrings.last_sort(str_list)
    print("Before Sorting")
    for i in str_list:
        print(i)
    print()
    print("After Sorting")
    for i in list_sorted:
        print(i)

if __name__ == "__main__":
    main()