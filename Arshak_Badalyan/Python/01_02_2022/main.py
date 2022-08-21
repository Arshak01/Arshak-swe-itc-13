import module


def main():
    str_list = ["wz3 45 df8",
                "qe3 12 907",
                "wz3 f12 mn0",
                "wz3 f12 mn1",
                "asd45 df 77",
                "po12 567 9"]
    list_sorted = module.last_sort(str_list)
    print("*** Unsort ***")
    module.printList(str_list)
    print("*** Sort ***")
    module.printList(list_sorted)


if __name__ == "__main__":
    main()
