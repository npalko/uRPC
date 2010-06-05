import Log_pb2, uRPC_pb2
import randexample_pb2
import zmq


def client():
  context = zmq.Context(1, 1)
  socket = context.socket(zmq.REQ)
  socket.connect("tcp://127.0.0.1:5555")
  
  request = uRPC_pb2.Request()
  randRequest = randexample_pb2.Request()
  request.service = 'some service'
  request.version = 8
  randRequest.m = 4
  randRequest.n = 3
  request.message = randRequest.SerializeToString()
  socket.send(request.SerializeToString())
  
  response = uRPC_pb2.Response()
  randResponse = randexample_pb2.Response()
  response.ParseFromString(socket.recv())
  randResponse.ParseFromString(response.message)
  print randResponse
  
if __name__ == '__main__':
  client()