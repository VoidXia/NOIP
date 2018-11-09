#!/bin/bash
while true; do
    ./data >data.in
    ./std <data.in >std.out
    ./code <data.in >code.out
    if diff code.out std.out; then
        printf "AC\n"
    else 
        printf "WA\n"
        exit 0
    fi
done