import sys

sys.path.append('../../python/')


import urpc 
import randexample_pb2

  
if __name__ == '__main__':
  client = urpc.client.SingleThreadClient()

  request = randexample_pb2.Request()
  reply = randexample_pb2.Reply()

  request.nMessage = 1
  request.nSample = 10
  client.sendRequest('some service',8,request)
  reply.ParseFromString(client.getReply())

  print reply


