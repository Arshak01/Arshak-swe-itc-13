import strings_sorting


def main():    
    arr = ["wz3 45 df8",
            "qe3 12 907",
            "wz3 f12 mn0",
            "wz3 f12 mn1",
            "asd45 df 77",
            "po12 567 9"]
    m_sorted = strings_sorting.final_sort(arr)
    print(arr)
    print(m_sorted)


if __name__ == "__main__":
    main()