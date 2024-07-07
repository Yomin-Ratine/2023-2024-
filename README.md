# 2023-2024 综合设计1

## 一、实习目的、要求

综合程序设计是配合专业课程《C语言程序设计》而设置的实践教学环节，课程的目标在于通过实现中等规模的应用软件，使学生加深对高级程序设计语言课程中基本知识的理解，掌握各种数据类型的使用技巧和模块化程序设计的方法；培养良好的程序设计风格与代码规范意识，包括程序结构形式，行文格式等，提高学生上机调试程序的能力；确立分析问题、建立模型和编写程序进行问题求解的思维方式，提高学生利用计算机系统对具有一定复杂度和规模的问题进行分析求解的综合能力。

要求学生根据所给定的实习题目，首先给出详细的设计思路，包括功能实现分析和模块流程图；在此基础上编写程序代码，调试程序使其能正确运行，并用实际数据进行测试；设计完成的软件要便于操作和使用，代码书写要规范，标识符要见名知意，并要有必要的注释。设计完成后提交设计实习报告和源程序。

## 二、实习主要内容

### 1.设计内容

项目二 停车场管理系统的设计与实现
项目三 银行业务模拟系统的设计与实现

### 2.设计方法和流程

#### 项目二 停车场管理系统的设计与实现

##### 设计方法：

面向对象设计：虽然代码使用了结构体而不是类，但它体现了面向对象设计的思想。Car 和 ParkingLot 结构体分别代表汽车和停车场这两个实体，它们有各自的属性和行为。

##### 流程及程序框图请自行用Virtus生成

##### 数组结构选择：

使用数组 cars 来模拟停车场内的车辆，通过 top 变量跟踪当前停车场内的车辆数量。
使用另一个数组 waitingQueue 来模拟等待进入停车场的车辆队列，通过 waitingTop 变量跟踪等待队列中的车辆数量。
时间模拟：使用 time(NULL) 函数来获取当前时间（以秒为单位），模拟车辆的到达时间和离开时间。
随机性：在 main 函数中，使用随机数生成器来决定哪辆车会离开停车场，以模拟实际情况下车辆离开的不确定性。

代码采用模块化设计，分别设计了三个函数用于初始化停车场、模拟车辆到达、模拟车辆离开这三个步骤。整体程序的过程是生成随机数模拟车辆的到达和离开。其中停车场最多能停放汽车的数量为宏定义，可以人工修改。
这个模拟程序可以帮助我们理解停车场管理系统的基本工作原理，并可以作为开发更复杂、更实际的停车场管理系统的起点。

#### 项目三 银行业务模拟系统的设计与实现

##### 设计方法：

程序在处理基本数据运算的时候使用了面向过程的设计思想，模拟了随机生成客户和服务时间、窗口管理、等待时间计算、服务时间、平均逗留时间等几个动作，设计原理分别如下：
随机生成客户和服务时间：
使用GenerateRandomNumber函数随机生成客户到达的时间间隔和每个客户的服务时间。这模拟了现实世界中客户到达和服务的不确定性。
窗口管理：
window数组用于跟踪每个窗口当前正在服务的客户数量。
ChooseArray函数选择下一个应该服务的窗口。如果所有窗口都是空的，则选择第一个窗口。否则，它选择当前服务客户最少的窗口。
等待时间计算：
CalcWaitTime函数计算客户在当前选择的窗口前的等待时间。但请注意，此函数中的Operate调用似乎有些问题，因为它实际上在服务客户后才被调用，而不是在之前。这可能导致等待时间的计算不准确。
服务时间：
Operate函数模拟了服务过程，减少了相应窗口的客户数量，并更新了总服务时间和总客户数。

平均逗留时间：
最后，代码计算了客户在银行逗留的平均时间，包括等待时间和服务时间。

##### 流程及程序框图请自行用Virtus生成

##### 代码设计说明：

