FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y python3-numpy python3-scipy python3-pip build-essential git
RUN pip3 install -U pip
RUN python3 --version | grep 'Python 3.10'

RUN apt install -y cmake g++ make

RUN git clone --recursive https://github.com/Carl-Rabbit/pybind_lib_test.git

RUN pip3 install -r ./pybind_lib_test/requirements.txt
RUN pip3 install ./pybind_lib_test/lib_src

WORKDIR /pybind_lib_test/lib_usage
CMD ["python3", "main.py"]