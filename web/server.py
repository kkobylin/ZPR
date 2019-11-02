import socket
import pickle
import json
import select

IP = "127.0.0.1"
PORT = 8080

JS_msg = {
    "Figure": "Pawn",
    "Position": "F5"
}

json_msg = json.dumps(JS_msg)
HEADER_SIZE = 10

# create the socket
# AF_INET == ipv4
# SOCK_STREAM == TCP
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((IP, PORT))
# queue
server_socket.listen(5)

# List of sockets for select.select()
sockets_list = [server_socket]


def receive_message(client_socket):
    try:
        message_header = client_socket.recv(HEADER_SIZE)

        if not len(message_header):
            return False

        message_length = int(message_header.decode('utf-8').strip())
        return {'header': message_header, 'data': client_socket.recv(message_length)}
    except:
        return False


while True:
    read_sockets, _, _ = select.select(sockets_list, [], [])

    for notified_socket in read_sockets:
        if notified_socket == server_socket:
            # Accept new connection
            client_socket, client_address = server_socket.accept()
            print(f"Connection from {client_address} has been established.")
            sockets_list.append(client_socket)
        else:
            # Receive message
            message = receive_message(notified_socket)

            if message is False:
                print('Closed connection from: {}'.format(notified_socket))
                sockets_list.remove(notified_socket)
                continue

            # todo cpp functions here with message
            print(message)
            msg = pickle.dumps(json_msg)
            msg = bytes(f"{len(msg):<{HEADER_SIZE}}", 'utf-8')+msg
            notified_socket.send(msg)
