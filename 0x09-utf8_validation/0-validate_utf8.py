#!/usr/bin/python3
"""
Validate UTF8
"""


def validUTF8(data):
    """
    validate if data are UTF8 chars
    """
    first = True
    charBytesNxt = 0
    charBytesPrv = 0
    binaryData = []

    for number in data:
        binaryData.append('{0:08b}'.format(number))

    for binary in binaryData:
        charBytesPrv = countBytes(binary)
        if first:
            if charBytesPrv == 0:
                continue

            if charBytesPrv >= 2 and charBytesPrv <= 4:
                first = False
                continue

            return False
        else:
            if charBytesPrv - 1 == charBytesNxt:
                charBytesPrv = charBytesNxt
                if charBytesPrv == 0:
                    first = True
                continue
            return False
    return True


def countBytes(binary):
    """
    coun number of bytes
    """
    oneCnt = 0
    for i in binary:
        if int(i) == 0:
            break
        oneCnt += 1
    return oneCnt
