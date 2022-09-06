# Day 2
- Porting of RTOS/EOS
- Process Independent
- Process Dependent
    - Timer => Clock Tick
    - Context Saving and Context Restoring

# Assignment
## RTOS Assignment
1. Find what is the task priority numbering for the RTOS you are using. eg. Higher the
number higher the priority or vice-versa. Find the range of priority that can be assigned to
a task for your RTOS.
2. What is the mechanism used to make a task periodic for the RTOS you are using? Write a
program to make a task periodic with periodicity of 500ms.
3. Find the APIs in your RTOS that provides timestamp and use it to print the periodic task.
Observe the jitter in the timestamp vs the periodicity. Enhance the code to 10 periodic tasks
with different periodicity. Futher observe the jitter in each of the task.
4. Create two task with priority 10 and 20. Each task prints its own custom message.
5. Swap the priority and observe the changes in the output. What is your conclusion on the
sequence of printing the messages.
6. What are the maximum number of tasks that can be created on the RTOS you are using?
Is it limited by the RTOS design or underlying hardware resources or both.
7. What is the scheduling algorithm used by your RTOS?
8. List the customization options for creating a task for the RTOS you are using. eg. priority
etc
9. Find the fields that are maintained in the Task Control Block / Process Control Block of the
RTOS you are using.
10. Draw a process or task state diagram for the RTOS you are using.
11. What is the API for deleting a task? Write a program demonstrate this capability.
12. What are the APIs provided by your RTOS for enabling and disabling the interrupts? Write
a program to demonstrate this capability?
13. Does your RTOS provide APIs to collect task statistics. If yes, list the statistics parameters
that are collected and write a program to display the runtime task statistics?
14. Find the tick frequency configuration for your RTOS.
15. Create a task to suspend itself after 1200 ms and resume it from another task
16. Write a RTOS application to demonstrate the use of changing priority
17. If you RTOS supports idle task hooking, write a program to demonstrate it
18. Write a RTOS application to demonstrate the use of task to task communication using
Queue management APIs. Also demonstrate blocking on a queue.
19. Write a RTOS application to demonstrate the effects of task priorities when sending to and
receiving from a queue.
20. Write a RTOS application to demonstrate deferred interrupt processing using binary semaphores
21. Write a RTOS application to demonstrate counting semaphores to synchronize a task
22. Write a RTOS application to demonstrate the usage of queues within an interrupt service
routine
23. Write a RTOS application to manage resources using mutual exclusion
24. Write a RTOS application to demonstrate a priority inversion problem. If your RTOS sup-
ports priority inheritance or priority ceiling, use it to solve the priority inversion problem.
25. Write a RTOS application to create a software timer that invokes a callback function every
5 seconds.

    - Ans1 = 0 - 24
    - Ans2 = Scheduling method
    - Ans3 =
    - Ans5 = Since the priorty of task1 is higher than task 2, Task 1 print first.
    - Ans6 = 25 task can be created in FreeRTOS. It is limited by RTOS design.
    - Ans7 = Fixed Priority Premptive Scheduling. 
    - Ans8 = 	vTaskDelay
  		vTaskDelayUntil												
		xTaskDelayUntil												
		uxTaskPriorityGet												
		vTaskPrioritySet											        
		vTaskSuspend												
  		vTaskResume											        
    		xTaskResumeFromISR											        
 		xTaskAbortDelay		
    - Ans9 =
    - Ans10 =
    - Ans11 = vTaskDelete(xHandle);
    - Ans12 = taskENABLE_INERRUPTS() and taskDISABLE_INTERRUPTS()
    - Ans13 = Yes, Run time Stats i.e. void vTaskGetRunTimeStats(char *pcWriteBuffer);.Abs Time(absolute time) and % Time(time percentage)
    - Ans14 = FreeRTOS is 100 in frequency
    - Ans16 =
    - Ans17 = Idle task Hooking mean to place the microcontroller CPU inot a power saving mode.

## REMAINING
    - Schedular Algorithm => High priority Task ?
    - Function in FreeRTOS => Scheduling
## DONE
    - Have separate file for Task 1 and and Task 2
    - Task1 => Resume => Task2
    - Task1 => Resume => Task2 and Task3
    - Task1 => Resume => Task2 => Resume => Task3 => Resume => Task1
## Class work
    - One Shot Timer(one time only print)
    - Free Timer(timer will be print multiple time's after every interval of time)
    - Counting Semaphore
    - Binary Semaphore
    - Stream Buffer
    - Message Buffer

- CRT  = CRT is  a C Real Time function where :-
    - 1> Initialization Interrupt
    - 2> Initialization Stack Pointer
    - 3> Initialization .Bss
    - 3> Initialization .Data
    - 4> Call main function 
- occurs before the main() funciton in int main()

# DAY 3
- Task => Stack (every task owe its own Stack)
    - Create Task   (when creating a stack its important to give size of the stack and priority)
        - Size of Stack 
        - Priority

# DAY 4
    - Stack Gaurd => Gaurd a particular stack area
	    - what it does=> It keep the guard value at the end of the stack. The moment it crosses the value, OS would understand that the thread have gone beyond the size of the thread allocated.
### Priorities
- Priorities affect the task execution(means task with high priority will execute first (on Free RTOS))(some RTOS might be the oppositely working)
    - ### Delay by Periodic
        - It delays for the given period of time
            - Delay task can give a chance to low priority to be execute even if there is high priority is present
        - #### There are three Catagories 
            - Periodic = The time between its execution is fixed
            - Aperiodic = The time between its execution in not fix i.e it varies. We don't know how much time will it take for the next execution period is.
            - Sporadic = Similar to Aperiodic but its Inter Arival Time is known.
- Task Specifications (Temporal)
    - Periodicity (Pi) = The time interval after which the task repeats itself is known as period of the task. 
    - Computation Time/Execution Time (Ci/Ei) = Task taken to compile/execute at a certain amount of time.
    - Deadline (Di) = It is a time by which a task should be finish it's execution.
- ### Rate Monotonic Scheduling(RMS)
    - They give priority to the task based on the rate.
    - Shorter the period > Higher the Rate > Higher the Priority
    - Summation Ci/Pi = m(2^1/m-1)

# DAY 5
- Interrupt Latency = Longer the interrupt are disable higher the Interrupt latency	
- Interrupt Response Time = The time between the reception of the Interrupt and the start of the user code that handles the Interrupt.
- Interrupt Recovery Time = Time required by the processor to return to the Interrupted Code.
- ISR Entry Function =
- ISR Exit Function =

# DAY 6
- Binary Signaling Semaphore
- Mutex
- Message Buffer = where data is release one by one i.e. if 4 msg block is given data then each data will receive one by one.(similar to fifo or fcfs)
- Stream Buffer = where all data is release in one shot .i.e. if 4 msg block is given then all 4 msg block of data will receive at one shot.
# Day 7
- Message Queue
- Event flag
