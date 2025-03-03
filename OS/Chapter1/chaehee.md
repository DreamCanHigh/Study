1.1 Operating System
- 하드웨어를 controll
- 각 자원들을 각 프로그램에 알맞게 할당하는 역할
- user와 hardware 사이에서 중재자 역할을 수행
 
A computer system can be divided: hardware, os, application programs, user
- 하드웨어 : CPU, memory, I/O devices, storage
- application programs : 문제를 해결하기 위해 자원이 어떻게 쓰일지 정의
- os : 각 프로그램들이 유용한 작업을 할 수 있는 환경 제공
 
1.1.1. User View
- 사용자 관점에서 컴퓨터는 인터페이스에 따라 달라진다. 랩탑, PC, 모바일, Siri(voice recognition) 등의 형태
- 이러한 시스템은 한 사용자가 자원을 독점하도록 설계되어있다. 때문에 사용자가 수행하는 작업을 최대화하는 것이 목표이다.
- os도 ease of use에 대부분 초점이 맞춰져있고, performance and security에 약간, resource utilization은 신경쓰지 않는다.
- user view가 아예 없는 것도 있다. embedded-system
 
1.1.2. System View
- system 관점에서는 더 하드웨어와 밀접하게 연관되어있다.
- os를 resource allocator(자원 할당자)로 볼 수 있다.
- 프로그램과 사용자에게 어떻게 자원을 효율적이고, 공정하게 할당할지 결정해야 한다.
- 다른 관점으로는 controll program(제어 프로그램)
- 컴퓨터의 improper user and errors 방지하는 역할
 
1.1.3. Defining OS
- 컴퓨터 시스템의 근본적인 목표는 프로그램을 실행하고, 사용자 문제를 어떻게 쉽게 푸는지에 있다.
- 그래서 하드웨어가 나타났고, 순수 하드웨어만으로는 조작하기 어려워 application program이 생겼다.
- 자원을 할당하고 제어하는 기능을 one piece로 묶은게 os이다.
- 보통 os를 kernel이라고 정의하기도 한다. 항상 실행되고 있는 프로그램으로 보면
- os = kernel + system programs(os와 관련이 있지만 kernel은 아닌거) + application programs(시스템 운영과 관련 없는거)
- 모바일 os는 middleware(application 개발을 도움)도 os에 포함: apple-iOS, google-Android
 
1.2 Computer-System Organization
- 컴퓨터 시스템 : 한 개 이상의 CPU + 여러 개의 device controller + common bus(구성 요소 간 데이터 전송) + shared memory


- device controller: 디스크 드라이브, 오디오 장치, 그래픽 디스플레이를 제어하는 컨트롤러, USB 허브는 여러 장치를 제어
- 각 device controller는 local buffer와 special-purpose registers(주변 장치에서 데이터를 이동시켜 자신의 로컬 버퍼에 저장)를 포함하고 있다.
- os는 device contoller에 대한 device driver를 제공한다.
 
1.2.1. Interrupts
- 하드웨어는 언제든지 CPU에 신호를 보내 interrupt를 발생시킬 수 있다. 하드웨어와 운영체제 간 상호작용에서 핵심 역할이다.
- device controller와 hardware가 interrupt를 발생시킨다.
- interrupt는 일반적으로 system bus로 전달된다.
- interrupt가 발생하면 CPU는 수행 중인 작업을 멈추고, 특정 위치(ISR: Interrupt Service Routine)로 실행을 전환한다.
- ISR 수행 후에는 CPU가 중단되었던 작업을 재개한다.
 
1.2.1.1. Overview
- ISR은 interrput에 맞는 핸들러를 호출한다.
- 빠르게 호출하기 위해 interrupt vector(ISR의 주소를 저장한 배열)를 통해 처리한다. 
- 각 interrupt는 고유한 숫자로 식별되고, 그 숫자로 백터 테이블에서 ISR을 찾는다.
- interrupt가 발생하면 복귀 주소를 Program Counter에 저장해서 돌아올 곳을 표시한다.
 
1.2.1.2. Inplementation
- CPU는 매 명령어 실행 후 interrupt-request 라인에서 신호를 감지한다.
- 만약, device controller가 interrupt-request 라인에 신호를 보내면, CPU는 interrupt 번호를 읽고 interrupt vector에서 번호를 찾아서 핸드러로 점프한다.
- 핸들러는 지금 수행을 멈춘 작업 상태를 저장하고, interrupt 원인을 파악한 후 처리한다. 그다음 저장한 상태를 다시 복원하고, return from interrupt 명령을 실행해서 CPU가 이전 작업을 다시 수행할 수 있도록 한다.
- 정리하자면, 장치 컨트롤러가 인터럽트 raises -> CPU가 이를 catches -> 인터럽트 핸들러 찾아서 dispatches -> 핸들러는 요청 clears 후 인터럽트 해제 -> CPU가 다시 돌아와서 이전 작업 수행
- 이 작업을 인터럽트 기반 I/O 사이클(interrupt-driven I/O)이라고 한다.

 
- 기본 매커니즘은 이러한데, 현대에는 향상된 인터럽트 처리 기능 제공
- 중요한 작업을 수행하면 인터럽트 처리 연기 가능, 장치별로 적합한 인터럽트 핸들러 효율적으로 호출, 다중 레벨 인터럽트(우선순위 순으로 인터럽트 처리)
- CPU 나 interrupt controller 하드웨어로 제공된다.
 
- 대부분의 CPU에는 nonmaskable interrupt, maskable interrupt 두 가지의 interrupt request line이 있다.
- 마스크 불가능 인터럽트: 메모리 오류와 같은 중요한 이벤트에 사용
- 마스크 가능 인터럽트 : CPU가 무시할 수 있는 인터럽트, 보통 device controller가 서비스를 요청할 때 사용된다.
 
- 백터 인터럽트 방식의 한계 : 장치 수가 인터럽트 백터 테이블의 크기보다 많을 수 있다. 즉, 장치마다 핸들러가 다른데 백터 테이블에 저장할 수 있는 핸들러의 개수는 한정되어 있다는 것이다.
- interrupt chaining : 백터 테이블의 한 항목이 하나의 인터럽트 핸들러 주소를 가리키는게 아니라, 같은 인터럽트 번호를 공유하는 여러 장치들의 인터럽트 핸들러 리스트를 가리키는 방식이다.
- 이렇게 하면, 해당 리스트에서 요청을 처리할 수 있는 핸들러가 발생할 때까지 실행한다.
 
- 인터럽트 우선순위 시스템 : 우선순위가 높으면 먼저 선점할 수 있다.
