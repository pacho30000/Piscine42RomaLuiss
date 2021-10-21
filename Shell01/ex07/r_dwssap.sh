cat /etc/passwd | sed -n 'n;/^#/d;s/\:.*//;p' | rev | sort -r | sed -n "$FT_LINE1 $FT_LINE2 p" | awk 1 ORS=', '| sed 's/, $/\./'
