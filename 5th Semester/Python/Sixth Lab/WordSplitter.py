import math


def clean(list):
    for i in range(len(list)):
        list[i] = list[i].replace(" ", "").replace("\n", "")[
            : math.ceil(len(list[i]) / 2)]
    return list


def merge(list1, list2):
    len1 = len(list1)
    len2 = len(list2)

    string = ""
    for i in range(len1):
        string += list1[i]
        if i < len2:
            string += list2[i]
        string += " "

    for i in range(len1, len2):
        string += list2[i]
        string += " "

    return string


with open("SampleFile1.txt") as first:
    with open("SampleFile2.txt") as second:
        first_file_words = clean(first.read().split(" "))
        second_file_words = clean(second.read().split(" "))
        print(merge(first_file_words, second_file_words))
