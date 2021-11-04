#!/bin/s
cat /etc/passwd | sed 's/:/ /g' | awk '{print $1}' | awk '!(NR%2)' | rev | sort -dr | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | tr '\n' "," | sed 's/,/, /g' | sed 's/, $/./'
