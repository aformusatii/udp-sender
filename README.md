Simple UDP Sender

netcat & /dev/udp/host/port are not good enouth to send binary data.

Compile:
```bash
gcc udpcl.c -o udpcl
```

Usage:
```bash
./udpcl host port byte1 byte2 byteN

./udpcl "192.168.1.10" 6001 1 2 3
```
