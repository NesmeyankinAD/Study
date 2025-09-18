FROM ubuntu:latest
RUN apt-get update && apt-get install -y clang git
WORKDIR E:/Cpp_Folder_0/module_7/Docker/Task_2.1
RUN git clone -q https://github.com/NesmeyankinAD/Docker_test.git 
RUN cd Docker_test
RUN clang++ -o ProgressBar ProgressBar.cpp
CMD ["./ProgressBar"]