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
    requestEnvelope = uRPC_pb2.RequestEnvelope()
    request = randexample_pb2.Request()
  
    wireRequestEnvelope = socket.recv()
    requestEnvelope.ParseFromString(wireRequestEnvelope)
    request.ParseFromString(requestEnvelope.request)
    
    statusMsg = 'GOT REQUEST [%s](%s) nMessage=%d nSample=%d' % \
      (requestEnvelope.service, requestEnvelope.version, request.nMessage, \
      request.nSample)
    print(statusMsg)
    

    for i in range(0, request.nMessage):
    
      replyEnvelope = uRPC_pb2.ReplyEnvelope()
      reply = randexample_pb2.Reply()
      
      for j in range(0, request.nSample):
        rnd = random.random()
        #print(rnd)
        reply.r.append(rnd)
      
      replyEnvelope.reply = reply.SerializeToString()
      wireReplyEnvelope = replyEnvelope.SerializeToString()
      
      if i == (request.nMessage - 1):
        socket.send(wireReplyEnvelope)
      else:
        socket.send(wireReplyEnvelope, zmq.SNDMORE)
        
      print('SENT %d bytes' % len(wireReplyEnvelope))
    

if __name__ == '__main__':
  server()  