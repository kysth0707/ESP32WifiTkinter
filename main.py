import socket

Port = 8765

print("[-] Server Opening...")
try:
	s = socket.socket()
	s.bind(('0.0.0.0', Port))
except:
	print("[✖] Failed to open server")
	raise
print("[✔] Server Opened")

s.listen(0)
print("[✔] Server started to listen...")

while True:
	Client, Address = s.accept()
	print(Client, Address)

	while True:
		Content = Client.recv(32)

		if len(Content) == 0:
			print(f"[✔] Connection ended")
			break
		else:
			print(f"[✔] Receved : {Content}")

	print("[-] Closing connection...")
	Client.close()
	print("[✔] Closed connection")