# Instructions:
# Run: docker build -t autograding_maxsubarray .

FROM ubuntu:22.04
MAINTAINER David Wang <dfwang@andrew.cmu.edu>

RUN apt-get update
RUN apt-get install -y gcc
RUN apt-get install -y make
RUN apt-get install -y build-essential
RUN apt-get install -y git
RUN apt-get install -y python3
RUN apt-get install -y sudo

# Install autodriver
WORKDIR /home
RUN useradd autolab
RUN useradd autograde
RUN mkdir autolab autograde output
RUN chown autolab:autolab autolab
RUN chown autolab:autolab output
RUN chown autograde:autograde autograde
RUN git clone https://github.com/autolab/Tango.git
WORKDIR Tango/autodriver
RUN make clean && make
RUN cp autodriver /usr/bin/autodriver
RUN chmod +s /usr/bin/autodriver

# Clean up
WORKDIR /home
RUN apt-get remove -y git
RUN apt-get -y autoremove
RUN rm -rf Tango/

# Check installation
RUN ls -l /home
RUN which autodriver