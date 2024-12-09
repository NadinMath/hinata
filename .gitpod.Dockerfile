FROM gitpod/workspace-dotnet
#FROM gitpod/workspace-full

RUN sudo apt-get update 
RUN sudo apt install -y git mc screen
#RUN sudo apt-get install -y valgrind libcmocka-dev cmocka-doc libcmocka0
