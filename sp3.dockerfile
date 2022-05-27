FROM ubuntu
COPY sp32.cpp .
COPY sp31.cpp .
RUN apt-get update
RUN apt-get install -y build-essential
RUN /bin/bash
