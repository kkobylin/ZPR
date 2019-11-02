import socket
import errno
import pickle
import sys
# todo change to external ip address


IP = "127.0.0.1"
PORT = 8080
# Header say how long our message will be
HEADER_SIZE = 10

# create the socket
# AF_INET == ipv4
# SOCK_STREAM == TCP
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((IP, PORT))
# Do not block receiving messages
client_socket.setblocking(False)

send_once = True

while True:
    # todo receive data from Javascript as well

    # Received message from frontend
    msg_to_send = "Hey from client side"
    # Send message to server
    if msg_to_send and send_once:
        msg_to_send = msg_to_send.encode('utf-8')
        msg_header = f"{len(msg_to_send):<{HEADER_SIZE}}".encode('utf-8')
        client_socket.send(msg_header + msg_to_send)
        send_once = False

    # Receive message from server
    try:
        full_msg = b''
        new_msg = True
        while True:
            # Receive data in a buffer size of 16 bytes
            msg = client_socket.recv(16)
            if new_msg:
                print("new msg len:", msg[:HEADER_SIZE])
                msg_len = int(msg[:HEADER_SIZE])
                new_msg = False

            print(f"full message length: {msg_len}")

            full_msg += msg

            print(len(full_msg))

            if len(full_msg)-HEADER_SIZE == msg_len:
                print("full msg received")
                print(pickle.loads(full_msg[HEADER_SIZE:]))
                new_msg = True
                full_msg = ""
    except IOError as e:
        # when there are no incoming data error is going to be raised
        # Some operating systems will indicate that using AGAIN, and some using WOULDBLOCK error code
        if e.errno == errno.EAGAIN or e.errno == errno.EWOULDBLOCK:
            continue
        else:
            print('Reading error: {}'.format(str(e)))
            sys.exit()
