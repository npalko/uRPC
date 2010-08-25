from __future__ import print_function
import sys

sys.path.append( '../../python/')

import randexample_pb2
import random
import urpc

class RandServer(urpc.server.SingleThreadServer):
  def processRequest(self, request):
    """ """
    
    randRequest = randexample_pb2.Request()
    randRequest.ParseFromString(request.request)
    statusMsg = 'GOT REQUEST [%s](%s) nMessage=%d nSample=%d' % \
      (request.service, request.version, randRequest.nMessage, \
      randRequest.nSample)
    print(statusMsg)
    
    for i in range(randRequest.nMessage):
      reply = randexample_pb2.Reply()
      for j in range(randRequest.nSample):
        rnd = random.random()
        reply.r.append(rnd)
      moreToCome = (i != randRequest.nMessage - 1)
      self.sendReply(reply, moreToCome)


if __name__ == '__main__':
  rs = RandServer()  
  rs.serve()
  