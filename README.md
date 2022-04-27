# IPC-example

Project is consist of two applications: parent and child. When the parent process starts, it also starts the child process and observes the state of child application. When child executable is terminated or crashed, it's immediately executed by parent application

## Build
```bash
mkdir build
cd build
cmake ..
make
```
# Run

Run the program with the period option

```bash
cd parent 
./parent -p 1000
```
