#!/usr/bin/python3
"""
parsing function
"""
import sys


counters = {
    "size": 0,
    "lines": 0
}

cntCode = {
    "200": 0, "301": 0, "400": 0, "401": 0,
    "403": 0, "404": 0, "405": 0, "500": 0
}


def printCodes():
    """
    function to print the codes and the number of ocurrence
    """
    # print file size
    print("File size: {}".format(counters["size"]))
    # print all codes
    for key, val in cntCode.items():
        # if one code is not 0
        if val != 0:
            print("{}: {}".format(key, val))
        # reset the value
        cntCode[key] = 0


def countCodeSize(listData):
    # count file size
    counters["size"] += int(listData[-1])
    # count status code
    cntCode[listData[-2]] += 1
    # line 10 print


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            counters["lines"] += 1
            countCodeSize(line.split(" "))
            if (counters["lines"] % 10 == 0):
                printCodes()
    except KeyboardInterrupt:
        printCodes()
        raise
    printCodes()
