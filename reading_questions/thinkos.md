## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

  Interpreted languages usually support dynamic typing. For example, in Python I can say:
  ```
  x = 5
  x = "hi"
  ```
  However, in C, I have to declare what type the variable is. For example:
  ```
  int x = 5;
  ```
  I cannot reassign `x` to something that is not an int.
  If I were to try to assign `x` to something that was not an int, I would get a compile time error. This is nice because I won't run into as many errors during runtime, but it also means that I cannot use the same functions for both string concatenation and int addition!

2) Name two advantages of static typing over dynamic typing.

Static typing allows compile-time checks of whether or not the operations done on variables are legal or if functions are being called with variables of the correct type. This is important because such problems are found at compile time, not runtime. Thus, bad code will never actually be run, and, furthermore, runtime will be faster since such checks are not done at runtime.

Static typing also saves space; variable names do not exist at runtime. Instead, during compilation, the addresses of the variables are saved, but not the actual variable names. In dynamically typed languages, the variable names are stored and accessed.

3) Give an example of a static semantic error.

A static semantic error would be if this function:

```
int foo(int a, int b) {
  return a + b;
}
```

were to be called as `foo(5);`. The error would be that the function does not have the correct number of arguments (1 instead of 2).

4) What are two reasons you might want to turn off code optimization?

Code optimization makes compilation time longer, so turning it off would be useful if you do not want to wait even longer for your code to compile. Also, optimization can make some bugs disappear or reappear, so when writing new, untested code, leaving optimization off is best so you can more easily debug the program.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

Different computers can have different architectures. `-S` generates the assemble language code specific for your computer's hardware.

6) If you spell a variable name wrong, or if you spell a function name wrong,
the error messages you get might look very different.  Why?

This is because these errors are detected during different parts of the compilation process. Spelling a variable name wrong results in an undeclared identifier, while spelling a function name wrong says there is no such declared function.

7) What is a segmentation fault?

A segmentation fault is a runtime error caused by attempting to read or write to an incorrect location in memory.


## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

Amazon virtually sells a ton of products. However, when you look at the seller of an item on Amazon, it is not always actually sold by Amazon. Yet, knowing from whom the product is sold is not important to the Amazon user; to them, Amazon pretty much sells everything since they just have to go to Amazon.com to search for the items (as opposed to searching for all of the actual sellers themselves).

2) What is the difference between a program and a process?

A process is the object that represents a running program. A process is what isolates a running program, such as the text of the program, any data of the program, and the state of the program, from other programs. Processes are isolated from each other so that their programs do not conflict/interfere with one another.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

This abstraction makes it so programmers do not have to think about how all of the processes could interact with each other. Thus, programmers do not have to worry about two processes possibly conflicting with each other (such as trying to access the same memory) or about how to make two processes run simultaneously. To the programmer, each program acts as if it has its own memory, runs continuously as desired, and can never accidentally interfere with another program.

4) What is the kernel?

The kernel is a part of the operating system. It is responsible for creating threads and other core capabilities.

5) What is a daemon?

A daemon is a process that runs in the background and provides operating system services.


## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

6 bits. This is because log<sub>2</sub>33 = 5.04, which rounded up is 6.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2<sup>32</sup> = 4,294,967,296 characters

3) What is the difference between "memory" and "storage" as defined in Think OS?

"Memory" refers to (usually) volatile RAM where most of a running process's data is held. "Storage" refers to HDDs and SSDs that are non-volatile and are used to store the files that a process reads or writes.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

A GiB is a gibibyte, which is 2<sup>30</sup> bytes. Memory is normally measured in GiB. A GB is a gigabyte, which is is 10<sup>9</sup> bytes. The percent difference is 1.78%.

5) How does the virtual memory system help isolate processes from each other?

When a program reads or writes to memory, it writes to virtual memory. These virtual addresses are then translated to physical addresses. No two processes translate from virtual to physical memory in the same way, so even if they try writing to the same virtual address, the virtual addresses will be translated to different physical addresses. Thus, processes cannot access data from other processes.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

This is so they can both have a lot of room to grow. As they expand, the space between them decreases, so they should be at opposite ends to allow for maximum space to expand.

