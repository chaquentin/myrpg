def is_intersection(p1, p2, p3, p4):
    p1 = [int(p1[0]), int(p1[1])]
    p2 = [int(p2[0]), int(p2[1])]
    p3 = [int(p3[0]), int(p3[1])]
    p4 = [int(p4[0]), int(p4[1])]
    a1 = p2[1] - p1[1]
    b1 = p1[0] - p2[0]
    c1 = a1 * p1[0] + b1 * p1[1]
    a2 = p4[1] - p3[1]
    b2 = p3[0] - p4[0]
    c2 = a2 * p3[0] + b2 * p3[1]
    delta = a1 * b2 - a2 * b1

    intersection = [-1, -1]
    if (delta == 0):
        return [-1, -1]
    intersection[0] = (b2 * c1 - b1 * c2) / delta
    intersection[1] = (a1 * c2 - a2 * c1) / delta
    return (intersection)

p = input().split(' ')
print(is_intersection(p[0].split(';'), p[1].split(';'), p[2].split(';'), p[3].split(';')))