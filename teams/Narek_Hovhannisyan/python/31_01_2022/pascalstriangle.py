def get_pascals_triangle(n):
    result = []
    for i in range(0, n):
        row = [1]
        for j in range(1, i):
            el = result[i - 1][j] + result[i - 1][j - 1]
            row.append(el)
        if i != 0:
            row.append(1)
        result.append(row)
    return result


def print_pascals_triangle(tri):
    for i in tri:
        print(i)


print_pascals_triangle(get_pascals_triangle(8))
