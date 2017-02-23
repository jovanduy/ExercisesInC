# Reflection 2

## Sprint reflection
This sprint we made a lot of progress towards our final deliverable. Our process throughout Sprint 2 was good. During every meeting we would check in on everyone's progress and assign everyone individual tasks to complete and update the Trello board accordingly. By splitting up tasks like this, we were able to cover a lot of groundwork for our project.

We also realized the full importance of all of the planning we did in Sprint 1. Because we had laid out the details of our protocol, actually implementing the a torrent client in code became much simpler since we just had to follow the steps we previously made.

Next sprint (Sprint 3) will be all about integrating our individual parts. Although integration is a large (and important!) step, we planned for it to be happening now and thus allocated an appropriate amount of time to it, so it is not as daunting as it might sound.

Throughout this sprint we also repeatedly reminded each other to do the readings we assigned for our group on time. This was important for us because during Sprint 1 we did not check in with each other about our reading progress, and as a result we were a little shaky in our comprehension. So, we made making sure everyone does the readings on time the kaizen for this sprint. However, although we are now making sure everyone actually does the readings and giving each other opportunities to ask about the readings, one thing we could work more on is actually testing our comprehension of the reading material; just because read a chapter does not mean we actually understand what it covered.

We also found that we are not following some typical programming standards; in particular, we have been committing executables! Thus, in order to help us become better programmers, after we did a sprint retrospective, we decided to make keeping our .gitignore correctly updated our new kaizen and a goal for the next sprint.

I have also found that I am making good progress to my own learning goals. We did a lot more coding during Sprint 2 than in Sprint 1, and as such I am now much more comfortable with my understanding of C. I also understand more about networking.

## Head First C
During this sprint my team decided to focus on reading Think OS. In Sprint 1 we only read chapters from HFC in order to advance our understanding of sockets and allow us to be able to actually implement our project. Thus, we dedicated Sprint 2 to the Think OS chapters that were part of the assigned readings since we were more ahead with HFC.

## Think OS
During Sprint 2, my team assigned the following readings and completed these exercises:

- Ch1:
  - [Exercise for ch1: compilation](https://github.com/jovanduy/ExercisesInC/blob/master/reading_questions/thinkos.md#chapter-1)
- Ch2:
  - [Exercise for ch2: processes](https://github.com/jovanduy/ExercisesInC/blob/master/reading_questions/thinkos.md#chapter-2)
- Ch3:
  - [Exercise for ch3: virtual memory](https://github.com/jovanduy/ExercisesInC/blob/master/reading_questions/thinkos.md#chapter-3)
- Ch4:
  - [Exercise for ch4: files and file systems](https://github.com/jovanduy/ExercisesInC/blob/master/reading_questions/thinkos.md#chapter-4)

## Exam question
This question should be answerable by students who have read TOS Ch 3.

Question: What is an MMU? What does is its purpose and how does it do its job?

Answer: An MMU is a memory management unit. It is a part of a processor that translates the virtual addresses of a process into physical addresses in such a way that no two processes can generate virtual addresses that map to the same physical addresses. It takes a virtual address and finds the page number and offset of that virtual address. It then looks up the virtual address's page number in the page table for the given process to find that virtual page number's associated physical page number. The offset is added to this physical page number, creating a physical address which can then be read from or written to by memory.
