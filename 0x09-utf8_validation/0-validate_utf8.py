#!/usr/bin/python3
"""
Validate UTF8
"""


def validUTF8(data):
    """
    validate if data are UTF8 chars
    """
    first = True
    charBytesPrv = 0
    charBytesCur = 0
    binaryData = []

    for number in data:
        binaryData.append('{0:08b}'.format((number & 255)))

    for binary in binaryData:
        charBytesCur = countBytes(binary)
        if first:
            if charBytesCur == 0:
                continue

            if charBytesCur >= 2 and charBytesCur <= 4:
                charBytesPrv = charBytesCur
                first = False
                continue

            return False
        else:
            if charBytesPrv - 1 == charBytesCur:
                charBytesPrv = charBytesCur
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