window[4]：表示四个服务窗口的当前客户数量。
MaxCustomerFlow、MinCustomerFlow：客流量范围（但在这段代码中，它们被错误地用于服务时间范围）。
TotalCustomers：累计服务客户数。
TotalWaitTime：累计等待时间。
CurrentTime：当前时间（模拟的分钟数）。
TotalServiceTime：银行营业的总时间（但也被错误地用于记录累计服务时间）。
MaxServiceTime、MinServiceTime：服务时间范围（同样，这两个变量被错误地使用了两次）。
函数：
find_min(int arr[], int size)：返回数组中最小值的索引。
GenerateRandomNumber(int min, int max)：生成指定范围内的随机整数。
ChooseArray()：选择下一个应该服务的窗口（基于当前窗口的客户数量）。
CalcWaitTime(int windowIndex)：计算在当前窗口前的等待时间（但在这段代码中，其实现方式有误）。
Operate(int CurrentTime, int WindowIndex)：模拟服务过程，包括减少窗口的客户数量、更新总服务时间和总客户数。
mabs(double n)：返回数值的绝对值（但在这段代码中，它是不必要的）。
主函数（main）：
初始化变量。
输入银行营业的总时间、客流量范围和服务时间范围（但输入部分存在问题，如前面所述）。
通过循环模拟客户的到达、选择窗口、等待、服务过程，直到达到银行营业的总时间。
计算并输出客户在银行逗留的平均时间。

## 三、实习总结（可另附报告）：

程序运行结果：
项目二 停车场管理系统的设计与实现
测试用例：停车场最大停车的数量：10
控制台输出：

```bash
Car 1 arrived and parked at position 1.
Car 1 left after 0 seconds and paid for its stay.
Car 2 arrived and parked at position 1.
Car 1 not found in the lot.
Car 3 arrived and parked at position 2.
Car 4 arrived and parked at position 3.
Car 5 arrived and parked at position 4.
Car 6 arrived and parked at position 5.
Car 4 left after 0 seconds and paid for its stay.
Car 7 arrived and parked at position 5.
Car 5 left after 0 seconds and paid for its stay.
Car 8 arrived and parked at position 5.
Car 9 arrived and parked at position 6.
Car 5 not found in the lot.
Car 10 arrived and parked at position 7.
Car 11 arrived and parked at position 8.
Car 8 left after 0 seconds and paid for its stay.
Car 12 arrived and parked at position 8.
Car 13 arrived and parked at position 9.
Car 1 not found in the lot.
Car 14 arrived and parked at position 10.
Car 8 not found in the lot.
Car 15 arrived and is waiting in queue.
Car 8 not found in the lot.
Car 16 arrived and is waiting in queue.
Car 9 left after 0 seconds and paid for its stay.
Car 15 from the waiting queue entered the lot.
Car 17 arrived and is waiting in queue.
Car 18 arrived and is waiting in queue.
Car 9 not found in the lot.
Car 19 arrived and is waiting in queue.
Car 8 not found in the lot.
Car 20 arrived and is waiting in queue.
```

运行结果与预期结果一致。

项目三 银行业务模拟系统的设计与实现
测试用例：银行营业时间：60min
客流量范围：2-8位
请输入每个客户服务时长范围：2-10min
控制台输出：

```bash
一天中客户在银行逗留的平均时间(分钟)：6.500047
```

运行结果与预期结果一致。
设计过程中的一些问题：

1. C语言不能直接使用C++的STL库的问题。本实习要求使用C语言而不能使用C++，C++的某些类库不能很方便地调用，故只能自行代写某些模块；
2. 在项目三统计客户的等待时间的过程中代码设计不够简洁，只能手动优化到能力范围内的最优算法；
3. 变量和函数过程的命名不严谨，只能采取Windows风格的名命名规则辅以旁注释；
4. 代码没有遵守较为完备的错误处理和资源节省原则。

这一次的实习项目中我选择了停车场管理系统的设计与实现和银行业务模拟系统的设计与实现。这两个项目有很多共同之处，让我在编写程序的过程中受益匪浅。两个项目都涉及到对现实世界流程的模拟。银行业务模拟系统模拟了客户在银行办理业务的流程，而停车场管理系统则模拟了车辆进出停车场的流程。在两个项目中，都需要设计系统的整体架构，包括各个模块之间的交互、数据流的处理等。两个系统都需要处理大量的数据，如银行业务模拟系统中的客户数据、交易数据，以及停车场管理系统中的车辆信息、停车位信息、停车时间等。在模拟过程中，都需要考虑随机性和不确定性因素，如银行业务模拟系统中的客户到达时间、服务时间，以及停车场管理系统中的车辆到达时间、离开时间等。
通过这两个项目，我加深对系统设计和开发的理解，提升设计和实现复杂系统的能力。在项目过程中，会遇到各种问题和挑战，通过分析和解决这些问题，可以锻炼自己的问题分析和解决能力。通过模拟停车场管理系统和银行业务模拟系统，可以加深对这两个业务领域的理解，为未来的工作和学习打下基础。



成绩评定：优秀