### Introduction
> 운영체제는 컴퓨터의 하드웨어를 관리하는 소프트웨어다

사용자(소프트웨어) <-> OS <-> 하드웨어
운영체제는 모든 곳에 존재한다. "Iot"라 불리는 것들 안에는 다 OS가 있다
지금 내가 텍스트를 치고, 화면을 보고, 마우스로 클릭. 노래를 듣는 것 모두 OS가 관리를 하고 있다.

`약간 지구의 공기 같은 느낌적인 느낌`

위처럼 운영체제는 하드웨어 자원을 관리하는 소프트웨어다. 그러면 하드웨어를 먼저 알아야 운영체제가 어떠한 역할을 하는지 이해하기 쉬울 것 같다.
여기서 말하는 하드웨어 자원에는, CPU, Memory, I/O devices, Stroage 등이 포함된다. OS의 목적은 이 것들의 자원을 관리하는 것이다

### 1.1 그래서 OS가 하는 일들...
컴퓨터 구조는 크게 4가지로 나뉠 수 있다.
1. Hardware
	- cpu, mem,i/o 등 시스템을 구성하는 기본 컴퓨터 자원
2. Operationg System
3. Application programs
	- PPT, Knox Messenger, Chrome 등 사용자들의 작업을 해주기 위한 도구
	- 이러한 도구들을 사용자들이 편하게 쓸 수 있도록 안 보이는 곳에서 도와주는 친구가 바로~ `OS`
4. User

뭐 이렇게도 볼 수 있고 아니면 `Hardware`, `Software`, `Data` 의 묶음으로 볼 수도 있다.
그리고 이러한 자원들을 OS가 관리하는 것이다. 그냥 `정부`라고 생각하면 될 것이다.

### 1.1.1 User view
사용자 입장에선 OS가 어떤 것일까??
대부분의 사용자들은 OS가 뭔지 모를 것이다. 사실 알 필요도 없다. 사용자들은 자기가 필요한 앱을 구동할 뿐이다.
위 상황에서 OS는 최대한 사용자가 사용 중인 프로그램의 성능을 높여주는 역할을 한다.
(성능, 보안, 자원 효율화 등)

요즘 1일 1시간 릴스는 필연적이다. 그렇다, 지금은 모바일 세상이다. 많은 데스크톱과 노트북이 휴대폰으로 대체되었다. 모바일은 셀룰러(데이터)나 와이파이를 통해 네트워크 연결을 한다. 또한 터치 스크린, 음성 인식 등 다양한 기능들이 있다.

물론 사용자와 상호작용이 없는 OS도 있다. Embedded computers다. 선풍기, 세탁기, 냉장고와 같은 것들 안에도 OS가 들어간다. 물론 버튼이나 요즘은 세상이 좋아져서 터치 스크린도 있긴 하지만, 원래 목적은 사용자 간섭 없이 동작하는 것이다.

### 1.1.2 System view
컴퓨터 입장에서 OS를 보면, 그냥 하드웨어 관리해주는 놈이다. 이러한 문맥으로 생각하면 OS는 `자원 할당자`다
컴퓨터 시스템은 작업을 하기 위해 많은 자원들을 필요로 한다(CPU 시간, 메모리 공간, 저장 공간, 입출력 기기 등)
그니깐 자원은 한정적인데 쓰려고 하는 놈들이 많으니깐 OS가 관리를 해주는 것이다.
약간 다른 관점에서 보면 OS는 사용자 프로그램과 수많은 입출력을 관리해야 한다. OS는 Control Program이다.

### 1.1.3 Defining Operating System
OS 없이 뭘 못한다. 모든 Iot 기기들의 근본이다.
잠깐 컴퓨터의 역사 타임을 가져보자. 컴퓨터의 역사는 짧지만 굉장히 빠르게 성장했다.
원래 컴퓨팅은 군대에서 암호 해독처럼 "특정 목적"을 위한 계산이였다. 이러한 컴퓨팅이 범용 목적으로 발전하였고, 이게 OS의 근간이다. 무어의 법칙이라고 있는데 그냥 몇 년마다 컴퓨터 성능이 몇 배 좋아진다! 이런거다.

OS가 하는 일이 너무 많아서 "딱 이거다"라고 못하나보다
컴퓨터 시스템의 목적 -> 프로그램을 실행하고, 사용자들의 문제를 더 쉽게 해결해주기 위함 -> 하드웨어가 나타나서 이를 해결했지만 사용하기 어려움 -> OS가 다 해준다

OS도 사실은 메모리 위에서 돌아가고 있는 프로그램이다. -> 이거를 Kernel이라고 생각하자
그러면 우리는 프로그램을 2가지로 나눌 수 있는데, 하나는 `System Program`: OS과 관련된 프로그램인데 꼭 커널일 필요는 없다. `Application Programs`: 시스템 동작과 관련 없는 모든 앱들

모바일은 core kernel 에 추가로 middleware(개발자들을 위한)까지 달려있다.

### 1.2 Computer-System Organization
요즘 시대가 발달해서 컴퓨터 시스템에 CPU 여러 개를 둔다. 그리고 I/O 기기들도 많이 연결된다(메모리와 연결될 때 bus를 통함). 각 기기는 고유 드라이버가 있다.`장치 관리자` 들어가서 보면 수많은 기기들이 연결돼 있고, 막 버스 장치, 컨트롤러 등을 볼 수 있다.
CPU, device controller는 병렬로 실행 가능하다. 공유 메모리 접속 시, 순서를 보장하기 위해 Memory Controller가 메모리 접근을 동기화 한다.

### 1.2.1 Interrupts
I/O 작업을 하려면 기기 드라이버가 기기 컨트롤러에서 올바른 레지스터를 가져온다. 컨트롤러는 작업을 내리고 기기와 데이터를 주고 받는다. 끝나면 드라이버한테 끝났다고 말한다. 그 뒤로 드라이버는 다시 사용하던 CPU 자원을 넘긴다. 그러면 어떻게 끝난 지를 아는 걸까?? -> 바로 Interrupt 다

하드웨어는 시스템 버스를 통해 메모리에 수많은 Interrupt 요청을 보낸다. CPU 가 interrupt 시, 하던 동작을 멈추고, 정해진 장소로 간다.

인터럽트는 컴퓨터 구조에서 굉장히 중요한 부분이다. 컴퓨터는 고유의 인터럽트 동작 방식을 가지고 있다(대부분은 비슷하다).

왔다 갔다 반복을 굉장히 빠르고 많이 해야 되니깐 포인터 테이블로 관리하면 된다.

또한, 그럴 때마다 기존 정보와 새로 바뀌는 정보들도 다 알고 있어야 한다.
