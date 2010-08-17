from __future__ import print_function

import random
import Log_pb2, uRPC_pb2
import randexample_pb2
import zmq



def server(connection='tcp://127.0.0.1:5555'):

  context = zmq.Context()
  socket = context.socket(zmq.REP)
  socket.bind(connection)
  print('bound to %s' % connection)
  
  while True:
    request = uRPC_pb2.Request()
    msg = socket.recv()
    
    request.ParseFromString(msg)
    randRequest = randexample_pb2.Request()
    randRequest.ParseFromString(request.message)
    
    print('GOT [%s](%d) (m=%d,n=%d)' % (request.service, \
      request.version, \
      randRequest.m, \
      randRequest.n))
    
    response = uRPC_pb2.Response()
    randResponse = randexample_pb2.Response()
    
    for i in range(0,randRequest.m * randRequest.n):
      randResponse.r.append(random.random())
    
    response.message = randResponse.SerializeToString()
    msg = response.SerializeToString()
    socket.send(msg)
    print('SENT %d bytes' % len(msg))
    

if __name__ == '__main__':
  server()  