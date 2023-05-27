Display owner of tty.

Used to set the DISPLAY after sudo

Spiros Ioannou 1995

```
$ gcc whowasi.c -O -o whowasi

$ sudo id
uid=0(root) gid=0(root) groups=0(root)

$ sudo ./whowasi
uid:gid:username:eusername=2032:5:sivann:root
```
