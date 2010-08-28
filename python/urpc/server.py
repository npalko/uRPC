import uRPC_pb2
import zmq

class SingleThreadServer(object):
  def __init__(self, connection='tcp://127.0.0.1:5555'):
    """ """
    
    self._context = zmq.Context()
    self._socket = self._context.socket(zmq.REP)
    self._socket.bind(connection)
    print('bound to %s' % connection)
  def processRequest(self, request):
    """ """
    
    raise ("must be implemented")
  def sendReply(self, reply, moreToCome=False):
    """ """
    
    sendFlag = zmq.SNDMORE if moreToCome else 0
    replyEnvelope = uRPC_pb2.ReplyEnvelope()
    replyEnvelope.reply = reply.SerializeToString()
    wireReplyEnvelope = replyEnvelope.SerializeToString()
    
    self._socket.send(wireReplyEnvelope, sendFlag)
    print('SENT %d bytes' % len(wireReplyEnvelope))
  def serve(self):
    """ """
    
    while True:
      wireRequestEnvelope = self._socket.recv()
    
      requestEnvelope = uRPC_pb2.RequestEnvelope()
      requestEnvelope.ParseFromString(wireRequestEnvelope)
      self.processRequest(requestEnvelope)
      
