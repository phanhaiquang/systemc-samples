FROM guusk/docker-systemc:2.3.0
COPY . /samples
RUN sudo apt-get update -y
RUN sudo apt-get install -y gtkwave
RUN sudo apt-get install -y dbus-x11
RUN sudo service dbus start
