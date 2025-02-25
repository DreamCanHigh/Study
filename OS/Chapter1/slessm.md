Introduction

Operating system is software that manages a computer’s hardware.
- The major componets of a contemporary computer stystem
- Data structure used in os
- Computing environments
- Open-source and free os

1.1 What Operating Systems Do

Roughly divided into four components

- The hardware - cpu, memory, i/o devices
- The operating system - word processors, spreadsheets, compilers, web browsers? - it’s like a government.
  (The question is that what’s mean exectly the word processors and spreadsheets in the operating system?)
- The application programs
- A user

1.1.1 User View : Like a touch screee, Siri, embeded computers, etc.

The goal is to maximize the work that the user is performing.

OS is designed for 
- ease of use
- Resource utilization

1.1.2 System View : resource allocator and control program.

Decide how to allocate them to specific programs and users. So that it can operate the computer system efficienly and fairly.

Emplahsizes the need to control the various i/o devices and user programs.

1.1.3 Defining Operating Systems

Fixed-purppose (military uses) → general-purpose

In the 1960s, Moore’s Law → variety of operation systems.

An operating system is difficult to define what an operating system is. (이게 맞는 문법?) becuase it exists to offer a resonable way to solve the poblem of creating a usable computing system. And the fundamental goal of computer systems is to execute programs and to make solving user problems easier.
→ application programs are devloped.
→ require certain common operations
→ operating system is a collection of functions to controll and allocating resource

Operating system is the one porgram running at all times on the computer → kernel
- system programs - associated with the os but not necessarily part of the kernel.
- Application programs - not associated with the os.

The operating system includes…
- Kernel
- Middleware : ios, android
- System porgrams

1.2 Computer-System Organization

OS have a device driver for each device controller.
- A device controller maintains some local buffer storage and a set of special-purpose registers.

1.2.1 Interrupts

1.2.1.1 Overview

Interrupts must be handled quickly. So a table of pointers to interrupt routines can be used instead to provide the necessary speed. (The interrupt vector)
- a unique number - the address of the interrupt service routine
- A state information of whatever was interrupted

1.2.1.2 Implementation

Basic
- the device controller raises an interrupt.
- the CPU catches the interrupt and dispatches it to the interrupt handler using interrupt-request line, it reads the interrupt number and jumps to the interrupt-hanlder routine.
- the handler clears the interrupt by servicing the device.

Plus
- the ability to defer interrupt handling
- An efficient way to ~
- Multilevel interrupts

Most CPUs have two interrupt request lines.
- the nonmaskable interrupt
- maskable : it can be turned off by the CPU.

Devices > address elements in the interrupt vector.
→ use interrupt chaining (inefficiency of dispatching)
→ interrupt priority levels (preempt)
