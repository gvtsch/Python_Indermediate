# Paraller Code Execution in Python

Threading (Concurrently)
- A new thread is spawned within the existing process
- Starting a thread is faster than starting a process
- Memory is shared between all threads
- Mutexes often necessary to control access to shared data

Multiprocessing (Parallel)
- A new process is started independent from the first process
- Starting a process is slower than starting a thread 
- Memory is not shared between processes

![Alt text](https://miro.medium.com/v2/resize:fit:4800/format:webp/1*F8ckVaR__PlBssnf-mn76A.png)

Asyng:
- Refers to the occurence of events independent of the main program flow
- Waiting for an event from the outside of our program
- Concurrent programming is the ability to release the CPU during waiting periods so that other tasks can use it
