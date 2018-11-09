#!/bin/bash
while true; do
    ./data > data.in
    ./std <data.in >std.out
    ./code <data.in >code.out
    if diff std.out code.out; then
        printf "AC\n"
    else
        printf "Wa\n"
        exit 0
    fi
done

作者：Steven1997
链接：https://www.jianshu.com/p/a4e02612fb22
來源：简书
简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。