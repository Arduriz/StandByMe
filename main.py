import tkinter
import math
import time
from tkinter import * # tkinter 라이브러리
import serial

###########################################################################
py_serial = serial.Serial(
	port = '/dev/ttyACM0', # 라즈베리파이 연결 포트

	baudrate=115200,
)
###########################################################################
stack = [] # 경로 기억을 위한 스택
stack_t = [] # 조작 타임을 기억하기 위한 스택

def move_forward():  # 전진
	global start
	command = "w"
	encoded_serial = command.encode(encoding="ascii", errors="ignore")
	py_serial.write(encoded_serial)
	start = time.time()
	if py_serial.readable():
		stack.append('s')

def move_backward():  # 후진
	global start
	command = "s"
	encoded_serial = command.encode(encoding="utf-8", errors="ignore")
	py_serial.write(encoded_serial)
	start = time.time()
	if py_serial.readable():
		stack.append('w')

def turn_left():  # 좌회전
	global start
	command = "a"
	encoded_serial = command.encode(encoding="utf-8", errors="ignore")
	py_serial.write(encoded_serial)
	start = time.time()
	if py_serial.readable():
		stack.append('d')

def turn_right():  # 우회전
	global start
	command = "d"
	encoded_serial = command.encode(encoding="utf-8",errors="ignore")
	py_serial.write(encoded_serial)
	start = time.time()
	if py_serial.readable():
		stack.append('a')

def init():  # 기록 시작(기존 경로 스택 초기화, 경로 기억 파일 초기화)
	global stack
	global stack_t
	stack = []
	stack_t = []
	file_clear = open("./path.txt",'w')
	file_clear.write('')
	file_clear.close()

def fin():  # 기록 종료(기록 시작시부터 스택에 이동한 경로 저장 후 겅로 기억 파일 작성)
	file_write = open("./path.txt", 'w')  # 이동한 경로와 시간을 파일 데이터로 저장
	print('기억한 경로는 :')
	for k in range(len(stack)):
		top = stack.pop()
		top_t = stack_t.pop()
		print(top, ' ', top_t)
		file_write.write(top)
		file_write.write(' ')
		file_write.write(top_t)
		file_write.write('\n')
	file_write.close()

def halt():  # 정지 / 정지까지 걸린 시간 스택에 저장
	global end
	command = "f"
	encoded_serial = command.encode(encoding="utf-8", errors="ignore")
	py_serial.write(encoded_serial)
	if py_serial.readable():
		end = time.time()  # 정지까지 걸린 시간
		print(f"{end - start:.10f}")
		stack_t.append(f"{end - start:.10f}")

def neck_up():  # stepper 모터를 이용한 디스플레이 높이 상승
	command = "u"
	encoded_serial = command.encode(encoding="utf-8",errors="ignore")
	py_serial.write(encoded_serial)

def neck_down():  # 디스플레이 높이 하강
	command = "j"
	encoded_serial = command.encode(encoding="utf-8",errors="ignore")
	py_serial.write(encoded_serial)

def reverse():  # 경로 기억 파일에 저장된 길을 그대로 돌아가는 프리셋 무브
	file_read = open("./path.txt", 'r') # 스택에 저장한 역 경로 파일 열기
	if (file_read == None): # 파일열기에 실패하였을 경우를 대비
		print('파일열기 실패\n')
	lines = file_read.readlines()

	for k in range(len(lines)):
		lines[k] = lines[k].strip().split()
		print('')
		if lines[k][0] == "w":
			rev_move_forward(lines[k][1])
		elif lines[k][0] == "s":
			rev_move_backward(lines[k][1])
		elif lines[k][0] == "a":
			rev_turn_left(lines[k][1])
		elif lines[k][0] == "d":
			rev_turn_right(lines[k][1])
		elif lines[k][0] == "f":
			halt()

	file_read.close()

def rev_move_forward(delay):  # reverse() 함수에서의 전진
	command = "w"
	encoded_serial = command.encode(encoding="ascii", errors="ignore")
	py_serial.write(encoded_serial)
	time.sleep(float(delay))
	command = "f"
	encoded_serial = command.encode(encoding="utf-8", errors="ignore")
	py_serial.write(encoded_serial)

def rev_move_backward(delay):  # reverse() 함수에서의 후진
	command = "s"
	encoded_serial = command.encode(encoding="ascii", errors="ignore")
	py_serial.write(encoded_serial)
	time.sleep(float(delay))
	command = "f"
	encoded_serial = command.encode(encoding="utf-8", errors="ignore")
	py_serial.write(encoded_serial)

def rev_turn_left(delay):  # reverse() 함수에서의 좌회전
	command = "a"
	encoded_serial = command.encode(encoding="ascii", errors="ignore")
	py_serial.write(encoded_serial)
	time.sleep(float(delay))
	command = "f"
	encoded_serial = command.encode(encoding="utf-8", errors="ignore")
	py_serial.write(encoded_serial)

def rev_turn_right(delay):  # reverse() 함수에서의 우회전
	command = "d"
	encoded_serial = command.encode(encoding="ascii", errors="ignore")
	py_serial.write(encoded_serial)
	time.sleep(float(delay))
	command = "f"
	encoded_serial = command.encode(encoding="utf-8", errors="ignore")
	py_serial.write(encoded_serial)

###########################################################################
tk = Tk() # 방향키 조작 루트화면 생성
tk.geometry('430x200') # 창 크기
tk.title('스탠바이미 조작 UI') # 창 이름

button_up = Button(tk,text='▲',font=15,width=5,height=3,bg='white',command=move_forward) # up arrow
button_down = Button(tk,text='▼',font=15,width=5,height=3,bg='white',command=move_backward) # down arrow
button_left = Button(tk,text='◀',font=15,width=5,height=3,bg='white',command=turn_left) # left arrow
button_right = Button(tk,text='▶',font=15,width=5,height=3,bg='white',command=turn_right) # right arrow
button_start = Button(tk,text='기록',font=15,width=5,height=3,bg='blue',command=init) # 기록 시작 버튼
button_end = Button(tk,text='종료',font=15,width=5,height=3,bg='red',command=fin) # 기록 종료 버튼
button_halt = Button(tk,text='멈춤',font=15,width=5,height=3,bg='yellow',command=halt) # 멈춤 버튼
button_reverse = Button(tk,text='복귀',font=15,width=5,height=3,bg='pink',command=reverse) # 복귀 버튼
button_start.grid(row=2,column=1,padx=3,pady=3)
button_end.grid(row=2,column=2,padx=3,pady=3)
button_up.grid(row=1,column=4,padx=3,pady=3)
button_halt.grid(row=2,column=4,padx=3,pady=3)
button_down.grid(row=3,column=4,padx=3,pady=3)
button_left.grid(row=2,column=3,padx=3,pady=3)
button_right.grid(row=2,column=5,padx=3,pady=3)
button_neck_up = Button(tk,text='▲',font=15,width=5,height=3,bg='green',command=neck_up) # 높이 up 버튼
button_neck_down = Button(tk,text='▼',font=15,width=5,height=3,bg='purple',command=neck_down) # 높이 down 버튼
button_neck_up.grid(row=1,column=6,padx=3,pady=3)
button_neck_down.grid(row=3,column=6,padx=3,pady=3)
button_reverse.grid(row=2,column=7,padx=3,pady=3)
###########################################################################
tk.mainloop() #종료 프로세스