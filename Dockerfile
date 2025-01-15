FROM continuumio/miniconda3:24.11.1-0

RUN apt-get update
RUN apt-get install -y cmake build-essential

## Prepare environment

WORKDIR /pybind_lib_test

COPY ./environment.yml .
RUN conda env create -n pybind_lib_test -f environment.yml
RUN echo "conda activate pybind_lib_test" >> ~/.bashrc
ENV PATH /opt/conda/envs/pybind_lib_test/bin:$PATH

COPY . .

## Build

WORKDIR /pybind_lib_test/lib_src
RUN pip install .

## Execute

WORKDIR /pybind_lib_test/lib_usage
CMD ["python3", "main.py"]