#!/usr/bin/python3
"""
lockboxes for interviews
"""


def canUnlockAll(boxes):
    """
    Function to determine if all boxes can be open
    """
    # check if is a list
    if type(boxes) is not list:
        return False
    # check if all boxes are lists
    for box in boxes:
        if type(box) is not list:
            return False
    # status of each box
    status = [False for i in range(len(boxes))]
    status[0] = True
    # get the key from box 0 (default opened box)
    keys = [key for key in boxes[0]]
    # while exists keys to open boxes
    while len(keys) != 0:
        newkeys = []
        for key in keys:
            if not status[key]:
                newkeys = newkeys + boxes[key]
                status[key] = True
        # if all boxes are open
        if False not in status:
            return True
        keys = newkeys
    return False
