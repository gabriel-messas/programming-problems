#!/bin/python3

#
# Complete the 'playlist' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts INTEGER_ARRAY songs as parameter.
#

def playlist(songs):
    array = [0] * 60
    pairs = 0
    for song in songs:
        pairs += array[-song % 60]
        array[song % 60] += 1
    return pairs
