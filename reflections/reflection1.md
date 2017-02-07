# Reflection 1

## Sprint Reflection

I think our process in Sprint 1 was, overall, pretty good. During every meeting we would check in (stand up) with everyone's progress and make sure everyone was up to date with what was going on in the project. We also keep our Trello board pretty updated. I feel like I have been making good progress towards my learning goals! I am learning a lot about networking and how computers can communicate with each other. The readings that I did for Head First C, along with all of the background research I did, prepared me well for when my team really started coding. However, I think my team could improve by explaining what having the individual members always explain how their code works more often so everyone knows how everyone else on the team is doing. Another thing that my team decided we lacked was making sure everyone thoroughly understood the readings. From the retrospective, we have decided that we can fix this by checking in with each other on how the readings went. So far, this seems to be working well.

I think that in the beginning of the sprint, we thought we would have a substantial amount of code by the end of the sprint. However, as we worked more on our project proposal and on the overall architecture of our project, we realized that we needed to devote more time to research and laying out our protocol. Thus, by the end of the sprint, our code consisted mainly of the HFC exercise 11 code, Allen's example server code, and some example server code from stack overflow, rather than a fully fleshed out MVP of our project.

## Head First C
During Sprint 1, my team assigned the following readings and completed these exercises:

- Ch1:
  - [Exercise 1](https://github.com/jovanduy/ExercisesInC/tree/master/exercises/ex01)
    - [cards.c](https://github.com/jovanduy/ExercisesInC/blob/master/exercises/ex01/cards.c)
    - [hello.c](https://github.com/jovanduy/ExercisesInC/blob/master/exercises/ex01/hello.c)
    - [hello.s](https://github.com/jovanduy/ExercisesInC/blob/master/exercises/ex01/hello.s)

- Ch2:
  - [Exercise 2](https://github.com/jovanduy/ExercisesInC/tree/master/exercises/ex02)
    - [stack.c](https://github.com/jovanduy/ExercisesInC/blob/master/exercises/ex02/stack.c)

- Ch3:
  [Exercise 3](https://github.com/jovanduy/ExercisesInC/tree/master/exercises/ex03)
    - [tee.c](https://github.com/jovanduy/ExercisesInC/blob/master/exercises/ex03/tee.c)

- Ch11:
  - [Exercise 11](https://github.com/jovanduy/ExercisesInC/tree/master/exercises/ex11)
    - [advice_client.c](https://github.com/jovanduy/ExercisesInC/blob/master/exercises/ex11/advice_client.c)
    - [ikkp-server.c](https://github.com/jovanduy/ExercisesInC/blob/master/exercises/ex11/ikkp-server.c)

We chose these readings because they gave us an introduction to C (especially ch 1 and 2) and also acted as necessary resources for our specific project (file reading and writing from Ch3 and client/server communication from Ch11). Had we not read Ch3 and Ch11 and instead read more of the assigned readings (such as the TOS chapters), we would not have had a good starting point for our project.

## Think OS

As explained above, we decided we needed the foundational C knowledge and the baseline resources provided to us by HFC more than we needed TOS at such an early stage in our project. During Sprint 2, we plan to read more of TOS to catch up on the assigned readings and to learn what we should understand from TOS.

## Exam Question
See [reflection1question.c](https://github.com/jovanduy/ExercisesInC/blob/master/reflections/reflection1question.c) and [reflection1solution.c](https://github.com/jovanduy/ExercisesInC/blob/master/reflections/reflection1solution.c). The question is that reflection1question.c should print out a huge number (100) by first calling make_num_huge() to update the variable `num` and then printing the updated `num`. However, there are some problems! Identify them and write out an updated version of the code so that everything works as expected.

Problems are:
- stdio.h is not included so printf() doesn't work
- current printf has %s instead of %i
- should pass &num as an argument to make_num_huge() instead of num
- the function declaration of make_num_huge() should be make_num_huge(int \*num) (there should be a \*)
- inside of make_num_huge(), num should be written as \*num instead of just num
