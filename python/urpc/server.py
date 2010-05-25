import Log_pb2, uRPC_pb2
import zmq


def main():
  context = zmq.Context(1, 1)
  socket = context.socket(zmq.REP)
  socket.bind("tcp://127.0.0.1:5555")
  
  while True:
    request = uRPC_pb2.Request()
    msg = socket.recv()
    request.ParseFromString(msg)
    print request
    
    response = uRPC_pb2.Response()
    response.message = "OK"
    socket.send(response.SerializeToString())
    print "sent OK"

if __name__ == '__main__':
  main()