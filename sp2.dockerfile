FROM ubuntu
COPY sp2asm.asm .
COPY sp2c.c .
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install gcc nasm gdb yasm -y
RUN /bin/bash