7) What Python data structure would you use to represent a sparse array?

scipy.sparse... But actually, maybe a dictionary? It would be similar to an associative table, when keys are VA and values are PA.

8) What is a context switch?

A context switch is when the operating system interrupts a running process, saves its state, and then runs another process.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  

The heap grows up. The first pointer is at 0x7f9c7b403170 and the second at 0x7f9c7b4031f0 (the second is larger).

2) Add a function that prints the address of a local variable, and check whether the stack grows down.

The stack grows down. The first local variable is at 0x7fff5b430a38 and the second at 0x7fff5b4309fc (second is smaller).

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

There is 0x10 (16) between them if I choose 11. But if I choose 31 there is 0x20 (32) between them.

## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically
true about files systems but not true of their implementations.

File systems make it so programmers do not have to worry about how the blocks of storage are organized or how SSDs can become unreliable. File systems instead allow the information of a file to be saved under a file name and in bytes, not blocks.

Under a file system, you can write to a file byte by byte. However, the file is actually written block by block. Thus, in a file system, you might think you are changing the file many times (if you intend to keep rewriting the same bytes for some reason), but in actuality the file is not actually saved to storage after each change; rather, it is saved to a buffer that is not translated to actual persistent storage until there is a full block or until the file is closed.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

An `OpenFileTableEntry` probably stores the file's name, whether it is opened for reading, writing, or both, and where you are in the file (the file position).

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

The operating system usually switches to another process while waiting for data from storage. The processor can also load more blocks (block transfers), the operating system can load blocks before the processor actually requests them (prefetching), the OS can save any written data in memory to a buffer before actually saving it to the disk so there is only one write as opposed to multiple (buffering), and the operating system can keep a block in memory that was previously requested so it does not need to be fetched from the disk when requested again (caching).

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the
file you wrote is not there.  What happened?

The program thought that the file had been saved, but in actuality, the operating system just cached the data in memory. Before the operating system had a chance to write it to the disk (which can take awhile), the power was cut!

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

A FAT doesn't really have a max file size, whereas in inode the maximum file size is 8 TiB. However, since FAT works basically like a linked list, if you wanted to get to some data at the end of a larger file, getting there would be really slow as you would have to go through all of the previous clusters. With inode, you would only have to go through a maximum of three indirection blocks to find what you are looking for.

6) What is overhead?  What is fragmentation?

Overhead is the space that the data structures used by the block allocation system use up. Fragmentation is the unused space when some blocks are unused or are only partially used.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

It is good because programmers can learn how to do multiple things (use pipes, sockets, etc) without much extra work if they already know how to write and read to/from files; the API for all of these is the same. It also makes a lot of code useable in multiple situations. However, this might cause programmers to lose sight of how the computer actually works, which might be a problem in debugging.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator.
Try it out and confirm that the result is interpreted as -12.

```
num = (12 ^ -1) + 1;
```
`num` does indeed come out to -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

```
void change_case(char *str, int len) {
  for (int i = 0; i < len; i++) {
    string[i] ^= 32;
  }
}
```

## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

`calloc` is proportional to the size of the chunk. `free` is probably constant. `malloc` also probably does not depend on the size of the chunk. `realloc` can depend on chunk size.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

Something random is stored at that location and is interpreted as something (for example, a string might be interpreted as a float that is a super large number). Or if you're lucky, you might get a seg fault at runtime if this error is detected.

b) Writing to unallocated memory.

A long time might pass before this bad value is read, so it can be difficult to find the source of the problem. You can also mess up the data structures that are used to implement `malloc` and `free` by writing past the end of an allocated chunk of memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.

That is a memory leak, which can be fine in a small program, but in a larger program...

You can run out of memory (either all of the physical memory is used up, the process's usable virtual memory is used up, etc) and the next time you call `malloc`, it will return `NULL`.

3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

`malloc` also uses space at the beginning and end of the chunk to store information about the chunk that makes up `malloc`'s internal data structures. These data structures take up space, so mallocing a lot of small chunks is not space efficient because a lot of these data structures will also be created. Instead, you can allocate your small structures together in an array as one large structure.

If you want to know more about how malloc works, read
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

Then the instruction corresponding to that new value will be the next instruction that is implemented.

2) What is the fundamental problem caches are meant to solve?

