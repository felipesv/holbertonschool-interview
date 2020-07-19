#!/usr/bin/python3
"""
lockboxes for interviews
"""


def canUnlockAll(boxes):
    """
    Function to determine if all boxes can be open
    """
    # if exists boxes
    if not boxes:
        return False
    # check if is a list
    if type(boxes) is not list:
        return False
    for box in boxes:
        if type(box) is not list:
            return False
    # used keys (default 0)
    keys = [0]
    # used each key
    for key in keys:
        # open the box and get the keys inside
        newKeys = boxes[key]
        for newKey in newKeys:
            # if the key wasn't use before and a valid key
            if newKey not in keys and newKey < len(box):
                keys.append(newKey)
    # if the number of boxes are the same number of keys used
    if len(boxes) == len(keys):
        return True
    return False
