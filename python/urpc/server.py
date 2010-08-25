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
    
    replyEnvelope = uRPC_pb2.ReplyEnvelope()
    replyEnvelope.reply = reply.SerializeToString()
    wireReplyEnvelope = replyEnvelope.SerializeToString()
    
    if moreToCome:
      self._socket.send(wireReplyEnvelope, zmq.SNDMORE)
    else:
      self._socket.send(wireReplyEnvelope)
      
    print('SENT %d bytes' % len(wireReplyEnvelope))
  def serve(self):
    
    while True:
      requestEnvelope = uRPC_pb2.RequestEnvelope()
      wireRequestEnvelope = self._socket.recv()
      requestEnvelope.ParseFromString(wireRequestEnvelope)
      self.processRequest(requestEnvelope)
      