The "memory bottleneck": a lot (about half) of the instructions load or store data. A cache is supposed to decrease the time taken to load data.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

50%
(.5 * 1ns) + (.5 * 10ns) = 5.5ns

90%
(.9 * 1ns) + (.1 * 10ns) = 1.9ns

4) The book gives several examples of programming language features, like loops, that tend
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

An example that might decrease spacial locality is a block of code with jumps or branches.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?


6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with
different cache sizes.


7) Why are cache policies generally more complex at the bottom of the memory hierarchy?


8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?


Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

The kernel's most basic task is handling interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The program counter, so the kernel knows where to resume.

3) What is the difference between an interrupt and a context switch?

An interrupt is a halt in the normal instruction cycle to allow the interrupt handler to run. If there is no context switch, after the interrupt has been handled and the hardware state before the interrupt has been restored, the original process that was running continues to run where it had left off. A context switch is when, instead of returning to the original process after the interrupt has been handled, a new process is chosen to run.

An interrupt is a halt in the normal flow of instruction execution, while a context switch loads another process (a different set of instructions) to be executed.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

One possible event is a system call, such as a disk request, completing. Upon completion, there is an interrupt and the interrupt handler then changes the state of the process that called that system call from blocked to ready.

5) Why might a scheduler want to give higher priority to an I/O bound process

An I/O bound process might be interactive and therefore should have low response time for the user. Furthermore, once the process starts running again, it might only run for a very short amount of time before blocking again while waiting for more input (a process that will run for a short amount of time before blocking should be run first before processes that will take a longer time so that more requests can be made in a shorter amount of time).

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)

- Cook 8 slices on one side for 5 minutes
- Flip 4, remove the other 4, and add on the next uncooked 4 and cook for 5 minutes
- Remove the 4 completely finished slices, flip the half cooked 4, add back on the other half cooked 4 and cook for 5 minutes

In total this takes 3*5 = 15 minutes



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

Each thread has its own stack so that threads can call functions without interfering with each other and cannot access each other's local variables.

2) What does the `gcc flag -lpthread` do?

The `-l` option allows you to compile with the Pthread library in `gcc`. This links your program with the Pthread library.

3) What does the argument of `pthread_exit` do?

This argument is a value that is passed to the thread that joins with the thread.

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

You can do that, but in the common model the parent joins the child.

5) What goes wrong if several threads try to increment a shared integer at the same time?

There can be a synchronization error; they all read the same value before any thread has incremented it, and then they all increment it. Thus, instead of the value being incremented to a higher value by every thread, each thread just increments the original value, so the value actually only is incremented once.

6) What does it mean to "lock a mutex"?

Locking a mutex has the effect of barring all other threads until the mutex has been unlocked. A mutex is an object that guarantees mutual exclusion for a block of code, so after a thread locks a mutex, it can then run some code with the guarantee that other threads will not also be running the same code until the mutex has been unlocked (thus preventing synchronization errors) and those other threads can stop blocking.


## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

If a data structure is thread safe, multiple threads can access it at the same time.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

This is because after the `n`th element, the queue wraps back around to the 0th element. The check to see if the queue is empty is by comparing `queue->next_in` with `queue->next_out`. If the last element were the `n`th element, once all `n` elements were full, the queue would return that it is empty because both next_out and next_in will be from the 0th index. Thus, in order to avoid this problem, the maximum number of elements is `n-1`.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

If it did not unlock the mutex, no other thread could access the queue and therefore no items could be added/removed to/from the queue, meaning that the queue would always stay the same and thus the condition would never be met.

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

We know that the condition is true and that the mutex is locked (so this thread can safely access the queue).
What we think that the condition is probably true.

6) What happens if you signal a condition variable when there are no waiting threads?

There is no effect.

7) Do you have to lock the mutex to signal a condition variable?

No.

8) Does the condition have to be true when you signal a condition variable?

No.



## Chapter 11


### Semaphores in C
