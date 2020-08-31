#!/usr/bin/python3
"""
parsing function
"""
import sys


def printCodes(cntCode, cntSize):
    """
    function to print the codes and the number of ocurrence
    """
    # print file size
    print("File size: {}".format(cntSize))
    # print all codes
    for key, val in cntCode.items():
        # if one code is not 0
        if val != 0:
            print("{}: {}".format(key, val))
        # reset the value
        cntCode[key] = 0


# dict to count the status codes
cntCode = {
    "200": 0, "301": 0, "400": 0, "401": 0,
    "403": 0, "404": 0, "405": 0, "500": 0
}
# count the file size
cntSize = 0
# count lines
cnt = 0

try:
    # read stdin
    for line in sys.stdin:
        # count lines
        cnt += 1
        # split the line by blank space
        splitVal = line.split(" ")
        # count file size
        cntSize += int(splitVal[8])
        # count status code
        cntCode[splitVal[7]] += 1
        # line 10 print
        if cnt % 10 == 0:
            printCodes(cntCode, cntSize)
            cntSize = 0
except KeyboardInterrupt:
    printCodes(cntCode, cntSize)
    raise
